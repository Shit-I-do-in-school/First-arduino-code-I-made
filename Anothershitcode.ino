int buttonPin = 18;
int ledPin = 3;
const int trials = 10;
enum status {start, wait};
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean Started = false;
boolean timer = false;
long startTime;
long endTime;
long randomTime;
float elapsedTime;
int current_trial = 0;
unsigned long last_time = 0;
unsigned long total_time = 0;

int buttonState = 0;
status current_status = start;



void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void ledOn() {
  digitalWrite(ledPin, HIGH);
}

void ledOff() {
  digitalWrite(ledPin, LOW);
}


void loop()
{
  if (current_trial == trials) {
    print_results();
    while(1);
  }

  if (current_status==start) {
    delay(random(2000, 8000));
    ledOn();
    Start_timer();
    current_status = wait;
  }

  else if (current_status == wait) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      ledOff();
      total_time += Stop_timer();
      current_status = start;
      current_trial++;
    }
  }
}
void Start_timer() {
  last_time = millis();
}

unsigned long Stop_timer() {
  return millis() - last_time;
}

void print_results() {
  Serial.print("Your average reaction time was ");
  Serial.print(total_time/trials);

}
