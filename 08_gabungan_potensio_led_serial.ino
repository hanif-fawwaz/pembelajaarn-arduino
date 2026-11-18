// ==============================================================================
// MODUL 08: GABUNGAN LENGKAP (POTENSIO MENGATUR KECERAHAN LED + SERIAL)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Menggabungkan Analog Input (Potensio) dengan Analog Output PWM (LED).
// 2. Memahami fungsi konversi map(nilai, dariRendah, dariTinggi, keRendah, keTinggi).
//    - Mengubah rentang pembacaan 0-1023 (Analog In) menjadi 0-255 (PWM Out).
// 3. Menampilkan status sinkronisasi ke Serial Monitor.
//
// Rangkaian (Wiring):
// 1. Potensiometer:
//    - Kaki Kiri   -> 5V
//    - Kaki Tengah -> A0
//    - Kaki Kanan  -> GND
// 2. LED:
//    - Kaki Anoda (+) -> Resistor 220 Ohm -> Pin Digital 9 (PWM)
//    - Kaki Katoda (-) -> GND
// ==============================================================================

const int PIN_POTENSIO = A0;
const int PIN_LED_PWM  = 9;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED_PWM, OUTPUT);

  Serial.println("==================================================");
  Serial.println(" SISTEM PENGATUR KECERAHAN LAMPU DENGAN POTENSIO ");
  Serial.println("==================================================");
}

void loop() {
  // 1. Baca nilai putaran potensiometer (0 - 1023)
  int nilaiPotensio = analogRead(PIN_POTENSIO);

  // 2. Konversi rentang:
  // Input:  0 sampai 1023
  // Output: 0 sampai 255 (karena analogWrite hanya menerima 0-255)
  int kecerahanLED = map(nilaiPotensio, 0, 1023, 0, 255);

  // 3. Tuliskan nilai PWM ke LED
  analogWrite(PIN_LED_PWM, kecerahanLED);

  // 4. Laporkan ke Serial Monitor
  Serial.print("Potensio: ");
  Serial.print(nilaiPotensio);
  Serial.print("  -->  Kecerahan LED (PWM): ");
  Serial.print(kecerahanLED);
  
  // Memberikan tanda persentase perkiraan
  int persen = map(kecerahanLED, 0, 255, 0, 100);
  Serial.print(" (");
  Serial.print(persen);
  Serial.println("%)");

  delay(100); // Jeda pembaruan data
}
