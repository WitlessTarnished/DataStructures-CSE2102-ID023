#include<iostream>
using namespace std;

class Node{
      public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};

class Stack{
    Node* top;
   public:
   Stack():top(nullptr){}

   void push(int value){
    Node* newNode = new Node(value);
    newNode->next=top;
    top = newNode;
   }
   void pop(){
    if(!top){
        cout<<"Stack is Empty."<<endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
   }

      int peek() {
        if (!top) {
            throw runtime_error("Stack is empty.");
        }
        return top->data;
    }

      void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Stack st;
    st.push(5);
    st.push(10);
    st.push(52);
    st.push(9);
    st.push(2);
    st.push(8);
    st.push(4);

    st.display();
    st.pop();
    st.display();
}