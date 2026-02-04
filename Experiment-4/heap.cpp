#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;   

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if(right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insert(int val) {
    if(heapSize == MAX) {
        cout << "overflow"<<endl;
        return;
    }
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

int search(int val) {
    for(int i = 0; i < heapSize; i++) {
        if(heap[i] == val)
            return i;
    }
    return -1;
}

void deleteAny(int val) {
    int index = search(val);

    if(index == -1) {
        cout << "element not found"<<endl;
        return;
    }

    heap[index] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(index);
    heapifyUp(index);
}

int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(1);
    insert(6);

    int deleteVal;
    
    cout << "Enter value to delete: "<<endl;
    cin >> deleteVal;
    deleteAny(deleteVal);

    for(int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";

    int SearchVal;

    cout << "Enter value to search: "<<endl;
    cin >> SearchVal;

    if(search(SearchVal) == -1)
        cout <<"Not found"<<endl;
    else
        cout <<"Found"<<endl;

    return 0;
}
