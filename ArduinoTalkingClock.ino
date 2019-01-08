/************************************************************************
*   Arduino Talking Clock
*   
*   File:   ArduinoTalkingClock.ino
*   Author:  Jithin Krishnan.K
*       Rev. 0.0.2 : 04/01/2019 :  07:13 PM
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
#define buttonPin 7
#define AmpON 4				   	   

DS3231 clock;
TMRpcm tmrpcm;
RTCDateTime dt;
char i, hr;		   

void setup()
{
    tmrpcm.speakerPin=9;
    pinMode(buttonPin, INPUT);						  
    pinMode(AmpON, OUTPUT);					   
    Serial.begin(115200);
    clock.begin();

    // Manual (YYYY, MM, DD, HH, II, SS								   
    //clock.setDateTime(2019, 1, 3, 8, 54, 54);										   
  if(!SD.begin(SD_ChipSelectPin)) {
      Serial.println("SD fail");
      return;
    }
    tmrpcm.setVolume(5);
    tmrpcm.quality(1); 				   
}


void loop()
  {
   dt = clock.getDateTime();
	  
   if(dt.hour > 12)
      hr = dt.hour - 12;
   else
      hr = dt.hour;
      if (hr == 0)
          hr = 12;
      
   if (!dt.minute && !dt.second) {
        AmpPowerUp();
        tmrpcm.play("ring.wav");
        while(tmrpcm.isPlaying());
       
        for(i = 0; i < hr; i++)
          {
            tmrpcm.play("ding.wav");
            while(tmrpcm.isPlaying());
          }
          AmpPowerDown();
      }

      if (dt.minute == 30 && !dt.second) {
          AmpPowerUp();
          tmrpcm.play("ring.wav");
          while(tmrpcm.isPlaying());     
          tmrpcm.play("ding.wav");
          while(tmrpcm.isPlaying());
          AmpPowerDown(); 
        }
		
   if (!digitalRead(buttonPin)) {
      AmpPowerUp(); 
      TexttoSpeech(dt.hour);
      while(tmrpcm.isPlaying());
      tmrpcm.play("h.wav");
      while(tmrpcm.isPlaying());
      TexttoSpeech(dt.minute);
      while(tmrpcm.isPlaying());
      tmrpcm.play("m.wav");
      while(tmrpcm.isPlaying());
      TexttoSpeech(dt.second);
      while(tmrpcm.isPlaying());
      tmrpcm.play("s.wav");
      while(tmrpcm.isPlaying());
      DayOfWeek(dt.dayOfWeek);
      while(tmrpcm.isPlaying());
      TexttoSpeech(dt.day);
      while(tmrpcm.isPlaying());
      SpeechMonth(dt.month);
      while(tmrpcm.isPlaying());
      tmrpcm.play("2K.wav");
      while(tmrpcm.isPlaying());
      TexttoSpeech(dt.year%2000);
      while(tmrpcm.isPlaying());
      AmpPowerDown();
   }		
}

void DayOfWeek(char d) 
{
  switch(d) {
    case 1:
      tmrpcm.play("mon.wav");
      while(tmrpcm.isPlaying());
      break;
    case 2:
      tmrpcm.play("tue.wav");
      while(tmrpcm.isPlaying());
      break;
    case 3:
      tmrpcm.play("wed.wav");
      while(tmrpcm.isPlaying());
      break;
    case 4:
      tmrpcm.play("thu.wav");
      while(tmrpcm.isPlaying());
      break;
    case 5:
      tmrpcm.play("fri.wav");
      while(tmrpcm.isPlaying());
      break;
    case 6:
      tmrpcm.play("sat.wav");
      while(tmrpcm.isPlaying());
      break;
    case 7:
      tmrpcm.play("sun.wav");
      while(tmrpcm.isPlaying());
      break;
  }
}
void SpeechMonth(char digit)
{
  switch(digit) {
    case 1:
      tmrpcm.play("jan.wav");
      while(tmrpcm.isPlaying());
      break;
    case 2:
      tmrpcm.play("feb.wav");
      while(tmrpcm.isPlaying());
      break;
    case 3:
      tmrpcm.play("mar.wav");
      while(tmrpcm.isPlaying());
      break;
    case 4:
      tmrpcm.play("apr.wav");
      while(tmrpcm.isPlaying());
      break;
    case 5:
      tmrpcm.play("may.wav");
      while(tmrpcm.isPlaying());
      break;
    case 6:
      tmrpcm.play("jun.wav");
      while(tmrpcm.isPlaying());
      break;
    case 7:
      tmrpcm.play("jul.wav");
      while(tmrpcm.isPlaying());
      break;
    case 8:
      tmrpcm.play("aug.wav");
      while(tmrpcm.isPlaying());
      break;
    case 9:
      tmrpcm.play("sep.wav");
      while(tmrpcm.isPlaying());
      break;
    case 10:
      tmrpcm.play("oct.wav");
      while(tmrpcm.isPlaying());
      break;
    case 11:
      tmrpcm.play("nov.wav");
      while(tmrpcm.isPlaying());
      break;
    case 12:
      tmrpcm.play("dec.wav");
      while(tmrpcm.isPlaying());
      break;         
  }
}
void TexttoSpeech(char digit)
{
  switch(digit) {
    case 0:
      tmrpcm.play("0.wav");
      while(tmrpcm.isPlaying());
      break;
    case 1:
      tmrpcm.play("1.wav");
      while(tmrpcm.isPlaying());
      break;
    case 2:
      tmrpcm.play("2.wav");
      while(tmrpcm.isPlaying());
      break;
    case 3:
      tmrpcm.play("3.wav");
      while(tmrpcm.isPlaying());
      break;
    case 4:
      tmrpcm.play("4.wav");
      while(tmrpcm.isPlaying());
      break;
    case 5:
      tmrpcm.play("5.wav");
      while(tmrpcm.isPlaying());
      break;
    case 6:
      tmrpcm.play("6.wav");
      while(tmrpcm.isPlaying());
      break;
    case 7:
      tmrpcm.play("7.wav");
      while(tmrpcm.isPlaying());
      break; 
    case 8:
      tmrpcm.play("8.wav");
      while(tmrpcm.isPlaying());
      break;
    case 9:
      tmrpcm.play("9.wav");
      while(tmrpcm.isPlaying());
      break;
    case 10:
      tmrpcm.play("10.wav");
      while(tmrpcm.isPlaying());
      break;
    case 11:
      tmrpcm.play("11.wav");
      while(tmrpcm.isPlaying());
      break;
    case 12:
      tmrpcm.play("12.wav");
      while(tmrpcm.isPlaying());
      break;
    case 13:
      tmrpcm.play("13.wav");
      while(tmrpcm.isPlaying());
      break;
    case 14:
      tmrpcm.play("14.wav");
      while(tmrpcm.isPlaying());
      break;
    case 15:
      tmrpcm.play("15.wav");
      while(tmrpcm.isPlaying());
      break;
    case 16:
      tmrpcm.play("16.wav");
      while(tmrpcm.isPlaying());
      break;
    case 17:
      tmrpcm.play("17.wav");
      while(tmrpcm.isPlaying());
      break;
    case 18:
      tmrpcm.play("18.wav");
      while(tmrpcm.isPlaying());
      break;
    case 19:
      tmrpcm.play("19.wav");
      while(tmrpcm.isPlaying());
      break;
    case 20:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      break;
    case 21:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("1.wav");
      while(tmrpcm.isPlaying());
      break;
    case 22:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("2.wav");
      while(tmrpcm.isPlaying());
      break;
    case 23:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("3.wav");
      while(tmrpcm.isPlaying());
      break;
    case 24:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("4.wav");
      while(tmrpcm.isPlaying());
      break;
     case 25:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("5.wav");
      while(tmrpcm.isPlaying());
      break;
     case 26:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("6.wav");
      while(tmrpcm.isPlaying());
      break;
     case 27:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("7.wav");
      while(tmrpcm.isPlaying());
      break;
     case 28:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("8.wav");
      while(tmrpcm.isPlaying());
      break;
    case 29:
      tmrpcm.play("20.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("9.wav");
      while(tmrpcm.isPlaying());
      break;
    case 30:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      break;
    case 31:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("1.wav");
      while(tmrpcm.isPlaying());
      break;
    case 32:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("2.wav");
      while(tmrpcm.isPlaying());
      break;
    case 33:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("3.wav");
      while(tmrpcm.isPlaying());
      break; 
    case 34:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("4.wav");
      while(tmrpcm.isPlaying());
      break;
    case 35:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("5.wav");
      while(tmrpcm.isPlaying());
      break;
    case 36:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("6.wav");
      while(tmrpcm.isPlaying());
      break;
    case 37:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("7.wav");
      while(tmrpcm.isPlaying());
      break;
    case 38:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("8.wav");
      while(tmrpcm.isPlaying());
      break;
    case 39:
      tmrpcm.play("30.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("9.wav");
      while(tmrpcm.isPlaying());
      break;
    case 40:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      break;
    case 41:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("1.wav");
      while(tmrpcm.isPlaying());
      break;
    case 42:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("2.wav");
      while(tmrpcm.isPlaying());
      break;
    case 43:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("3.wav");
      while(tmrpcm.isPlaying());
      break; 
    case 44:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("4.wav");
      while(tmrpcm.isPlaying());
      break;
    case 45:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("5.wav");
      while(tmrpcm.isPlaying());
      break;
    case 46:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("6.wav");
      while(tmrpcm.isPlaying());
      break;      
    case 47:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("7.wav");
      while(tmrpcm.isPlaying());
      break;
    case 48:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("8.wav");
      while(tmrpcm.isPlaying());
      break;
    case 49:
      tmrpcm.play("40.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("9.wav");
      while(tmrpcm.isPlaying());
      break;
    case 50:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      break;
    case 51:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("1.wav");
      while(tmrpcm.isPlaying());
      break;
    case 52:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("2.wav");
      while(tmrpcm.isPlaying());
      break;  
   case 53:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("3.wav");
      while(tmrpcm.isPlaying());
      break;
    case 54:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("4.wav");
      while(tmrpcm.isPlaying());
      break;  
    case 55:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("5.wav");
      while(tmrpcm.isPlaying());
      break;
    case 56:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("6.wav");
      while(tmrpcm.isPlaying());
      break;  
    case 57:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("7.wav");
      while(tmrpcm.isPlaying());
      break;
    case 58:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("8.wav");
      while(tmrpcm.isPlaying());
      break;
    case 59:
      tmrpcm.play("50.wav");
      while(tmrpcm.isPlaying());
      tmrpcm.play("9.wav");
      while(tmrpcm.isPlaying());
      break;                                       
   }
}

void AmpPowerUp() 
{
  digitalWrite(AmpON, HIGH); 
  delay(500);
}

void AmpPowerDown() 
{
  delay(500);
  digitalWrite(AmpON, LOW);
  
}
