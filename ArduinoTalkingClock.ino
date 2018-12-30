/************************************************************************
*   Arduino Talking Clock
*   
*   File:   ArduinoTalkingClock.ino
*   Author:  Jithin Krishnan.K
*       Rev. 0.0.1 : 30/12/2018 :  08:47 PM
* 
* This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Email: jithinkrishnan.k@gmail.com
*   
************************************************************************/
#include <Wire.h>
#include <DS3231.h>
#include "SD.h"
#include "TMRpcm.h"
#include "SPI.h"

#define SD_ChipSelectPin 10

DS3231 clock;
TMRpcm tmrpcm;
RTCDateTime dt;

void setup()
{
    tmrpcm.speakerPin=9;
    Serial.begin(115200);
    clock.begin();

  if(!SD.begin(SD_ChipSelectPin)) {
      Serial.println("SD fail");
      return;
    }
    tmrpcm.setVolume(5);
}


void loop()
  {
   dt = clock.getDateTime();
   Serial.print(dt.year);   Serial.print("-");
   Serial.print(dt.month);  Serial.print("-");
   Serial.print(dt.day);    Serial.print(" ");
   Serial.print(dt.hour);   Serial.print(":");
   Serial.print(dt.minute); Serial.print(":");
   Serial.print(dt.second); Serial.println("");
   TexttoSpeech(dt.hour);
   delay(500);
   tmrpcm.play("h.wav");
   delay(1000);
   TexttoSpeech(dt.minute);
   delay(500);
   tmrpcm.play("m.wav");
   delay(1000);
   TexttoSpeech(dt.second);
   delay(500);
   tmrpcm.play("s.wav");
   delay(1000);
   DayOfWeek(dt.dayOfWeek);
   delay(500);
   TexttoSpeech(dt.day);
   delay(500);
   SpeechMonth(dt.month);
   delay(500);
   tmrpcm.play("2000.wav");
   delay(1000);
   TexttoSpeech(dt.year%2000);
   delay(10000);
}

void DayOfWeek(char d) 
{
  switch(d) {
    case 1:
      tmrpcm.play("monday.wav");
      delay(500);
      break;
    case 2:
      tmrpcm.play("tuesday.wav");
      delay(500);
      break;
    case 3:
      tmrpcm.play("wednesday.wav");
      delay(500);
      break;
    case 4:
      tmrpcm.play("thursday.wav");
      delay(500);
      break;
    case 5:
      tmrpcm.play("friday.wav");
      delay(500);
      break;
    case 6:
      tmrpcm.play("saturday.wav");
      delay(500);
      break;
    case 7:
      tmrpcm.play("sunday.wav");
      delay(500);
      break;
  }
}
void SpeechMonth(char digit)
{
  switch(digit) {
    case 1:
      tmrpcm.play("jan.wav");
      delay(500);
      break;
    case 2:
      tmrpcm.play("feb.wav");
      delay(500);
      break;
    case 3:
      tmrpcm.play("mar.wav");
      delay(500);
      break;
    case 4:
      tmrpcm.play("apr.wav");
      delay(500);
      break;
    case 5:
      tmrpcm.play("may.wav");
      delay(500);
      break;
    case 6:
      tmrpcm.play("jun.wav");
      delay(500);
      break;
    case 7:
      tmrpcm.play("jul.wav");
      delay(500);
      break;
    case 8:
      tmrpcm.play("aug.wav");
      delay(500);
      break;
    case 9:
      tmrpcm.play("sep.wav");
      delay(500);
      break;
    case 10:
      tmrpcm.play("oct.wav");
      delay(500);
      break;
    case 11:
      tmrpcm.play("nov.wav");
      delay(500);
      break;
    case 12:
      tmrpcm.play("dec.wav");
      delay(500);
      break;         
  }
}
void TexttoSpeech(char digit)
{
  switch(digit) {
    case 0:
      tmrpcm.play("0.wav");
      delay(500);
      break;
    case 1:
      tmrpcm.play("1.wav");
      delay(500);
      break;
    case 2:
      tmrpcm.play("2.wav");
      delay(500);
      break;
    case 3:
      tmrpcm.play("3.wav");
      delay(500);
      break;
    case 4:
      tmrpcm.play("4.wav");
      delay(500);
      break;
    case 5:
      tmrpcm.play("5.wav");
      delay(500);
      break;
    case 6:
      tmrpcm.play("6.wav");
      delay(500);
      break;
    case 7:
      tmrpcm.play("7.wav");
      delay(500);
      break; 
    case 8:
      tmrpcm.play("8.wav");
      delay(500);
      break;
    case 9:
      tmrpcm.play("9.wav");
      delay(500);
      break;
    case 10:
      tmrpcm.play("10.wav");
      delay(500);
      break;
    case 11:
      tmrpcm.play("11.wav");
      delay(500);
      break;
    case 12:
      tmrpcm.play("12.wav");
      delay(500);
      break;
    case 13:
      tmrpcm.play("13.wav");
      delay(500);
      break;
    case 14:
      tmrpcm.play("14.wav");
      delay(500);
      break;
    case 15:
      tmrpcm.play("15.wav");
      delay(500);
      break;
    case 16:
      tmrpcm.play("16.wav");
      delay(500);
      break;
    case 17:
      tmrpcm.play("17.wav");
      delay(500);
      break;
    case 18:
      tmrpcm.play("18.wav");
      delay(500);
      break;
    case 19:
      tmrpcm.play("19.wav");
      delay(500);
      break;
    case 20:
      tmrpcm.play("20.wav");
      delay(500);
      break;
    case 21:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("1.wav");
      delay(500);
      break;
    case 22:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("2.wav");
      delay(500);
      break;
    case 23:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("3.wav");
      delay(500);
      break;
    case 24:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("4.wav");
      delay(500);
      break;
     case 25:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("5.wav");
      delay(500);
      break;
     case 26:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("6.wav");
      delay(500);
      break;
     case 27:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("7.wav");
      delay(500);
      break;
     case 28:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("8.wav");
      delay(500);
      break;
    case 29:
      tmrpcm.play("20.wav");
      delay(500);
      tmrpcm.play("9.wav");
      delay(500);
      break;
    case 30:
      tmrpcm.play("30.wav");
      delay(500);
      break;
    case 31:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("1.wav");
      delay(500);
      break;
    case 32:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("2.wav");
      delay(500);
      break;
    case 33:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("3.wav");
      delay(500);
      break; 
    case 34:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("4.wav");
      delay(500);
      break;
    case 35:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("5.wav");
      delay(500);
      break;
    case 36:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("6.wav");
      delay(500);
      break;
    case 37:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("7.wav");
      delay(500);
      break;
    case 38:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("8.wav");
      delay(500);
      break;
    case 39:
      tmrpcm.play("30.wav");
      delay(500);
      tmrpcm.play("9.wav");
      delay(500);
      break;
    case 40:
      tmrpcm.play("40.wav");
      delay(500);
      break;
    case 41:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("1.wav");
      delay(500);
      break;
    case 42:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("2.wav");
      delay(500);
      break;
    case 43:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("3.wav");
      delay(500);
      break; 
    case 44:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("4.wav");
      delay(500);
      break;
    case 45:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("5.wav");
      delay(500);
      break;
    case 46:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("6.wav");
      delay(500);
      break;      
    case 47:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("7.wav");
      delay(500);
      break;
    case 48:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("8.wav");
      delay(500);
      break;
    case 49:
      tmrpcm.play("40.wav");
      delay(500);
      tmrpcm.play("9.wav");
      delay(500);
      break;
    case 50:
      tmrpcm.play("50.wav");
      delay(500);
      break;
    case 51:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("1.wav");
      delay(500);
      break;
    case 52:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("2.wav");
      delay(500);
      break;  
   case 53:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("3.wav");
      delay(500);
      break;
    case 54:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("4.wav");
      delay(500);
      break;  
    case 55:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("5.wav");
      delay(500);
      break;
    case 56:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("6.wav");
      delay(500);
      break;  
    case 57:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("7.wav");
      delay(500);
      break;
    case 58:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("8.wav");
      delay(500);
      break;
    case 59:
      tmrpcm.play("50.wav");
      delay(500);
      tmrpcm.play("9.wav");
      delay(500);
      break;                                       
   }
}
