#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <Arduino.h>

class Configuration {
    public:
        class Beacon {
            public: 
                Beacon() : message("Lora iGate, Info: https://github.com/dl1lmh/LoRa-Board"), GPS_Latitude(0.0), GPS_Longitude(0.0) {}

                String message;
                double GPS_Latitude;
                double GPS_Longitude;
        };

        class APRS_IS{
	        public:
		        APRS_IS() : active(false), server("euro.aprs2.net"), port(14580), beacon(true), beaconTimeout(15) {}

		        bool active;
		        String password;
		        String server;
		        int port;
		        bool beacon;
		        int beaconTimeout;
	    };

        
	    class LoRa{
	        public:
		        LoRa() : frequencyRx(433775000), frequencyTx(433775000), power(20), spreadingFactor(12), signalBandwidth(125000), codingRate4(5) {}

		        long frequencyRx;
		        long frequencyTx;
		        int power;
		        int spreadingFactor;
		        long signalBandwidth;
		        int codingRate4;
	    };
};


#endif