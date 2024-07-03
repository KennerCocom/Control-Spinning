const int sensorPin = A0; // Pin donde está conectado el sensor
const int threshold = 512; // Umbral para convertir la señal analógica en digital
int count = 0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  static bool lastState = LOW;
  bool currentState = sensorValue > threshold;

  if (currentState && !lastState) {
    count++;
  }

  lastState = currentState;

  unsigned long currentTime = millis();
  if (currentTime - lastTime >= 800) { // Calcular la velocidad cada 800 ms
    Serial.print("Count: ");
    Serial.println(count);
    float rpm = (count / 0.5) * 60; // Convertir a RPM
    Serial.print("RPM: ");
    Serial.println(rpm);
    count = 0;
    lastTime = currentTime;
  }
}
