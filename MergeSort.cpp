#include <iostream>

void merge(int *arr, int left, int mid, int right) {


    int leftArraySize = mid - left + 1; // include the middle one
    int rightArraySize = right - mid;

    // Initializing template array
    int *leftArray = new int[leftArraySize];
    int *rightArray = new int[rightArraySize];

    // Copying value to template array
    for (int i = 0; i < leftArraySize; i++) {
        leftArray[i] = arr[left+i];
    }
    for (int j = 0; j < rightArraySize; j++) {
        rightArray[j] = arr[mid+1+j];
    }

    auto indexLeftSubArray = 0,
        indexRightSubArray = 0;
    int indexMergedResult = left;

    // Merge the array back [left..right]
    while (indexLeftSubArray < leftArraySize && indexRightSubArray < rightArraySize) {
        if (leftArray[indexLeftSubArray] <= rightArray[indexRightSubArray]) {
            arr[indexMergedResult] = leftArray[indexLeftSubArray];
            indexLeftSubArray += 1;
        }
        else {
            arr[indexMergedResult] = rightArray[indexRightSubArray];
            indexRightSubArray += 1;
        }
        indexMergedResult += 1;
    }

    // For the leftover in the left array
    while ( indexLeftSubArray < leftArraySize ) {
        arr[indexMergedResult] = leftArray[indexLeftSubArray];
        indexLeftSubArray += 1;
        indexMergedResult += 1;
    }

    // For the leftover in the right array
    while ( indexRightSubArray < rightArraySize ) {
        arr[indexMergedResult] = rightArray[indexRightSubArray];
        indexRightSubArray += 1;
        indexMergedResult += 1;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void MergeSortNumber(int *arr, int begin, int end)
{

    if (begin >= end) {
        return;
    }

    auto mid = begin + (end - begin) / 2;

    MergeSortNumber(arr, begin, mid); // The first half
    MergeSortNumber(arr, mid+1, end);   // The second half

    merge(arr, begin, mid, end);
}   

int main() {

    int arr[5] = {1,4,3,2,5};

    MergeSortNumber(arr, 0, 4);

    for (int  i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}