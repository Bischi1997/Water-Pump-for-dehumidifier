int motorPin = A0; // pin that turns on the motor
int blinkPin = 13; // pin that turns on the LED
int watertime = 5; // how long to water in seconds

int floaterPin = 2;
int buttonPin = 4;

void setup()
{
  pinMode(motorPin, OUTPUT); // set A0 to an output so we can use it to turn on the transistor
  pinMode(blinkPin, OUTPUT); // set pin 13 to an output so we can use it to turn on the LED
  pinMode(floaterPin, INPUT_PULLUP); //float switch trigger
  pinMode(buttonPin, INPUT_PULLUP; //button on case
}

void loop()
{
  while(digitalRead(floaterPin) == LOW)
  {
    digitalWrite(motorPin, HIGH); // turn on the motor
    digitalWrite(blinkPin, HIGH); // turn on the LED
    delay(watertime*1000);        // multiply by 1000 to translate seconds to milliseconds
    
    digitalWrite(motorPin, LOW);  // turn off the motor
    digitalWrite(blinkPin, LOW);  // turn off the LED
  }
  if(digitalRead(buttonPin) == LOW) //if button on case is pressed, then Pump
  {
    digitalWrite(motorPin, HIGH); // turn on the motor
    digitalWrite(blinkPin, HIGH); // turn on the LED
  }
  else //if the button is not pressed do not pump
  {
    digitalWrite(motorPin, LOW);  // turn off the motor
    digitalWrite(blinkPin, LOW);  // turn off the LED
  }
}

