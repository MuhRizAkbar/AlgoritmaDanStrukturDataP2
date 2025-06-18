#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
using namespace std;

struct Queue {
    char data[MAX];
    int head, tail;
};

Queue antrian;

void init() {
    antrian.head = antrian.tail = -1;
}

int isEmpty() {
    return antrian.tail == -1;
}

int isFull() {
    return antrian.tail == MAX - 1;
}

void enqueue(char huruf) {
    if (isFull()) {
        cout << "Antrian penuh!\n";
    } else if (isEmpty()) {
        antrian.head = antrian.tail = 0;
        antrian.data[antrian.tail] = huruf;
    } else {
        antrian.tail++;
        antrian.data[antrian.tail] = huruf;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
    } else {
        for (int i = antrian.head; i < antrian.tail; i++) {
            antrian.data[i] = antrian.data[i + 1];
        }
        antrian.tail--;
        if (antrian.tail < antrian.head)
            init();
    }
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
    } else {
        for (int i = antrian.head; i <= antrian.tail; i++) {
            cout << antrian.data[i] << " ";
        }
        cout << endl;
    }
}

void reset() {
    antrian.head = antrian.tail = -1;
    cout << "Queue berhasil di-reset\n";
}

int main() {
    int pilih;
    char huruf;
    init();

    do {
        cout << "\nQUEUE MENU\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display\n";
        cout << "4. Reset\n";
        cout << "5. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan karakter: ";
                cin >> huruf;
                enqueue(huruf);
                break;
            case 2:
                dequeue();
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
