#include <iostream>
#include <chrono>
#include <functional>
#include <iomanip>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

string name = "Muhammad Rizky Akbar";
string id = "2410817210016";

const int n = 5;

string nama[n], nim[n];
string namaAwal[n] = {"Adam", "Heri", "Alwy", "Muhammad Rizky Akbar", "Waffa"};
string nimAwal[n] = {"2601", "2101", "2702", "2410817210016", "2309"};

void resetData(bool isNama) {
    for (int i = 0; i < n; i++) {
        if (isNama) nama[i] = namaAwal[i];
        else nim[i] = nimAwal[i];
    }
}

void tampilData(const string arr[]) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " | ";
    }
    cout << endl;
}

void timeSort(const function<void()>& func, const string& method) {
    auto start = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> dur = end - start;
    cout << fixed << setprecision(10);
    cout << method << " selesai dalam " << dur.count() << " detik\n";
}

// Sorting untuk nama
void insertionSortNama() {
    for (int i = 1; i < n; i++) {
        string key = nama[i];
        int j = i - 1;
        while (j >= 0 && nama[j] > key)
            nama[j + 1] = nama[j--];
        nama[j + 1] = key;
    }
}

void merge(string arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    string L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortNama(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortNama(l, m);
        mergeSortNama(m + 1, r);
        merge(nama, l, m, r);
    }
}

void shellSortNama() {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            string temp = nama[i];
            int j = i;
            while (j >= gap && nama[j - gap] > temp) {
                nama[j] = nama[j - gap];
                j -= gap;
            }
            nama[j] = temp;
        }
}

// Sorting untuk NIM
void quickSortNIM(int low, int high) {
    if (low < high) {
        string pivot = nim[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
            if (nim[j] < pivot)
                swap(nim[++i], nim[j]);
        swap(nim[i + 1], nim[high]);
        int pi = i + 1;
        quickSortNIM(low, pi - 1);
        quickSortNIM(pi + 1, high);
    }
}

void bubbleSortNIM() {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (nim[j] > nim[j + 1])
                swap(nim[j], nim[j + 1]);
}

void selectionSortNIM() {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (nim[j] < nim[minIdx])
                minIdx = j;
        swap(nim[i], nim[minIdx]);
    }
}

int main() {
    int pilihan;

    do {
        system("cls");
        cout << "=== MENU SORTING ===\n";
        cout << "1. Insertion Sort (Nama)\n";
        cout << "2. Merge Sort (Nama)\n";
        cout << "3. Shell Sort (Nama)\n";
        cout << "4. Quick Sort (NIM)\n";
        cout << "5. Bubble Sort (NIM)\n";
        cout << "6. Selection Sort (NIM)\n";
        cout << "7. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                resetData(true);
                cout << "\nSebelum: "; tampilData(nama);
                timeSort(insertionSortNama, "Insertion Sort");
                cout << "Sesudah: "; tampilData(nama);
                break;
            case 2:
                resetData(true);
                cout << "\nSebelum: "; tampilData(nama);
                timeSort([&]() { mergeSortNama(0, n - 1); }, "Merge Sort");
                cout << "Sesudah: "; tampilData(nama);
                break;
            case 3:
                resetData(true);
                cout << "\nSebelum: "; tampilData(nama);
                timeSort(shellSortNama, "Shell Sort");
                cout << "Sesudah: "; tampilData(nama);
                break;
            case 4:
                resetData(false);
                cout << "\nSebelum: "; tampilData(nim);
                timeSort([&]() { quickSortNIM(0, n - 1); }, "Quick Sort");
                cout << "Sesudah: "; tampilData(nim);
                break;
            case 5:
                resetData(false);
                cout << "\nSebelum: "; tampilData(nim);
                timeSort(bubbleSortNIM, "Bubble Sort");
                cout << "Sesudah: "; tampilData(nim);
                break;
            case 6:
                resetData(false);
                cout << "\nSebelum: "; tampilData(nim);
                timeSort(selectionSortNIM, "Selection Sort");
                cout << "Sesudah: "; tampilData(nim);
                break;
            case 7:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

        if (pilihan != 7) {
            cout << "\nTekan sembarang tombol untuk kembali ke menu...";
            getch();
        }

    } while (pilihan != 7);

    return 0;
}
