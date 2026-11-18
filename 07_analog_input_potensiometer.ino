// ==============================================================================
// MODUL 07: ANALOG INPUT (MEMBACA TEGANGAN PUTARAN POTENSIOMETER)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami fungsi Pin Analog Input (A0 s/d A5).
// 2. Menggunakan fungsi analogRead(pin) dengan resolusi ADC 10-bit:
//    - Putaran mentok kiri  (0 Volt)   = bernilai 0
//    - Putaran mentok kanan (5 Volt)   = bernilai 1023
// 3. Menampilkan nilai pembacaan sensor ke Serial Monitor.
//
// Rangkaian (Wiring Potensiometer 3 Kaki):
// - Kaki 1 (Kiri)   -> Pin 5V Arduino
// - Kaki 2 (Tengah) -> Pin Analog A0 Arduino (Kaki sinyal/wiper)
// - Kaki 3 (Kanan)  -> Pin GND Arduino
// ==============================================================================

const int PIN_POTENSIO = A0; // Menggunakan Pin Analog A0

void setup() {
  Serial.begin(9600);
  // Catatan: Pin Analog A0 s/d A5 otomatis menjadi INPUT secara default,
  // sehingga kita tidak wajib menuliskan pinMode(A0, INPUT).
  
  Serial.println("Program Pembacaan Potensiometer Dimulai.");
  Serial.println("Silakan putar kenop potensiometer Anda!");
}

void loop() {
  // Membaca nilai voltase dari kaki tengah potensiometer (rentang 0 s/d 1023)
  int nilaiSensor = analogRead(PIN_POTENSIO);

  // Menghitung estimasi voltase asli (rumus: nilai / 1023.0 * 5.0 Volt)
  float voltase = (nilaiSensor / 1023.0) * 5.0;

  // Menampilkan data ke Serial Monitor
  Serial.print("Nilai ADC (0-1023): ");
  Serial.print(nilaiSensor);
  Serial.print("  |  Tegangan: ");
  Serial.print(voltase);
  Serial.println(" Volt");

  // Jeda 200 milidetik agar tampilan tidak bergerak terlalu cepat
  delay(200);
}
