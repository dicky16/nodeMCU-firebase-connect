#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
 
const char* ssid = "realme C3";
const char* password = "raolehdijalok";
 
FirebaseData firebaseData;
 
#define ac D1
#define ld D0
#define lt D2
#define lb D3
 
void setup() {
  Serial.begin(9600);
  pinMode(ac, OUTPUT);
  pinMode(ld, OUTPUT);
  pinMode(lt, OUTPUT);
  pinMode(lb, OUTPUT);
  
  konekWifi();
  Firebase.begin("isi dengan host firebase kalian, contoh : https://slim-b5937.firebaseio.com/", "isi dengan key firebase kalian");
  //Firebase.begin("firebase host", "firebase auth database");
}
 
void konekWifi() {
  WiFi.begin(ssid, password);
  //memulai menghubungkan ke wifi router
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); //status saat mengkoneksikan
  }
  Serial.println("Sukses terkoneksi wifi!");
  Serial.println("IP Address:"); //alamat ip lokal
  Serial.println(WiFi.localIP());
}
 
void loop() {
  if (Firebase.getInt(firebaseData, "/ac/status")) { //misal database diberikan nama relay1
      int acStatus = firebaseData.intData();
      Serial.println("status ac :");
      Serial.println(acStatus);
      delay(0.1);
      if(acStatus == 0) {
        digitalWrite(ac, LOW);
      } else if(acStatus == 1) {
        digitalWrite(ac, HIGH);
      }
  }
  if (Firebase.getInt(firebaseData, "/lampuDepan/status")) { //misal database diberikan nama relay1
      int ldStatus = firebaseData.intData();
      delay(0.1);
      if(ldStatus == 0) {
        digitalWrite(ld, LOW);
      } else if(ldStatus == 1) {
        digitalWrite(ld, HIGH);
      }
  }

  if (Firebase.getInt(firebaseData, "/lampuBelakang/status")) { //misal database diberikan nama relay1
      int lbStatus = firebaseData.intData();
      delay(0.1);
      if(lbStatus == 0) {
        digitalWrite(lb, LOW);
      } else if(lbStatus == 1) {
        digitalWrite(lb, HIGH);
      }
  }

  if (Firebase.getInt(firebaseData, "/lampuTengah/status")) { //misal database diberikan nama relay1
      int ltStatus = firebaseData.intData();
      delay(0.1);
      if(ltStatus == 0) {
        digitalWrite(lt, LOW);
      } else if(ltStatus == 1) {
        digitalWrite(lt, HIGH);
      }
  }
}
