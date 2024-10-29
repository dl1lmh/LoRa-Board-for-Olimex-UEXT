#include <Arduino.h>

#include <ETH.h>
#include <ESPmDNS.h>
#include <AsyncTCP.h>
#include <AsyncUDP.h>
#include <ArduinoOTA.h>


static bool eth_connected = false;

void WiFiEvent(WiFiEvent_t event){
  switch (event) {
    case ARDUINO_EVENT_ETH_START:
      Serial.println("ETH Service Started");
      ETH.setHostname("LoRa-APRS Igate");
      break;

    case ARDUINO_EVENT_ETH_CONNECTED: 
      Serial.println("ETH Connected");
      break;  
          
    case ARDUINO_EVENT_ETH_GOT_IP:
      Serial.print("Ask for IP Address for ETH MAC: ");
      Serial.print(ETH.macAddress());
      Serial.print(", IPv4: ");
      Serial.print(ETH.localIP());
      if (ETH.fullDuplex()) {
        Serial.print(", FULL_DUPLEX");
      }
      Serial.print(", ");
      Serial.print(ETH.linkSpeed());
      Serial.println("Mbps");
      eth_connected = true;
      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH Disconnected");
      eth_connected = false;
      break;

    case ARDUINO_EVENT_ETH_STOP:
      Serial.println("ETH Stopped");
      eth_connected = false;
      break;

    default:
      break;
  }
}

void setup() {

  //Wait for Initialise Peripherial interfaces
  delay(2000);

  Serial.begin(115200);


  //Setup OTA
  ArduinoOTA.begin();


}

void loop() {

  ArduinoOTA.handle();
}

