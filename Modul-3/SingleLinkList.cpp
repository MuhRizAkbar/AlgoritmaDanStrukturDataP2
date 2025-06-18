#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
} TNode;

TNode *head, *tail;
string dataBaru, data;

int pil;
char pilihan[2];

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    return head == NULL;
}

bool isFull() {
    TNode* test = new(nothrow) TNode;
    if (test == NULL)
        return true;
    delete test;
    return false;
}

void tambahDepan() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = baru;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian depan." << endl;
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru = new TNode;
    baru->data = dataBaru;
    baru->next = baru;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di bagian belakang." << endl;
}

void hapusDepan() {
    if (!isEmpty()) {
        TNode *hapus = head;
        data = hapus->data;
        if (head != tail) {
            head = head->next;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        TNode *hapus = tail;
        data = hapus->data;

        if (head != tail) {
            TNode *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = head;
        } else {
            init();
        }

        delete hapus;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void tampilkan() {
    if (!isEmpty()) {
        TNode *bantu = head;
        cout << "Isi Linked List: ";
        do {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void reset() {
    if (!isEmpty()) {
        TNode *bantu = head, *hapus;
        do {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        } while (bantu != head);
        init();
        cout << "Seluruh elemen pada Linked List telah dibersihkan." << endl;
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void cariData() {
    if (!isEmpty()) {
        string cari;
        cout << "Masukkan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu = head;
        bool ditemukan = false;

        do {
            if (cari == bantu->data) {
                ditemukan = true;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (ditemukan) {
            cout << "Data \"" << cari << "\" ditemukan di dalam Linked List." << endl;
        } else {
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void hapusData() {
    if (!isEmpty()) {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;

        TNode *bantu = head, *sebelum = tail, *hapus;
        bool ditemukan = false;

        do {
            if (bantu->data == cari) {
                ditemukan = true;
                if (bantu == head) {
                    hapusDepan();
                    bantu = head;
                    sebelum = tail;
                    continue;
                } else if (bantu == tail) {
                    hapusBelakang();
                    break;
                } else {
                    hapus = bantu;
                    sebelum->next = bantu->next;
                    bantu = bantu->next;
                    delete hapus;
                    continue;
                }
            }
            sebelum = bantu;
            bantu = bantu->next;
        } while (bantu != head);

        if (ditemukan) {
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List telah dihapus." << endl;
        } else {
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void sisipkanSebelum() {
    if (!isEmpty()) {
        string nextData;
        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        TNode *bantu = head, *sebelum = tail;
        bool ditemukan = false;

        do {
            if (nextData == bantu->data) {
                ditemukan = true;
                break;
            }
            sebelum = bantu;
            bantu = bantu->next;
        } while (bantu != head);

        if (ditemukan) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;

            if (bantu == head) head = baru;

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan sebelum data \"" << nextData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << nextData << "\" pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

void sisipkanSetelah() {
    if (!isEmpty()) {
        string prevData;
        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        TNode *bantu = head;
        bool ditemukan = false;

        do {
            if (prevData == bantu->data) {
                ditemukan = true;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (ditemukan) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;
            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            if (bantu == tail) tail = baru;

            cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah data \"" << prevData << "\"." << endl;
        } else {
            cout << "Tidak terdapat data \"" << prevData << "\" pada Linked List." << endl;
        }
    } else {
        cout << "Tidak terdapat data pada Linked List." << endl;
    }
}

int main() {
    int pil;
    char pilihan[3];
    init();

    do {
        system("cls");
        cout << "Single Linked List Circular (SLLC)" << endl;
        cout << "==================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan Data" << endl;
        cout << "6. Hapus Semua Elemen" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Hapus Setiap Data Tertentu" << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);

        cout << endl;

        switch (pil) {
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
                break;
            case 4:
                hapusBelakang();
                cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                reset();
                break;
            case 7:
                cariData();
                break;
            case 8:
                hapusData();
                break;
            case 9:
                sisipkanSebelum();
                break;
            case 10:
                sisipkanSetelah();
                break;
            case 11:
                cout << "\nTERIMA KASIH" << endl;
                cout << "Program ini dibuat oleh Orlando Sugian (2410817210017)." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        if (pil != 11) {
            cout << "\nTekan tombol apa saja untuk melanjutkan...";
            getch();  
        }

    } while (pil != 11);

    return 0;
}
