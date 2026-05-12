int tempPin = A0;
int moisturePin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int reading = analogRead(tempPin);

  float voltage = reading * (3.3 / 1023.0);

  float tempC = voltage * 100;

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  int moisture = analogRead(moisturePin);

  Serial.print("Moisture: ");
  Serial.println(moisture);

  if (moisture < 300) {
    Serial.println("ALERT: Plant needs water");
  }

  if (tempC > 30) {
    Serial.println("ALERT: Too hot");
  }

  if (tempC < 10) {
    Serial.println("ALERT: Too cold");
  }


  delay(1000);
}
