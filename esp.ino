#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
String data;


const char* ssid = "AndroidAP_5787";
const char* password = "praveen41";

WiFiClient client;

unsigned long channelID = 3410422;
const char* writeAPIKey = "JRMCF6KF8CVRP1BA";


void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  ThingSpeak.begin(client);

}

void loop() {
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
     //Serial.print("wlev,tem,hum,smoi,rain,ldr");
    int wlev,tem,hum,smoi,rain,ldr;
    sscanf(data.c_str(), "%d,%d,%d,%d,%d,%d",&wlev, &tem, &hum, &smoi, &rain, &ldr);

    Serial.println("Received:");
    Serial.println("wlev=" + String(wlev));
    Serial.println("tem=" + String(tem));
    Serial.println("hum=" + String(hum));
    Serial.println("smoi=" + String(smoi));
    Serial.println("rain=" + String(rain));
    Serial.println("ldr=" + String(ldr));
    ThingSpeak.setField(1, wlev);
    ThingSpeak.setField(2, tem);
    ThingSpeak.setField(3, hum);
    ThingSpeak.setField(4, smoi);
    ThingSpeak.setField(5, rain);
    ThingSpeak.setField(6, ldr);

    int status = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (status == 200) {
    Serial.println("Data sent successfully");
  } else {
    Serial.print("Error code: ");
    Serial.println(status);
  }

  delay(20000);
    
  }
}