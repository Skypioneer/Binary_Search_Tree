// Jason Wang
// File: BST.h
// Date: 10/17/20
// Purpose: Define and implement the class BST

#ifndef P2_BST_H
#define P2_BST_H
#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class BST {
private:
    struct Node {           // create struct Node
        T data;             // value of input
        Node * left;        // pointing to Node's left
        Node * right;       // pointing to Node's right
    };
    Node * root;            // declare Node

    Node * copyConstructor(const Node *);
    // Copy constructor
    // Precondition: receive a reference of Node
    // Postcondition: copy constructor

    void insert(Node *&, Node *&);
    // Insert data to linked list
    // Precondition: receive two references of two Node
    // Postcondition: insert data to linkedList

    bool contains(Node *&, T);
    // Check if data is in the linked list
    // Precondition: receive a reference of Node and type T data
    // Postcondition: return boolean

    void remove(Node *&, T);
    // Remove Node in linked list
    // Precondition: receive a reference of Node and type T data
    // Postcondition: call its helper function and remove the Node
    // that contains the data

    void makeDeletion(Node *&, T);
    // Make decision to delete Node
    // Precondition: receive a reference of Node and type T data
    // Postcondition: delete Node from linkedList

    int size(Node *&);
    // Return the size of the linked list
    // Precondition: receive a reference of Node
    // Postcondition:

    int getLeafCount(Node *&);
    // Return the number of leaves
    // Precondition: receive a reference of Node
    // Postcondition: return the number of leaves

    int getHeight(Node *&);
    // Return the height of the linked list
    // Precondition: receive a reference of Node
    // Postcondition: return the height of the linked list

    int getLevel(Node *&, T, int);
    // Return the level of the linked list
    // Precondition: receive a reference of Node and int variable
    // Postcondition: return the level of the linked list

    void destroyTree(Node *&);
    // Make Node point to nullptr
    // Precondition: receive a reference of Node
    // Postcondition: make Node point to nullptr

    void getPreOrderTraversal(Node *, stringstream &);
    // Return traversal in pre-order
    // Precondition: receive a reference of Node and a reference of
    // stringstream variable
    // Postcondition: return traversal in pre-order

    void getInOrderTraversal(Node *, stringstream &);
    // Return traversal in pre-order
    // Precondition: receive a reference of Node and a reference of
    //stringstream variable
    // Postcondition: return traversal in pre-order

    void getPostOrderTraversal(Node *, stringstream &);
    // Return traversal in in-order
    // Precondition: receive a reference of Node and a reference of
    // stringstream variable
    // Postcondition: return traversal in post-order

    bool getAncestors(Node *, stringstream &, T);
    // Return ancestors of the data
    // Precondition: receive a reference of Node, a reference of stringstream
    // variable, and a type T varuable
    // Postcondition: return ancestors of the data

public:
    BST();
    // Constructor
    // Precondition: none
    // Postcondition: initialize Node head pointing to nullptr

    ~BST();
    // Destructor
    // Precondition: none
    // Postcondition: call its helper function to delete LinkedList

    BST(const BST &);
    // Copy constructor
    // Precondition: receive a reference of BST
    // Postcondition: call its helper function to copy present BST to new BST

    BST& operator=(const BST &);
    // Overload constructor
    // Precondition: receive a reference of BST
    // Postcondition: call its helper function to overload old BST with new BST

    void insert(T);
    // Insert data to linked list
    // Precondition: receive a type T data
    // Postcondition: call its helper function to insert data to linkedList

    bool contains(T);
    // Check if data is in the linked list
    // Precondition: receive a type T data
    // Postcondition: call its helper function to return boolean

    void remove(T);
    // Remove Node in linked list
    // Precondition: receive a type T data
    // Postcondition: call its helper function to remove the Node that
    //contains the data

    bool empty();
    // Check if the linked list is empty
    // Precondition: none
    // Postcondition: return boolean

    int size();
    // Return the size of the linked list
    // Precondition: none
    // Postcondition: call its helper function to return size of the linked list

    int getLeafCount();
    // Return the number of leaves
    // Precondition: none
    // Postcondition: call its helper function to return the number of leaves

    int getHeight();
    // Return the height of the linked list
    // Precondition: none
    // Postcondition: call its helper function to return the height
    // of the linked list

    int getLevel(T);
    // Return the level of the linked list
    // Precondition: none
    // Postcondition: call its helper function to return the level of
    // the linked list

    string getPreOrderTraversal();
    // Return traversal in pre-order
    // Precondition: none
    // Postcondition: call its helper function to return traversal in pre-order

    string getInOrderTraversal();
    // Return traversal in in-order
    // Precondition: none
    // Postcondition: call its helper function to return traversal in in-order

    string getPostOrderTraversal();
    // Return traversal in post-order
    // Precondition: none
    // Postcondition: call its helper function to return traversal in post-order

    string getAncestors(T);
    // Return ancestors of the data
    // Precondition: receive a type T data
    // Postcondition: call its helper function to return ancestors of the data
};

template <typename T>
BST<T>::BST(){
    root = nullptr;
}

template <typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template <typename T>
void BST<T>::destroyTree(Node *&ptr) {
    if (ptr != nullptr) {
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }
    ptr = nullptr;
}

template <typename T>
BST<T>::BST(const BST &obj) {
    root = copyConstructor(obj.root);
}

template <typename T>
BST<T>& BST<T>::operator=(const BST<T> &obj) {
    if (this != obj){
        destroyTree(root);
        root = copyConstructor(obj.root);
    }
    return *this;
}

template <typename T>
typename BST<T>::Node * BST<T>::copyConstructor(const Node * objPtr) {
    if (objPtr == nullptr)
        return nullptr;
    else{
        Node * newPtr = new Node;
        newPtr->data = objPtr->data;
        newPtr->left = copyConstructor(objPtr->left);
        newPtr->right = copyConstructor(objPtr->right);

        return newPtr;
    }
}

template <typename T>
void BST<T>::insert(T item) {
    Node * newNode = new Node;
    newNode->data = item;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template <typename T>
void BST<T>::insert(Node *& ptr, Node *& newNode) {
    if (ptr == nullptr)
        ptr = newNode;
    else if (ptr->data > newNode->data)
        insert(ptr->left, newNode);
    else
        insert(ptr->right, newNode);
}

template <typename T>
bool BST<T>::contains(T item) {
    return contains(root, item);
}

template <typename T>
bool BST<T>::contains(Node *& ptr, T item) {
    if (ptr == nullptr)
        return false;

    if (ptr->data == item)
        return true;
    else if (ptr->data > item)
        return contains(ptr->left, item);
    else
        return contains(ptr->right, item);
}

template <typename T>
void BST<T>::remove(T item) {
    remove(root, item);
}

template <typename T>
void BST<T>::remove(Node *& ptr, T item) {
    if (ptr != nullptr) {
        if (ptr->data > item)
            remove(ptr->left, item);
        else if (ptr->data < item)
            remove(ptr->right, item);
        else
            makeDeletion(ptr, item);
    }
}

template <typename T>
void BST<T>::makeDeletion(Node *& ptr, T item) {
    Node * curr = nullptr;
    if (ptr != nullptr) {
        if (ptr->left == nullptr) {
            curr = ptr;
            ptr = ptr->right;
            delete curr;
        } else if (ptr->right == nullptr) {
            curr = ptr;
            ptr = ptr->left;
            delete curr;
        } else {
            curr = ptr->right;
            while (curr->left != nullptr)
                curr = curr->left;
            ptr->data = curr->data;
            remove(ptr->right, curr->data);
        }
    }
}

template <typename T>
bool BST<T>::empty() {
    return root == nullptr;
}

template <typename T>
int BST<T>::size() {
    return size(root);
}

template<typename T>
int BST<T>::size(Node *& ptr) {
    if (ptr == nullptr)
        return 0;
    else{
        int count = 1;
        count += size(ptr->left);
        count += size(ptr->right);

        return count;
    }
}

template <typename T>
int BST<T>::getLeafCount(){
    return getLeafCount(root);
}

template <typename T>
int BST<T>::getLeafCount(Node *& ptr) {
    if (ptr == nullptr)
        return 0;
    else {
        if (ptr->left == nullptr && ptr->right == nullptr)
            return 1;
        else
            return getLeafCount(ptr->left) + getLeafCount(ptr->right);
    }
}

template <typename T>
int BST<T>::getHeight() {
    return getHeight(root);
}

template<typename T>
int BST<T>::getHeight(Node *& ptr) {
    if (ptr == nullptr)
        return 0;
    else {
        int left = getHeight(ptr->left);
        int right = getHeight(ptr->right);

        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

template <typename T>
int BST<T>::getLevel(T item) {
    return getLevel(root, item, 0);
}

template <typename T>
int BST<T>::getLevel(Node *& ptr, T item, int count) {
    int level = 0;

    if (!contains(item))
        return -1;

    if (ptr->data == item)
        return count;
    else if (ptr-> data < item)
        level += getLevel(ptr->right, item, count + 1);
    else if (ptr-> data > item)
        level += getLevel(ptr->left, item, count + 1);

    return level;
}

template <typename T>
string BST<T>::getInOrderTraversal() {
    stringstream ss;
    getInOrderTraversal(root, ss);
    return ss.str();
}

template <typename T>
void BST<T>::getInOrderTraversal(Node * ptr, stringstream &ss) {
    if (ptr != nullptr) {
        getInOrderTraversal(ptr->left, ss);
        ss << ptr->data << " ";
        getInOrderTraversal(ptr->right, ss);
    }
}

template <typename T>
string BST<T>::getPreOrderTraversal() {
    stringstream ss;                    // variable holding data
    getPreOrderTraversal(root, ss);
    return ss.str();
}

template <typename T>
void BST<T>::getPreOrderTraversal(Node * ptr, stringstream &ss) {
    if (ptr != nullptr) {
        ss << ptr->data << " ";
        getPreOrderTraversal(ptr->left, ss);
        getPreOrderTraversal(ptr->right, ss);
    }
}

template <typename T>
string BST<T>::getPostOrderTraversal() {
    stringstream ss;                    // variable holding data
    getPostOrderTraversal(root, ss);
    return ss.str();
}

template<typename T>
void BST<T>::getPostOrderTraversal(Node * ptr, stringstream &ss) {
    if (ptr != nullptr) {
        getPostOrderTraversal(ptr->left, ss);
        getPostOrderTraversal(ptr->right, ss);
        ss << ptr->data << " ";
    }
}

template <typename T>
string BST<T>::getAncestors(T item) {
    stringstream ss;                    // variable holding data
    getAncestors(root, ss, item);
    return ss.str();
}

template <typename T>
bool BST<T>::getAncestors(Node * ptr, stringstream & ss, T item) {
    if(ptr == nullptr) {
        return false;
    }
    if(ptr->data == item) {
        return true;
    }
    if((getAncestors(ptr->left, ss, item)) || (getAncestors(ptr->right,ss,
                                                            item))) {
        ss << ptr->data << " ";
        return true;
    }
    return false;
}

#endif //P2_BST_H
