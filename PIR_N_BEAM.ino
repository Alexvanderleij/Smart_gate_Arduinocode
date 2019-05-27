int Sinput = 0;
int SinputTwo =0;
int average = 0;
int Deviation = 40;
int highest;
int highestTwo;
int sensMax;
int sensMaxTwo;
int oldMax;
int oldMaxTwo;
int sensMin;
int sensMinTwo;
int oldMin;
int oldMinTwo;
int firstValue;
int firstValueTwo;
int timeMax;
int timeMaxTwo;
int timeMin;
int timeMinTwo;
int tempA;
int tempATwo;
int tempB;
int tempBTwo;
int maxValue;
int maxValueTwo;
int minValue;
int minValueTwo;
int dirFirst;
int dirFirstTwo;
int counter;
//int OSpin;
//int ISpin;

#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>

int period = 1000;

unsigned long time_now = 0;
unsigned long time_low = 0;
unsigned long time_high = 0;

void setup() {
  Serial.begin(115200);       //  setup serial
  delay(100);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
 Serial.println("@RELATION direction");
 Serial.println("       ");
 Serial.print("@ATTRIBUTE timestamp DATE");
 Serial.print(" ");
 Serial.print("\"");
 Serial.print("yyyy-MM-dd HH:mm:ss");
 Serial.println("\"");
 Serial.println("@ATTRIBUTE A1 real");
 Serial.println("@ATTRIBUTE A2 real");
 Serial.println("@ATTRIBUTE T1 real");
 Serial.println("@ATTRIBUTE T2 real");
 Serial.println("@ATTRIBUTE A3 real");
 Serial.println("@ATTRIBUTE A4 real");
 Serial.println("@ATTRIBUTE T3 real");
 Serial.println("@ATTRIBUTE T4 real");
 Serial.println("@ATTRIBUTE class{In,Uit}");
 
 Serial.println("       ");
 Serial.println("@DATA");
  delay(250);

  for (int i = 0; i < 100; i++) {
    average = average + analogRead(A0);
  }
  average = average / 100;
Serial.println(average);
  int oldMin = average;
   while (!Serial) ;
 setSyncProvider(RTC.get);   // the function to get the time from the RTC
  digitalWrite(2,HIGH);


}



void loop() {
 int falseLOG =0;
 // millis();
  Sinput = analogRead(0);
  SinputTwo = analogRead(1);
  analogWrite(A2,LOW);
  digitalWrite(2,HIGH);
  oldMax=average-10;
  oldMaxTwo=average-10;
  oldMin=average+10;
  oldMinTwo=average+10;
  int OSpin = digitalRead(2);
  int ISpin = analogRead(A2);



//  delay(500);
//  Serial.print("OUTSIDE= ");
//  Serial.print(OSpin);
//  Serial.print("   INSIDE= ");
//  Serial.println(ISpin);
 
 
 
  if(OSpin == HIGH){ // outside pin triggerd.
   
 int firstIR = 1;
  int EXint =1;
   ReadIN(firstIR,EXint,falseLOG); // call the function inside
 }
 

  if(ISpin == LOW){ // inside pin triggerd.
    int firstIR = 0;
    int EXint = 0;
    ReadOUT(firstIR,EXint); // call the function outside
    }


}
  
  void ReadIN (int firstIR, int EXint, int falseLOG){ 
 // delay(5);
  for( int i =0; i <1500; i++){// startloop 
  int ISpin = analogRead(2);
  int falseLOG;
  if(ISpin>200 && i<1400){
            Sinput = analogRead(0);
            SinputTwo =analogRead(1);
            analogWrite(A2,LOW);
//            OSpin = digitalRead(2);
         //   ISpin = analogRead(A2);
           

            int temp = analogRead(A2);

           
            digitalWrite(11, HIGH);
            
                                        sensMax = max(Sinput, oldMax);
                                       
                                                                      if (sensMax > oldMax){
                                                                        oldMax=sensMax;
                                                                        timeMax=i;
                                                                       // Serial.println("timeMax triggerd");
                                                                         
                                                                      }
                                        sensMaxTwo =max(SinputTwo, oldMaxTwo);
                                                                       if (sensMaxTwo > oldMaxTwo){
                                                                        oldMaxTwo=sensMaxTwo;
                                                                        timeMaxTwo=i;
                                                                       // Serial.println("timeMax triggerd");  
                                                                      }
                                        
                                        sensMin =min(Sinput, oldMin);
                                                                      if(sensMin< oldMin){
                                                                        oldMin=sensMin;
                                                                        timeMin=i;
                                                                      }
                                        sensMinTwo =min(SinputTwo, oldMinTwo);
                                                                      if(sensMinTwo< oldMinTwo){
                                                                        oldMinTwo=sensMinTwo;
                                                                        timeMinTwo=i;
                                                                      }

                                       
                                        
                                   delay(1);
                                   //  int OSpin1 = digitalRead(2);
                                   //  int ISpin1 = analogRead(A2);
                           digitalWrite(11, LOW);
                         // printr();

                                        }
                                        else if (ISpin<200){
                                          
                                          //Serial.print("reading complete ,walked in= ");
                                         // Serial.print(i);
                                         // int Snelheid = i/100*1;
                                         // Serial.print(" speed= ");
                                         // Serial.println(Snelheid);
                                          printr(1);
                                          i=1500;
                                          }
                                          else if(falseLOG<1) {
                                            int falseLOG=1;
                                            Serial.println("FALSE IN / NO SECOND BEAM BROKEN");
                                            break;
                                          }
                                        }
                                        

  }
              
    void ReadOUT (int firstIR, int EXint){ 
 // delay(5);
  for( int i =0; i <1500; i++){// startloop 300
    int OSpin = digitalRead(2);
  int falseLOG;
  if(OSpin == LOW && i<1400){ // If other beam not triggerd and not 1400 yet. 
   // Serial.println(i);
            Sinput = analogRead(0);
            SinputTwo =analogRead(1);
//            OSpin = digitalRead(2);
         //   ISpin = analogRead(A2);
           

            
            
            digitalWrite(11, HIGH);
            
                                        sensMax = max(Sinput, oldMax);
                                       
                                                                      if (sensMax > oldMax){
                                                                        oldMax=sensMax;
                                                                        timeMax=i;
                                                                       // Serial.println("timeMax triggerd");
                                                                         
                                                                      }
                                        sensMaxTwo =max(SinputTwo, oldMaxTwo);
                                                                       if (sensMaxTwo > oldMaxTwo){
                                                                        oldMaxTwo=sensMaxTwo;
                                                                        timeMaxTwo=i;
                                                                       // Serial.println("timeMax triggerd");  
                                                                      }
                                        
                                        sensMin =min(Sinput, oldMin);
                                                                      if(sensMin< oldMin){
                                                                        oldMin=sensMin;
                                                                        timeMin=i;
                                                                      }
                                        sensMinTwo =min(SinputTwo, oldMinTwo);
                                                                      if(sensMinTwo< oldMinTwo){
                                                                        oldMinTwo=sensMinTwo;
                                                                        timeMinTwo=i;
                                                                      }

                                       
                                        
                                          
                                   delay(1);
                                   //  int OSpin1 = digitalRead(2);
                                   //  int ISpin1 = analogRead(A2);
                           digitalWrite(11, LOW);
                         // printr();

                                        }
                                        else if (OSpin == HIGH){
                                          
                                          //Serial.print("reading complete ,walked in= ");
                                         // Serial.print(i);
                                         // int Snelheid = i/100*1;
                                         // Serial.print(" speed= ");
                                         // Serial.println(Snelheid);
                                          printr(0);
                                          i=1500;
                                          }
                                          else if(falseLOG<1) {
                                            int falseLOG=1;
                                            Serial.println("FALSE OUT / NO SECOND BEAM BROKEN");
                                            break;
                                          }
                                        }
    }

                              
                
void printr (int dVal) {
                                  dirFirst=min(timeMax,timeMin);
                         
                                  Serial.print("\"");
                                  Serial.print(year()); 
                                  Serial.print("-");
                                  Serial.print(month());
                                  Serial.print("-");
                                  Serial.print(day());
                                  Serial.print(" ");
                                  Serial.print(hour());
                                  printDigits(minute());
                                  printDigits(second());
                                  Serial.print("\"");
                                  
                                  Serial.print(",");
                                  Serial.print(oldMax);
                                  Serial.print(",");
                                  Serial.print(oldMin);
                                  Serial.print(",");
                                  Serial.print(timeMax);
                                  Serial.print(",");
                                  Serial.print(timeMin);
                                  Serial.print(",");
                                  Serial.print(oldMaxTwo);
                                  Serial.print(",");
                                  Serial.print(oldMinTwo);
                                  Serial.print(",");
                                  Serial.print(timeMaxTwo);
                                  Serial.print(",");
                                  Serial.print(timeMinTwo);
                                        
                                   if (dirFirst == timeMin){
                                    Serial.print(",U,");//Uit
                                    digitalWrite(12, LOW);
                                  }
                                  else{
                                    Serial.print(",I,");//In
                                    digitalWrite(12, HIGH);
                                  }
                                  if(dVal==1){
                                    Serial.print("I");
                                    counter++;
                                  }
                                  else{
                                    Serial.print("U");
                                    counter--;
                                  }

                                  Serial.print(", counter= ");
                                  Serial.println(counter);
                                  
                                  //if (oldMax==average+deviation or oldMax < average
                                  
                                //  Serial.println(minValue);
                                  dVal=0;
                                  delay(1000); 
                              
                }
                
  void printDigits(int digits){
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
  
}

                
