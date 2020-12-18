#include <Arduino.h>
#include "loadcell.h"
#include <Arduino_JSON.h>


//pin init
#define pin_dout1  23
#define pin_clk1   22

#define pin_dout2  25
#define pin_clk2  24

#define pin_dout3  27
#define pin_clk3  26

#define pin_dout4  29
#define pin_clk4  28

#define pin_dout4  29
#define pin_clk4  28

#define pin_dout5  31
#define pin_clk5  30

#define pin_dout6  33
#define pin_clk6  32

#define pin_dout7  35
#define pin_clk7  34

#define pin_dout8  37
#define pin_clk8  36

#define pin_dout9  39
#define pin_clk9  38

float offset;

// output
JSONVar output;
String out1;
String out2;
String out3;
String out4;
String out5;
String out6;
String out7;
String out8;
String out9;


// class init
loadcell cell_1;
loadcell cell_2;
loadcell cell_3;
loadcell cell_4;
loadcell cell_5;
loadcell cell_6;
loadcell cell_7;
loadcell cell_8;
loadcell cell_9;

int time_m = 0;

void setup() {
  Serial.begin(9600);
  //Serial.println("AE_HX711 test");
  
  cell_1.Pin(pin_dout1,pin_clk1);
  cell_1.Init();
  cell_1.Cariblation(0.539,0.398);

  cell_2.Pin(pin_dout2,pin_clk2);
  cell_2.Init();
  cell_2.Cariblation(0.539,0.398);

  cell_3.Pin(pin_dout3,pin_clk3);
  cell_3.Init();
  cell_3.Cariblation(0.539,0.398);

  cell_4.Pin(pin_dout4,pin_clk4);
  cell_4.Init();
  cell_4.Cariblation(0.539,0.398);

  cell_5.Pin(pin_dout5,pin_clk5);
  cell_5.Init();
  cell_5.Cariblation(0.539,0.398);

  cell_6.Pin(pin_dout6,pin_clk6);
  cell_6.Init();
  cell_6.Cariblation(0.539,0.398);

  cell_7.Pin(pin_dout7,pin_clk7);
  cell_7.Init();
  cell_7.Cariblation(0.539,0.398);

  cell_8.Pin(pin_dout8,pin_clk8);
  cell_8.Init();
  cell_8.Cariblation(0.539,0.398);

  cell_9.Pin(pin_dout9,pin_clk9);
  cell_9.Init();
  cell_9.Cariblation(0.539,0.398);
}

void loop() {
  time_m = millis();
  float data1;
  float data2;
  float data3;
  float data4;
  float data5;
  float data6;
  float data7;
  float data8;
  float data9;
  //char S1[20];
  //char s[20];

  //char S2[20];
  //char s2[20];

  //data2 = cell_1.GetGram_cal(5);


  //sprintf(S1,"%s [g] (0x%4x)",dtostrf((data-cell_1.offset_val), 5, 3, s),cell_1.Read());
  //sprintf(S2,"%s [g] (0x%4x)",dtostrf((data2-cell_1.offset_val), 5, 3, s2),cell_1.Read());
  //Serial.println(S1);
  //Serial.println(S2);

  
  data1 = cell_1.GetGram(1);
  data2 = cell_2.GetGram(1);
  data3 = cell_3.GetGram(1);
  data4 = cell_4.GetGram(1);
  data5 = cell_5.GetGram(1);
  data6 = cell_6.GetGram(1);
  data7 = cell_7.GetGram(1);
  data8 = cell_8.GetGram(1);
  data9 = cell_9.GetGram(1);

  out1 = (String)data1;
  out2 = (String)data2;
  out3 = (String)data3;
  out4 = (String)data4;
  out5 = (String)data5;
  out6 = (String)data6;
  out7 = (String)data7;
  out8 = (String)data8;
  out9 = (String)data9;

  output["1"]=out1;
  output["2"]=out2;
  output["3"]=out3;
  output["4"]=out4;
  output["5"]=out5;
  output["6"]=out6;
  output["7"]=out7;
  output["8"]=out8;
  output["9"]=out9;
  time_m -= millis();
  Serial.println(output);
  Serial.println(time_m);
}
