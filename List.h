/*
 * Name: Jackson Champion
 * Date Submitted: 12 Sept 2022
 * Lab Section: 001
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List {

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
 //void print(string);
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  delete start;
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if(mySize == 0) //size() == 0?
    return true;
  else 
    return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> * head = new Node<T>(value);
  
  head->next = start;
  start = head;
  mySize++;

}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> * newNode = new Node<T>(value);
  Node<T> * last = start;
  
  if(start == nullptr) {
    start = newNode;
  }
  else { 
    
    while(last->next != nullptr) {
      last = last->next;
    }
    last->next = newNode; //no next?
  }

  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T> * position = start;
  Node<T> * newNode = new Node<T>(value);

  if(j == 0) {
    insertStart(value);
    return;
  }

  if(j == mySize) {
    insertEnd(value);
    return;
  }
  
  for(int i = 0; i < j-1; i++) {
    position = position->next;
  }

  newNode->next = position->next;
  position->next = newNode;
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  Node<T> * removeNode = start;
  start = start->next;

  if(removeNode->next != nullptr) { 
    delete removeNode;
  }
  
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node<T> * removeNode = start;
  Node<T> * beforeNode = nullptr;

  while(removeNode->next != nullptr) {
    beforeNode = removeNode;
    removeNode = removeNode->next;
  }
  
  delete removeNode;
  beforeNode->next = nullptr;
  mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){

  if(j == 0) {
    removeStart();
  }

  else if(j == mySize - 1) {
    removeEnd();
  }

  else{
    Node<T> * position = start;
    Node<T> * prev = nullptr;

    for(int i = 0; i < j; i++) {
      prev = position;
      position = position->next;
    }
  
    prev->next = position->next;
    delete position;
    mySize--;
  }
}


//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  Node<T> * tail = start;

  while(tail->next != nullptr) {
    tail = tail->next;
  }

  return tail->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node<T> * getNode = start;
  int count = 0;

  while(getNode != nullptr) {
    if(count == j) {
      break;
    }
    count++;
    getNode = getNode->next;
  }
  
  return getNode->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T> * findNode = start;
  int count = 0;

  while(findNode->next != nullptr){
    count++;
    if(findNode->value == key) { 
      break;
    }
    findNode = findNode->next;
  }
  
  if(findNode->value != key) {
    return -1;
  }

  return count - 1;
}
