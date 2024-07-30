// Define the pin connections
const byte ROWS = 2; // Number of rows
const byte COLS = 2; // Number of columns
byte rowPins[ROWS] = {2, 4}; // Row pins
byte colPins[COLS] = {8, 7}; // Column pins

// Define LED pins
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;

// Keypad matrix
char keys[ROWS][COLS] = {
  {'1', '2'},
  {'3', '4'}
};

// Function prototypes
char getKey();

void setup() {
  Serial.begin(9600);
 
  // Set LED pins as OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
 
  // Set row pins as OUTPUT and column pins as INPUT
  for (byte i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH); // Set row pins HIGH
  }
  for (byte i = 0; i < COLS; i++) {
    pinMode(colPins[i], INPUT_PULLUP); // Set column pins as INPUT_PULLUP
  }
}

void loop() {
  char key = getKey();
 
  if (key == '1') {
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
  }
  if (key == '2') {
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }
  if (key == '3') {
    digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led3, LOW);
  }
  if (key == '4') {
    digitalWrite(led4, HIGH);
    delay(1000);
    digitalWrite(led4, LOW);
  }
}

char getKey() {
  for (byte row = 0; row < ROWS; row++) {
    // Set current row to LOW
    digitalWrite(rowPins[row], LOW);
   
    for (byte col = 0; col < COLS; col++) {
      // Check if key is pressed
      if (digitalRead(colPins[col]) == LOW) {
        delay(50);
        if (digitalRead(colPins[col]) == LOW) {
          // Return the key that is pressed
          digitalWrite(rowPins[row], HIGH); // Reset row pin
          return keys[row][col];
        }
      }
    }
    // Reset row pin
    digitalWrite(rowPins[row], HIGH);
  }
  return '\0';
}
