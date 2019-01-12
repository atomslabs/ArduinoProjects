#include <ESP8266WiFi.h>

const char* ssid     = "AtomsLabs-Wifi";
const char* password = "Muscat01";
const char* host = "thingspeak.com";
int field1Val=0;
int field2Val=0;

String url = "https://api.thingspeak.com/update?api_key=UQH46MQTYLUZOBEX&field1=atm1";


void setup() {

   Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Not Connected Yet");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  Serial.println( url+vout +"&fiel2="+current+"&field2="+ power);
  
client.print(String("GET ") + url +"&field2="+field2Val+"&field3="+ field3Val+" HTTP/1.1\r\n" +
               "Host: " + "thingspeak.com" + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");

delay(1000);

}
