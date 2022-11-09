//
// Created by praist on 2022/11/7.
//

#include "Node.h"

bool Node::isLeaf() {
    return leftChild == NULL && rightChild == NULL;
}

bool Node::isRoot() {
    return parent == NULL;
}

bool Node::isLeftChild() {
    return parent != NULL && this == this->parent->leftChild;
}
