// ==============================================================================
// MODUL 06: ANALOG OUTPUT / PWM (MENGATUR TERANG-REDUP LED)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami konsep PWM (Pulse Width Modulation): Membuat sinyal analog semu
//    dari pin digital yang memiliki tanda tilde (~), misal: Pin 3, 5, 6, 9, 10, 11.
// 2. Menggunakan fungsi analogWrite(pin, nilai) dengan resolusi 8-bit (0 s/d 255):
//    - 0   = Padam total (0 Volt)
//    - 127 = Menyala separuh terang (2.5 Volt)
//    - 255 = Menyala maksimal (5 Volt)
// 3. Menggunakan perulangan 'for' dari C++ untuk membuat efek "Breathing LED".
//
// Rangkaian (Wiring):
// - PENTING: Pindahkan LED ke Pin bertanda PWM (~), misal Pin 9.
// - LED Anoda (+) -> Resistor 220 Ohm -> Pin Digital 9
// - LED Katoda (-) -> Pin GND
// ==============================================================================

const int PIN_LED_PWM = 9; // Pin 9 mendukung fitur PWM (ada simbol ~)

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED_PWM, OUTPUT);

  Serial.println("Memulai efek Breathing LED (Analog Output PWM)...");
}

void loop() {
  // 1. PERLAHAN TERANG (Fade In)
  // Kecerahan naik dari 0 ke 255 bertahap
  for (int kecerahan = 0; kecerahan <= 255; kecerahan += 5) {
    analogWrite(PIN_LED_PWM, kecerahan);
    delay(20); // Jeda 20 milidetik agar perubahan terlihat halus di mata manusia
  }

  delay(200); // Tahan sebentar saat terang maksimal

  // 2. PERLAHAN REDUP (Fade Out)
  // Kecerahan turun dari 255 kembali ke 0 bertahap
  for (int kecerahan = 255; kecerahan >= 0; kecerahan -= 5) {
    analogWrite(PIN_LED_PWM, kecerahan);
    delay(20); // Jeda 20 milidetik
  }

  delay(500); // Tahan sebentar saat padam sebelum mengulang
}
