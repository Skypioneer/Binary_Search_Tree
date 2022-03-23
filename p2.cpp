// Jason Wang
// File: p2.cpp
// Date: 10/18/20
// Purpose: The program tests insert, contains, remove, empty, size,
//          getLeafCount, getHeight, getLevel, getInOrderTraversal,
//          getPreOrderTraversal, getPostOrderTraversal, and getAncestors of
//          BST functions

#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

void integerBST();
// Print the integer sign out
// IN: none
// MODIFY: none
// OUT: integer sign

void stringBST();
// Print the string sign out
// IN: none
// MODIFY: none
// OUT: string sign

void welcome();
// Print the welcome message out
// IN: none
// MODIFY: none
// OUT: welcome message

void goodBye();
// Print the goodBye message out
// IN: none
// MODIFY: none
// OUT: goodBye message


string empty(bool);
// Check if linked list is empty
// IN: boolean from linked list
// MODIFY: check if linked list is empty
// OUT: true or false

string contains(bool);
// Check if the Node is in linked list
// IN: boolean from linked line
// MODIFY: check if Node is in linked list
// OUT: true or false

template<typename T>
void readInIntegerFile(BST<T> &, int[], int &);
// Read in integer file and populate data to BST and array
// IN: reference of BST, array, and reference of variable count
// MODIFY: populate data to BST and array
// OUT: none

template<typename T>
void readInStringFile(BST<T> &, string[], int &);
// Read in string file and populate data to BST and array
// IN: reference of BST, array, and reference of variable count
// MODIFY: populate data to BST and array
// OUT: none

template<typename T>
void createBST(BST<T> &);
// Print information of linked list out
// IN: reference of BST
// MODIFY: call function to print information of linkded list
// OUT: information of linked list

template<typename T>
void testInsert(BST<T> &);
// Print data and information of linked list out
// IN: reference of BST
// MODIFY: call function to print information of linked list
// OUT: data and information of linked list

template<typename T>
void testTraversals(BST<T> &);
// Print pre, in, post order of linked list
// IN: reference of BST
// MODIFY: print pre, in, post order of reference
// OUT: pre, in, post order of linked list

template <typename T>
void testLevelAncestors(BST<T> &, T[], int &);
// Print ancestors of the input Node
// IN: reference of BST, type T array, reference of int variable
// MODIFY: print ancestors of the input Node
// OUT: ancestors of the input Node

template <typename T>
void testContains(BST<T> &, const T[], const int &);
// Check if the Node in the linked list
// IN: reference of BST, type T array, reference of int variable
// MODIFY: check if the Node in the linked list
// OUT: if the Node is in the linked list
// OUT: if the Node is in the linked list

template <typename T>
void testRemove(BST<T> &, const T[], const int &);
// Remove Node in the linked list
// IN: reference of BST, type T array, reference of int variable
// MODIFY: remove Node in the linked list
// OUT: none

template<typename T>
void testInsertAgain(BST<T> &, const T[], const int &);
// Insert Node in linked list and print data and information of linked list out
// IN: reference of BST, type T array, reference of int variable
// MODIFY: Insert Node in linked list and call function to print information
// of linked list
// OUT: data and information of linked list

int main() {
    const int SIZE = 8;                 // size of array
    int countInteger = 0;               // initiate integer count to 0
    int countString = 0;                // initiate string count to 0
    BST<int> linkedListInteger;         // create integer BST
    BST<string> linkedListString;       // create string BST
    int integerArray[SIZE];             // create integer array
    string stringArray[SIZE];           // create string array

    // create integer array populated integer data
    int otherInteger[SIZE]= {20, 40, 10, 70, 99, -2, 59, 43};

    // create string array populated string data
    string otherString[SIZE] {"gene", "mary", "bea", "uma", "yan", "amy",
                              "ron", "opal"};

    welcome();

    integerBST();
    createBST(linkedListInteger);
    readInIntegerFile(linkedListInteger, integerArray, countInteger);
    testInsert(linkedListInteger);
    testTraversals(linkedListInteger);
    testLevelAncestors(linkedListInteger, integerArray, countInteger);
    testContains(linkedListInteger, otherInteger, SIZE);
    testRemove(linkedListInteger, otherInteger, SIZE);
    testInsertAgain(linkedListInteger, otherInteger, SIZE);

    stringBST();
    createBST(linkedListString);
    readInStringFile(linkedListString, stringArray, countString);
    testInsert(linkedListString);
    testTraversals(linkedListString);
    testLevelAncestors(linkedListString, stringArray, countString);
    testContains(linkedListString, otherString, SIZE);
    testRemove(linkedListString, otherString, SIZE);
    testInsertAgain(linkedListString, otherString, SIZE);

    goodBye();

    return 0;
}

void integerBST(){
    cout << "******************************" << endl;
    cout << "* INTEGER BINARY SEARCH TREE *" << endl;
    cout << "******************************" << endl;
}

void stringBST(){
    cout << "********************" << endl;
    cout << "* test string BST  *" << endl;
    cout << "********************" << endl;
}

void welcome(){
    cout << "Welcome to implement BST program!\nThe program tests insert, "
            "contains, remove, empty, size, getLeafCount,\ngetHeight, "
            "getLevel, getInOrderTraversal, getPreOrderTraversal,\n"
            "getPostOrderTraversal and getAncestors of BST "
            "functions.\n" << endl;
}

void goodBye(){
    cout << "Thank you for using BST program. GoodBye~";
}

template<typename T>
void createBST(BST<T> & linkedList){
    cout << "** CREATE BST **" << endl;
    cout << "# of nodes:  " << linkedList.size() << endl;
    cout << "# of leaves: " << linkedList.getLeafCount() << endl;
    cout << "BST height:  " << linkedList.getHeight() << endl;
    cout << "BST empty?   " << empty(linkedList.empty()) << endl << endl;
}

string empty(bool empty){
    if (empty)
        return "true";
    else
        return "false";
}

template<typename T>
void readInIntegerFile(BST<T> & linkedList, int array[], int & count){
    string fileName, line;      // variables holding file name and data
    int number;                 // variable holding data in type integer
    ifstream infile;            // file variable

    cout << "Enter integer file: ";
    cin >> fileName;

    infile.open(fileName);

    // read in the file and populate data into linked list and array
    if (infile){
        while (infile >> line){
            number = stoi(line);
            linkedList.insert(number);
            array[count] = number;
            count++;
        }
    }
    else
        cout << "Error opening file...\n";

    infile.close();
}


template<typename T>
void readInStringFile(BST<T> & linkedList, string array[], int & count){
    string fileName, line;      // variables holding file name and data
    ifstream infile;            // file variable

    cout << "Enter integer file: ";
    cin >> fileName;

    infile.open(fileName);

    // read in the file and populate data into linked list and array
    if (infile){
        while (getline(infile, line)){
            linkedList.insert(line);
            array[count] = line;
            count++;
        }
    }
    else
        cout << "Error opening file...\n";

    infile.close();
}

template<typename T>
void testInsert(BST<T> & linkedList){
    cout << "\n** TEST INSERT **" << endl;
    cout << "Inserting in this order: "
         << linkedList.getPreOrderTraversal() << endl;
    cout << "# of nodes:  " << linkedList.size() << endl;
    cout << "# of leaves: " << linkedList.getLeafCount() << endl;
    cout << "tree height: " << linkedList.getHeight() << endl;
    cout << "tree empty?  " << empty(linkedList.empty()) << endl;
}

template<typename T>
void testTraversals(BST<T> & linkedList){
    cout << "\n** TEST TRAVERSALS **" << endl;
    cout << "pre-order:  " << linkedList.getPreOrderTraversal() << endl;
    cout << "in-order:   " << linkedList.getInOrderTraversal() << endl;
    cout << "post-order: " << linkedList.getPostOrderTraversal() << endl;
}

template<typename T>
void testLevelAncestors(BST<T> & linkedList, T array[], int & count){
    cout << "\n** TEST LEVEL & ANCESTORS **" << endl;

    for (int i = 0; i < count; i++){
        cout << "level(" << array[i] << "): " << linkedList.getLevel(array[i])
             << ", ancestors(" << array[i] << "): "
             << linkedList.getAncestors(array[i]) << endl;
    }
}

template<typename T>
void testContains(BST<T> & linkedList, const T array[], const int & size){
    cout << "\n** TEST CONTAINS **" << endl;

    for (int k = 0; k < size; k++){
        cout << "contains(" << array[k] << "): "
             << contains(linkedList.contains(array[k])) << endl;
    }
}

string contains(bool contains){
    if (contains)
        return "true";
    else
        return "false";
}

template<typename T>
void testRemove(BST<T> & linkedList, const T array[], const int & size){
    cout << "\n** TEST REMOVE **" << endl;
    cout << "Removing in the order: ";
    for (int k = 0; k < size; k++) {
        cout << array[k] << " ";
        if (k == size - 1)
            cout << endl;
    }

    for (int i = 0; i < size; i++)
        linkedList.remove(array[i]);

    cout << "# of nodes:  " << linkedList.size() << endl;
    cout << "# of leaves: " << linkedList.getLeafCount() << endl;
    cout << "tree height: " << linkedList.getHeight() << endl;
    cout << "tree empty:  " << empty(linkedList.empty()) << endl;
    cout << "pre-order:   " << linkedList.getPreOrderTraversal() << endl;
    cout << "in-order:    " << linkedList.getInOrderTraversal() << endl;
    cout << "post-order   " << linkedList.getPostOrderTraversal() << endl;
}

template <typename T>
void testInsertAgain(BST<T> & linkedList, const T array[], const int & size){
    cout << "\n** TEST INSERT (again) **" << endl;
    cout << "Inserting in this order: ";
    for (int k = 0; k < size; k++) {
        cout << array[k] << " ";
        if (k == size - 1)
            cout << endl;
    }

    for (int i = 0; i < size; i++)
        linkedList.insert(array[i]);

    cout << "# of nodes:  " << linkedList.size() << endl;
    cout << "# of leaves: " << linkedList.getLeafCount() << endl;
    cout << "tree height: " << linkedList.getHeight() << endl;
    cout << "tree empty?  " << empty(linkedList.empty()) << endl;
    cout << "pre-order:  " << linkedList.getPreOrderTraversal() << endl;
    cout << "in-order:   " << linkedList.getInOrderTraversal() << endl;
    cout << "post-order: " << linkedList.getPostOrderTraversal()
         << endl << endl;
}