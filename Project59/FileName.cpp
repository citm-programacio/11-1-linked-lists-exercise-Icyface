#include <iostream>
using namespace std;

class List {
public:
    // Constructor y destructor
    List() : first(nullptr), last(nullptr), num_elems(0) {}
    ~List() { clear(); }

    // Modificadores
    void push_back(const int& value) {
        Node* newNode = new Node{ value, nullptr, last };
        if (last) {
            last->next = newNode;
        }
        else {
            first = newNode;
        }
        last = newNode;
        num_elems++;
    }

    void insert(unsigned int position, const int& value) {
        if (position > num_elems) {
            cout << "Error: posición fuera de rango.\n";
            return;
        }

        Node* newNode = new Node{ value, nullptr, nullptr };

        if (position == 0) {
            // Insertar al inicio
            newNode->next = first;
            if (first) {
                first->prev = newNode;
            }
            else {
                last = newNode;
            }
            first = newNode;
        }
        else if (position == num_elems) {
            // Insertar al final
            push_back(value);
            return;
        }
        else {
            // Insertar en el medio
            Node* current = first;
            for (unsigned int i = 0; i < position; ++i) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }

        num_elems++;
    }

    void print() {
        Node* current = first;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Métodos no implementados pero necesarios para evitar errores
    void clear() {
        while (first) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
        last = nullptr;
        num_elems = 0;
    }

private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
    };

    Node* first;
    Node* last;
    unsigned int num_elems;
};

int main() {
    List list;

    // Insertar elementos en posiciones específicas y mostrar el estado de la lista
    list.push_back(10);         // Lista: 10
    list.print();

    list.insert(0, 5);          // Insertar 5 al inicio: 5 10
    list.print();

    list.insert(2, 15);         // Insertar 15 al final: 5 10 15
    list.print();

    list.insert(1, 7);          // Insertar 7 en la posición 1: 5 7 10 15
    list.print();

    list.insert(3, 12);         // Insertar 12 en la posición 3: 5 7 10 12 15
    list.print();

    return 0;
}
