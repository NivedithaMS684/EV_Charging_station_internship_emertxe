#include <Arduino.h>
#include <DHT.h>
#include "State.h"
#include "Peripherals.h"
#include "config.h"


DHT   dht(DHT_PIN , DHT_TYPE);
float mapFloat(long x,long inMin,long inMax,float outMin,float outMax){
   return (x-inMin) * (outMax - outMin) / (float)(inMax - inMin) + outMin;
}

void sample_sensor(void)
{
   int raw_current = analogRead(CURRENT_PIN); // 0 to 4095 //0 to 32A
   int raw_voltage = analogRead(VOLTAGE_PIN); // 0 to 4095 // 0 to 250V
   
   //map voltage
   voltage = mapFloat(raw_voltage,0,4095,0,250);
   if(bayStatus == "CHARGING"){
      current = mapFloat(raw_current,0,4095,0,32);


   }
   //read current and store it 5 value array 

   //map current
   current = mapFloat(raw_current,0,4095,0,32);

   //power
   power=voltage * current;

   //to read temp
   float t=dht.readTemperature(DHT_PIN);
   if(!(isnan(t))){
       temperature= t;
   }

    
    
    //to read temperature 
  
    
   }
   float recentAvgCurrent(){
      float sum=0;
      //read recent 5 current values
      for(int i=0;i<5;i++){
         sum=sum + current ;
      
      }
      return sum/5;
   }



bool plugin_flag_once = 1;
bool plugout_flag_once = 1;

void plug_status(void)
{
   bool pluginReading = digitalRead(BTN_PLUGIN);
   // detect the sw is pressed
   if(pluginReading == LOW && plugin_flag_once){


   sessionStartMs=millis();
   // plug in switch is pressed
   plugin_flag_once = 0;
   // change bay_status FREE to charging
   if(bayStatus == "FREE"){
      bayStatus= "CHARGING";
      Serial.println("BAY1 plugin detected,BAY1 is charging");
      digitalWrite(RELAY_PIN,HIGH);//turn on relay
   }
   //update leds
   }
   if(pluginReading == HIGH){
      plugin_flag_once=1;
   }

   // plug out switch is pressed
   bool plugoutReading = digitalRead(BTN_PLUGOUT);
   // detect the sw is pressed
   if(plugoutReading == LOW && plugout_flag_once){


   
   // plug in switch is pressed
   plugout_flag_once = 0;
   // change bay_status FREE to charging
   if(bayStatus == "CHARGING"){
      bayStatus= "FREE";
      Serial.println("BAY1 plugout detected,BAY1 is FREE");
   }
   //update leds
   }
   if(plugoutReading == HIGH){
      plugout_flag_once=1;
   }
   // change bay_status  charging to FREE
   //update leds

   



}
/*void update_led_status(void){
   //free green led on 
   if(bayStatus == "FREE")
   {
      digitalWrite(LED_GREEN,HIGH);
      digitalWrite(LED_YELLOW,LOW);
   }
   else{
   //charging turn on yellow
      digitalWrite(LED_GREEN,LOW);
      digitalWrite(LED_YELLOW,HIGH);

   } */


