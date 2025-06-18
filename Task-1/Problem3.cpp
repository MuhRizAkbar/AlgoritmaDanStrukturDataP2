#include <iostream>
using namespace std;

struct Data {
    char huruf;
    char kata[50];
    int angka;
};

int main () {

    Data input;
    Data* ptr = &input;

    cout << "a. Masukkan Sebuah Huruf = ";
    cin >> ptr->huruf;

    cout << "b. Masukkan Sebuah Kata = ";
    cin >> ptr->kata;

    cout << "c. Masukkan Sebuah Angka = ";
    cin >> ptr->angka;

    cout <<"d. huruf yang anda masukkan adalah = " << ptr->huruf<<endl;
    cout <<"e. Kata yang anda masukkan adalah = " << ptr->kata<<endl;
    cout <<"f. Angka yang anda masukkan adalah = " << ptr->angka<<endl;
    
    return 0;
}
