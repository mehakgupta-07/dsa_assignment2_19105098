#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node{
    
public:
  int data;
  Node *next;
  Node *prev;
  
  // Constructor for creating a node.
  Node(int data){
    this->data = data;
    prev = NULL;
    next = NULL;
  }
  
  // Creating a node with prev and next node given 
  Node(int data, Node *prev, Node *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
  }
};

class DoublyLinkedList{
public:
  Node *head;
  Node *tail;
  
  DoublyLinkedList(Node *head, Node *tail){
    this->head = head;
    this->tail = tail;
  }
  void insertNode(int data, int index){
      
    Node *temp = head;
    Node *prev;
    while (temp != NULL && index--){
      prev = temp;
      temp = temp->next;
    }
    Node *node = new Node(data);
    if (temp != NULL){
      if (temp != head)
        temp->prev->next = node;
      node->prev = temp->prev;
      temp->prev = node;
      node->next = temp;
      if (temp == head)
        head = node;
    }
    else{
      prev->next = node;
      node->prev = prev;
      tail = node;
    }
  }

  void printList(){
    Node *temp = head;
    if (temp == NULL){
      cout << "Empty List" << endl;
    }
    while (temp != NULL){
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void deleteNode(int position){
    Node *temp = head;
    // while loop to traverse to the specified node to delete;
    while (temp != NULL && position--){
        temp = temp->next;
    }
    if(temp== NULL){
        cout<<"Index out of bounds for Linked List"<<endl;
        return;
    }

    // If the node to be deleted is head, we have to update head.
    if (temp != NULL){
      if (temp == head){
        head = head->next;
        head->prev = NULL;
      }
      
      // If it is the last node, we have to update tail.
      else if (temp->next == NULL){
        tail = tail->prev;
        tail->next = NULL;
      }
      
      // If it is any node in between, we have to update its previous node's and next node's pointers.
      else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
      }

      delete temp;
    }
  }
};

int main(){
  // Initializing the doubly linked list with a single node having data 1;
  Node *n = new Node(1);
  DoublyLinkedList l(n, n);

  // Adding two new nodes having data 2 and 3;
  l.insertNode(2, 1);
  l.insertNode(3, 2);
  l.insertNode(4, 3);

  // Linked List initially would look like 1 -> 2 -> 3 -> 4;

  cout << "Initial linked list : " << endl;
  l.printList();
  int input1;
  cout << "Enter index of node to be deleted: " << endl;
  cin >> input1;
  l.deleteNode(input1);

  // Printing updated linked list
  cout << endl;
  cout << "Updated linked list : " << endl;
  l.printList();
}