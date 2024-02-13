Olá!
Esse projeto tem o intuito de apresentar uma forma simples de realizar uma conexão entre uma ESP32(ou 8266)a um banco de dados firebase, atualizando as informações no banco utilizando um sensor real de umidade e temperatura. O sensor utilizado no nosso exemplo foi o DHT11, o modelo da ESP foi a ESP-32 DEVKIT V1.

Para que o projeto funcione é necessário criar uma conta no Google Firebase e gerar uma chave de API para o seu projeto. 
Além disso é necessário mudar as regras de leitura e escrita dentro do firebase de false para true, assim será possível ler os dados e gravar através da ESP

Outro detalhe importante é que a lib ArduinoJson deve ser a fornecida pelo Benoit Blanchon, e não pode ser superior a versão 5.13.5

O código apresenta alguns comentários para facilitar o entendimento, você pode retira-los sem problema algum.

Bom divertimento!
