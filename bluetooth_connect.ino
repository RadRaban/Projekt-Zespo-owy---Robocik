#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial BT(10, 11); // RX = A1, TX = A2
LiquidCrystal lcd(12, 9, 5, 4, 3, 2);

void setup() {
    Serial.begin(9600);  // Komunikacja z komputerem
    BT.begin(9600);      // Komunikacja z Bluetooth
    lcd.begin(16, 2); 
    lcd.print("Hello, Arduino!");
}

void loop() {
    // Odbieranie pełnej linii z Bluetooth i wysyłanie do komputera
    if (BT.available()) {
        String ztel = BT.readStringUntil('\n'); // Odczyt do znaku nowej linii
        Serial.println("Odebrano z telefonu: " + ztel);
    }

    // Odbieranie pełnej linii z komputera i wysyłanie do Bluetooth
    if (Serial.available()) {
        String zkom = Serial.readStringUntil('\n'); // Odczyt do znaku nowej linii
        Serial.println("Wysłano na telefon: " + zkom);
        BT.println(zkom); // Wysyłamy pełną linię do Bluetooth
    }
}

