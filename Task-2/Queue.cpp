#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Queue {
    char data[MAX];
    int front, rear;
};

void init(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front == -1;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, char element) {
    if (isFull(q)) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }
    q.data[q.rear] = element;
    cout << "Element '" << element << "' added to the queue." << endl;
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Element '" << q.data[q.front] << "' removed from the queue." << endl;
    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue contents: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.data[i] << ' ';
    }
    cout << endl;
}

void reset(Queue &q) {
    init(q);
    cout << "Queue has been reset." << endl;
}

int main() {
    Queue q;
    init(q);
    int choice;
    char element;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Reset\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to enqueue: ";
                cin >> element;
                enqueue(q, element);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                reset(q);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "Press any key to continue...";
        getch();
        system("cls");

    } while (choice != 5);

    return 0;
}
