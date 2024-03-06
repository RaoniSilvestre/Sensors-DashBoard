# Sensor Dashboard

Sisteminha que fiz nas férias para pegar dados do ambiente de uma planta, enviar para meu "home server" e mostrar na rede local

## Partes do projeto

- Frontend: 
  - Cria gráficos;
  - Pega dados do backend via API para os gráficos;

- Backend:
  - Recebe dados do ESP32 e guarda num banco de dados sqlite, 
  - Envia dados do banco de dados via api para a rede, onde é capturada pelo frontend;

- Sistema Embarcado: 
  - Monitoramento via sensores;
  - envia os dados periodicamente para o backend;

## Tecnologias Utilizadas

- Frontend:
  - React;
  - ChartJS;
  - Axios;

- Backend:
  - Express;
  - Sqlite3;

- Sistema Embarcado:
  - Sensores de umidade do ar, umidade do solo e temperatura;