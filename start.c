/*
GENERAL NOTE: This is only a test code with some of the algo's at the top of my head. Take note of the following implementations to update, organize, add or double check on:
-  Queues
-  Stacks
-  Array's
- Linked Lists
- Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Queue
void enqueue(int queue[], int* front, int* rear, int maxSize, int value);
int dequeue(int queue[], int* front, int* rear);

// Stack
void push(int stack[], int* top, int maxSize, int value);
int pop(int stack[], int* top);

// Linked List
typedef struct Node Node;
Node* insertLinkedList(Node* head, int value);
void displayLinkedList(Node* head);

// Array
void displayArray(int arr[], int size);

// Binary & Linear Search
int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int left, int right, int key);

// Heap Sort
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// Radix Sort
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);

// Quick Sort
void quickSort(int arr[], int low, int high);

// Insertion Sort
void insertionSort(int arr[], int n);

// Selection Sort
void selectionSort(int arr[], int n);

// Bubble Sort
void bubbleSort(int arr[], int n);

// 1. Queue
void enqueue(int queue[], int* front, int* rear, int maxSize, int value) {
    if (*rear == maxSize - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (*front == -1) *front = 0;
    queue[++(*rear)] = value;
}

int dequeue(int queue[], int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[(*front)++];
}

// 2. Stack
void push(int stack[], int* top, int maxSize, int value) {
    if (*top == maxSize - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = value;
}

int pop(int stack[], int* top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

// 3. Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertLinkedList(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void displayLinkedList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 4. Array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 5. Binary & Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 6. Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// 7. Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// 8. Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 9. Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 10. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// 11. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
