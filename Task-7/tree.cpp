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
    if (*root == NULL){
        Node *newNode = new Node;

        newNode->data = newData;
        newNode->left = NULL;
        newNode->right = NULL;

        *root = newNode;

        cout << "Data has been added\n";
    }
    else if (newData < (*root)->data){
        insert(&((*root)->left), newData);
    }
    else if (newData > (*root)->data){
        insert(&((*root)->right), newData);
    }
    else if (newData == (*root)->data){
        cout << "Data is already exist\n";
    }
}

void preOrder(Node *root){
    if (root == NULL) return;

    cout << root->data << " ";  // Root
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";  // Root
    inOrder(root->right);
}

void postOrder(Node *root){
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";  // Root
}

void printTree(Node *root, int space = 0){
    if (root == NULL) return;

    space += 5;

    printTree(root->right, space);

    cout << endl;
    for (int i = 0; i < space; i++) cout << " "; 
    cout << root->data << endl;

    printTree(root->left, space);
}

int main(){
    int opt, val;
    Node *tree = NULL;

    do {
        system("cls");

        cout << "1. Insert\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Print Tree\n";
        cout << "6. Exit\n";

        cout << "\nOption: "; cin >> opt;

        switch (opt) {

            case 1:
                cout << "\n Input:" << endl;
                cout << "---------" << endl;
                cout << "New data: "; cin >> val;
                insert(&tree, val);
                break;

            case 2:
                cout << "PreOrder Traversal\n";
                cout << "==========================\n";
                if (tree == NULL) {
                    cout << "Tree is empty!\n";
                }
                else {
                    preOrder(tree);
                    cout << endl;
                }
                break;

            case 3:
                cout << "InOrder Traversal\n";
                cout << "==========================\n";
                if (tree == NULL) {
                    cout << "Tree is empty!\n";
                }
                else {
                    inOrder(tree);
                    cout << endl;
                }
                break;

            case 4:
                cout << "PostOrder Traversal\n";
                cout << "==========================\n";
                if (tree == NULL) {
                    cout << "Tree is empty!\n";
                }
                else {
                    postOrder(tree);
                    cout << endl;
                }
                break;

            case 5:
                cout << "Print Tree\n";
                cout << "==========================\n";
                if (tree == NULL) {
                    cout << "Tree is empty!\n";
                }
                else {
                    printTree(tree);
                }
                break;

            case 6:
                return 0;

            default:
                cout << "Option is not valid! Please re-enter your option.";
                break;
        }

        getch();

    } while (opt != 6);

    return 0;
}

