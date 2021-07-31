volatile byte led1_status,led2_status,led3_status = 0;
const byte ledPin = 13;

void setup()
{
pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(ledPin, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
Serial.begin(9600);
PCICR |= 0b00000111;
PCMSK2 |= 0b11100000;

TCCR1A = 0;  
TCCR1B = 0;
TCNT1 = 0;

OCR1A = 31250;
  
TCCR1B |= (1 << CS12) | (1<<CS10);
TIMSK1 |= (1<< OCIE1A);
TCCR1B |= (1<<WGM12);

sei();
}

void loop()
{
digitalWrite(8, led1_status);
digitalWrite(9, led2_status);
digitalWrite(10, led3_status);
}

ISR(PCINT2_vect)
{
 
  if(led1_status = PIND & B00100000)
  {
      Serial.println("Blue Led: ON");
  }
  
  if(led2_status = PIND & B01000000)
  {
      Serial.println("Green Led: ON");
  }
  
  if(led3_status = PIND & B10000000)
  {
      Serial.println("Yellow Led: ON");
  }
}


ISR(TIMER1_COMPA_vect)
{
   digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
   Serial.print("Red Led: ");
   if(digitalRead(ledPin) == 1)
   {
     Serial.println("ON");
   }
  
  else
  {
    Serial.println("OFF");
  }
   
}
 
