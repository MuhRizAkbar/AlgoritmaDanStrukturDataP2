#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

string name = "Orlando Sugian";
string id = "2410817210017";

const int n = 5;
string namaAwal[n] = {"Akbar", "Xever", "Eren", "Orlando Sugian", "Brody"};
string nimAwal[n]  = {"2601", "2101", "2702", "2410817210017", "2309"};

string nama[n];
string nim[n];

void resetNama() {
    for (int i = 0; i < n; i++) {
        nama[i] = namaAwal[i];
    }
}

void resetNIM() {
    for (int i = 0; i < n; i++) {
        nim[i] = nimAwal[i];
    }
}

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(10);
    cout << sortName << " took " << duration.count() << " seconds\n";
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        string key = nama[i];
        int j = i - 1;
        while (j >= 0 && nama[j] > key) {
            nama[j + 1] = nama[j];
            j--;
        }
        nama[j + 1] = key;
    }
}

void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    string L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortNama(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortNama(left, mid);
        mergeSortNama(mid + 1, right);
        merge(nama, left, mid, right);
    }
}

void shellSort() {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            string temp = nama[i];
            int j;
            for (j = i; j >= gap && nama[j - gap] > temp; j -= gap) {
                nama[j] = nama[j - gap];
            }
            nama[j] = temp;
        }
    }
}

int partition(int low, int high) {
    string pivot = nim[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nim[j] < pivot) {
            i++;
            swap(nim[i], nim[j]);
        }
    }
    swap(nim[i + 1], nim[high]);
    return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nim[j] > nim[j + 1]) {
                swap(nim[j], nim[j + 1]);
            }
        }
    }
}

void selectionSort() {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nim[j] < nim[min_idx]) {
                min_idx = j;
            }
        }
        swap(nim[i], nim[min_idx]);
    }
}

void tampilNama() {
    for (int i = 0; i < n; i++) {
        cout << nama[i];
        if (i < n - 1) cout << " | ";
    }
    cout << endl;
}

void tampilNIM() {
    for (int i = 0; i < n; i++) {
        cout << nim[i];
        if (i < n - 1) cout << " | ";
    }
    cout << endl;
}

int main() {
    int pilihan;
    do {
        system("cls");
        cout << "\n=== MENU SORTING ===\n";
        cout << "1. Insertion Sort (Nama)\n";
        cout << "2. Merge Sort (Nama)\n";
        cout << "3. Shell Sort (Nama)\n";
        cout << "4. Quick Sort (NIM)\n";
        cout << "5. Bubble Sort (NIM)\n";
        cout << "6. Selection Sort (NIM)\n";
        cout << "7. Keluar\n";
        cout << "Pilih metode sorting: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                resetNama();
                cout << "\nData sebelum sorting:\n";
                tampilNama();
                timeSort(insertionSort, "Insertion Sort (Nama)");
                cout << "Data setelah sorting:\n";
                tampilNama();
                break;
            case 2:
                resetNama();
                cout << "\nData sebelum sorting:\n";
                tampilNama();
                timeSort([&]() { mergeSortNama(0, n - 1); }, "Merge Sort (Nama)");
                cout << "Data setelah sorting:\n";
                tampilNama();
                break;
            case 3:
                resetNama();
                cout << "\nData sebelum sorting:\n";
                tampilNama();
                timeSort(shellSort, "Shell Sort (Nama)");
                cout << "Data setelah sorting:\n";
                tampilNama();
                break;
            case 4:
                resetNIM();
                cout << "\nData sebelum sorting:\n";
                tampilNIM();
                timeSort([&]() { quickSort(0, n - 1); }, "Quick Sort (NIM)");
                cout << "Data setelah sorting:\n";
                tampilNIM();
                break;
            case 5:
                resetNIM();
                cout << "\nData sebelum sorting:\n";
                tampilNIM();
                timeSort(bubbleSort, "Bubble Sort (NIM)");
                cout << "Data setelah sorting:\n";
                tampilNIM();
                break;
            case 6:
                resetNIM();
                cout << "\nData sebelum sorting:\n";
                tampilNIM();
                timeSort(selectionSort, "Selection Sort (NIM)");
                cout << "Data setelah sorting:\n";
                tampilNIM();
                break;
            case 7:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

        cout << "\nTekan sembarang tombol untuk kembali ke menu...";
        getch();
    } while (pilihan != 7);

    return 0;
}

