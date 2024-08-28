#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}

    ~List() {
        clear();
    }

    T front() {
        if (empty()) {
            throw runtime_error("La lista está vacía.");
        }
        return head->data;
    }

    T back() {
        if (empty()) {
            throw runtime_error("La lista está vacía.");
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T value) {
        Node<T>* new_node = new Node<T>{value, head};
        head = new_node;
    }

    void push_back(T value) {
        Node<T>* new_node = new Node<T>{value, nullptr};
        if (empty()) {
            head = new_node;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    T pop_front() {
        if (empty()) {
            throw runtime_error("La lista está vacía.");
        }
        T value = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return value;
    }

    T pop_back() {
        if (empty()) {
            throw runtime_error("La lista está vacía.");
        }
        if (head->next == nullptr) {
            T value = head->data;
            delete head;
            head = nullptr;
            return value;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return value;
    }

    T operator[](int index) {
        if (index < 0) {
            throw out_of_range("Índice fuera de rango.");
        }
        Node<T>* temp = head;
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
        Node<T>* temp = head;
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
            Node<T>* temp = head;
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
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
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
    List<int> myList;

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
