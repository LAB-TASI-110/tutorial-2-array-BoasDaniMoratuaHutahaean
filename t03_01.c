#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk INT_MAX dan INT_MIN, nilai batas integer

int main() {
    // Deklarasi variabel
    int n;           // Menyimpan jumlah baris masukan berikutnya
    int current_num; // Menyimpan bilangan bulat yang sedang dibaca
    int min_val;     // Menyimpan nilai terkecil yang ditemukan
    int max_val;     // Menyimpan nilai terbesar yang ditemukan

    // 1. Baca baris pertama untuk mendapatkan nilai 'n'
    scanf("%d", &n);

    // Inisialisasi min_val dan max_val dengan nilai batas ekstrem
    min_val = INT_MAX; // Nilai integer maksimum yang mungkin
    max_val = INT_MIN; // Nilai integer minimum yang mungkin

    // 2. Loop 'n' kali untuk membaca 'n' baris masukan berikutnya
    for (int i = 0; i < n; i++) {
        // Baca setiap bilangan bulat
        scanf("%d", &current_num);

        // Perbarui min_val jika current_num lebih kecil
        if (current_num < min_val) {
            min_val = current_num;
        }

        // Perbarui max_val jika current_num lebih besar
        if (current_num > max_val) {
            max_val = current_num;
        }
    }

    // 3. Tampilkan hasil keluaran sesuai spesifikasi
    printf("%d\n", min_val); // Nilai terkecil
    printf("%d\n", max_val); // Nilai terbesar

    return 0; // Menandakan bahwa program berhasil dieksekusi
}
