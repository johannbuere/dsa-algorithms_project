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
#include <time.h>

// Menu's
void mainMenu();
void linearDSMenu();
void nonlinDSMenu();
void stringsMenu();
void sortingMenu();
void searchingMenu();
void treeMenu();

// Sorting Algo's

// Heap Sort
void maxHeapify(int arr[], int n, int i, int* iterations);
void minHeapify(int arr[], int n, int i, int* iterations);
void heapSort();

// radix Sort
void countSortRadix(int arr[], int n, int exp, int* iterations);
void lsdRadixSort(int arr[], int n, int* iterations);
void radixSort();

// quick Sort
int lomutoPartition(int arr[], int low, int high, int* iterations);
int hoarePartition(int arr[], int low, int high, int* iterations);
void quickSortHelper(int arr[], int low, int high, int* iterations, int partitionType);
void quickSort();

// Merge Sort
void mergeSortHelper(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);  
void mergeSort();

// random sort
void randSort();          

// insertion sort
void insertSort();          

 //  Counting Sort
void countSort();          

// Selection Sort
void selecSort();           

// Bubble Sort
void bubbleSort();          


// Main code block
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
                stringsMenu(); 
                break;
            case 4:
                sortingMenu(); 
                break;
            case 5:
                searchingMenu(); 
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
            /*case 1:
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
                break;*/
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
            treeMenu(); 
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
        /*case 1:
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
            break;*/
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
            heapSort(); 
            break;
        case 2:
            radixSort(); 
            break;
        case 3:
            quickSort();
            break;
        case 4:
            mergeSort(); 
            break; 
        case 5:
            randSort(); 
            break;
        case 6:
            insertSort(); 
            break;
        case 7:
            countSort(); 
            break;
        case 8:
            selecSort(); 
            break;
        case 9:
            bubbleSort();
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
        /*case 1:
            linSearch(); // To be made
            break;
        case 2:
            binSearch(); // To be made
            break;*/
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
        /*case 1:
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
            break;*/
        case 5:
            printf("Returning to Non-Linear DS Menu...\n");
            break;
        }
    } while (choice != 5); 
}



// Heap Sort 
void maxHeapify(int arr[], int n, int i, int *iterations) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*iterations)++;
        maxHeapify(arr, n, largest, iterations);
    }
}


// Heap sort
void minHeapify(int arr[], int n, int i, int *iterations) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        (*iterations)++;
        minHeapify(arr, n, smallest, iterations);
    }
}

void heapSort() {
    int n, type, iterations = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Ask for Heap Type (Max or Min)
    printf("Choose Heap Type (1 for Max Heap, 2 for Min Heap): ");
    scanf("%d", &type);
    

    // Build the heap based on the chosen type
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

//Radix sort
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


// Merge 
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


//Merge Sort
void mergeSort() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSortHelper(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Random Sort
void randSort() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    srand(time(0));
    int sorted = 0;

    while (!sorted) {
        // Shuffle array
        for (int i = 0; i < n; i++) {
            int randomIndex = rand() % n;
            int temp = arr[i];
            arr[i] = arr[randomIndex];
            arr[randomIndex] = temp;
        }

        // Check if sorted
        sorted = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                sorted = 0;
                break;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Insertion Sort
void insertSort() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Counting Sort
void countSort() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Find max value
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    int count[max + 1];
    for (int i = 0; i <= max; i++) count[i] = 0;

    for (int i = 0; i < n; i++) count[arr[i]]++;

    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", output[i]);
    printf("\n");
}


// selection sort
void selecSort() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Initial Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Selection Sort Algorithm with display after each iteration
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
        
        // Display array after the iteration
        printf("After iteration %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// bubble sort
void bubbleSort() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Initial Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Bubble Sort Algorithm with display after each iteration
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Display array after the iteration
        printf("After iteration %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
