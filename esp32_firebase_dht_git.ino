
#include <WiFi.h>                          //importa biblioteca para conectar esp32 com wifi
#include <IOXhop_FirebaseESP32.h>          //importa biblioteca para esp32 se comunicar com firebase
#include <ArduinoJson.h>                   //importa biblioteca para colocar informação no formato json, utilizado no firebase (instalar versão 5)
#include <DHT.h>                           //importa biblioteca do sensor dht11

//definições da rede e do banco
#define WIFI_SSID "xxxxx"            //dados da rede conectada(substitua pelos dados da sua rede)     
#define WIFI_PASSWORD "vaicorinthians"             
#define FIREBASE_HOST "https://eeeeeeeeeeeee-rtdb.firebaseio.com/"    //link do seu realtime-databse(substitua pelos dados do seu firebase)
#define FIREBASE_AUTH "ASDW$#RFgrwg4wgwGrgw$4fGsaf"   ///chave api do firebase

DHT dht(26, DHT11); // pino do sensor


void setup() {
  Serial.begin(115200);      //inicia comunicação serial
  dht.begin();               //inicializa o sensor
  Serial.println();          //imprime pulo de linha

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     //inicia comunicação com wifi com rede definida anteriormente
  
  Serial.print("Conectando Sensores! a internet!");       //imprime "Conectando ao wifi"
  while (WiFi.status() != WL_CONNECTED)     //enquanto se conecta ao wifi fica imprimindo pontos
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();  

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   //inicia comunicação com firebase definido anteriormente
  Serial.print("Conectado!");
}

void loop() { //loop com atualização da temperatura e humidade do banco

  Firebase.setFloat("/sensor/temperatura", readDHTTemperature()); //chama função de leitura de temperatura
  Firebase.setFloat("/sensor/humidade", readDHTHumidity()); //chama função de leitura de humidade
  delay(3000);

}

//funções de ler temperatura e umidade

float readDHTTemperature() {
  // Ler temperatura como Celsius
  float t = dht.readTemperature();
  if (isnan(t)) {    
    Serial.println("Failed to read from DHT sensor!"); //exceção caso haja algum erro na leitura dos dados do sensor
    return -1;
  }
  else {
    Serial.println(t);
    return t;           //RETORNA TEMPERATURA
  }
}

float readDHTHumidity() {     //le umidade

  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");      //exceção caso haja algum erro na leitura dos dados do sensor
    return -1;
  }
  else {
    Serial.println(h);
    return h;                                             //retorna umidade do sensor
  }
}
