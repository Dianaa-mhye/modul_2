#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long long iteratif(int n, int r) {
    long long hasil = 1;
    int i;
    for (i = 0; i < r; i++) {
        hasil = hasil * (n - i);
    }
    return hasil;
}

long long rekursif(int n, int r) {
    if (r == 0) {
        return 1;
    }
    return n * rekursif(n - 1, r - 1);
}

void bersihkanLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void tampilKelompok() {
    printf("+--------------------------------------------------+\n");
    printf("|              DAFTAR ANGGOTA KELOMPOK             |\n");
    printf("+--------------------------------------------------+\n");
    printf("| 1. 260530911030 - I Putu Arvin Danendra Diputra  |\n");
    printf("| 2. 260530911010 - Ni Kadek Arya Swandewi         |\n");
    printf("| 3. 260530911156 - Nur Diana                      |\n");
    printf("| 4. 260530911121 - Noel Tarvaota Raya Duha        |\n");
    printf("| 5. 260530911074 - I Nyoman Putra Sanjaya         |\n");
    printf("| 6. 260530911018 - I Kadek Arya Wikcaksana        |\n");
    printf("+--------------------------------------------------+\n");
}

int main() {
    int barang, posisi, pilihan;
    char lanjut[10] = "yes";
    int i;
    long long hasil;

    tampilKelompok();

    do {
        printf("\n");
        printf("+--------------------------------------------------+\n");
        printf("|                       MENU                       |\n");
        printf("+--------------------------------------------------+\n");
        printf("| 1. Hitung Iteratif                               |\n");
        printf("| 2. Hitung Rekursif                               |\n");
        printf("| 0. Keluar                                        |\n");
        printf("+--------------------------------------------------+\n");
        printf("Pilih menu (0-2)       : ");
        scanf("%d", &pilihan);

        if (pilihan == 0) {
            printf("\nTerima kasih, program selesai.\n");
            break;
        }

        if (pilihan != 1 && pilihan != 2) {
            printf(">> Pilihan tidak valid! Silakan pilih 0-2.\n");
            continue;
        }

        printf("\n");
        printf("Masukkan jumlah barang : ");
        scanf("%d", &barang);
        printf("Masukkan jumlah posisi : ");
        scanf("%d", &posisi);

        if (posisi > barang) {
            printf(">> Posisi tidak boleh lebih banyak dari barang!\n");
            continue;
        }

        if (pilihan == 1) {
            hasil = iteratif(barang, posisi);
        } else {
            hasil = rekursif(barang, posisi);
        }

        printf("\n");
        printf("+--------------------------------------------------+\n");
        printf("|                 HASIL PERHITUNGAN                |\n");
        printf("+--------------------------------------------------+\n");
        printf("| Metode         : %-31s |\n", pilihan == 1 ? "Iteratif" : "Rekursif");
        printf("| Jumlah barang  : %-31d |\n", barang);
        printf("| Jumlah posisi  : %-31d |\n", posisi);
        printf("| Hasil          : %-31lld |\n", hasil);
        printf("+--------------------------------------------------+\n");

        do {
            printf("\nLanjut hitung lagi? (yes/no) : ");
            scanf("%9s", lanjut);

            for (i = 0; lanjut[i] != '\0'; i++) {
                lanjut[i] = tolower(lanjut[i]);
            }

            if (strcmp(lanjut, "yes") != 0 && strcmp(lanjut, "y") != 0 &&
                strcmp(lanjut, "no") != 0 && strcmp(lanjut, "n") != 0) {
                printf(">> Jawab dengan yes atau no saja!\n");
            }
        } while (strcmp(lanjut, "yes") != 0 && strcmp(lanjut, "y") != 0 &&
                 strcmp(lanjut, "no") != 0 && strcmp(lanjut, "n") != 0);

        if (lanjut[0] == 'y') {
            bersihkanLayar();
            tampilKelompok();
        } else {
            printf("\nTerima kasih, program selesai.\n");
        }
    } while (lanjut[0] == 'y');

    return 0;
}
