#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size = 0;
    heap(){
        arr[0] = -1;
        size = 0;
    } 

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(index < size && arr[index] > arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
        
    }

    void print(){
        for(int i=0; i<size; i++){
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
            int left = 2*i;
            int right = 2*i + 1;

            if(left < size && arr[left] > arr[i]){
                swap(arr[left], arr[i]);
                left = i;
            }else if(right < size && arr[right] > arr[i]){
                swap(arr[right], arr[i]);
                right = i;
            }else{
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n &&  arr[left] > arr[largest]){
        largest = left;
    }

    if(right <= n &&  arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }   

}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, n, 1);
    }
}


int main(){

}