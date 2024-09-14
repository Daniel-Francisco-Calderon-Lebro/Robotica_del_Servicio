#include <WiFi.h>
#include <WebServer.h>
const char* ssid = "UNE_HFC_E9FD"; // Reemplaza con el nombre de tu red Wi-Fi
const char* password = "EQB9LMLO"; // Reemplaza con tu contraseña Wi-Fi


WebServer server(80); // Crear un servidor web en el puerto 80

void setup() {
    // Inicializar la comunicación serial
    Serial.begin(115200);
    Serial.println();

    // Conectar a la red Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to ");
    Serial.print(ssid);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Configurar el servidor web
    server.on("/", HTTP_GET, []() {
        server.send(200, "text/plain", "Cambio");
    });

    server.begin(); // Iniciar el servidor web
}

void loop() {
    server.handleClient(); // Manejar las solicitudes de cliente
}
