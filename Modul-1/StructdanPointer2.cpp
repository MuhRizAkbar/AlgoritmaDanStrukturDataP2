#include<iostream>

using namespace std;

struct Kendaraan {
    char platNomor[20];
    char jenis[20];
    char pemilik[50];
    char alamat[50];
    char kota[20];
};

int main() {
    Kendaraan data;

    cout << "Plat Nomor Kendaraan : "; cin.getline(data.platNomor, 20);
    cout << "Jenis Kendaraan      : "; cin.getline(data.jenis, 20);
    cout << "Nama Pemilik         : "; cin.getline(data.pemilik, 50);
    cout << "Alamat               : "; cin.getline(data.alamat, 50);
    cout << "Kota                 : "; cin.getline(data.kota, 20);

    cout << "a. Plat Nomor Kendaraan : " << data.platNomor << endl;
    cout << "b. Jenis Kendaraan : " << data.jenis << endl;
    cout << "c. Nama Pemilik : " << data.pemilik << endl;
    cout << "d. Alamat : " << data.alamat << endl;
    cout << "e. Kota : " << data.kota << endl;

    return 0;
}
