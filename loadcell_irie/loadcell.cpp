#include "Arduino.h"
#include "loadcell.h"

loadcell::Pin(int pin_dout,int pin_clk){
    dout = pin_dout;
    clk = pin_clk;


}

loadcell::Cariblation(double A,double B){
    tilt = A;
    intercept = B;
    //Serial.print(tilt);
    //Serial.print(intercept);
    //Serial.println();
  }
  




void loadcell::Init(void){

    tilt =1;
    intercept = 0;
    pinMode(dout,INPUT);
    pinMode(clk,OUTPUT);

    digitalWrite(clk,1);
    delayMicroseconds(1);
    digitalWrite(clk,0);
    delayMicroseconds(1); 

    offset_val = GetGram(10);
    //Serial.print("offset");
    //Serial.print(offset_val);
    //Serial.println();

}


long loadcell::Read(void){
  long data=0;
  while(digitalRead(dout)!=0);
  delayMicroseconds(5);
  for(int i=0;i<24;i++)
  {
    digitalWrite(clk,1);
    delayMicroseconds(1);
    digitalWrite(clk,0);
    delayMicroseconds(1);
    data = (data<<1)|(digitalRead(dout));
  }
  //Serial.println(data,HEX);   
  digitalWrite(clk,1);
  delayMicroseconds(1);
  digitalWrite(clk,0);
  delayMicroseconds(1);
  return data^0x800000; 
}



long loadcell::Averaging(long adc,char num){
    long sum=0;
    for (int i = 0; i < num; i++) sum += Read();
    return sum/num;
}

float loadcell::GetGram(char num){
    #define OUT_VOL   0.002f   // [V]
    #define LOAD      20000.0f    //[g]

    #define HX711_R1  20000.0f
    #define HX711_R2  8200.0f
    #define HX711_VBG 1.25f
    #define HX711_AVDD      4.2987f//(HX711_VBG*((HX711_R1+HX711_R2)/HX711_R2))
    #define HX711_ADC1bit   HX711_AVDD/16777216 //16777216=(2^24)
    #define HX711_PGA 128
    #define HX711_SCALE     (OUT_VOL * HX711_AVDD / LOAD *HX711_PGA)

    float data;
    int time_m;

    data = Read()*HX711_ADC1bit /HX711_SCALE -offset_val; 


  return data;

}

double loadcell::GetGram_cal(char num){
  float data;
  data = (GetGram(num)-intercept)/tilt;
  return data;

}
