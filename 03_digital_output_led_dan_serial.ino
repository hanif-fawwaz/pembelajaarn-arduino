// ==============================================================================
// MODUL 03: MENGGABUNGKAN DIGITAL OUTPUT (LED) DENGAN SERIAL MONITOR
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Mempelajari cara melihat status alat fisik secara nyata di layar laptop.
// 2. Praktik terbaik: Selalu berikan pesan Serial saat status pin berubah
//    agar mempermudah proses pencarian kesalahan (debugging).
//
// Rangkaian (Wiring):
// - LED Anoda (+) -> Resistor 220 Ohm -> Pin Digital 13
// - LED Katoda (-) -> Pin GND
// ==============================================================================

const int PIN_LED = 13;

void setup() {
  // Inisialisasi komunikasi Serial
  Serial.begin(9600);

  // Inisialisasi pin LED sebagai OUTPUT
  pinMode(PIN_LED, OUTPUT);

  Serial.println("Program Blink LED + Laporan Serial Dimulai...");
}

void loop() {
  // 1. Nyalakan LED dan laporkan ke Serial Monitor
  digitalWrite(PIN_LED, HIGH);
  Serial.println("[STATUS] LED Menyala (HIGH - 5 Volt)");
  delay(1500); // Tahan selama 1.5 detik

  // 2. Matikan LED dan laporkan ke Serial Monitor
  digitalWrite(PIN_LED, LOW);
  Serial.println("[STATUS] LED Padam  (LOW  - 0 Volt)");
  delay(1500); // Tahan selama 1.5 detik
}
