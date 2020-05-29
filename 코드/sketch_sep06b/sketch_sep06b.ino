const int xpin = A1;
const int ypin = A2;
const int zpin = A3;
int val;

void setup() {
  Serial.begin(9600);
}

void loop() {
    int val1 = analogRead(xpin);
    int val2 = analogRead(ypin);
    int val3 = analogRead(zpin);
    Serial.print(val1);
    Serial.print("\t");
        Serial.print(val2);
        Serial.print("\t");
            Serial.print(val3);
    Serial.println();
  delay(10);
}
