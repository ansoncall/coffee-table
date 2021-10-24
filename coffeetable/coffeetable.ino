// Coffee table with planter and LED grow lights
// Anson Call
// anson.clark.call@gmail.com
// 2021-10-24T00:26:13Z

// libraries
#include <Wire.h> // for RTC module
#include <DS3231.h> // for RTC module
#include <LiquidCrystal.h> // for LCD display

// define pins and initialize vars
// RTC module - no pins need definition
3231 clock;
RTCDateTime dt;
// LCD display
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(33, 30, 26, 29, 25, 22); // RS, E, D4-7 - all digital out
// LED out
// define pins for the red, green and blue LEDs
#define RED_LED 6
#define BLUE_LED 2
#define GREEN_LED 4
// Rotary encoders
// Encoder 0
 int CLK0 = 45;  
 int DT0 = 42;   
 int RotPosition0 = 0; 
 int rotation0;  
 int value0;
 boolean LeftRight0;
// Encoder 1
 int CLK1 = 49;  
 int DT1 = 46;   
 int RotPosition1 = 0; 
 int rotation1;  
 int value1;
 boolean LeftRight1;
// Encoder 2
 int CLK2 = 53;  
 int DT2 = 50;   
 int RotPosition2 = 0; 
 int rotation2;  
 int value2;
 boolean LeftRight2; 

void setup()
{
  // open serial comm for error-checking
  Serial.begin(9600);
  
  // Initialize DS3231
  Serial.println("Initialize RTC module");
  clock.begin();

  // Send sketch compiling time to Arduino to set the time
  clock.setDateTime(__DATE__, __TIME__);    
  /*
  Tips:This command will be executed every time when Arduino restarts. 
       Comment this line out to store the memory of DS3231 module
  */
  
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
  
  // Set up LED pins to output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  
   // Set up rotary encoder inputs 
   pinMode (CLK0,INPUT);
   pinMode (DT0,INPUT);
   pinMode (CLK1,INPUT);
   pinMode (DT1,INPUT);
   pinMode (CLK2,INPUT);
   pinMode (DT2,INPUT);
   
   rotation0 = digitalRead(CLK);   
   rotation1 = digitalRead(CLK);
   rotation2 = digitalRead(CLK);
}

void loop()
{
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");
  
  delay(1000);
}

/* the following is from the ELEGOO LCD demo */

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

/* the following is from the LED light strip demo
https://gist.github.com/anonymous/d4fa3719478c3c5a9c321cc372e95407 */



//overall brightness value
int brightness = 255;
//individual brightness values for the red, green and blue LEDs
int gBright = 0; 
int rBright = 0;
int bBright = 0;

int fadeSpeed = 10;


void setup() {


//Call the TurnOn method, wait, then call TurnOff
TurnOn();
delay(5000);
TurnOff();
}



void TurnOn(){
   
    for (int i=0;i<256; i++){
      
      analogWrite(RED_LED, rBright);
      rBright +=1;
      delay(fadeSpeed);

    }
    
    for (int i=0;i<256; i++){
      
      analogWrite(BLUE_LED, bBright);
      bBright += 1;
delay(fadeSpeed);
    }  

    for (int i=0;i<256; i++){
      
      analogWrite(GREEN_LED, gBright);
      gBright +=1;
      delay(fadeSpeed);
    }  
}

void TurnOff(){
    for (int i=0;i<256; i++){
          analogWrite(GREEN_LED, brightness);
          analogWrite(RED_LED, brightness);
          analogWrite(BLUE_LED, brightness);
    
      
      brightness -= 1;
 
      delay(fadeSpeed);

    }
}

void loop(){
  
}

/* the following is from the KY-040 demo
https://create.arduino.cc/projecthub/vandenbrande/arduino-rotary-encoder-simple-example-ky-040-b78752 */

 void loop() { 
   value = digitalRead(CLK);
     if (value != rotation){ // we use the DT pin to find out which way we turning.
     if (digitalRead(DT) != value) {  // Clockwise
       RotPosition ++;
       LeftRight = true;
     } else { //Counterclockwise
       LeftRight = false;
       RotPosition--;
     }
     if (LeftRight){ // turning right will turn on red led.
       Serial.println ("clockwise");
       digitalWrite (RedLed, HIGH);
       digitalWrite (GreenLed, LOW);
     }else{        // turning left will turn on green led.   
       Serial.println("counterclockwise");
       digitalWrite (RedLed, LOW);
       digitalWrite (GreenLed, HIGH);
     }
     Serial.print("Encoder RotPosition: ");
     Serial.println(RotPosition);
     // this will print in the serial monitor.
     
   } 
   rotation = value;
 } 

