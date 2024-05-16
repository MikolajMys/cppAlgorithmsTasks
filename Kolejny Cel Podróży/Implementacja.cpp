#include <iostream>
#include <string>

struct location{
    std::string name;
    int x, place;
    //location() {}
};

class MaxHeap{
private:
    location *heap;
    int capacity;
    int size;

    int getParentIndex(int index){
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index){
        return 2 * index + 1;
    }

    int getRightChildIndex(int index){
        return 2 * index + 2;
    }

//    void heapifyUp(int index) {
//        while (index > 0 && heap[index].x > heap[getParentIndex(index)].x) {
//            std::swap(heap[index], heap[getParentIndex(index)]);
//            index = getParentIndex(index);
//        }
//    }

    void heapifyUp(int index){
        while (index > 0) {
            int parentIndex = getParentIndex(index);

            // Dodatkowy warunek sprawdzający loc.place, gdy loc.x są równe
            if (heap[index].x > heap[parentIndex].x ||
                (heap[index].x == heap[parentIndex].x && heap[index].place < heap[parentIndex].place)) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;  // Przerwij pętlę, gdy warunek nie jest spełniony
            }
        }
//        int parentIndex = getParentIndex(index);

//        if (index > 0 &&
//            (heap[index].x > heap[parentIndex].x ||
//             (heap[index].x == heap[parentIndex].x && heap[index].place < heap[parentIndex].place))) {
//            std::swap(heap[index], heap[parentIndex]);
//            heapifyUp(parentIndex);
//        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int largest = index;

        if ((leftChildIndex < size && heap[leftChildIndex].x > heap[largest].x) ||
            (leftChildIndex < size && heap[leftChildIndex].x == heap[largest].x &&
             heap[leftChildIndex].place < heap[largest].place)) {
            largest = leftChildIndex;
        }

        if ((rightChildIndex < size && heap[rightChildIndex].x > heap[largest].x) ||
            (rightChildIndex < size && heap[rightChildIndex].x == heap[largest].x &&
             heap[rightChildIndex].place < heap[largest].place)) {
            largest = rightChildIndex;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }


public:
    MaxHeap(int capacity){
        this->capacity = capacity;
        size = 0;
        heap = new location[capacity];
    }

    ~MaxHeap(){
        delete[] heap;
    }

    void insert(location value){
        if (size == capacity) {
            std::cout << "Heap is full\n";
            return;
        }

        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    location extractMax(){
        location temp;
        if (isEmpty()) {
            std::cout << "Heap is empty\n";
            return temp;
        }
        //location temp;
        temp.x = heap[0].x;
        temp.name = heap[0].name;
        temp.place = heap[0].place;
        heap[0] = heap[size-1];
        size--;
        heapifyDown(0);

        return temp;
    }

    void findLoc(int max) {
        while (!isEmpty() && max != 0) {
            location currentMax = extractMax();

            if (currentMax.x < max) {
                std::cout << currentMax.name << " ";
                max -= currentMax.x;
            } else if (currentMax.x == max) {
                std::cout << currentMax.name << " ";
                break;
            } else {

            }
        }
    }


    bool isEmpty(){
        return size == 0;
    }

    void printHeap(){
        for (int i = 0; i < size; i++) {
            std::cout << heap[i].name << "+" << heap[i].x << " " << "+" << heap[i].place << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n;
    MaxHeap maxHeap(n);

    for (int i = 0; i < n; ++i) {
        location loc;
        std::cin >> loc.name >> loc.x;
        loc.place = i;
        maxHeap.insert(loc);
    }

    std::cin >> k;

    maxHeap.findLoc(k);

//    std::cout << "Heap: ";
//    maxHeap.printHeap();

//    std::cout << "Extracted Max: " << maxHeap.extractMax() << "\n";

//    std::cout << "Heap after extraction: ";
//    maxHeap.printHeap();

    return 0;
}