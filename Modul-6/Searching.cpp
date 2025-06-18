#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


void sequentialSearch(const vector<int> &nums, int target) {
    vector<int> posisi;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            posisi.push_back(i);
        }
    }

    if (!posisi.empty()) {
        cout << "\nAngka ditemukan sebanyak " << posisi.size() << " kali pada indeks: ";
        for (int idx : posisi) {
            cout << idx << " ";
        }
        cout << endl;
    } else {
        cout << "\nAngka tidak ditemukan dalam array." << endl;
    }
}

void binarySearch(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    cout << "\nData setelah diurutkan:\n";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    int kiri = 0, kanan = nums.size() - 1, tengah, posisi = -1;
    bool ketemu = false;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (nums[tengah] == target) {
            ketemu = true;
            posisi = tengah;
            break;
        } else if (target < nums[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu) {
        cout << "\nAngka ditemukan pada indeks ke-" << posisi << "!" << endl;
    } else {
        cout << "\nAngka tidak ditemukan!" << endl;
    }
}

void clearScreen() {
    system("cls");
}

void explain() {
    cout << "\n=== Penjelasan dan Perbandingan Algoritma Searching ===\n";

    cout << "\n>> 1. Penjelasan Sequential Searching dan Binary Searching\n\n";
    cout << "Sequential Searching:\n";
    cout << "- Memeriksa elemen satu per satu.\n";
    cout << "- Tidak perlu data terurut.\n";
    cout << "- Menampilkan semua indeks dan jumlah kemunculan.\n\n";

    cout << "Binary Searching:\n";
    cout << "- Data harus terurut.\n";
    cout << "- Memakai pembagian dua (divide and conquer).\n";
    cout << "- Menampilkan indeks jika ditemukan.\n\n";

    cout << ">> 2. Kelebihan dan Kekurangan\n\n";
    cout << "Sequential Search:\n";
    cout << "- Kelebihan: Mudah diterapkan, tidak butuh data terurut, bisa temukan semua posisi.\n";
    cout << "- Kekurangan: Kurang efisien untuk jumlah data besar karena harus cek satu-satu.\n\n";

    cout << "Binary Search:\n";
    cout << "- Kelebihan: Proses pencarian jauh lebih cepat, terutama untuk data besar.\n";
    cout << "- Kekurangan: Harus mengurutkan data dulu, hanya menunjukkan satu posisi, tidak bisa temukan semua kemunculan jika ada lebih dari satu.\n\n";

    cout << ">> 3. Kompleksitas dan Penggunaan\n\n";
    cout << "Kompleksitas Waktu:\n";
    cout << "- Sequential: O(n) karena cek satu-satu.\n";
    cout << "- Binary: O(log n) karena membagi dua setiap langkah.\n\n";

    cout << "Kompleksitas Memori:\n";
    cout << "- Kedua algoritma sama-sama O(1), tidak butuh memori tambahan besar.\n\n";

    cout << "Kapan digunakan:\n";
    cout << "- Gunakan Sequential untuk data kecil atau belum terurut.\n";
    cout << "- Gunakan Binary untuk data besar yang sudah diurutkan agar lebih cepat.\n";
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching beserta kelebihan dan kekurangannya!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);
                
                for (auto &val : nums) {
                    val = dist(rng);
                }
                cout << "\nData:\n";

                for (int val : nums) 
                cout << val << " ";
                cout << "\nMasukkan angka yang ingin dicari: ";
                cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val : nums) {
                    val = dist(rng);
                }
                cout << "\nData sebelum diurutkan:\n";

                for (int val : nums) cout << val << " ";
                cout << "\nMasukkan angka yang ingin dicari: ";
                cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Orlando Sugian (2410817210017)\n";
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi\n";
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}
