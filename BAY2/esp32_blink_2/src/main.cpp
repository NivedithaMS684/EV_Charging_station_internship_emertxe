#include <Arduino.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include <WiFi.h>
#include "Network.h"
#include "Telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"


void setup()
{

    Serial.begin(115200);
    dht.begin(); 
     // initialise sesnor
    configTime(0,0,"pool.ntp.org","time.nist.gov");
    //configure peripheral pins
    pinMode(BTN_PLUGIN,INPUT_PULLUP);
    pinMode(BTN_PLUGOUT,INPUT_PULLUP);
    pinMode(RELAY_PIN,OUTPUT);
    pinMode(LED_GREEN,OUTPUT);
    pinMode(LED_YELLOW,OUTPUT);
    pinMode(LED_RED,OUTPUT);
    //connect board to wifi
    connectWiFi();

    //config mqtt servor
    //connect board to server
    mqtt.setServer(MQTT_SERVER,MQTT_PORT);
    //connect to cloud
    connectMQTT();

}

unsigned long now;
unsigned long last_print;

void loop()
{   
    mqtt.loop();
    //push data every 2 sec
    now = millis();
    if (WiFi.status() != WL_CONNECTED)
    {
        connectWiFi();
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        return;
    }

    if (!mqtt.connected())
    {
        connectMQTT();
    }

    
    if((now - last_print) > 5000)
    {
        last_print = now;
        //read data from sensor
        sample_sensor();
        
        //run ai to get prediction 
        runEdgeAIInference();
        //decide load based on prediction
        runOptimization();
        applyRelayDutyCycle();


        //publish data
        publishTelemetry();
        

    }
    plug_status();
    updateLeds();


    
}

