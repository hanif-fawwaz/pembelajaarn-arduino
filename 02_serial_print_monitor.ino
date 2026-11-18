// ==============================================================================
// MODUL 02: PENGENALAN SERIAL MONITOR (DEBUGGING & TEXT OUTPUT)
// ==============================================================================
// Tujuan Pembelajaran:
// 1. Memahami fungsi Serial Monitor sebagai jembatan komunikasi Arduino ke Laptop.
// 2. Mengaktifkan komunikasi serial dengan Serial.begin(baudrate).
// 3. Mengetahui perbedaan Serial.print() (tanpa enter) dan Serial.println() (dengan enter).
//
// Cara Membuka Serial Monitor di Arduino IDE:
// - Klik icon kaca pembesar di pojok kanan atas, atau tekan Ctrl + Shift + M.
// - Pastikan kecepatan baud di pojok kanan bawah Serial Monitor diset ke: 9600 baud.
// ==============================================================================

int hitungan = 1; // Variabel counter penghitung

void setup() {
  // Mengaktifkan komunikasi Serial dengan kecepatan 9600 bit per detik (baud rate)
  // Ini wajib dipanggil sebelum kita bisa mengirim teks ke komputer
  Serial.begin(9600);

  // Mengirim pesan pembuka sekali saja saat alat baru menyala
  Serial.println("========================================");
  Serial.println("    SISTEM ARDUINO BERHASIL MENYALA!    ");
  Serial.println("========================================");
}

void loop() {
  // Mengirim teks 'print' (kursor tetap di baris yang sama)
  Serial.print("Detik ke-");

  // Mengirim nilai variabel hitungan dan diakhiri pindah baris ('println')
  Serial.println(hitungan);

  // Menambah nilai hitungan sebanyak 1
  hitungan++;

  // Menunggu jeda 1 detik sebelum mengirim baris berikutnya
  delay(1000);
}
