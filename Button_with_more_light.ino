

// constants won't change. They're used here to set pin numbers:
const int ON = 1;
const int OFF = 0;
const int buttonPin = 21;  // the number of the pushbutton pin
const int ledPin2 = 2;    // the number of the LED pin
const int ledPin3 = 3;    // the number of the LED pin
const int ledPin4 = 4;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int lysdiod_status = OFF;

void setup() {
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void setup2() {
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void setup3() {
  pinMode(ledPin4, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void toggle_led() {
	if (lysdiod_status == ON) {
		digitalWrite(ledPin2, LOW);
		lysdiod_status = OFF;
	}
	else {
		digitalWrite(ledPin2, HIGH);
    lysdiod_status = ON;	
  }
}

void toggle_led2() {
	if (lysdiod_status == ON) {
		digitalWrite(ledPin3, LOW);
		lysdiod_status = OFF;
	}
	else {
		digitalWrite(ledPin3, HIGH);
    lysdiod_status = ON;	
  }
}

void toggle_led3() {
	if (lysdiod_status == ON) {
		digitalWrite(ledPin4, LOW);
		lysdiod_status = OFF;
	}
	else {
		digitalWrite(ledPin4, HIGH);
    lysdiod_status = ON;	
  }
}


void nextled() {

  
}