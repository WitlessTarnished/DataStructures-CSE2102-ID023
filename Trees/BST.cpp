#include<iostream>
using namespace std;

class Node{

    public:
    Node* leftChild;
    int data;
    Node* rightChild;
 
    Node(int data):
    leftChild(nullptr),data(data),rightChild(nullptr){}
};

class BST
{
    Node *root;

    Node *insert(Node *node, int value)
    {
        if (!node)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->leftChild = insert(node->leftChild, value);
        }
        else if (value > node->data)
        {
            node->rightChild = insert(node->rightChild, value);
        }
        return node;
    }

    bool search (Node* node, int value){
        if (!node) return false;
        if (node->data == value) return true;
     ( value < node->data )? search(node->leftChild, value): search(node->rightChild, value);
        
    }

  Node* findMin (Node* node){
        while(node && node->leftChild){
         node = node->leftChild;
        }
        return node;
    }

    Node* remove(Node* node, int value){
        if(!node) return nullptr;
        if(value < node->data) node->leftChild = remove(node->leftChild, value);
        else if(value > node->data) node->rightChild = remove(node->rightChild, value);
        else{
            if (!node->leftChild && !node->rightChild){
                delete node;
                return nullptr;
            }else if(!node->leftChild){
                Node* temp = node->rightChild;
                delete node;
                return temp;
            }else if(!node->rightChild){
                Node* temp = node->leftChild;
                delete node;
                return temp;
            }else{
                Node* temp=findMin (node->rightChild);
                node->data = temp->data;
                node->rightChild = remove(node->rightChild,temp->data);
             
            }
        }
        return node;
    }

    void inOrder(Node* node){
        if (!node) return; 
        inOrder(node->leftChild);
        cout<<node->data<<" ";
        inOrder(node->rightChild);
    }
    void preOrder(Node* node){
        if (!node) return;
        cout<<node->data<<" "; 
        preOrder(node->leftChild);
        preOrder(node->rightChild);
    }

     void postOrder(Node* node){
        if (!node) return; 
        postOrder(node->leftChild);
        postOrder(node->rightChild);
        cout<<node->data<<" ";
    }
public:
 BST():root(nullptr){}

   void insert(int value ){
    root = insert(root, value);
   }

   bool search (int value){
   return search(root, value);
   }

   void remove(int value){
    remove(root, value);
   }

  void inOrder() {
        cout << "Inorder: ";
        inOrder(root);
        cout << endl;
    }

    void preOrder() {
        cout << "Preorder: ";
        preOrder(root);
        cout << endl;
    }

    void postOrder() {
        cout << "Postorder: ";
        postOrder(root);
        cout << endl;
    }

};


int main(){
    BST tree;

    int arr[]{20, 40, 31, 12,23,15, 58, 45, 65, 38};
    for(int i : arr){
        tree.insert(i);
    }
    
    tree.inOrder();
    
    tree.remove(20);
    tree.inOrder();
    tree.preOrder();
}