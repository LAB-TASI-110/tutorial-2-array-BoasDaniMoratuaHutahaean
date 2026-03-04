#include <stdio.h>  // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk DBL_MAX dan DBL_MIN, digunakan untuk inisialisasi rata-rata

int main() {
    // Deklarasi variabel
    int n;             // Menyimpan jumlah baris masukan berikutnya
    
    // 1. Baca baris pertama untuk mendapatkan nilai 'n'
    scanf("%d", &n);

    // Deklarasi array setelah n diketahui (Variable Length Array - VLA)
    // VLA umumnya didukung di C99/C11 dan oleh GCC.
    int numbers[n];
    
    // Inisialisasi variabel untuk mencari nilai terkecil dan terbesar
    int min_val = INT_MAX; // Nilai integer maksimum yang mungkin
    int max_val = INT_MIN; // Nilai integer minimum yang mungkin

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

    // 3. Hitung rata-rata terendah dan tertinggi dari pasangan bilangan berurutan
    double lowest_consecutive_avg = DBL_MAX;  // Inisialisasi dengan nilai double maksimum
    double highest_consecutive_avg = DBL_MIN; // Inisialisasi dengan nilai double minimum
    
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

            // Perbarui highest_consecutive_avg jika rata-rata saat ini lebih besar
            if (current_avg > highest_consecutive_avg) {
                highest_consecutive_avg = current_avg;
            }
        }
    } else {
        // Jika tidak ada pasangan (n < 2), atur rata-rata ke nilai default yang sesuai
        // atau biarkan DBL_MAX/DBL_MIN agar mencetak nilai yang sangat besar/kecil.
        // Untuk tujuan ini, kita akan menjaga agar nilainya tidak berubah, yang berarti
        // DBL_MAX untuk terendah dan DBL_MIN untuk tertinggi akan tercetak jika n < 2.
    }

    // 4. Tampilkan hasil keluaran sesuai spesifikasi
    printf("%d\n", min_val);                     // Nilai terkecil
    printf("%d\n", max_val);                     // Nilai terbesar
    printf("%.2f\n", lowest_consecutive_avg);    // Rata-rata terendah dengan 2 digit presisi
    printf("%.2f\n", highest_consecutive_avg);   // Rata-rata tertinggi dengan 2 digit presisi

    return 0; // Menandakan bahwa program berhasil dieksekusi
}
