const express = require("express");
const sqlite3 = require("sqlite3").verbose();
const app = express();
const bodyParser = require("body-parser");
const cors = require('cors');
const db = new sqlite3.Database("dados-sensor.db");

db.run(
  `CREATE TABLE IF NOT EXISTS dados_sensor (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    temperatura FLOAT,
    umidade FLOAT,
    umidade_solo FLOAT,
    data_hora DATETIME DEFAULT CURRENT_TIMESTAMP
  )`
);

app.use(cors());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.post("/dados", (req, res) => {
  const dados = req.body;

  db.run(
    `INSERT INTO dados_sensor (temperatura, umidade, umidade_solo) VALUES (${dados.temperatura.toFixed(2)}, ${dados.umidade}, ${dados.umidade_solo})`,
    function (err) {
      if (err) {
        return console.log(err.message);
      }
      console.log(`Dados inseridos com sucesso as ${new Date().toLocaleString('pt-br')}`);
      res.send(`Dados inseridos com sucesso`);
    }
  );
});

app.get("/dados", (req, res) => {
  db.all(`SELECT * FROM dados_sensor WHERE data_hora >= strftime('%Y-%m-%d %H:%M%S', 'now', '-1 day', 'localtime'); `, (err, rows) => {
    if (err) {
      return console.log(err.message);
    }
    res.send(rows);
	console.log("Dados capturados as ");
  });
});


app.listen(3000, () => {
  console.log("Server running on port 3000");
});
