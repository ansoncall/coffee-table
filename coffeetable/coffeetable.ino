// Coffee table with planter and LED grow lights
// Anson Call
// anson.clark.call@gmail.com
// 2021-10-24T00:26:13Z

// libraries
#include <Wire.h> // for RTC module
#include <DS3231.h> // for RTC module
#include <LiquidCrystal.h> // for LCD display

/* the following is from the ELEGOO RTC demo */

3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);

  Serial.println("Initialize RTC module");
  // Initialize DS3231
  clock.begin();

  
  // Manual (YYYY, MM, DD, HH, II, SS
  // clock.setDateTime(2016, 12, 9, 11, 46, 00);
  
  // Send sketch compiling time to Arduino
  clock.setDateTime(__DATE__, __TIME__);    
  /*
  Tips:This command will be executed every time when Arduino restarts. 
       Comment this line out to store the memory of DS3231 module
  */
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

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

/* the following is from the LED light strip demo
https://gist.github.com/anonymous/d4fa3719478c3c5a9c321cc372e95407 */

//define pins for the red, green and blue LEDs
#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9

//overall brightness value
int brightness = 255;
//individual brightness values for the red, green and blue LEDs
int gBright = 0; 
int rBright = 0;
int bBright = 0;

int fadeSpeed = 10;


void setup() {
  //set up pins to output.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

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

 int CLK = 9;  // Pin 9 to clk on encoder
 int DT = 8;  // Pin 8 to DT on encoder
 int RedLed = 4;// You do not need to use the leds. 
                // you can take a look in the serial monitor if you dont have leds.
                // there it will display values. 
 int GreenLed = 5;
 int BlueLed = 6;
 int RotPosition = 0; 
 int rotation;  
 int value;
 boolean LeftRight;
 void setup() { 
   Serial.begin (9600);
   pinMode (CLK,INPUT);
   pinMode (DT,INPUT);
   pinMode (RedLed, OUTPUT);
   pinMode (GreenLed, OUTPUT);
   pinMode (BlueLed, OUTPUT);
   rotation = digitalRead(CLK);   
 } 
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

