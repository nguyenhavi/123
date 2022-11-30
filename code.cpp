#include <iostream>
#include <math.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(const int &data){this->data = data;this->left = NULL; this->right = NULL;}
};

class BinarySearchTree{
    private:
        Node* root;
    protected:
        int getSizeRec(Node*);
        int getHeightRec(Node*);
        bool addRec(Node*&, const int&);
        bool removeRec(Node*&, const int&);
        int getHeight1(Node*);
    public:
        BinarySearchTree(){
            this->root = NULL;
        }
        int getSize();
        int getHeight();
        bool add(const int &value);
        bool remove(const int &value);
        void preOrder();
};

int BinarySearchTree::getSizeRec(Node* node){
    if (node == NULL){return 0;}
    return 1 + getSizeRec(node->left) + getSizeRec(node->right);
}

int BinarySearchTree::getSize(){
    return getSizeRec(root);
}

int BinarySearchTree::getHeightRec(Node* node) {
    if (node == NULL){return 0;}
    return 1 + max(getHeightRec(node->left),getHeightRec(node->right));
}

int BinarySearchTree::getHeight(){
    return getHeightRec(root);
}

bool BinarySearchTree::addRec(Node* &node, const int &value){
    if (node == NULL){
        node = new Node(value);
        return 1;
    }
    else {
        if (value < node->data){
            return addRec(node->left, value);
        }
        else if (value > node->data){
            return addRec(node->right, value);
        }
        return 0;
    }
}

bool BinarySearchTree::add(const int &value){
    return addRec(root, value);
}

bool BinarySearchTree::removeRec(Node* &node, const int &value){
    if (node == NULL){
        return 0;
    }
    if (value < node->data){
        return removeRec(node->left, value);
    }
    else if (value > node->data){
        return removeRec(node->right, value);
    }
    else {
        if (node->left == NULL){
            Node* dltPtr = node;
            node = node->right;
            delete(dltPtr);
            return true;
        }
        else if (root->right == NULL){
            Node* dltPtr = node;
            node = node->left;
            delete(dltPtr);
            return true;
        }
        else {
            Node* dltPtr = node->left;
            while (dltPtr->right != NULL){
                dltPtr = dltPtr->right;
            }
            node->data = dltPtr->data;
            return removeRec(node->left, dltPtr->data);
        }
    }
}

bool BinarySearchTree::remove(const int &value){
    return removeRec(root, value);
}



int main (){
    BinarySearchTree a;
    int val[9] = {5,2,-4,3,17,9,21,19,25};
    for (int i = 0; i < 9; i++){
        a.add(val[i]);
    }
    cout << a.getHeight();
    return 0;
}