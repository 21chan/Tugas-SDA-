#include <iostream>
using namespace std;

class Node {
public:
    char id;
    Node* next;

    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = NULL;
    }

    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == NULL) {
            head = tail = node;
        } else {
            Node* tmp = head;
            head = node;
            node->next = tmp;
        }
    }

    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void insertNodeAfter(char data, char after) {
        if (head == NULL) {
            cout << "Tidak Ada Data, Tidak Bisa Mengisi Data di tengah" << endl;
        } else {
            Node* node = new Node();
            node->id = data;

            Node* tmp = head;
            while (tmp != NULL && tmp->id != after) {
                tmp = tmp->next;
            }

            if (tmp == NULL) {
                cout << "After node is not found" << endl;
            } else {
                node->next = tmp->next;
                tmp->next = node;
                if (tmp == tail) {
                    tail = node;
                }
            }
        }
    }

    void printALL() {
        if (head != NULL) {
            Node* tmp = head;
            do {
                cout << tmp->id << "->";
                tmp = tmp->next;
            } while (tmp != NULL);
            cout << "NULL" << endl;
        }
    }

    void deleteHead() {
        if (head != NULL) {
            Node* remove = head;
            head = head->next;
            delete remove;
            if (head == NULL) {
                tail = NULL;
            }
        }
    }

    void deleteTail() {
        if (head != NULL) {
            if (head == tail) {
                delete head;
                head = tail = NULL;
            } else {
                Node* tmp = head;
                while (tmp->next != tail) {
                    tmp = tmp->next;
                }
                delete tail;
                tail = tmp;
                tail->next = NULL;
            }
        }
    }
};

int main(int argc, char** argv) {
    LinkedList* link1 = new LinkedList();

    Node* node1 = new Node();
    node1->id = 'A';
    link1->head = node1;
    link1->tail = node1;
    Node* nodeX = new Node();
    nodeX->id = 'X';

    Node* tmp = link1->head;
    link1->head = nodeX;
    nodeX->next = tmp;

    link1->insertToHead('Y');
    link1->insertNodeAfter('Z', 'X');
    

    cout << link1->head->id << endl;
    cout << link1->tail->id << endl;

    link1->printALL();

    link1->deleteTail();
    link1->deleteHead();
    link1->printALL();

    return 0;
}
