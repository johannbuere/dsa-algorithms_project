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

int main() {
    int choice, size, value, key, maxSize, top = -1, front = -1, rear = -1;
    int *arr, *queue, *stack;
    Node *head = NULL;
    int running = 1;

    printf("Welcome to the Data Structures and Algorithms Menu!\n");

    while (running) {
        printf("\nChoose an option:\n");
        printf("1. Queue Operations\n");
        printf("2. Stack Operations\n");
        printf("3. Linked List Operations\n");
        printf("4. Array Display\n");
        printf("5. Linear Search\n");
        printf("6. Binary Search\n");
        printf("7. Heap Sort\n");
        printf("8. Radix Sort\n");
        printf("9. Quick Sort\n");
        printf("10. Insertion Sort\n");
        printf("11. Selection Sort\n");
        printf("12. Bubble Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Queue Operations
                printf("Enter maximum queue size: ");
                scanf("%d", &maxSize);
                queue = (int *)malloc(maxSize * sizeof(int));
                int queueRunning = 1;
                while (queueRunning) {
                    printf("\nQueue Operations:\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Exit Queue Menu\nEnter choice: ");
                    scanf("%d", &choice);
                    if (choice == 1) {
                        printf("Enter value to enqueue: ");
                        scanf("%d", &value);
                        enqueue(queue, &front, &rear, maxSize, value);
                    } else if (choice == 2) {
                        int dequeued = dequeue(queue, &front, &rear);
                        if (dequeued != -1)
                            printf("Dequeued: %d\n", dequeued);
                    } else if (choice == 3) {
                        queueRunning = 0;
                    }
                }
                free(queue);
                break;

            case 2: // Stack Operations
                printf("Enter maximum stack size: ");
                scanf("%d", &maxSize);
                stack = (int *)malloc(maxSize * sizeof(int));
                int stackRunning = 1;
                while (stackRunning) {
                    printf("\nStack Operations:\n");
                    printf("1. Push\n2. Pop\n3. Exit Stack Menu\nEnter choice: ");
                    scanf("%d", &choice);
                    if (choice == 1) {
                        printf("Enter value to push: ");
                        scanf("%d", &value);
                        push(stack, &top, maxSize, value);
                    } else if (choice == 2) {
                        int popped = pop(stack, &top);
                        if (popped != -1)
                            printf("Popped: %d\n", popped);
                    } else if (choice == 3) {
                        stackRunning = 0;
                    }
                }
                free(stack);
                break;

            case 3: // Linked List Operations
                printf("\nLinked List Operations:\n");
                printf("1. Insert Node\n2. Display List\nEnter choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    head = insertLinkedList(head, value);
                } else if (choice == 2) {
                    displayLinkedList(head);
                }
                break;

            case 4: // Array Display
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                displayArray(arr, size);
                free(arr);
                break;

            case 5: // Linear Search
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Enter key to search: ");
                scanf("%d", &key);
                int linearIndex = linearSearch(arr, size, key);
                if (linearIndex != -1)
                    printf("Key found at index: %d\n", linearIndex);
                else
                    printf("Key not found.\n");
                free(arr);
                break;

            case 6: // Binary Search
                printf("Enter size of sorted array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d sorted elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Enter key to search: ");
                scanf("%d", &key);
                int binaryIndex = binarySearch(arr, 0, size - 1, key);
                if (binaryIndex != -1)
                    printf("Key found at index: %d\n", binaryIndex);
                else
                    printf("Key not found.\n");
                free(arr);
                break;

            case 7: // Heap Sort
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                heapSort(arr, size);
                printf("Sorted Array: ");
                displayArray(arr, size);
                free(arr);
                break;

            case 8: // Radix Sort
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                radixSort(arr, size);
                printf("Sorted Array: ");
                displayArray(arr, size);
                free(arr);
                break;

            case 9: // Quick Sort
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                quickSort(arr, 0, size - 1);
                printf("Sorted Array: ");
                displayArray(arr, size);
                free(arr);
                break;

            case 10: // Insertion Sort
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                insertionSort(arr, size);
                printf("Sorted Array: ");
                displayArray(arr, size);
                free(arr);
                break;

            case 11: // Selection Sort
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                selectionSort(arr, size);
                printf("Sorted Array: ");
                displayArray(arr, size);
                free(arr);
                break;

            case 12: // Bubble Sort
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                bubbleSort(arr, size);
                printf("Sorted Array: ");
                displayArray(arr, size);
                free(arr);
                break;

            case 0:
                running = 0;
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

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
