# Control-Spinning
Uso de una máquina de spinning para general el movimiento en videojuegos, mediante el uso de un control con Xbox 360. 

1. Modificar el velocímetro del BodyCrunch
Para obtener las lecturas de las dos entradas, puedes realizar un puenteo de las conexiones. Esto implica:
Conectar un cable de salida entre las entradas.
O bien, desconectar la segunda entrada (lado derecho) y utilizar dos jumpers para la conexión.
El cable que conecta el disco al velocímetro será el que se modifique con los jumpers.

![cONFIG](https://github.com/user-attachments/assets/9feb61d2-caee-4cd1-9f04-bf6decc1fa88)
![Entrada](https://github.com/user-attachments/assets/476e4c90-6173-468e-bac6-10f1cc25cc01)

2. Modificar el mando
En este caso, se utilizará un control de Xbox 360. Nuestro objetivo es enviar señales que simulen el uso de ciertos botones.

Conecta un jumper a cada terminal del mando. Estos jumpers serán los puntos donde se enviarán las señales para simular los botones.

![cONTROL2](https://github.com/user-attachments/assets/f3515299-5cd2-4e9c-96f1-253ea64093f1)

3. Incorporar un relé
Para evitar errores al asignar valores y simular botones, será necesario un relé. Este dispositivo permitirá restaurar los valores iniciales de los botones al finalizar la simulación.


![GitRele](https://github.com/user-attachments/assets/16442859-364b-42e8-a955-05695c473699)

![Reletras1](https://github.com/user-attachments/assets/cdc87bb9-0ef9-41d5-a69b-c7cb7d9ffa22)

4. Conectar todo al Arduino
Una vez listos los componentes, realiza las conexiones en el Arduino siguiendo el esquema. Considera lo siguiente:

Los parlantes se utilizan para simular las entradas del BodyCrunch.
El relé también es simulado si no cuentas con el modelo específico.
Los cables azules representan las salidas del joystick que han sido modificadas.

![Esquema a medias](https://github.com/user-attachments/assets/b639c0a0-9667-4771-b547-bb7ea80e26e7)

5. Probar el sistema
Finalmente, sube el código al Arduino y realiza pruebas. En el repositorio encontrarás diferentes códigos que te permitirán verificar cada componente:

Prueba las entradas del BodyCrunch.
Asegúrate de que las conexiones del joystick funcionen correctamente.
¡Listo! Una vez comprobado todo, puedes comenzar a usar el sistema.

