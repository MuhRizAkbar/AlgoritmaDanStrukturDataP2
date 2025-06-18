#include <iostream>

using namespace std;

struct kendaraan
{
    char plat[10], jenis[20], pemilik[25], alamat[35], kota[20];
};

int main () {

    kendaraan data;

    cout<<"Plat Nomor Kendaraan : "; cin.getline(data.plat,10);
    cout<<"Jenis Kendaraan : "; cin.getline(data.jenis,20);
    cout<<"Nama Pemilik : "; cin.getline(data.pemilik,25);
    cout<<"Alamat : "; cin.getline(data.alamat,35);
    cout<<"Kota : "; cin.getline(data.kota,20);

    cout<<"a.Plat Nomor Kendaraan : " << data.plat << endl;
    cout<<"b.Jenis Kendaraan : " << data.jenis << endl;
    cout<<"c.Nama Pemilik : " << data.pemilik << endl;
    cout<<"d.Alamat : " << data.alamat << endl;
    cout<<"e.Kota : " << data.kota << endl;
    cout<<endl<<endl;

}
