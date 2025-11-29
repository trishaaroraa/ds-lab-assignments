#include <iostream>
using namespace std;

class PriorityQueue {
    int heap[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void insert(int value) {
        heap[size] = value;
        int i = size;
        size++;

        while(i != 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && heap[left] > heap[largest])
            largest = left;

        if(right < size && heap[right] > heap[largest])
            largest = right;

        if(largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    int deleteMax() {
        if(size <= 0)
            return -1;

        if(size == 1) {
            size--;
            return heap[0];
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return root;
    }

    int getMax() {
        if(size > 0)
            return heap[0];
        return -1;
    }

    void display() {
        for(int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(10);
    pq.insert(60);
    pq.insert(30);
    pq.insert(90);
    pq.insert(20);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Max Element: " << pq.getMax() << endl;

    cout << "Deleted: " << pq.deleteMax() << endl;
    cout << "After Deletion: ";
    pq.display();

    return 0;
}
