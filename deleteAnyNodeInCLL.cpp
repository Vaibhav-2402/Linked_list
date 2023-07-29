#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
    
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }
    cout << " the memory has been freed for : " << value;
    cout << endl;
    }
};

void insertNode(Node* &tail, int d, int element) {
    //empty list
    if(tail == NULL){
        Node* nodeToInsert = new Node(d);
        tail = nodeToInsert;
        nodeToInsert -> next = nodeToInsert;
    }
    else {
        Node* curr = tail;

        while(curr -> data != element) {
            curr = curr -> next;
        }
         Node* newNode = new Node(d);
         newNode -> next = curr -> next;
         curr -> next = newNode;
    }
}

void deleteNode(Node* &tail, int value){
  //Empty List
  if(tail == NULL){
      cout << "the list is already empty !!! "<< endl;
  }
  else {
      Node* prev = tail;
      Node* curr = prev -> next;
      
      while(curr -> data != value){
          prev = curr;
          curr = curr -> next;
      }
      if(tail == curr){
          tail = prev;
      }
      
      if(curr == prev) {
          tail = NULL;
      }
      prev -> next = curr -> next;
      curr -> next = NULL;
      delete curr;
  }
}

void print(Node* tail) {
    
    if(tail == NULL) {
        cout <<  "the list is empty " << endl;
        return;
    }
    Node* temp = tail;
    
    do {
        cout << tail -> data << "  ";
        tail = tail -> next;
    } while(tail != temp);
    
    cout << endl;
}

int main() {
    
    Node* tail = NULL;
    insertNode(tail, 45, 23);
    print(tail);
    
    insertNode(tail, 55, 45);
    print(tail);
    
    insertNode(tail, 65, 55);
    print(tail);
    
    insertNode(tail, 75, 65);
    print(tail);
    
    deleteNode(tail, 45);
    print(tail);
    
    return 0;
}