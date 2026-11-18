# Kurikulum Dasar Arduino: Digital I/O, Analog I/O, Serial, & Custom Library

Materi ini dirancang murni untuk tingkat dasar dengan fokus pada:
1. **Basic Pemrograman Arduino** (`setup`, `loop`, `delay`, `pinMode`)
2. **Digital I/O** (Lampu LED sebagai output & Pushbutton sebagai input)
3. **Analog I/O** (Potensiometer sebagai analog input & LED PWM sebagai analog output)
4. **Serial Monitor** (Pelaporan status & kontrol alat dari keyboard laptop)
5. **Modularisasi Kode** (Penggunaan Fungsi lokal & Pembuatan Library terpisah `.h`)

---

## 🎯 Urutan Alur Pembelajaran (10 Modul)

| No | File Program (.ino / .h) | Topik & Kategori | Konsep Utama yang Dipelajari |
|:---:|:---|:---|:---|
| 1 | `01_basic_blink_led.ino` | Basic & Digital Output | `setup()`, `loop()`, `pinMode(OUTPUT)`, `digitalWrite(HIGH/LOW)`, `delay()`. |
| 2 | `02_serial_print_monitor.ino` | Serial Communication | `Serial.begin(9600)`, `Serial.print()` vs `println()`, Baud Rate. |
| 3 | `03_digital_output_led_dan_serial.ino` | Digital Output + Serial | Mengirim laporan status nyala/mati LED ke layar komputer untuk debugging. |
| 4 | `04_digital_input_button_led.ino` | Digital Input | `pinMode(INPUT_PULLUP)` tanpa resistor luar, `digitalRead()`, logika saklar. |
| 5 | `05_serial_input_kontrol_led.ino` | Serial Input Dua Arah | `Serial.available()`, `Serial.read()`, mengontrol LED via ketikan angka '1'/'0'. |
| 6 | `06_analog_output_pwm_led.ino` | Analog Output (PWM) | Pin PWM bertanda `~`, `analogWrite(0-255)`, efek lampu redup-terang (breathing). |
| 7 | `07_analog_input_potensiometer.ino` | Analog Input | Pin `A0`, resolusi ADC 10-bit (`analogRead(0-1023)`), konversi ke Voltase. |
| 8 | `08_gabungan_potensio_led_serial.ino` | Integrasi Lengkap | Fungsi `map()`, memutar potensiometer untuk mengatur kecerahan lampu LED. |
| 9 | `09_penggunaan_fungsi_arduino.ino` | Pemrograman Modular (Fungsi) | Fungsi `void` dengan parameter (`kedipkanLED`) & fungsi `return` (`bacaPersenPotensio`). |
| 10 | `10_library_sendiri_beda_file.ino` & `kontrol_alat.h` | Library Arduino Sendiri (Beda File) | Membuat file header `.h`, `#pragma once`, `#include <Arduino.h>`, dan memanggilnya dengan `#include "kontrol_alat.h"`. |

---

## 🔌 Panduan Rangkaian Kabel Sederhana (Wiring)

Hanya membutuhkan 3 komponen dasar:

### 1. Rangkaian LED (Digital & PWM)
* Kaki Panjang LED (Anoda `+`) $\rightarrow$ Resistor 220 $\Omega$ $\rightarrow$ **Pin 13** (Digital) atau **Pin 9** (PWM `~`).
* Kaki Pendek LED (Katoda `-`) $\rightarrow$ **Pin GND**.

### 2. Rangkaian Pushbutton (Tombol)
* Menggunakan mode `INPUT_PULLUP` (resistor internal chip Arduino aktif, sehingga tidak perlu resistor tambahan di breadboard).
* Kaki Tombol 1 $\rightarrow$ **Pin Digital 2**.
* Kaki Tombol 2 $\rightarrow$ **Pin GND**.

### 3. Rangkaian Potensiometer (3 Kaki)
* Kaki 1 (Kiri) $\rightarrow$ **Pin 5V**.
* Kaki 2 (Tengah / Sinyal) $\rightarrow$ **Pin Analog A0**.
* Kaki 3 (Kanan) $\rightarrow$ **Pin GND**.

---

## 💡 Tips Penting Saat Mengajar:
1. **Serial Monitor:** Pastikan murid mencocokkan baud rate di pojok kanan bawah Serial Monitor ke **9600 baud**, agar tidak muncul teks aneh/rusak.
2. **PWM Pin:** Jelaskan bahwa tidak semua pin digital bisa mengatur redup-terang lampu; hanya pin yang memiliki simbol cacing/tilde (`~`) seperti 3, 5, 6, 9, 10, 11 pada Arduino Uno.
3. **Pembeda Library Header `.h` di Arduino:**
   * Wajib menulis `#include <Arduino.h>` di dalam file `.h`. Jika tidak, compiler akan bingung mengenali apa itu `digitalWrite`, `HIGH`, `LOW`, atau `delay`.
   * Di Arduino IDE, file `.h` yang ditaruh di folder yang sama akan otomatis muncul sebagai **Tab baru** di samping file `.ino`, sangat memudahkan murid untuk mengorganisasi proyek besar.
