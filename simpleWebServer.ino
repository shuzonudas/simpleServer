#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 

const char* ssid = "your wifi access point"; 
const char* password = "your password";

ESP8266WebServer server(80);

void handleRoot() {
	server.send(200, "text/plain", "I'm an awasome webServer!!!");  
	delay(100); 
}

void ledOn() {
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
}

void ledOff() {
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
}

void lcdFlash() {
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
}

void setup(void) {

	Serial.begin(115200);
	Serial.print("Connecting to network");

	WiFi.begin(ssid, password);   // Connect to WiFi network
						     
	while (WiFi.status() != WL_CONNECTED) {    // Wait for connection
		delay(500);    
		Serial.print(".");  
	}

	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	server.on("/", handleRoot);
	server.on("/0", ledOff);
	server.on("/1", ledOn);
	server.on("/2", lcdFlash);

	server.begin();  
	Serial.println("HTTP server started");
}

void loop(void) 
{ 
	server.handleClient(); 
}

