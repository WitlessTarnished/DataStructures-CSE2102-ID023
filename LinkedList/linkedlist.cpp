#include<iostream>
using namespace std;

class Node{
    public:
    int Data;
    Node * nextNode;

    Node(int data):Data(data),nextNode(nullptr){}

};

class LinkedList{
    private : 
    Node* head;

    public:
    LinkedList():head(nullptr){}
    LinkedList(int* arr, int size):head(nullptr){
    for (size_t i = 0; i < size; i++)
    {
        insertLast(arr[i]);
    }
    
    }
   
    void Display(){
     Node* temp = head;
     while (temp)
     {
        cout<<temp->Data<<" ";
        temp = temp->nextNode;
     }
     cout<<endl;
     
    }

    void insertLast(int value)
    {
        Node *p = new Node(value);
        if (head == nullptr)
        {
            head = p;
            return;
        }

        Node *temp = head;

        while (temp->nextNode)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = p;
    }

    void insertFirst(int value){
     Node* temp = new Node(value);
     temp->nextNode = head;
     head = temp;
    }

    void insertAtIndex(int index, int value){
        if (index==0)
        {
            insertFirst(value);
            return;
        }
        
        Node* p = new Node(value);
        Node* temp = head;
        for (size_t i = 0; i < index -1 && temp ; i++)
        {
          temp = temp->nextNode;
        }

       if (temp == nullptr) return;
        p->nextNode = temp->nextNode;
        temp->nextNode = p;
        
    }

    void Delete(int index){
      if (index == 1)
      {
       Node* p = head;
       head = head->nextNode;
       delete p;
       return;

      } 
      else{
       Node* p = head;
        Node* q = nullptr;
      for (size_t i = 0; i < index - 1 && p ; i++)
      {
       q = p ;
       p = p->nextNode;
      }

      if (p)
      {
        q->nextNode = p->nextNode;
        delete p;
      }
    
    }
}
   
    int length(){
        Node* temp = head;
        int count{0};
        while (temp)
        {
            temp=temp->nextNode;
         count++;
        }
        return count;
        
    }


};

int main(){
    LinkedList list((int[]){1,2,3,4,5},5);
    list.Display();

    list.insertFirst(0);
    list.Display();

    list.insertAtIndex(3,8);
    list.Display();

    list.insertLast(10);
    list.Display();

    cout<<"Length: "<<list.length()<<endl;

    list.Delete(1);
    list.Display();

    cout<<"Length: "<<list.length()<<endl;

 


}