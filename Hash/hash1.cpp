#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Node* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->data < key) {
            prev = current;
            current = current->next;
        }

        if (prev == nullptr) {
            newNode->next = table[index];
            table[index] = newNode;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Key " << key << " not found.\n";
            return;
        }

        if (prev == nullptr)
            table[index] = current->next; 
        else
            prev->next = current->next;

        delete current;
        cout << "Key " << key << " deleted.\n";
    }

  
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " --> ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(20);
    ht.insert(10);
    ht.insert(30);
    ht.insert(25);
    ht.insert(15);
    ht.insert(35);

    cout << "Hash Table:\n";
    ht.display();

    cout << "\nSearching 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Searching 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    ht.remove(25);
    ht.remove(99); 

    cout << "\nHash Table after deletions:\n";
    ht.display();

    return 0;
}
