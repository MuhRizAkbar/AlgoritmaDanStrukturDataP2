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
    cout << "\n--- Penjelasan dan Perbandingan Sequential Search dan Binary Search ---\n";

    cout << "\n1. Sequential Search (Pencarian Berurutan):\n";
    cout << "- Mencari data dengan memeriksa satu per satu elemen dalam array.\n";
    cout << "- Tidak memerlukan data yang terurut.\n";
    cout << "- Cocok digunakan untuk dataset kecil atau yang tidak terurut.\n";
    cout << "- Kompleksitas waktu: O(n), di mana n adalah jumlah elemen.\n";
    cout << "- Kelebihan:\n";
    cout << "  * Sederhana dan mudah diimplementasikan.\n";
    cout << "  * Tidak perlu prasyarat data terurut.\n";
    cout << "- Kekurangan:\n";
    cout << "  * Kurang efisien untuk jumlah data besar.\n";

    cout << "\n2. Binary Search (Pencarian Biner):\n";
    cout << "- Mencari data dengan membagi dua bagian array secara terus-menerus.\n";
    cout << "- Memerlukan data yang sudah diurutkan terlebih dahulu.\n";
    cout << "- Lebih efisien daripada Sequential Search pada dataset besar.\n";
    cout << "- Kompleksitas waktu: O(log n).\n";
    cout << "- Kelebihan:\n";
    cout << "  * Sangat cepat pada array besar yang sudah terurut.\n";
    cout << "  * Mengurangi jumlah perbandingan secara signifikan.\n";
    cout << "- Kekurangan:\n";
    cout << "  * Harus mengurutkan data terlebih dahulu.\n";
    cout << "  * Implementasi sedikit lebih kompleks dibanding Sequential Search.\n";

    cout << "\nKesimpulan:\n";
    cout << "- Gunakan Sequential Search jika data belum terurut dan ukuran kecil.\n";
    cout << "- Gunakan Binary Search jika data besar dan sudah dalam keadaan terurut.\n";
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
                for (int val : nums)
                    cout << val << " ";

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
                cout << "Programme was made by Muhammad Rizky Akbar (2410817210016)\n";
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
