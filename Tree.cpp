//
// Created by praist on 2022/11/7.
//

#include "Tree.h"

Node *Tree::getRoot() {
    return root;
}

void Tree::setRoot(Node *root) {
    this->root = root;
}

void Tree::inorderTraverse(Node* root){
    if (root == NULL) {
        return;
    }

    inorderTraverse(root->leftChild);

    if (root->ch != NULL) {
        cout << root->ch << endl;
    }

    inorderTraverse(root->rightChild);
}
