#include<SPI.h>
#include<Stepper.h>.
#include<SD.h>


const int stepx=2;
const int dirx=3;

const int stepy=4;
const int diry=5;

const int stepz=6;
const int dirz=7;



int i=0;
char data[10];
int d1,d2,d3;

File myfil;
void setup()

{
    // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(10,OUTPUT);
   Serial.println(SD.begin(10));
  myfil=SD.open("motor.txt");
  pinMode(stepx,OUTPUT);
  pinMode(dirx,OUTPUT);
  pinMode(stepy,OUTPUT);
  pinMode(diry,OUTPUT);
  pinMode(stepz,OUTPUT);
  pinMode(dirz,OUTPUT);     
  
       
}
 
void loop(){
  // put your main code here, to run repeatedly:

  if (myfil.available())
  {
    while ( myfil.available())
       {
            char t;
            t=myfil.read();
            if (isdigit(t))
            {
              data[i]=t;
              i+=1;
             }
            else{  
                  break;      
                 }
       }
     
     d1=atoi(data);
     Serial.println(d1);
     i=0;



   
     while ( myfil.available())
       {
            char t;
            t=myfil.read();
            if (isdigit(t))
            {
              data[i]=t;
              i+=1;
             }
            else{  
                  break;      
                 }
       }
     
     d2=atoi(data);
     Serial.println(d2);
     i=0;
     while ( myfil.available())
       {
            char t;
            t=myfil.read();
            if (isdigit(t))
            {
              data[i]=t;
              i+=1;
             }
            else{  
                  break;      
                 }
       }
    
     d3=atoi(data);
     Serial.println(d3);
     i=0;
     while ( myfil.available())
       {
            char t;
            t=myfil.read();
            if (isdigit(t))
            {
              i+=1;
             }
            else{  
                  break;      
                 }
       }
     i=0;
  }
  for (int i=0;i<d1;i++)
  {
    digitalWrite(stepx,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepx,LOW);
    delayMicroseconds(500);
  }
  for (int i=0;i<d2;i++)
  {
    digitalWrite(stepy,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepy,LOW);
    delayMicroseconds(500);
  }
 
  for (int i=0;i<d3;i++)
  {
    digitalWrite(stepz,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepz,LOW);
    delayMicroseconds(500);
  }
  delay(2000);
 
}
