#include <iostream>
using namespace std;

struct Data {
    char huruf;
    char kata[50];
    int angka;
};

int main() {
    Data input;
    Data* ptr = &input;

    cout << "a. Masukkan sebuah huruf = ";
    cin >> ptr->huruf;

    cout << "b. Masukkan sebuah kata = ";
    cin >> ptr->kata;

    cout << "c. Masukkan angka = ";
    cin >> ptr->angka;

    cout << "d. Huruf yang Anda masukkan adalah " << ptr->huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << ptr->kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << ptr->angka << endl;

    return 0;
}
