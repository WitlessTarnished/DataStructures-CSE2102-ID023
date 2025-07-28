#include <iostream>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;

            if (table[newIndex] == -1 || table[newIndex] == -2) {
                table[newIndex] = key;
                return;
            }
            i++;
        }

        cout << "Hash table is full, cannot insert " << key << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;

            if (table[newIndex] == -1)
                return false;

            if (table[newIndex] == key)
                return true;

            i++;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;

        while (i < TABLE_SIZE) {
            int newIndex = (index + i * i) % TABLE_SIZE;

            if (table[newIndex] == -1)
                break;

            if (table[newIndex] == key) {
                table[newIndex] = -2; 
                cout << "Key " << key << " deleted.\n";
                return;
            }

            i++;
        }

        cout << "Key " << key << " not found.\n";
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == -1)
                cout << i << " --> [empty]" << endl;
            else if (table[i] == -2)
                cout << i << " --> [deleted]" << endl;
            else
                cout << i << " --> " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(25);
    ht.insert(35);
    ht.insert(15);
    ht.insert(5);

    ht.display();

    cout << "\nSearching 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Searching 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    ht.remove(25);
    ht.remove(99);

    cout << "\nHash Table after deletion:\n";
    ht.display();

    return 0;
}
