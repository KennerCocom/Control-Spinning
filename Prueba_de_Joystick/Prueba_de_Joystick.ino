// Definir el pin del joystick
const int joystickPin = A0;  

void setup() {
  // Inicializar la comunicación serie para ver los valores del joystick
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del joystick
  int joystickValue = analogRead(joystickPin);

  // Imprimir el valor del joystick en el monitor serie
  Serial.print("Valor del joystick: ");
  Serial.println(joystickValue);

  // Pequeña pausa para evitar demasiadas lecturas rápidas
  delay(100);
}
