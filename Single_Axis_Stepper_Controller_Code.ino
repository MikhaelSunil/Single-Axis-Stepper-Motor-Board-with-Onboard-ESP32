
// Single-axis stepper controller with homing 
#define DIR_PIN      19   // Direction
#define STEP_PIN     18   //  Step
#define EN_PIN       21   //  Enable 
#define LIMIT_MIN    32   // Limit switch for Home 
#define LIMIT_MAX    33   // Limit switch for End 


const int stepsPerRevolution = 200; // Full steps per revolution (1.8° motor)(aprrox estimation)
const int microstepSetting   = 16;      // 16 for 1/16 microstepping
const int stepDelay          = 800;     // Microseconds between steps (~speed)

void setup() {
  Serial.begin(115200);

  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(LIMIT_MIN, INPUT_PULLUP);
  pinMode(LIMIT_MAX, INPUT_PULLUP);

  digitalWrite(EN_PIN, LOW);  
  Serial.println("System Initialized. Starting homing sequence...");

  homeAxis();
}

void loop() {
  
  moveToLimit(LIMIT_MAX, true);   // Move toward max limit
  delay(1000);
  moveToLimit(LIMIT_MIN, false);  // Move toward min limit
  delay(1000);
}

void homeAxis() {
  digitalWrite(DIR_PIN, LOW); // Move toward home (negative)
  Serial.println("Homing...");

  while (digitalRead(LIMIT_MIN) == HIGH) {
    stepMotor();
  }

  Serial.println("Home position reached.");
  delay(200);
  // Back off slightly from the limit switch
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 100; i++) stepMotor();

  Serial.println("Axis homed and ready.");
}


void moveToLimit(int limitPin, bool dirForward) {
  digitalWrite(DIR_PIN, dirForward ? HIGH : LOW);
  Serial.print("Moving ");
  Serial.print(dirForward ? "forward" : "backward");
  Serial.print(" until limit pin ");
  Serial.print(limitPin);
  Serial.println("...");


  while (digitalRead(limitPin) == HIGH) {
    // If opposite limit triggers accidentally, stop
    if (!dirForward && digitalRead(LIMIT_MIN) == LOW) break;
    if (dirForward && digitalRead(LIMIT_MAX) == LOW) break;

    stepMotor();
  }

  Serial.println("Limit reached, motion stopped.");
}

void stepMotor() {
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(stepDelay);
}
