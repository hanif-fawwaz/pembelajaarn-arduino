// ==============================================================================
// MODUL 05: SERIAL INPUT (KOMPUTER MENGONTROL LED ARDUINO)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami interaksi dua arah: Laptop mengirim perintah ke Arduino.
// 2. Menggunakan Serial.available() untuk memeriksa apakah ada data masuk.
// 3. Menggunakan Serial.read() untuk membaca 1 karakter huruf dari keyboard.
// 4. Menerapkan percabangan 'if - else' atau 'switch-case' dari materi C++.
//
// Cara Pengujian:
// - Buka Serial Monitor (Ctrl + Shift + M).
// - Ketik angka '1' di kolom atas lalu tekan Enter -> LED Menyala.
// - Ketik angka '0' di kolom atas lalu tekan Enter -> LED Padam.
// ==============================================================================

const int PIN_LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);

  Serial.println("=========================================");
  Serial.println(" KONTROL LED VIA SERIAL MONITOR KOMPUTER ");
  Serial.println(" Ketik '1' + Enter untuk MENYALAKAN LED  ");
  Serial.println(" Ketik '0' + Enter untuk MEMATIKAN LED   ");
  Serial.println("=========================================");
}

void loop() {
  // Serial.available() mengecek jumlah karakter yang masuk ke antrean buffer serial.
  // Jika nilainya > 0, berarti pengguna baru saja mengetik sesuatu dari laptop.
  if (Serial.available() > 0) {
    
    // Membaca satu karakter yang diketik
    char perintah = Serial.read();

    if (perintah == '1') {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("[DITERIMA] Perintah '1' -> Lampu LED DINYALAKAN.");
    } 
    else if (perintah == '0') {
      digitalWrite(PIN_LED, LOW);
      Serial.println("[DITERIMA] Perintah '0' -> Lampu LED DIPADAMKAN.");
    }
    // Mengabaikan karakter enter / newline ('\n' atau '\r')
  }
}
