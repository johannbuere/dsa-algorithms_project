// Johann Reuel D. Buere || BSCS 2A
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

void mainMenu();
void linearDSMenu();
void nonlinDSMenu();
void treeMenu();

// Sorting Algo's

// Heap Sort
void maxHeapify(int arr[], int n, int i, int* iterations);
void minHeapify(int arr[], int n, int i, int* iterations);
void heapSort();
void countSortRadix(int arr[], int n, int exp, int* iterations);
void lsdRadixSort(int arr[], int n, int* iterations);
void radixSort();
int lomutoPartition(int arr[], int low, int high, int* iterations);
int hoarePartition(int arr[], int low, int high, int* iterations);
void quickSortHelper(int arr[], int low, int high, int* iterations, int partitionType);
void quickSort();



int main() {
    int choice, size, value, key, maxSize, top = -1, front = -1, rear = -1;
    int *arr, *queue, *stack;
    //Node *head = NULL;
    printf("Welcome to the Data Structures and Algorithms Menu!\n");
    do {
        //Main Menu
        mainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                linearDSMenu();
                break;
            case 2:
                nonlinDSMenu();
                break;
            case 3:
                stringsMenu(); // To be made
                break;
            case 4:
                sortingMenu(); // To be made
                break;
            case 5:
                searchingMenu(); // To be made
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!=6);
    return 0;
}

//Menu's

// Main Menu
void mainMenu() {
    printf("\n=== Main Menu ===\n");
    printf("1) Linear DS\n");
    printf("2) Non-Linear DS\n");
    printf("3) Strings\n");
    printf("4) Sorting\n");
    printf("5) Searching\n");
    printf("6) Quit\n");
}

void linearDSMenu() {
    int choice;
    do {
        printf("\n=== Linear DS Menu ===\n");
        printf("1) Arrays\n");
        printf("2) Linked List\n");
        printf("3) Stacks\n");
        printf("4) Queues\n");
        printf("5) Exit to Main Menu\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayMenu(); // To be made
                break;
            case 2:
                linkedListMenu(); // To be made
                break;
            case 3:
                stackMenu(); // To be made
                break;
            case 4:
                queueMenu(); // To be made
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void nonlinDSMenu() {
    int choice;
    do {
        printf("\n=== Non-Linear DS Menu ===\n");
        printf("1) Trees\n");
        printf("2) Exit to Main Menu\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            treeMenu(); // To be made
            break;
        case 2:
            printf("Returning to Main Menu...\n");
            break;        
        }
    } while (choice != 2);
}

void stringsMenu(){
    int choice;
    do {
        printf("\n=== String Menu ===\n");
        printf("1) Get Character (getchar)\n");
        printf("2) Put Character (putchar)\n");
        printf("3) Length \n");
        printf("4) Position of Character\n");
        printf("5) Concatenate (concat)\n");
        printf("6) Substring\n");
        printf("7) Insert\n");
        printf("8) Delete\n");
        printf("9) Compare");
        printf("10) Sort");
        printf("11) Exit to Main Menu\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            strGetChar(); // To be made
            break;
        case 2:
            strPutChar(); // To be made
            break;
        case 3:
            length(); // To be made
            break;
        case 4:
            pos(); // To be made
            break; 
        case 5:
            concat(); // To be made
            break;
        case 6:
            substring(); // To be made
            break;
        case 7:
            strInsert(); // To be made
            break;
        case 8:
            strDel(); // To be made
            break;
        case 9:
            strComp(); // To be made
            break;
        case 10:
            strSort(); // To be made
            break;
        case 11:
            printf("Returning to Main Menu...\n");
            break;  
        }
    } while (choice != 11);
}

void sortingMenu(){
    int choice;
    do {
        printf("\n=== Sorting Menu ===\n");
        printf("1) Heap Sort\n");
        printf("2) Radix Sort\n");
        printf("3) Quick Sort \n");
        printf("4) Merge Sort\n");
        printf("5) Random Sort\n");
        printf("6) Insertion Sort\n");
        printf("7) Counting Sort\n");
        printf("8) Selection Sort\n");
        printf("9) Bubble Sort\n");
        printf("10) Exit to Main Menu\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            heapSort(); // To be made
            break;
        case 2:
            radixSort(); // To be made
            break;
        case 3:
            quickSort(); // To be made
            break;
        case 4:
            mergeSort(); // To be made
            break; 
        case 5:
            randSort(); // To be made
            break;
        case 6:
            insertSort(); // To be made
            break;
        case 7:
            countSort(); // To be made
            break;
        case 8:
            selecSort(); // To be made
            break;
        case 9:
            bubbleSort(); // To be made
            break;
        case 10:
            printf("Returning to Main Menu...\n");
            break;
        }
    } while (choice != 10); 
}

void searchingMenu(){
    int choice;
    do {
        printf("\n=== Searching Menu ===\n");
        printf("1) Linear Search\n");
        printf("2) Binary Search\n");
        printf("3) Exit to Main Menu\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            linSearch(); // To be made
            break;
        case 2:
            binSearch(); // To be made
            break;
        case 3:
            printf("Returning to Main Menu...\n");
            break;
        }
    } while (choice != 3); 
}

// Minor Menu's
void treeMenu(){
    int choice;
       do {
        printf("\n=== Tree Menu ===\n");
        printf("1) Tree Representation\n");
        printf("2) Rooted Trees\n");
        printf("3) Ordered Trees\n");
        printf("4) Binary Trees\n");
        printf("5) Exit to Non-Linear DS Menu\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            showTree(); // To be made
            break;
        case 2:
            rootTree(); // To be made
            break;
        case 3:
            orderTree(); // To be made
            break;
        case 4:
            binaryTree(); // To be made
            break; 
        case 5:
            printf("Returning to Non-Linear DS Menu...\n");
            break;
        }
    } while (choice != 5); 
}



// Heap Sort 
void maxHeapify(int arr[], int n, int i, int* iterations) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    (*iterations)++;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest, iterations);
    }
}

void minHeapify(int arr[], int n, int i, int* iterations) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    (*iterations)++;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest, iterations);
    }
}


// Radix Sort
void heapSort() {
    int n, type, iterations = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Choose Heap Type (1 for Max Heap, 2 for Min Heap): ");
    scanf("%d", &type);

    if (type == 1) {
        // Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i, &iterations);
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, i, 0, &iterations);
        }
    } else {
        // Min Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            minHeapify(arr, n, i, &iterations);
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            minHeapify(arr, i, 0, &iterations);
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nIterations: %d\n", iterations);
}

void countSortRadix(int arr[], int n, int exp, int* iterations) {
    int output[n];
    int count[10] = {0};
    (*iterations)++;

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

void lsdRadixSort(int arr[], int n, int* iterations) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp, iterations);
}

void radixSort() {
    int n, type, iterations = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Choose Radix Type (1 for LSD, 2 for MSD): ");
    scanf("%d", &type);

    if (type == 1) {
        lsdRadixSort(arr, n, &iterations);
    } else {
        printf("MSD Radix Sort is not implemented yet.\n");
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nIterations: %d\n", iterations);
}

// Quick Sort
int lomutoPartition(int arr[], int low, int high, int* iterations) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        (*iterations)++;
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
    return i + 1;
}

int hoarePartition(int arr[], int low, int high, int* iterations) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (1) {
        do {
            i++;
            (*iterations)++;
        } while (arr[i] < pivot);
        do {
            j--;
            (*iterations)++;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSortHelper(int arr[], int low, int high, int* iterations, int partitionType) {
    if (low < high) {
        int pi;
        if (partitionType == 1)
            pi = lomutoPartition(arr, low, high, iterations);
        else
            pi = hoarePartition(arr, low, high, iterations);
        quickSortHelper(arr, low, pi - 1, iterations, partitionType);
        quickSortHelper(arr, pi + 1, high, iterations, partitionType);
    }
}

void quickSort() {
    int n, type, iterations = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Choose Partition Type (1 for Lomuto, 2 for Hoare): ");
    scanf("%d", &type);

    quickSortHelper(arr, 0, n - 1, &iterations, type);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nIterations: %d\n", iterations);
}
