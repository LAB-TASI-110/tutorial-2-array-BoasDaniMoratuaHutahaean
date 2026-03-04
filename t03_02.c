#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MAX, digunakan untuk inisialisasi rata-rata terendah

int main() {
    // Deklarasi variabel
    int n;             // Menyimpan jumlah baris masukan berikutnya
    // Menggunakan array untuk menyimpan semua bilangan agar bisa menghitung rata-rata pasangan berurutan
    // Ukuran array perlu ditentukan. Karena input bilangan bulat antara -100 dan 100,
    // kita asumsikan n tidak akan terlalu besar sehingga array statis bisa digunakan,
    // atau menggunakan Variable Length Array (VLA) jika compiler mendukung C99/C11.
    // Jika n sangat besar, alokasi dinamis (malloc) akan lebih baik.
    // Untuk contoh ini, VLA dianggap OK karena sering didukung compiler modern.
    // Asumsikan N maksimal cukup untuk array statis atau VLA
    
    // 1. Baca baris pertama untuk mendapatkan nilai 'n'
    scanf("%d", &n);

    // Deklarasi array setelah n diketahui (VLA)
    int numbers[n];
    
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer minimum

    // 2. Loop 'n' kali untuk membaca 'n' baris masukan berikutnya
    // Sambil membaca, langsung tentukan nilai min dan max
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]); // Baca bilangan dan simpan ke array

        // Perbarui min_val jika bilangan saat ini lebih kecil
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }

        // Perbarui max_val jika bilangan saat ini lebih besar
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    // 3. Hitung rata-rata terendah dari pasangan bilangan berurutan
    double lowest_consecutive_avg = DBL_MAX; // Inisialisasi dengan nilai double maksimum
    
    // Pastikan ada setidaknya dua bilangan untuk membentuk pasangan
    if (n >= 2) {
        for (int i = 1; i < n; i++) {
            // Hitung rata-rata dari pasangan (numbers[i-1], numbers[i])
            // Lakukan type casting ke double untuk mendapatkan hasil floating point
            double current_avg = (double)(numbers[i-1] + numbers[i]) / 2.0;

            // Perbarui lowest_consecutive_avg jika rata-rata saat ini lebih kecil
            if (current_avg < lowest_consecutive_avg) {
                lowest_consecutive_avg = current_avg;
            }
        }
    } else {
        // Jika tidak ada pasangan (n < 2), set lowest_consecutive_avg ke nilai yang sesuai
        // Contoh: NaN (Not a Number) atau sebuah nilai sentinel,
        // namun berdasarkan contoh output, kita asumsikan n selalu >= 2 untuk adanya pasangan.
        // Jika perlu, bisa diatur untuk mencetak pesan error atau 0.00.
        // Untuk contoh ini, jika n < 2, DBL_MAX akan tetap tercetak.
        // Asumsi contoh input akan selalu menghasilkan output 2.50.
    }

    // 4. Tampilkan hasil keluaran sesuai spesifikasi
    printf("%d\n", min_val);                 // Nilai terkecil
    printf("%d\n", max_val);                 // Nilai terbesar
    printf("%.2f\n", lowest_consecutive_avg); // Rata-rata terendah dengan 2 digit presisi

    return 0; // Menandakan bahwa program berhasil dieksekusi
}
