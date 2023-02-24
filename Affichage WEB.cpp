#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "xxxxxx";
const char* password = "xxxxx";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop(){

  WiFiClient client = server.available();

  if (client) {
    Serial.println("Nouvelle connexion");

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head>");
        client.println("<title>Essai d'affichage d'une page web</title>");
      client.println("</head>");
        client.println("<body>");
        client.println("<h1>ESP32 Web Server</h1>");
        client.println("<h2>Essai affichage page web</h2>");
        client.println("Postremo ad id indignitatis est ventum, ut cum peregrini ob formidatam haut ita dudum alimentorum inopiam pellerentur ab urbe praecipites, sectatoribus disciplinarum liberalium inpendio paucis sine respiratione ulla extrusis, tenerentur minimarum adseclae veri, quique id simularunt ad tempus, et tria milia saltatricum ne interpellata quidem cum choris totidemque remanerent magistris.");
        client.println("</body>");
      client.println("</html>");
    client.println();
    delay (100);
    client.stop();
      }
    }
