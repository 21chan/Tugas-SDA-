#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int front, rear;
    int items[MAX_SIZE];

public:
    Queue() {
        front = -1;  
        rear = -1;   
    }

    
    bool kosong() {
        return front == -1 && rear == -1;
    }

    
    bool penuh() {
        return rear == MAX_SIZE - 1;
    }

    
    void enqueue(int value) {
        if (penuh()) {
            cout << "Queue penuh." << endl;
            return;
        }
        if (kosong()) {
            front = rear = 0;
        } else {
            rear++;
        }
        items[rear] = value;
        cout << "Elemen " << value << " telah dimasukkan ke dalam queue." << endl;
    }

    
    void dequeue() {
        if (kosong()) {
            cout << "Queue kosong." << endl;
            return;
        } else if (front == rear) {
            cout << "Elemen " << items[front] << " dihapus dari queue." << endl;
            front = rear = -1;
        } else {
            cout << "Elemen " << items[front] << " dihapus dari queue." << endl;
            front++;
        }
    }

    
    void display() {
        if (kosong()) {
            cout << "Queue kosong." << endl;
            return;
        }
        cout << "Isi queue: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(4);
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();

    return 0;
}
