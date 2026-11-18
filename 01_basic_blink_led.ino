// ==============================================================================
// MODUL 01: BASIC ARDUINO & DIGITAL OUTPUT (BLINK LED)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami dua fungsi wajib di Arduino: setup() dan loop().
// 2. Memahami fungsi pinMode(pin, OUTPUT) untuk menentukan peran pin.
// 3. Mengontrol tegangan listrik: HIGH (5V / Nyala) dan LOW (0V / Mati).
// 4. Memahami fungsi jeda waktu: delay(milidetik).
//
// Rangkaian (Wiring):
// - Kaki Anoda LED (kaki panjang) -> Resistor 220 Ohm -> Pin Digital 13
// - Kaki Katoda LED (kaki pendek) -> Pin GND (Ground)
// (Catatan: Arduino Uno sudah memiliki lampu LED bawaan di Pin 13)
// ==============================================================================

// Menentukan nomor pin yang digunakan (menggunakan variabel konstanta)
const int PIN_LED = 13;

void setup() {
  // ----------------------------------------------------------------------------
  // void setup() HANYA BERJALAN 1 KALI saat Arduino pertama kali dinyalakan.
  // Tempat untuk konfigurasi awal perangkat.
  // ----------------------------------------------------------------------------
  
  // Mengatur PIN_LED (pin 13) sebagai OUTPUT (pemberi arus listrik)
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // ----------------------------------------------------------------------------
  // void loop() AKAN BERPUTAR TERUS-MENERUS SELAMANYA secara berulang-ulang
  // (seperti while(true) di C++), dari baris atas ke baris bawah, lalu kembali ke atas.
  // ----------------------------------------------------------------------------

  // 1. Nyalakan LED dengan memberi tegangan 5 Volt (HIGH)
  digitalWrite(PIN_LED, HIGH);

  // 2. Tahan kondisi selama 1000 milidetik (1 detik)
  delay(1000);

  // 3. Matikan LED dengan memutus tegangan menjadi 0 Volt (LOW)
  digitalWrite(PIN_LED, LOW);

  // 4. Tahan kondisi mati selama 1000 milidetik (1 detik)
  delay(1000);
}
