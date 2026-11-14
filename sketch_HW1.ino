const int buttonPin = 2;    
const int redPin = 3;       
const int greenPin = 4;    
const int bluePin = 5;      

int buttonState = HIGH;     
int lastButtonState = HIGH; 
int colorState = 0;         

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  updateColors(colorState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      
      if (buttonState == LOW) {
        colorState = (colorState + 1) % 6; 
        updateColors(colorState);
      }
    }
  }

  lastButtonState = reading;
}

void updateColors(int state) {
  switch (state) {
    case 0: 
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    case 1: 
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    case 2: 
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      break;
    case 3: 
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      break;
    case 4: 
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      break;
    case 5: 
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, HIGH);
      break;
  }
}