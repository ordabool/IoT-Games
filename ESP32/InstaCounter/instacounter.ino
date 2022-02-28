#include <Arduino_JSON.h>
#include <JSON.h>
#include <JSONVar.h>
#include <WiFi.h>
#include <HTTPClient.h>

unsigned long printTime;
const char* ssid = "SSID_NAME";
const char* password = "SSID_PASS";
String serverName = "https://www.instagram.com/ACCOUNTNAME/?__a=1";

String GRAPHQL = "graphql";
String USER = "user";
String EDGE_FOLLOWED_BY = "edge_followed_by";
String COUNT = "count";


unsigned long lastTime = 0;
unsigned long timerDelay = 60 * 60000; // 1 Hour

void setup() {
    Serial.begin(9600);

    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
    
    Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
    //Send an HTTP POST request every 10 minutes
    if (((millis() - lastTime) > timerDelay) || (lastTime == 0)) {
        //Check WiFi connection status
        if(WiFi.status()== WL_CONNECTED){
        HTTPClient http;

        String serverPath = serverName;
        // String serverPath = serverName + "?temperature=24.37";
        
        // Your Domain name with URL path or IP address with path
        http.begin(serverPath.c_str());
        
        // Send HTTP GET request
        int httpResponseCode = http.GET();
        
        if (httpResponseCode>0) {
            Serial.print("(");
            Serial.print(millis());
            Serial.print(") ");
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            String payload = http.getString();

            JSONVar myObject = JSON.parse(payload);
  
            // JSON.typeof(jsonVar) can be used to get the type of the var
            if (JSON.typeof(myObject) == "undefined") {
                Serial.println("Parsing input failed!");

                
                lastTime = millis();
                return;
            }

            // myObject.keys() can be used to get an array of all the keys in the object
            JSONVar keys = myObject.keys();
            
            int followers = myObject[GRAPHQL][USER][EDGE_FOLLOWED_BY][COUNT];

            for (int i = 0; i < keys.length(); i++) {
              if (GRAPHQL.equals(keys[i])) {
                JSONVar value = myObject[keys[i]];
                Serial.print(keys[i]);
                Serial.print(" = ");
                Serial.println(value);
                break;
              }
            }
        }
        else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
        }
        // Free resources
        http.end();
        }
        else {
            Serial.println("WiFi Disconnected");
        }
        lastTime = millis();
    }
}