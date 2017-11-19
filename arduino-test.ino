#include <Servo.h>
const int sampleWindow = 250; 
unsigned int clap;

boolean isOff = true;
boolean readVolt = true;

int i=0;
Servo LightSwitch;

void setup() {
  Serial.begin(9600);
  LightSwitch.attach (5);
  LightSwitch.write (10);
  
  // put your setup code here, to run once:

}

void loop() 

{
  // put your main code here, to run repeatedly:
unsigned long start = millis();
unsigned int peakToPeak = 0; 

unsigned int signalMax=0;
unsigned int signalMin=1024; 

//collect data for 250 miliseconds 

Serial.println ("loop");
  while (millis() - start < sampleWindow)
  {
    clap = analogRead (1); 
    
    //Serial.println(claps;

        if (clap < 1024) //this is the max of the 10-bit ADC so this loop will inlcude all readings 
        {
            if (clap > signalMax) 
            {
              signalMax = clap; 
            }
            else if (clap < signalMin)

              {
                signalMin = clap;
              }
        }
}

peakToPeak = signalMax - signalMin; 
double volts = (peakToPeak * 3.3) / 1024; //convert to volts


Serial.println(volts);
Serial.println(readVolt);

delay (200); 

  if (volts >= 1.5)
  {
    //turn on LED 
    //readVolt =false; 

    if (isOff){
      Serial.println(i);
      LightSwitch.write(10);
      delay(50);
      
      Serial.println("Lights On");
      Serial.println(isOff);
      isOff = false;
      Serial.println(isOff);

  }
  else{
    Serial.println(i);
    
    LightSwitch.write(160);
    
    delay(50);
    
    Serial.println("Lights out");
    isOff = true;
  }
  
    delay (0);
  }

}
  
    
