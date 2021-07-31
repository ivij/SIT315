
const uint8_t PIR_PIN = 2;
const uint8_t PIR_PIN_2 = 3;
const uint8_t LED_PIN = 13;
const uint8_t LED_PIN_2 = 10;
uint8_t led_state = LOW;
uint8_t led_state_2 = LOW;

void setup()
{
  pinMode(PIR_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN_2, INPUT_PULLUP);
  pinMode(LED_PIN_2, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN),toggle,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN_2),toggle_2,CHANGE);
}

void loop()
  {
    delay(500);
}

void toggle()
{
 led_state = !led_state;
  digitalWrite(LED_PIN, led_state);
  Serial.print("Led State of PIR 1: ");
  Serial.print(led_state);
  Serial.println("");
}
void toggle_2()
{
 led_state_2 = !led_state_2;
  digitalWrite(LED_PIN_2, led_state_2);
  Serial.print("Led State of PIR 2: ");
  Serial.print(led_state_2);
  Serial.println("");
}