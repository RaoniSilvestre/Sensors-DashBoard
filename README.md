# Sensor Dashboard

Sisteminha que fiz nas férias para pegar dados do ambiente de uma planta, enviar para meu "home server" e mostrar na rede local

## Partes do projeto

- Frontend: 
  - Simplesmente cria gráficos com dados recebidos da api 

- Backend:
  - Recebe dados do ESP32 e guarda num banco de dados sqlite, 
  - envia dados do banco de dados via api para a rede, onde é capturada pelo frontend;

- Sistema Embarcado: 
  - Têm os sensores do ambiente e envia os dados periodicamente para o backend;
