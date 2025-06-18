#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = NULL;

void Init() {
    head = NULL;
}

bool cekKosong() {
    return head == NULL;
}

void Tampilkan() {
    if (cekKosong()) {
        cout << "Daftar Kosong" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

void masukDepan(string value) {
    Node* newNode = new Node{value, NULL};
    if (cekKosong()) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}


void masukBelakang(string value) {
    Node* newNode = new Node{value, NULL};
    if (cekKosong()) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}


void hapusDepan() {
    if (cekKosong()) {
        cout << "daftar Kosong" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        delete temp;
    }
}


void hapusBelakang() {
    if (cekKosong()) {
        cout << "Daftar Kosong" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* prev = NULL;
        Node* temp = head;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
}

void reset() {
    if (cekKosong()) return;
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = NULL;
    cout << "Daftar sudah ter-reset" << endl;
}


Node* cariElemen(string value) {
    if (cekKosong()) return NULL;
    Node* temp = head;
    do {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

void tambahDepan(string target, string value) {
    Node* targetNode = cariElemen(target);
    if (targetNode == NULL) {
        cout << "Elemen tidak ditemukan" << endl;
        return;
    }
    Node* newNode = new Node{value, targetNode->next};
    targetNode->next = newNode;
}

void tambahBelakang(string target, string value) {
    if (cekKosong()) return;

    Node* prev = NULL;
    Node* current = head;

    do {
        if (current->data == target)
            break;
        prev = current;
        current = current->next;
    } while (current != head);

    if (current->data != target) {
        cout << "Elemen tidak ditemukan" << endl;
        return;
    }

    Node* newNode = new Node{value, current};
    if (current == head) {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        head = newNode;
    } else {
        prev->next = newNode;
    }
}

void menu() {
    int menuPilihan;
    string nilai, target;

    do {
        cout << "\n=== Circular Linked List Menu ===" << endl;
        cout << "1. Masukkan di Depan\n2. Masukkan di Belakang\n3. Hapus Depan\n4. Hapus Belakang\n";
        cout << "5. Tampilkan List\n6. Reset\n7. Cari Elemen Spesifik\n8. Tambahkan Nilai di Depan Elemen Spesifik\n";
        cout << "9. Tambahkan Nilai di Belakang Elemen Spesifik\n0. Akhiri Program" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> menuPilihan;
        switch (menuPilihan) {
            case 1:
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                masukDepan(nilai);
                break;
            case 2:
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                masukBelakang(nilai);
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                Tampilkan();
                break;
            case 6:
                reset();
                break;
            case 7:
                cout << "Masukkan Elemen yang ingin dicari: ";
                cin >> nilai;
                if (cariElemen(nilai))
                    cout << "Elemen Ditemukan" << endl;
                else
                    cout << "Elemen TIdak Ditemukan" << endl;
                break;
            case 8:
                cout << "Masukkan Target Elemen: ";
                cin >> target;
                cout << "Masukkan Nilai Elemen Baru: ";
                cin >> nilai;
                tambahDepan(target, nilai);
                break;
            case 9:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> nilai;
                tambahBelakang(target, nilai);
                break;
            case 0:
                reset();
                cout << "Mengakhiri Program..." << endl;
                break;
            default:
                cout << "Pilihan tidak Valid" << endl;
        }
    } while (menuPilihan != 0);
}

int main() {
    Init();
    menu();
    return 0;
}
