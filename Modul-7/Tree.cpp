#include <iostream>
#include <conio.h>   
#include <stdlib.h> 
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert(Node **root, int newData){
    if (*root == nullptr){
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->left = nullptr;
        newNode->right = nullptr;
        *root = newNode;
        cout << "Data has been added\n";
    }
    else if (newData < (*root)->data){
        insert(&((*root)->left), newData);
    }
    else if (newData > (*root)->data){
        insert(&((*root)->right), newData);
    }
    else {
        cout << "Data is already exist\n";
    }
}

void printTreeWithBranches(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "         " << root->data << endl;

    if (root->left || root->right) {
        cout << "       ";
        if (root->left) cout << "/"; else cout << " ";
        cout << "   ";
        if (root->right) cout << "\\"; else cout << " ";
        cout << endl;
    }

    cout << "     ";
    if (root->left) cout << root->left->data; else cout << " ";
    cout << "       ";
    if (root->right) cout << root->right->data; else cout << " ";
    cout << endl;

    if ((root->left && (root->left->left || root->left->right)) ||
        (root->right && (root->right->left || root->right->right))) {
        cout << "   ";
        if (root->left && root->left->left) cout << "/"; else cout << " ";
        cout << "   ";
        if (root->left && root->left->right) cout << "\\"; else cout << " ";
        cout << "   ";
        if (root->right && root->right->left) cout << "/"; else cout << " ";
        cout << "   ";
        if (root->right && root->right->right) cout << "\\"; else cout << " ";
        cout << endl;
    }

    cout << "   ";
    if (root->left && root->left->left) cout << root->left->left->data; else cout << " ";
    cout << "   ";
    if (root->left && root->left->right) cout << root->left->right->data; else cout << " ";
    cout << "   ";
    if (root->right && root->right->left) cout << root->right->left->data; else cout << " ";
    cout << "   ";
    if (root->right && root->right->right) cout << root->right->right->data; else cout << " ";
    cout << endl;
}

void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(Node *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}


void freeTree(Node *root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    int opt, val;
    Node *tree = nullptr;

    do {
        system("cls"); 

        cout << "Visual Tree Structure\n==========================\n";
        printTreeWithBranches(tree);

        cout << "\n==========================\n";
        cout << "1. Insert\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";

        cout << "\nOption: ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "\nNew data: ";
                cin >> val;
                insert(&tree, val);
                break;
            case 2:
                cout << "\nPreOrder Traversal:\n";
                preOrder(tree);
                cout << endl;
                break;
            case 3:
                cout << "\nInOrder Traversal:\n";
                inOrder(tree);
                cout << endl;
                break;
            case 4:
                cout << "\nPostOrder Traversal:\n";
                postOrder(tree);
                cout << endl;
                break;
            case 5:
                freeTree(tree);
                cout << "Memory cleared. Exiting program.\n";
                return 0;
            default:
                cout << "Invalid option.\n";
                break;
        }

        cout << "\nPress any key to continue...";
        getch(); 
    } while (opt != 5);

    return 0;
}
