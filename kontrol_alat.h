// ==============================================================================
// FILE LIBRARY ARDUINO SENDIRI: kontrol_alat.h
// ==============================================================================
// Catatan Penting untuk Mengajar:
// 1. Ekstensi file ini adalah .h (Header File).
// 2. Di Arduino IDE, file ini bisa dibuka sebagai "Tab Baru" di samping file .ino.
// 3. PENTING: File .h untuk Arduino WAJIB menyertakan #include <Arduino.h>
//    agar fungsi digitalWrite, delay, HIGH, LOW, dll. dapat dikenali!
// ==============================================================================

#pragma once           // Mencegah library dibaca ganda oleh compiler
#include <Arduino.h>   // WAJIB: Meminjam fungsi bawaan Arduino ke dalam file header

// ------------------------------------------------------------------------------
// FUNGSI 1: Mengedipkan LED dengan pola cepat (misal untuk status peringatan)
// ------------------------------------------------------------------------------
void kedipPeringatan(int pin, int jumlahKedip) {
  for (int i = 0; i < jumlahKedip; i++) {
    digitalWrite(pin, HIGH);
    delay(80);
    digitalWrite(pin, LOW);
    delay(80);
  }
}

// ------------------------------------------------------------------------------
// FUNGSI 2: Mengecek apakah tombol sedang ditekan (Khusus mode INPUT_PULLUP)
// Mengembalikan nilai true jika tombol ditekan, dan false jika tidak ditekan.
// ------------------------------------------------------------------------------
bool cekTombolDitekan(int pinTombol) {
  if (digitalRead(pinTombol) == LOW) {
    return true;  // Tombol sedang ditekan (menghubung ke GND)
  } else {
    return false; // Tombol sedang dilepas
  }
}

// ------------------------------------------------------------------------------
// FUNGSI 3: Efek lampu memudar halus (PWM Fade)
// ------------------------------------------------------------------------------
void efekLampuNafas(int pinPwm) {
  // Naik perlahan
  for (int nilai = 0; nilai <= 255; nilai += 15) {
    analogWrite(pinPwm, nilai);
    delay(20);
  }
  // Turun perlahan
  for (int nilai = 255; nilai >= 0; nilai -= 15) {
    analogWrite(pinPwm, nilai);
    delay(20);
  }
}
