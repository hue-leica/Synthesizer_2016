const int VCCPin = A4;
const int xPin   = A1;
const int yPin   = A2;
const int zPin   = A3;
const int GNDPin = A0;

// variables
int x = 0;
int y = 0;
int z = 0;
int prev = 0;
int cur;
int cnt = 0;


void setup() {
  // pin A0 (pin14) is VCC and pin A4 (pin18) in GND to activate the GY-61-module
  pinMode(A0, OUTPUT);
  pinMode(A4, OUTPUT);
  analogWrite(A4, 1024);
  analogWrite(A0, 0);

  // activating debugging for arduino UNO
  Serial.begin(9600);
} // end setup

void loop() {
  Finger();
}

void Finger()
{
  z = analogRead(zPin);
  cur = map(z, 400, 281, 0, 100);
  if (cur - prev > 20 && cnt == 1) {
    cnt--;
    prev = cur;
    return;
  }
  if (prev - cur > 20) {

    Serial.println("bang"); cnt++;
    delay(100);
  }
  //Serial.print(" z angle = ");
  //Serial.println(cur);
  //  Serial.println(constrain(map(z, 400, 281, 0, 5), 0, 2));
  delay(100);
  prev = cur;
}

