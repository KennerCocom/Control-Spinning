#define buttonPin 2      // Pin digital conectado al botón del joystick
#define externalButton 8 // Pin digital conectado al botón externo

bool joystickPressed = false; // Estado actual del botón del joystick

void setup() {
   Serial.begin(9600);             
   pinMode(buttonPin, OUTPUT);      // Configurar el pin del botón del joystick como salida
   digitalWrite(buttonPin, HIGH);   // Inicialmente, el pin del botón del joystick está en estado alto (no presionado)
   pinMode(externalButton, INPUT_PULLUP); // Configurar el pin del botón externo como entrada con pull-up interno activado
}

void loop() {
   // Leer el estado del botón externo
   int externalButtonState = digitalRead(externalButton);

   // Comprobar si el botón externo está presionado (debido al pull-up interno, está activo en bajo)
   if (externalButtonState == LOW && !joystickPressed) {
      Serial.println("Botón externo presionado. Simulando presión del botón del joystick.");
      digitalWrite(buttonPin, LOW); // Simular presión del botón (conectando a GND)
      joystickPressed = true;       // Actualizar el estado a presionado
   }

   // Comprobar si el botón externo no está presionado y el joystick está presionado
   if (externalButtonState == HIGH && joystickPressed) {
      Serial.println("Botón externo liberado. Liberando botón del joystick.");
      digitalWrite(buttonPin, HIGH); // Liberar el botón (volver a estado alto)
      joystickPressed = false;       // Actualizar el estado a no presionado
   }

   delay(100);
}
