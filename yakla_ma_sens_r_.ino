

#define trigPin 9
#define echoPin 10
#define buzzerPin 8

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Mesafe ölçüm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ses hızı
  if (distance < 10) {
    bip(100); // çok hızlı
  } else if (distance < 20) {
    bip(200); // orta hızlı
  } else if (distance < 30) {
    bip(400); // daha yavaş
  } else if (distance < 50) {
    bip(700); // çok yavaş
  } else {
    digitalWrite(buzzerPin, LOW); //çok uzaksa ses yok
    delay(100);
  }
}

// Bip fonksiyonu
void bip(int gecikmeMs) {
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  digitalWrite(buzzerPin, LOW);
  delay(gecikmeMs);
}
