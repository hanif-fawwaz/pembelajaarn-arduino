// ==============================================================================
// MODUL 09: PENGGUNAAN FUNGSI DI ARDUINO
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami konsep fungsi di Arduino agar kode di void loop() rapi dan tidak
//    menumpuk berantakan.
// 2. Membuat fungsi VOID dengan parameter:
//    - Contoh: kedipkanLED(pin, jumlahKedip, jedaMs)
// 3. Membuat fungsi dengan NILAI BALIK (RETURN VALUE):
//    - Contoh: bacaPersenPotensio(pin) -> mengembalikan angka 0 sampai 100%
//
// Rangkaian (Wiring):
// - LED Anoda (+) -> Resistor 220 Ohm -> Pin Digital 13
// - Potensiometer Kaki Tengah -> Pin Analog A0
// ==============================================================================

const int PIN_LED = 13;
const int PIN_POTENSIO = A0;

// ------------------------------------------------------------------------------
// FUNGSI 1: VOID DENGAN PARAMETER
// Berfungsi mengedipkan LED sejumlah kali yang kita minta tanpa menulis ulang
// digitalWrite dan delay berkali-kali.
// ------------------------------------------------------------------------------
void kedipkanLED(int pin, int jumlahKedip, int jedaMs) {
  for (int i = 0; i < jumlahKedip; i++) {
    digitalWrite(pin, HIGH);
    delay(jedaMs);
    digitalWrite(pin, LOW);
    delay(jedaMs);
  }
}

// ------------------------------------------------------------------------------
// FUNGSI 2: DENGAN NILAI BALIK (RETURN VALUE)
// Berfungsi membaca analog sensor, lalu langsung mengonversinya menjadi persen (0-100)
// ------------------------------------------------------------------------------
int bacaPersenPotensio(int pinAnalog) {
  int nilaiMentah = analogRead(pinAnalog);           // Nilai 0 s/d 1023
  int persen = map(nilaiMentah, 0, 1023, 0, 100);    // Konversi ke 0 s/d 100%
  return persen;                                     // Kembalikan hasilnya
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);

  Serial.println("Program Fungsi Arduino Dimulai...");

  // Contoh penggunaan Fungsi 1 saat startup: Kedipkan LED 3x dengan cepat sebagai tanda alat aktif
  Serial.println("Mengedipkan LED 3x sebagai tanda inisialisasi...");
  kedipkanLED(PIN_LED, 3, 150); // Pin 13, kedip 3 kali, jeda 150 milidetik
}

void loop() {
  // Menggunakan Fungsi 2 untuk membaca nilai persen
  int persenSekarang = bacaPersenPotensio(PIN_POTENSIO);

  Serial.print("Posisi Potensio: ");
  Serial.print(persenSekarang);
  Serial.println(" %");

  // Jika potensiometer diputar lebih dari 75%, beri peringatan kedip 2x
  if (persenSekarang > 75) {
    Serial.println(">> PERINGATAN: Nilai di atas 75%! Mengedipkan LED...");
    kedipkanLED(PIN_LED, 2, 100);
  }

  delay(500);
}
