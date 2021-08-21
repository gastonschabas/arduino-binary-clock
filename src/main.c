int seconds = 30;
int minutes = 25;
int hours = 13;

void setup(){
  Serial.begin(9600);
  DDRD = DDRD | 0b11111100; // set digital pins 2-7  for output
  DDRB = DDRB | 0b00111111; // set digital pins 8-13 for output
  DDRC = DDRC | 0b00011111; // set analog  pins 0-4  for output
}

void loop(){
    seconds++;
    if(seconds > 59)
    {
      seconds = 0;
      minutes++;
      if(minutes > 59)
      {
        minutes = 0;
        hours++;
        if(hours > 23)
        {
          hours = 0;
        }
      }
    }
    Serial.print("Hours: ");
    Serial.print(hours);
    Serial.print(" Minutes: ");
    Serial.print(minutes);
    Serial.print(" Seconds: ");
    Serial.println(seconds);
    PORTD = seconds;
    PORTB = minutes;
    PORTC = hours;
    delay(1000);
}
