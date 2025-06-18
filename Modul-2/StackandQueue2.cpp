#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
using namespace std;

struct Stack {
    int data[MAX];
    int top;
};

Stack tumpukan;

void init() {
    tumpukan.top = -1;
}

int isEmpty() {
    return tumpukan.top == -1;
}

int isFull() {
    return tumpukan.top == MAX - 1;
}

void push(int nilai) {
    if (isFull()) {
        cout << "Stack penuh!\n";
    } else {
        tumpukan.top++;
        tumpukan.data[tumpukan.top] = nilai;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
    } else {
        tumpukan.top--;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
    } else {
        for (int i = tumpukan.top; i >= 0; i--) {
            cout << tumpukan.data[i] << " ";
        }
        cout << endl;
    }
}

void reset() {
    tumpukan.top = -1;
    cout << "Stack berhasil di-reset\n";
}

int main() {
    int pilih, nilai;
    init();

    do {
        cout << "\nSTACK MENU\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Reset\n";
        cout << "5. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                push(nilai);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                reset();
                break;
        }
    } while (pilih != 5);

    return 0;
}
