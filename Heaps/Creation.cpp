#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size  = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                swap(arr[index] , arr[parent]);
                index = parent;
            }

            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletefromHeap(){
        if(size == 0){
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else{
                return;
            }


        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    int size = n;

    while(size > 1){
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, n, 1);
    }
}

int main(){

    // calling heapify
    int n;
    int arr[100];
    for(int i = n/2 ; i > 0 ; i--){
        heapify(arr, n, i);
    }



    // creating maxheap using STL;
    priority_queue<int> pq;
    pq.top();
    pq.empty();


    // creating minheap using STL;
    priority_queue<int, vector<int>, greater<int>> minHeap;
}