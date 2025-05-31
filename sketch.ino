//#include <WiFi.h>


//simulaçao das configurações wi-fi
const char* ssid = "LuizaAmaral01";
const char* password = "senha1234";

const int pirPin = 15;
const int ledPin = 2;
const int buzzerPin = 13;

void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.println("Iniciando sistema de vigilância");


  //simulando conexão wi-fi
  Serial.print("Conectando ao wi-fi ");
  Serial.println(ssid);
  delay(2000);
  Serial.println("Conectando ao Wi-fi");
}

void loop() {
  int movimento = digitalRead(pirPin);

  if (movimento == HIGH) {
    Serial.println("Movimento detectado! Enviando alerta para o celular!");

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    Serial.println("ALERTA: Movimento detectado na área monitorada!");

    delay(5000); //Esse alarme fica ativo por 5 segundos.

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    Serial.println("Alerta encerrado. Aguardando próximo movimento!");
    delay(2000);

  }
}
