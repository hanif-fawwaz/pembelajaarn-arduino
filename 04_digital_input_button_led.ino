// ==============================================================================
// MODUL 04: DIGITAL INPUT (PUSHBUTTON MEMBACA TOMBOL & MENGONTROL LED)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami fungsi pinMode(pin, INPUT_PULLUP) -> menggunakan resistor internal
//    bawaan mikrokontroler (tidak perlu pasang resistor tambahan untuk tombol!).
// 2. Membaca kondisi tombol dengan digitalRead(pin).
// 3. Memahami logika tombol PULL-UP:
//    - Tombol TIDAK DITEKAN = HIGH (karena ditarik ke 5V oleh resistor internal)
//    - Tombol SEDANG DITEKAN = LOW (karena arus terhubung langsung ke GND)
//
// Rangkaian (Wiring):
// - LED Anoda (+) -> Resistor 220 Ohm -> Pin Digital 13
// - LED Katoda (-) -> Pin GND
// - Pushbutton Kaki 1 -> Pin Digital 2
// - Pushbutton Kaki 2 -> Pin GND
// ==============================================================================

const int PIN_LED = 13;
const int PIN_TOMBOL = 2;

void setup() {
  Serial.begin(9600);

  // LED sebagai Output
  pinMode(PIN_LED, OUTPUT);

  // Tombol sebagai Input dengan fitur PULLUP internal aktif
  // Praktis! Murid cukup sambungkan kaki tombol ke Pin 2 dan GND tanpa resistor luar
  pinMode(PIN_TOMBOL, INPUT_PULLUP);

  Serial.println("Program Pushbutton Siap! Silakan tekan tombol...");
}

void loop() {
  // Membaca kondisi listrik di Pin Tombol (HIGH atau LOW)
  int statusTombol = digitalRead(PIN_TOMBOL);

  // Cek apakah tombol ditekan (Pada INPUT_PULLUP, ditekan bernilai LOW)
  if (statusTombol == LOW) {
    digitalWrite(PIN_LED, HIGH); // Nyalakan LED
    Serial.println(">> Tombol SEDANG DITEKAN -> LED MENYALA");
  } else {
    digitalWrite(PIN_LED, LOW);  // Matikan LED
    // Tidak mencetak apa-apa saat dilepas agar serial monitor tidak penuh
  }

  // Jeda kecil 50 milidetik untuk stabilitas pembacaan tombol (debouncing sederhana)
  delay(50);
}
