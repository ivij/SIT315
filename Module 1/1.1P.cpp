
int PIR_PIN = 2;
int LED_PIN = 13;
int motion_status = 0;

void setup()
{
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  motion_status = digitalRead(PIR_PIN);
  if(motion_status == HIGH)
  {
    digitalWrite(LED_PIN,HIGH);
    Serial.println("Motion Detected and Led On");
    delay(1000);
  }
  else
  {
    digitalWrite(LED_PIN,LOW);
    Serial.println("No Motion Detected and Led Off");
    delay(1000);
  }
  
}