#include <iostream>

// Swap procedure
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i
void heapify(int *arr, int N, int i)
{

    int largest = i; // save the index of the largest element of the subtree

    int l = i*2 + 1; // left child node of the arr[i] parent node
    int r = i*2 + 2; // right child node of the arr[i] parent node

    if (l < N && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < N && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, N, largest); // Recusively heapify the arr[largest] element
    }
};

void HeapSort(int *arr, int N) {

    // Build the max-heap
    for (int i = N/2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }

    // "Sorting" process
    for (int j = N - 1; j > 0; j--) {
        swap(&arr[0], &arr[j]);
        heapify(arr, j, 0);
    }

};

int main() {

    int arr[] = {2,3,1,4,8,6};

    int size = sizeof(arr)/sizeof(arr[0]);

    HeapSort(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}