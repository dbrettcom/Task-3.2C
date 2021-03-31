// This #include statement was automatically added by the Particle IDE.
#include <JsonParserGeneratorRK.h>

// This #include statement was automatically added by the Particle IDE.
#include <BH1750Lib.h>

//********************************************************************
// BH1750Lib for Spark
// http://github.com/davidegironi/spark-bh1750lib
// Copyright (c) Davide Gironi, 2014 
//
// References:
//   https://github.com/claws/BH1750/
//
// Released under GPLv3.
// Please refer to LICENSE file for licensing information.
//********************************************************************

//debug to serial port
#define UARTDEBUG 1

//initialize devide
BH1750Lib lightSensor;

void setup() {
    
    lightSensor.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
    uint16_t luxvalue = lightSensor.lightLevel();

  
#if UARTDEBUG == 1
    Serial.begin(9600); 
    Serial.println("Starting...");
#endif

    Particle.variable("lux", luxvalue);
}

void loop() {

    uint16_t luxvalue = lightSensor.lightLevel();

    char szEventInfo[64];
    sprintf(szEventInfo, "lux = %d", luxvalue);

    Spark.publish("Light Sensor", szEventInfo);
    
#if UARTDEBUG == 1
    //read
    Serial.print("lux: ");
    Serial.print(luxvalue);
    Serial.println("lux");
#endif
    
    //wait for the next reading
    delay(2000);
}
