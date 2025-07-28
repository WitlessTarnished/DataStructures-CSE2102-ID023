#include <iostream>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                cout << "Hash table is full, cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex)
                break;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << "Key " << key << " deleted.\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex)
                break;
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
