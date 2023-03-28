#include <iostream>
#include <chrono>




/*random*/
void random(int *arr, int SIZE)
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10;
    }
    /*for (int i = 0; i < N; i++)
    {
 std::cout << arr[i] << " ";
    }*/
}

/* Bubble Sort*/
void bubble(int *arr, int SIZE)
{

    for(int i = 0; i < SIZE; i++)
    {
        bool flag(true);
        for(int j = 0; j < SIZE - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                flag = false;
                std::swap(arr[j], arr[j + 1]);
            }
        }
        if(flag)
        {
            break;
        }
    }
    /*for(int k = 0; k < N; k++)
    {
std::cout << arr[k] << " ";
    }*/
}

/*Insertion Sort*/
void insertion(int *arr, int SIZE)
{

    for(int i = 1; i < SIZE; i++)
    {
        for(int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            std::swap(arr[j - 1], arr[j]);
        }
    }
}

/*Merge Sort*/
void merge(int* array, int const left, int const mid,
           int const right)
{
    int const sizeOne = mid - left + 1;
    int const sizeTwo = right - mid;
    int *leftArray = new int[sizeOne], *rightArray = new int[sizeTwo];
    for (int i = 0; i < sizeOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < sizeOne
           && indexOfSubArrayTwo < sizeTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < sizeOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < sizeTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int* array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void mergeSort_1(int* ar, int size){
    mergeSort(ar, 0, size - 1);
}

/*Selection Sort*/
void selection(int *arr, int SIZE)
{
    int k;

    for(int j = 0; j < SIZE; j++)
    {
        int min = j;
        for(int i = j; i < SIZE; i++)
        {
            if(arr[i] < arr[min])
            {
                min = i;
            }
        }
        std::swap(arr[j], arr[min]);
    }
}

/*Quick Sort*/
void quicksort(int* arr, int low, int high){
    int i = low;
    int j = high;
    int k= arr[(i + j) / 2];
    while (i <= j)
    {
        while (arr[i] < k)
            i++;
        while (arr[j] > k)
            j--;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quicksort(arr, low, j);
    if (i < high)
        quicksort(arr, i, high);
}

void quicksort_1(int* arr, int M){
    quicksort(arr, 0, M - 1);
}

/*Count Sort*/
void count(int* arr, int SIZE) {

    int* arr1 = new int[SIZE];
    int x = arr[0];

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > x)
            x = arr[i];
    }

    int* count_arr = new int[x+1];

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < SIZE; i++) {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }

    for (int i = SIZE - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = arr1[i];
    }
    delete[] arr1;
    delete[] count_arr;
}