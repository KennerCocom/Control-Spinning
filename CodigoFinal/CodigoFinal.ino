//// ====JOYSTICK=====
const int pinJoystickY = A1; // Pin analógico para el eje Y del joystick
const int pinModifiedJoystickY = A2; // Pin para la señal modificada
bool joystickPressed = false; // Estado actual del botón del joystick
#define buttonPin 2      // Pin digital conectado al botón del joystick


/// =====SPINING MACHINE====
const int sensorPin = A0; // Pin donde está conectado el sensor
const int threshold = 512; // Umbral para convertir la señal analógica en digital
int count = 0;
unsigned long lastTime = 0;
#define relayPin 7 // Pin de control del relé


void setup() {
   Serial.begin(9600);
   delay(300);
   pinMode(relayPin, OUTPUT); // Configurar el pin del relé como salida
   pinMode(pinModifiedJoystickY, OUTPUT); // Configurar el pin para la señal modificada como salida
   pinMode(buttonPin, OUTPUT);      // Configurar el pin del botón del joystick como salida
   digitalWrite(buttonPin, HIGH);   // Inicialmente, el pin del botón del joystick está en estado alto (no presionado)
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
    //Funciones de usuario.
    
   int joystickValue;
   if (count > 0) {
      joystickValue = 0;
      digitalWrite(relayPin, LOW);
      analogWrite(pinModifiedJoystickY, joystickValue);
      Serial.print("mOVIENDOSE");
      //FUNCIONES DE USIARIO
       if (count > 1 && !joystickPressed) {
        Serial.println("Corriendo");
        digitalWrite(buttonPin, LOW); // Simular presión del botón (conectando a GND)
        joystickPressed = true;       // Actualizar el estado a presionado
    }
    
   } else {
      joystickValue =255; 
      digitalWrite(relayPin, HIGH);
      Serial.print("I still standin");
      if (count <= 1 && joystickPressed) {
        Serial.println("Liberando botón del joystick");
        digitalWrite(buttonPin, HIGH); 
        joystickPressed = false;    
   }
    count = 0;
    lastTime = currentTime;
  }
}
