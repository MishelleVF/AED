#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        clear();
    }

    int front() {
        return head->data;
    }

    int back() {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(int value) {
        Node* new_node = new Node{value, head};
        head = new_node;
    }

    void push_back(int value) {
        Node* new_node = new Node{value, nullptr};
        if (empty()) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    int pop_front() {
        int value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return value;
    }

    int pop_back() {
        if (head->next == nullptr) {
            int value = head->data;
            delete head;
            head = nullptr;
            return value;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        int value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return value;
    }

    int operator[](int index) {
        if (index < 0) {
            throw out_of_range("Índice fuera de rango.");
        }
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            if (temp == nullptr) {
                throw out_of_range("Índice fuera de rango.");
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            throw out_of_range("Índice fuera de rango.");
        }
        return temp->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void sort() {
        if (empty() || head->next == nullptr) {
            return;
        }
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next != nullptr) {
                if (temp->data > temp->next->data) {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main() {
    List myList;

    myList.push_back(5);
    myList.push_back(3);
    myList.push_back(8);
    myList.push_back(1);

    cout << "Lista original: ";
    for (int i = 0; i < myList.size(); ++i) {
        cout << myList[i] << " ";
    }
    cout << endl;

    myList.sort();
    cout << "Lista ordenada: ";
    for (int i = 0; i < myList.size(); ++i) {
        cout << myList[i] << " ";
    }
    cout << endl;

    myList.reverse();
    cout << "Lista invertida: ";
    for (int i = 0; i < myList.size(); ++i) {
        cout << myList[i] << " ";
    }
    cout << endl;

    return 0;
}
