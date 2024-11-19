/* 
✨ Johann Reuel D. Buere || BSCS 2A ✨ 
📚 Lab 2: Progress Report 🛠️ 

Lab 2 is wrapping up, and I’ve made some serious progress on the program during this time. Let’s break down what’s been achieved so far and what’s left to do!

🎉 Updates in Lab 2:
- Sorting: Fully implemented and refined! 🎯 The sorting algorithms now feature polished user input handling and better usability. No more messy inputs; it’s all smooth sailing now!

- Searching: 🎉 New feature alert! Searching algorithms have been added to the program and are fully functional—finding data is a breeze. 🚀

- Linear DS: 1 out of 5 tasks complete! A small step forward, but still plenty of work to finish here. 🛤️
- Others: Still under construction, but I’ll be taking the reins solo after Lab 2 to complete them. 🚧

📊 Main Menu Progress:
    === Main Menu ===

    Linear DS [1/5 Done] 🟩⬜⬜⬜⬜
    Non-Linear DS [Not Yet] 🚧
    Strings [Not Yet] 🚧
    Sorting [Done! ✅]
    Searching [Done! ✅]
    Quit

    
📈 Comparison Since Lab 1:
- Sorting was basic and clunky in Lab 1. Now it’s optimized with precise user controls and a clean interface! 💡
- Searching didn’t even exist back then. Now, it’s fully functional and makes finding data intuitive and simple! ✨
- The Main Menu now reflects real-time progress with percentages and markers to show what’s done and what’s still being worked on.

✨ Overall Progress:
    [█████-----] 40% Complete!  
    Still more to finish, but we’re making solid strides! 💪  

🌟 Next Steps:  
    After Lab 2, I’ll be working on the remaining features (Linear DS, Non-Linear DS, and Strings) on my own time. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

//terminal commands
void setTerminalSize();
void clearScreen();


unsigned int seed = 1; // Initialize a seed for randomness

// Menu's
void mainMenu(int *choice);
void linearDSMenu();
void nonlinDSMenu();
void stringsMenu();
void sortingMenu();
void searchingMenu();
void treeMenu();

//print array func prototype
void printArray(int arr[], int n, const char *sortType, int iterations);

//print sorted Array
void printSortedArray(int arr[], int n, int iterations);

// Function to display title page and ask if the user wants to continue
int welcomeScreen();

// Function to display program introduction
void introductionScreen();

// Function to clear the input buffer
void clearInputBuffer();

// Helper function to print centered text
void printCentered(const char *text, int width);

// input
void getInput(int *n);

// Searching Algo's
void linSearch(int arr[], int size, int target);
void binSearch(int arr[], int size, int target);
void binaryInsertionSort(int arr[], int size);

// Sorting Algo's

// Heap Sort
void maxHeapify(int arr[], int n, int i, int *iterations, const char *sortType);
void minHeapify(int arr[], int n, int i, int *iterations, const char *sortType);
void heapSort();

// radix Sort
void countSortRadix(int arr[], int n, int exp, int* iterations, const char *sortType, int isMSD);
void msdRadixSort(int arr[], int n, int* iterations, const char *sortType);
void lsdRadixSort(int arr[], int n, int* iterations, const char *sortType);
void radixSort();

// quick Sort
int lomutoPartition(int arr[], int low, int high, int* iterations, const char *sortType);
int hoarePartition(int arr[], int low, int high, int* iterations, const char *sortType);
void quickSortHelper(int arr[], int low, int high, int* iterations, int partitionType, const char *sortType);
void quickSort();

// Merge Sort
void mergeSortHelper(int arr[], int l, int r, int* iterations, const char *sortType);
void merge(int arr[], int l, int m, int r, int* iterations, const char *sortType);
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
    setTerminalSize(); // Set terminal size once
    clearScreen();

    if (!welcomeScreen()) { // If the user chooses not to continue
        printCentered("Exiting program. Goodbye!", WIDTH);
        return 0; // Exit the program
    }
    
    introductionScreen(); // Display the introduction

    do {
        system("cls");
        setTerminalSize();
        printf("\n");
        printf("\n");
        printCentered("Welcome to the Data Structures and Algorithms Menu!", WIDTH);
        //Main Menu
        mainMenu(&choice);
        clearScreen();

        switch (choice) {
            case 1:
                linearDSMenu();
                break;
            case 2:
                clearScreen();
                nonlinDSMenu();
                break;
            case 3:
                clearScreen();
                stringsMenu(); 
                break;
            case 4:
                clearScreen();
                sortingMenu(); 
                break;
            case 5:
                clearScreen();
                searchingMenu(); 
                break;
            case 6:
                clearScreen();
                printCentered("Exiting program. Goodbye!\n", WIDTH);
                break;
            default:
                printCentered("Invalid choice. Try again.\n", WIDTH);
        }
    } while (choice!=6);
    return 0;
}



//Terminal commands
void setTerminalSize() { 
    const int rows = 24;
    const int cols = WIDTH; // Ensure WIDTH is defined and valid
    char command[50];

    sprintf(command, "mode con: cols=%d lines=%d", cols, rows);
    printf("[DEBUG] Executing command: %s\n", command); // Debugging

    fflush(stdout); // Flush output before changing terminal size
    int result = system(command);

    if (result != 0) {
        printf("[ERROR] Failed to set terminal size.\n");
    }
}

void clearScreen() {
    system("cls");
}



//Menu's

// Main Menu
void mainMenu(int *choice) {
    printf("\n");
    printCentered("=== Main Menu ===", WIDTH);
    printCentered("1) Linear DS [1/5 Done]", WIDTH);
    printCentered("2) Non-Linear DS [Not Yet]", WIDTH);
    printCentered("3) Strings [Not Yet]", WIDTH);
    printCentered("4) Sorting", WIDTH);
    printCentered("5) Searching", WIDTH);
    printCentered("6) Quit", WIDTH);
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", choice); // Update choice directly
    clearInputBuffer();  // Clear any extra input from buffer
}

void linearDSMenu() {
    int choice;
    do {
        printf("\n");
        printCentered("=== Linear DS Menu ===", WIDTH);
        printCentered("1) Arrays", WIDTH);
        printCentered("2) Linked List", WIDTH);
        printCentered("3) Stacks", WIDTH);
        printCentered("4) Queues", WIDTH);
        printCentered("5) Exit to Main Menu", WIDTH);
        printf("\n");
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
                printCentered("Returning to Main Menu...", WIDTH);
                break;
            default:
                printCentered("Invalid choice. Please try again.", WIDTH);
                clearInputBuffer();
        }
    } while (choice != 5);
}

void nonlinDSMenu() {
    int choice;
    do {
        printf("\n");
        printCentered("=== Non-Linear DS Menu ===", WIDTH);
        printCentered("1) Trees", WIDTH);
        printCentered("2) Exit to Main Menu", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                treeMenu();
                break;
            case 2:
                printCentered("Returning to Main Menu...", WIDTH);
                break;
            default:
                printCentered("Invalid choice. Please try again.", WIDTH);
                clearInputBuffer();
        }
    } while (choice != 2);
}

void stringsMenu(){
    int choice;
    do {
        printf("\n");
        printCentered("=== String Menu ===", WIDTH);
        printCentered("1) Get Character (getchar)", WIDTH);
        printCentered("2) Put Character (putchar)", WIDTH);
        printCentered("3) Length", WIDTH);
        printCentered("4) Position of Character", WIDTH);
        printCentered("5) Concatenate (concat)", WIDTH);
        printCentered("6) Substring", WIDTH);
        printCentered("7) Insert", WIDTH);
        printCentered("8) Delete", WIDTH);
        printCentered("9) Compare", WIDTH);
        printCentered("10) Sort", WIDTH);
        printCentered("11) Exit to Main Menu", WIDTH);
        printf("\n");
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
            printCentered("Returning to Main Menu...", WIDTH);
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
            clearInputBuffer();
        }
    } while (choice != 11);
}

void sortingMenu(){
    int choice;
    do {
        printf("\n");
        printCentered("=== Sorting Menu ===", WIDTH);
        printCentered("1) Heap Sort", WIDTH);
        printCentered("2) Radix Sort", WIDTH);
        printCentered("3) Quick Sort", WIDTH);
        printCentered("4) Merge Sort", WIDTH);
        printCentered("5) Random Sort", WIDTH);
        printCentered("6) Insertion Sort", WIDTH);
        printCentered("7) Counting Sort", WIDTH);
        printCentered("8) Selection Sort", WIDTH);
        printCentered("9) Bubble Sort", WIDTH);
        printCentered("10) Exit to Main Menu", WIDTH);
        printf("\n");
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
            printCentered("Returning to Main Menu...", WIDTH);
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
            clearInputBuffer();
        }
    } while (choice != 10); 
}

void searchingMenu(){
    int choice, n, target;
    do {
        printf("\n");
        printCentered("=== Searching Menu ===", WIDTH);
        printCentered("1) Linear Search", WIDTH);
        printCentered("2) Binary Search", WIDTH);
        printCentered("3) Exit to Main Menu", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);
        int arr[n];

        switch (choice) {
        case 1:
        getInput(&n);
        printf("Enter the elements: ");
        for (int i = 0; i < n; i++) {
            while (1) {
                if (scanf("%d", &arr[i]) != 1) {
                    printf("Invalid input. \nPlease enter an integer: ");
                    clearInputBuffer();
                } else {
                    break;
                }
            }
        }
            printf("Enter the element to search for: ");
            scanf("%d", &target);
            linSearch(arr, n, target);
            break;
        case 2:
        getInput(&n);
        printf("Enter the elements: ");
        for (int i = 0; i < n; i++) {
            while (1) {
                if (scanf("%d", &arr[i]) != 1) {
                    printf("Invalid input. \nPlease enter an integer: ");
                    clearInputBuffer();
                } else {
                    break;
                }
            }
        }
            printf("Enter the element to search for: ");
            scanf("%d", &target);
            binSearch(arr, n, target);
            break;
        case 3:
            printCentered("Returning to Main Menu...", WIDTH);
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
            clearInputBuffer();
        }
    } while (choice != 3); 
}

// Minor Menu's
void treeMenu(){
    int choice;
       do {
        printf("\n");
        printCentered("=== Tree Menu ===", WIDTH);
        printCentered("1) Tree Representation", WIDTH);
        printCentered("2) Rooted Trees", WIDTH);
        printCentered("3) Ordered Trees", WIDTH);
        printCentered("4) Binary Trees", WIDTH);
        printCentered("5) Exit to Non-Linear DS Menu", WIDTH);
        printf("\n");
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
            printCentered("Returning to Non-Linear DS Menu...", WIDTH);
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
            clearInputBuffer();
        }
    } while (choice != 5); 
}


// printing array func
void printArray(int arr[], int n, const char *sortType, int iterations) {
    char buffer[WIDTH]; // Temporary buffer for array content
    int length = 0;

    printf("\n");
    // Add the sort type and iteration info to the buffer
    length += snprintf(buffer + length, sizeof(buffer) - length, "%s - Iteration %d: ", sortType, iterations);

    // Add array elements to the buffer
    for (int i = 0; i < n && length < sizeof(buffer) - 1; i++) {
        length += snprintf(buffer + length, sizeof(buffer) - length, "%d ", arr[i]);
    }

    // Calculate padding for centering
    int padding = (WIDTH - strlen(buffer)) / 2;

    // Ensure padding is non-negative
    if (padding < 0) padding = 0;

    // Print spaces for centering and then the buffer content
    printf("%*s%s\n", padding, "", buffer);
}

void printSortedArray(int arr[], int n, int iterations) {
    char buffer[WIDTH]; // Buffer for the array content
    int length = 0;

    printf("\n");
    // Construct the array output
    length += snprintf(buffer + length, sizeof(buffer) - length, "Sorted Array: ");
    for (int i = 0; i < n && length < sizeof(buffer) - 1; i++) {
        length += snprintf(buffer + length, sizeof(buffer) - length, "%d ", arr[i]);
    }

    // Center the sorted array
    int padding = (WIDTH - strlen(buffer)) / 2;
    if (padding < 0) padding = 0;
    printf("%*s%s\n", padding, "", buffer);

    // Construct and center the iterations count
    snprintf(buffer, sizeof(buffer), "Iterations: %d", iterations);
    padding = (WIDTH - strlen(buffer)) / 2;
    if (padding < 0) padding = 0;
    printf("%*s%s\n", padding, "", buffer);
    printf("\n");
}

// Helper function to print centered text
void printCentered(const char *text, int width) {
    int padding = (width - strlen(text)) / 2; // Calculate leading spaces
    if (padding > 0) {
        printf("%*s%s\n", padding, "", text); // Print spaces, then the text
    } else {
        printf("%s\n", text); // If text is wider than the width, just print it
    }
}

// Function to display the title page and ask the user to continue
int welcomeScreen() {
    char choice;
    clearScreen();

    // Center the content vertically
    for (int i = 0; i < HEIGHT / 3; i++) {
        printf("\n");
    }

    // Display the title screen
    printCentered("CS 104 - Data Structures and Algorithms", WIDTH);
    printCentered("Instructor: Laarni D. Pancho", WIDTH);
    printCentered("Student: Johann Reuel D. Buere", WIDTH);
    printf("\n\n");
    printCentered("Would you like to continue? (y/n): ", WIDTH);

    // Get the user's choice
    while (1) {
        scanf(" %c", &choice);
        clearInputBuffer(); // Clear any additional input
        if (choice == 'y' || choice == 'Y') {
            return 1; // Continue
        } else if (choice == 'n' || choice == 'N') {
            return 0; // Exit
        } else {
            printCentered("Invalid input. Please enter 'y' or 'n'.", WIDTH);
            printCentered("Would you like to continue? (y/n): ", WIDTH);
        }
    }
}

void introductionScreen() {
    clearScreen();

    // Center the content vertically
    for (int i = 0; i < HEIGHT / 4; i++) {
        printf("\n");
    }

    // Display the program's introduction
    printCentered("Welcome to the Data Structures and Algorithms Program!", WIDTH);
    printf("\n");
    printCentered("This program is designed to help you learn and interact with", WIDTH);
    printCentered("various data structures and algorithms, such as:", WIDTH);
    printCentered("- Linear Data Structures (Arrays, Stacks, Queues, etc.)", WIDTH);
    printCentered("- Non-Linear Data Structures (Trees, Graphs)", WIDTH);
    printCentered("- Sorting Algorithms (Quick Sort, Merge Sort, etc.)", WIDTH);
    printCentered("- Searching Algorithms (Linear Search, Binary Search)", WIDTH);
    printf("\n");
    printCentered("Its purpose is to provide an interactive way to understand", WIDTH);
    printCentered("and visualize how these concepts work.", WIDTH);
    printf("\n");
    printCentered("You will also be guided with menus to select and explore", WIDTH);
    printCentered("each topic step by step. Have fun learning!", WIDTH);
    printf("\n\n");
    printCentered("Press Enter to continue...", WIDTH);

    getchar(); // Wait for the user to press Enter
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Consume remaining characters in the input buffer
    }
}

// checks input for uncertainties
void getInput(int *n) {
    int validInput = 0;

    while (!validInput) {
        // Centered prompt for number of elements
        printf("Enter the number of elements: ");
        if (scanf("%d", n) != 1 || *n <= 0) {
            printCentered("\nInvalid input.", WIDTH);
            printCentered("Please enter a positive integer.\n", WIDTH);
            clearInputBuffer(); // Clear invalid input from the buffer
        } else if (*n >= 30) {
            char confirm;
            printCentered("That's quite a large number of elements.", WIDTH);
            printf("Are you sure you want to continue? (y/n): ");
            scanf(" %c", &confirm);
            clearInputBuffer(); // Clear any additional input
            if (confirm == 'y' || confirm == 'Y') {
                validInput = 1; // Input confirmed as valid
            } else {
                printCentered("Please enter a smaller number of elements.", WIDTH);
            }
        } else {
            validInput = 1; // Valid input
        }
    }
}

// Searching Algorithm
void linSearch(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d.\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

// Binary search function
void binSearch(int arr[], int size, int target) {
    // Perform binary insertion sort before binary search
    binaryInsertionSort(arr, size);

    int low = 0, high = size - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            printf("Element %d found at index %d.\n", target, mid);
            found = 1;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

// Binary Insertion Sort function
void binaryInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int low = 0, high = i - 1;
        
        // Binary search to find the correct position
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Move all elements after the found position to one place ahead
        for (int j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
        }

        // Insert the key at its correct position
        arr[low] = key;
    }
}




// Heap Sort 
void maxHeapify(int arr[], int n, int i, int *iterations, const char *sortType) {
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
        printArray(arr, n, sortType, *iterations);  
        maxHeapify(arr, n, largest, iterations, sortType);
    }
}

void minHeapify(int arr[], int n, int i, int *iterations, const char *sortType) {
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
        printArray(arr, n, sortType, *iterations);  
        minHeapify(arr, n, smallest, iterations, sortType);
    }
}

void heapSort() {
    int n, type, iterations = 0;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    printf("Choose Heap Type (1 for Max Heap, 2 for Min Heap): ");
    clearInputBuffer();
    scanf("%d", &type);
    const char *sortType = (type == 1) ? "Max Heap Sort" : "Min Heap Sort";

    if (type == 1) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, n, i, &iterations, sortType);  // Pass pointer
        }
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            iterations++;  // Increment iterations directly
            printArray(arr, n, sortType, iterations);  // Print after each swap
            maxHeapify(arr, i, 0, &iterations, sortType);  // Pass pointer
        }
    } else {
        for (int i = n / 2 - 1; i >= 0; i--) {
            minHeapify(arr, n, i, &iterations, sortType);  // Pass pointer
        }
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            iterations++;  // Increment iterations directly
            printArray(arr, n, sortType, iterations);  // Print after each swap
            minHeapify(arr, i, 0, &iterations, sortType);  // Pass pointer
        }
    }

    printSortedArray(arr, n, iterations);
}


//Radix sort
void countSortRadix(int arr[], int n, int exp, int* iterations, const char *sortType, int isMSD) {
    int output[n];
    int count[10] = {0};
    (*iterations)++;

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Convert counts to positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    printArray(arr, n, sortType, *iterations);  // Print after each iteration

    // For MSD: Recursively sort buckets if needed
    if (isMSD) {
        for (int i = 0; i < 10; i++) {
            int start = (i == 0) ? 0 : count[i - 1];
            int end = count[i];
            if (start < end) {  // Non-empty bucket
                countSortRadix(arr + start, end - start, exp / 10, iterations, sortType, isMSD);
            }
        }
    }
}

void lsdRadixSort(int arr[], int n, int* iterations, const char *sortType) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp, iterations, sortType, 0);  // LSD does not use recursion
}

void msdRadixSort(int arr[], int n, int* iterations, const char *sortType) {
    int max = arr[0];
    for (int i = 1; i < n; i++)  // Find the maximum number
        if (arr[i] > max)
            max = arr[i];

    int exp = 1;
    while (max / exp > 9)
        exp *= 10;  // Find the most significant digit's place value

    countSortRadix(arr, n, exp, iterations, sortType, 1);  // MSD uses recursion
}

void radixSort() {
    int n, type, iterations = 0;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    printf("Choose Radix Type (1 for LSD, 2 for MSD): ");
    scanf("%d", &type);
    clearInputBuffer();

    const char *sortType = "Radix Sort";

    if (type == 1) {
        lsdRadixSort(arr, n, &iterations, sortType);
    } else if (type == 2) {
        msdRadixSort(arr, n, &iterations, sortType);
    } else {
        printf("Invalid choice.\n");
        return;
    }

    printSortedArray(arr, n, iterations);
}



// Quick Sort
int lomutoPartition(int arr[], int low, int high, int* iterations, const char *sortType) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        (*iterations)++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printArray(arr, high + 1, sortType, *iterations);  // Print after each iteration
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

int hoarePartition(int arr[], int low, int high, int* iterations, const char *sortType) {
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
        printArray(arr, high + 1, sortType, *iterations);  // Print after each iteration
    }
}

void quickSortHelper(int arr[], int low, int high, int* iterations, int partitionType, const char *sortType) {
    if (low < high) {
        int pi;
        if (partitionType == 1)
            pi = lomutoPartition(arr, low, high, iterations, sortType);
        else
            pi = hoarePartition(arr, low, high, iterations, sortType);
        quickSortHelper(arr, low, pi - 1, iterations, partitionType, sortType);
        quickSortHelper(arr, pi + 1, high, iterations, partitionType, sortType);
    }
}

void quickSort() {
    int n, type, iterations = 0;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    printf("Choose Partition Type (1 for Lomuto, 2 for Hoare): ");
    scanf("%d", &type);

    const char *sortType = "Quick Sort";

    quickSortHelper(arr, 0, n - 1, &iterations, type, sortType);

    printSortedArray(arr, n, iterations);
}



// Merge 
void merge(int arr[], int l, int m, int r, int* iterations, const char *sortType) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*iterations)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        printArray(arr, r + 1, sortType, *iterations);  // Print after each merge step
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*iterations)++;
        printArray(arr, r + 1, sortType, *iterations);  // Print after adding remaining elements
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*iterations)++;
        printArray(arr, r + 1, sortType, *iterations);  // Print after adding remaining elements
    }
}

void mergeSortHelper(int arr[], int l, int r, int* iterations, const char *sortType) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, iterations, sortType);
        mergeSortHelper(arr, m + 1, r, iterations, sortType);
        merge(arr, l, m, r, iterations, sortType);
    }
}

void mergeSort() {
    int n, iterations = 0;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    const char *sortType = "Merge Sort";
    mergeSortHelper(arr, 0, n - 1, &iterations, sortType);

    printSortedArray(arr, n, iterations);
}


// Random Sort
void randSort() {
    int n;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input.\nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    // Shuffle and check for sorting
    int sorted = 0;
    int iterations = 0; // Count the number of shuffles
    const char *sortType = "Random Sort";

    while (!sorted) {
        // Custom random number generator (LCG)
        seed = (seed * 1103515245 + 12345) % 2147483648;

        // Shuffle array
        for (int i = 0; i < n; i++) {
            int randomIndex = seed % n;
            int temp = arr[i];
            arr[i] = arr[randomIndex];
            arr[randomIndex] = temp;
        }

        // Increment iteration counter
        iterations++;

        // Use printArray to display the current shuffle
        printArray(arr, n, sortType, iterations);

        // Check if sorted
        sorted = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                sorted = 0;
                break;
            }
        }
    }

    // Display final sorted array
    printSortedArray(arr, n, iterations);
}

// Insertion Sort
void insertSort() {
    int n, iterations = 0;  
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    const char *sortType = "Insertion Sort";  

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        iterations++;  
        printArray(arr, n, sortType, iterations);  
    }

    printSortedArray(arr, n, iterations);   
}


void countSort() {
    int n, iterations = 0; 
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }

    // Find max value
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    int count[max + 1];
    for (int i = 0; i <= max; i++) count[i] = 0;

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    iterations++;  // Increment iteration after count array is filled
    printArray(count, max + 1, "Counting Sort - Count Array", iterations);  // Print count array after counting

    // Update count array with cumulative counts
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    iterations++;  // Increment iteration after cumulative count
    printArray(count, max + 1, "Counting Sort - Cumulative Count", iterations);  // Print cumulative count array

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    iterations++;  // Increment iteration after placing elements in output array
    printArray(output, n, "Counting Sort - Output Array", iterations);  // Print output array

    printSortedArray(arr, n, iterations);
}


// selection sort
void selecSort() {
    int n, iterations = 0;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }
    
    // Initial array print
    printArray(arr, n, "Selection Sort - Initial Array", ++iterations);

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
        printArray(arr, n, "Selection Sort - After Iteration", ++iterations);
    }

    // Final sorted array print
    printSortedArray(arr, n, iterations);
}

// bubble sort
void bubbleSort() {
    int n, iterations = 0;
    getInput(&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. \nPlease enter an integer: ");
                clearInputBuffer();
            } else {
                break;
            }
        }
    }
    
    // Initial Array print
    printArray(arr, n, "Bubble Sort - Initial Array", ++iterations);

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
        printArray(arr, n, "Bubble Sort - After Iteration", ++iterations);
    }

    // Final sorted array print
    printSortedArray(arr, n, iterations);
}
