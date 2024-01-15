import React, { useEffect, useState } from "react";
import {
  Chart as ChartJS,
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend,
} from "chart.js";
import { Line } from "react-chartjs-2";

ChartJS.register(
  CategoryScale,
  LinearScale,
  PointElement,
  LineElement,
  Title,
  Tooltip,
  Legend
);

export const optionsTemp = {
  responsive: true,
  plugins: {
    legend: {
      position: "top",
    },
    title: {
      display: true,
      text: "Temperatura",
    },
  },
};

export const optionsHumidity = {
  responsive: true,
  plugins: {
    legend: {
      position: "top",
    },
    title: {
      display: true,
      text: "Umidade do ar",
    },
  },
};

export const optionsMoisture = {
  responsive: true,
  plugins: {
    legend: {
      position: "top",
    },
    title: {
      display: true,
      text: "Umidade do solo",
    },
  },
};

export function App() {
  const [tempData, setTempData] = useState({ labels: [], datasets: [] });
  const [humidityData, setHumidityData] = useState({
    labels: [],
    datasets: [],
  });
  const [moistureData, setMoistureData] = useState({
    labels: [],
    datasets: [],
  });

  useEffect(() => {
    fetch("http://192.168.0.200:3000/dados")
      .then((response) => {
        if (!response.ok) {
          throw new Error(`HTTP error! status: ${response.status}`);
        }
        return response.json();
      })
      .then((data) => {
        console.log(data);
        const labels = data.map((item) => item.data_hora);
        const tempDataset = data.map((item) => item.temperatura);
        const humidityDataset = data.map((item) => item.umidade);
        const moistureDataset = data.map((item) => item.umidade_solo);

        setMoistureData({
          labels,
          datasets: [
            {
              label: "Umidade do solo",
              data: moistureDataset,
              borderColor: "rgb(99,99,250)",
              backgroundColor: "rgba(99,99,250, 0.5)",
            },
          ],
        });

        setHumidityData({
          labels,
          datasets: [
            {
              label: "Umidade do ar",
              data: humidityDataset,
              borderColor: "rgb(99,250,99)",
              backgroundColor: "rgba(99,250,99,0.5)",
            },
          ],
        });

        setTempData({
          labels,
          datasets: [
            {
              label: "Temperatura",
              data: tempDataset,
              borderColor: "rgb(255, 99, 132)",
              backgroundColor: "rgba(255, 99, 132, 0.5)",
            },
          ],
        });
      })
      .catch((error) => {
        console.error("Error:", error);
      });
  }, []);

  return (
    <div>
      <Line options={optionsTemp} data={tempData} />
      <Line options={optionsHumidity}  data={humidityData} />
      <Line options={optionsMoisture}   data={moistureData} />
    </div>
  );
}

export default App;
