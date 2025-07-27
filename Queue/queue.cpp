#include<iostream>
using namespace std;

class Node{
      public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class Queue{
    Node* front;
    Node* rear;
    public:
    Queue():front(nullptr), rear(nullptr){}
    
    void enqueue(int value){
        Node* newNode = new Node(value);
       if(!rear){
        front = rear = newNode;
       }
       else{
        rear->next = newNode;
        rear = newNode;
       }
    }

    void dequeue(){
        if(!front){
            cout<<"Empty queue.."<<endl;
        }
      Node* temp = front;
      front = front->next;
      delete temp;

      if(!front){
        rear = nullptr;
      }
    }

    int peek(){
        return front->data;
    }

    void display(){
        Node* temp =  front;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;

        }
        cout<<endl;
    }

};

int main(){
    Queue queue;
    queue.enqueue(3);
    queue.enqueue(6);
    queue.enqueue(34);
    queue.enqueue(32);
    queue.enqueue(4);
    queue.enqueue(35);
    queue.enqueue(21);
    queue.enqueue(23);

    queue.display();
    cout<<"Front value:"<<queue.peek()<<endl;
    queue.dequeue();
    queue.display();

}