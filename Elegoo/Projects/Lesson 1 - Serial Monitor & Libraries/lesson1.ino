// Demo of including the Bridge library to the project
// Just use the built-in library manager

#include <Bridge.h>
#include <BridgeClient.h>
#include <BridgeServer.h>
#include <BridgeSSLClient.h>
#include <BridgeUdp.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

// Zip Library
// Can be added by Arduino IDE or by putting the uncompressed folder inside Documents/Arduino/libraries
#include <LiquidCrystal.h>


void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("This will display every second.");
    delay(1000);
}