#define TRIG_PIN 14
#define ECHO_PIN 12
#define MAX_DISTANCE 30

// Crear instancia del sensor de ultrasonido
UltrasonicSensor sensor(TRIG_PIN, ECHO_PIN);

// Crear array de instancias de LEDs
LED leds[] = { LED(23), LED(22), LED(18), LED(19), LED(21) };

void setup() {
  Serial.begin(9600);  // Inicializar la comunicación serial
}

void loop() {
  long distance = sensor.getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  int ledCount;

  if (distance <= 0) {
    ledCount = 6;
  } else if (distance >= MAX_DISTANCE) {
    ledCount = 0;
  } else {
    ledCount = 6 - ((distance * 6) / MAX_DISTANCE);
  }

  for (int i = 0; i < 6; i++) {
    if (i < ledCount) {
      leds[i].on(); 
    } else {
      leds[i].off();
    }
    leds[i].touch();
  }

}
