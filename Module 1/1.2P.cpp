
const uint8_t PIR_PIN = 2;
const uint8_t LED_PIN = 13;
uint8_t led_state = LOW;

void setup()
{
  pinMode(PIR_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN),toggle,CHANGE);
}

void loop()
  {
    delay(500);
}

void toggle()
{
 led_state = !led_state;
  digitalWrite(LED_PIN, led_state);
  Serial.print("Led State: ");
  Serial.print(led_state);
  Serial.println("");
}