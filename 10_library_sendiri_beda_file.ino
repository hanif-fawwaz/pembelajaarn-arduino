// ==============================================================================
// MODUL 10: MEMBUAT & MENGGUNAKAN LIBRARY SENDIRI (MULTI-FILE ARDUINO)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami cara memisahkan fungsi ke file header terpisah (.h).
// 2. Mengimpor library buatan sendiri menggunakan tanda petik: #include "kontrol_alat.h".
// 3. Menghubungkan fungsi dari file terpisah ke program utama Arduino.
// 4. Melihat betapa ringkas dan bersihnya void loop() setelah menggunakan library!
//
// Cara Penggunaan di Arduino IDE:
// 1. Letakkan file 'kontrol_alat.h' di folder yang sama dengan file .ino ini.
// 2. Buka file .ino ini di Arduino IDE, file 'kontrol_alat.h' otomatis muncul sebagai
//    TAB kedua di samping tab utama.
//
// Rangkaian (Wiring):
// - LED -> Pin Digital 9 (PWM ~)
// - Pushbutton -> Pin Digital 2 (Mode INPUT_PULLUP)
// ==============================================================================

// ------------------------------------------------------------------------------
// MEMANGGIL LIBRARY BUATAN KITA SENDIRI DARI FILE TERPISAH
// Perhatikan tanda petik dua ("..."):
// Arduino IDE akan mencari file 'kontrol_alat.h' yang ada di folder/tab yang sama.
// ------------------------------------------------------------------------------
#include "kontrol_alat.h"

const int PIN_LED = 9;     // Pin PWM untuk LED
const int PIN_TOMBOL = 2;  // Pin untuk Pushbutton

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_TOMBOL, INPUT_PULLUP);

  Serial.println("==================================================");
  Serial.println(" SISTEM ARDUINO DENGAN LIBRARY SENDIRI (.h) SIAP ");
  Serial.println("==================================================");
  
  // Memanggil fungsi dari file kontrol_alat.h
  kedipPeringatan(PIN_LED, 3);
}

void loop() {
  // Menggunakan fungsi cekTombolDitekan() dari file kontrol_alat.h
  if (cekTombolDitekan(PIN_TOMBOL)) {
    Serial.println(">> Tombol terdeteksi ditekan! Menjalankan efek lampu nafas...");
    
    // Memanggil fungsi efekLampuNafas() dari file kontrol_alat.h
    efekLampuNafas(PIN_LED);

  } else {
    // Jika tombol tidak ditekan, matikan LED
    digitalWrite(PIN_LED, LOW);
  }

  delay(50); // Stabilitas loop
}
