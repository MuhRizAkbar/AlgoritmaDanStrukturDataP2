#include <iostream>
#include <conio.h>
#include <stdlib.h> 

#define MAX 20

using namespace std;

struct Stack {
    int data[MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int value) {
    if (isFull(s)) {
        cout << "Stack is full!\n";
    } else {
        s.top++;
        s.data[s.top] = value;
        cout << "Pushed " << value << " to the stack.\n";
    }
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!\n";
    } else {
        cout << "Popped " << s.data[s.top] << " from the stack.\n";
        s.top--;
    }
}

void display(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements: ";
        for (int i = s.top; i >= 0; i--) {
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}


void reset(Stack &s) {
    s.top = -1;
    cout << "Stack has been reset.\n";
}


int main() {
    Stack s;
    init(s);

    int choice, value;
    do {
        system("cls"); 
        cout << "=== STACK MENU ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Reset\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                display(s);
                break;
            case 4:
                reset(s);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
        cout << "Press any key to continue...";
        getch(); 
    } while(choice != 5);

    return 0;
}
