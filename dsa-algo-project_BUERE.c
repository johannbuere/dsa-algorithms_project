/* 
✨ Johann Reuel D. Buere || BSCS 2A ✨
📚 Version 1: Final Release 🛠️

This version marks the beginning of the program, setting the foundation for future updates. Here's a breakdown of what has been achieved so far:

✨ Overall Progress:
[██████████] 100% Complete!

🌟 Next Steps:
After this release, I’ll be resting
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <windows.h>

#define WIDTH 80
#define HEIGHT 24


//typed def data type
typedef enum { DT_INT, DT_CHAR, DT_STRING } DataType;

// Define the tree node structure for integers
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes for tree's
TreeNode* insertInt(TreeNode* root, int value);
TreeNode* deleteInt(TreeNode* root, int value);
TreeNode* findMinNode(TreeNode* root);
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);
int findHeight(TreeNode* root);
int countNodes(TreeNode* root);
int countLeaves(TreeNode* root);
void findAncestors(TreeNode* root, int value);
int findDepth(TreeNode* root, int value);
void printTree(TreeNode* root, int level);

// Singly Linked List Node
typedef struct SinglyNode {
    void *data;
    struct SinglyNode *next;
} SinglyNode;

// Doubly Linked List Node
typedef struct DoublyNode {
    void *data;
    struct DoublyNode *next;
    struct DoublyNode *prev;
} DoublyNode;


// StackNode struct
typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

// Stack struct
typedef struct Stack {
    StackNode *top;
    int size;
    int capacity;
} Stack;

// Stack Function prototypes
void stackMenu();
void push(StackNode **top, DataType type, int *size); 
void pop(StackNode **top, DataType type, int *size); 
void peek(Stack *stack, DataType type);
void resetStack(StackNode **top, int *size); 
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void printStack(StackNode *top, DataType type); 


// QUEUE Function proto
void queueMenu();
void enqueue(StackNode **front, StackNode **rear, DataType type, int *size);
void dequeue(StackNode **front, StackNode **rear, DataType type, int *size);
void peekQueue(StackNode *front, DataType type);
void resetQueue(StackNode **front, StackNode **rear, int *size);
void printQueue(StackNode *front, DataType type);

//terminal commands
void setTerminalSize();
void clearScreen();

// Menu's
void mainMenu(int *choice);
void linearDSMenu();
void nonlinDSMenu();
void stringsMenu();
void sortingMenu();
void searchingMenu();
void treeMenu();

// Helper functions for input handling
void fgetsInput(int *value, const char *errorMsg); // Handles integer input
void fgetsInputChar(char *value, const char *errorMsg); // Handles character input
void fgetsInputString(char *value, int size, const char *errorMsg); // Handles string input

//print array func prototype
void printArrayMulti(void *arr, int n, const char *sortType, int iterations, int type);

//print sorted Array
void printSortedArrayMulti(void *arr, int n, int iterations, int type);  // Print sorted array for multiple data types

// Function to display title page and ask if the user wants to continue
int welcomeScreen();

// Function to display program introduction
void introductionScreen();

// Function to clear the input buffer
void clearInputBuffer();

// Helper function to print centered text
void printCentered(const char *text, int width);

//PrintCentered with Dynamic Content
void printCenteredDynamic(int width, const char *format, ...);

// input
void getInput(int *n);

// Searching Algo's
void linSearch(void *arr, int size, void *target, int type);
void binSearch(void *arr, int size, void *target, int type);
void binaryInsertionSort(void *arr, int size, int type);

// Sorting Algo's

/*
    Heap Sort - Prototype Functions
    Heapify functions for multiple data types (Max and Min)

*/ 

// heapify for integers
void maxHeapifyInt(int arr[], int n, int i, int *iterations);  
void minHeapifyInt(int arr[], int n, int i, int *iterations); 

// heapify for characters
void maxHeapifyChar(char arr[], int n, int i, int *iterations);  
void minHeapifyChar(char arr[], int n, int i, int *iterations);  

//heapify for strings
void maxHeapifyString(char *arr[], int n, int i, int *iterations);  
void minHeapifyString(char *arr[], int n, int i, int *iterations);  

// Heap Sort function that uses different heap types
void heapSort();  // Main heap sort function handling Min and Max heap for int, char, string


// radix Sort
void countSortRadix(void *arr, int n, int exp, int* iterations, const char *sortType, int isMSD, int type);
void msdRadixSort(void *arr, int n, int* iterations, const char *sortType, int type);
void lsdRadixSort(void *arr, int n, int* iterations, const char *sortType, int type);
void radixSort();

// quick Sort
int lomutoPartition(void *arr, int low, int high, int* iterations, const char *sortType, int type);
int hoarePartition(void *arr, int low, int high, int* iterations, const char *sortType, int type);
void quickSortHelper(void *arr, int low, int high, int* iterations, int partitionType, const char *sortType, int type);
void quickSort();

// Merge Sort
void mergeSortHelper(void *arr, int l, int r, int* iterations, const char *sortType, int type);
void merge(void *arr, int l, int m, int r, int* iterations, const char *sortType, int type);
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



// Function Prototypes For String
void strGetChar();
void strPutChar();
void length();
void pos();
void concat();
void substring();
void strInsert();
void strDel();
void strComp();
void strSort();
void printCentered(const char *text, int width);
void clearInputBuffer();



//func  for arrays
void arrayMenu(); // Main menu for array operations
void traverseArray(); // Traverses an array and prints its elements
void insertArray(); // Inserts an element into an array
void deleteArray(); // Deletes an element from an array
void mergeArray(); // Merges two arrays into one (to be implemented)


//func for linked list
void linkedListMenu();
void singularLinkedList();
void doublyLinkedList();
void circularLinkedList();
void circularDoublyLinkedList();

void initializeList(void **head, DataType type, int isDoubly, int isCircular);
void insertNode(void **head, DataType type, int isDoubly, int isCircular);
void traverseList(void *head, DataType type, int isDoubly, int isCircular);
void searchList(void *head, DataType type, int isDoubly, int isCircular);
void deleteNode(void **head, DataType type, int isDoubly, int isCircular);
void reverseList(void **head, DataType type, int isDoubly, int isCircular);
void printList(void *head, DataType type, int isDoubly, int isCircular);




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
                clearScreen();
                printCentered("Exiting program. Goodbye!\n", WIDTH);
                break;
            default:
                printCentered("Invalid choice. Try again.\n", WIDTH);
        }
    } while (choice!=6);
    return 0;
}



#include <windows.h>

void setTerminalSize() {
    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the buffer size (scrollback buffer)
    COORD bufferSize;
    bufferSize.X = 120;  // Set the width of the console screen buffer (no horizontal scroll)
    bufferSize.Y = 1000; // Set the height of the console screen buffer (scrollback lines)
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Set the window size (visible part of the terminal)
    SMALL_RECT windowSize = {0, 0, 80, 23};  // 120 columns, 24 rows (no horizontal scroll)
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


void clearScreen() {
    system("cls");
}



//Menu's

// Main Menu
void mainMenu(int *choice) {
    printf("\n");
    printCentered("=== Main Menu ===", WIDTH);
    printCentered("1) Linear DS", WIDTH);
    printCentered("2) Non-Linear DS", WIDTH);
    printCentered("3) Strings", WIDTH);
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
        printCentered("5) Exit", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1:
                arrayMenu(); 
                break;
            case 2:
                linkedListMenu();
                break;
            case 3:
                stackMenu(); 
                break;
            case 4:
                queueMenu();
                break;
            case 5:
                    clearScreen();
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
        printCentered("2) Exit", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                treeMenu();
                break;
            case 2:
                    break;
            default:
                printCentered("Invalid choice. Please try again.", WIDTH);
                clearInputBuffer();
        }
    } while (choice != 2);
}

void stringsMenu(){
    int choice;
    clearScreen();
    do {
        printf("\n");
        printCentered("=== String Menu ===", WIDTH);
        printf("\n");
        printCentered("The String Menu allows you to perform", WIDTH);
        printCentered("various operations on strings such as", WIDTH);
        printCentered("manipulation, searching, and merging.", WIDTH);
        printCentered("Explore functionalities specific to", WIDTH);
        printCentered("string-based data handling.", WIDTH);
        printf("\n");

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
        printCentered("11) Exit", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            strGetChar();
            break;
        case 2:
            strPutChar(); 
            break;
        case 3:
            length(); 
            break;
        case 4:
            pos(); 
            break; 
        case 5:
            concat(); 
            break;
        case 6:
            substring(); 
            break;
        case 7:
            strInsert(); 
            break;
        case 8:
            strDel(); 
            break;
        case 9:
            strComp(); 
            break;
        case 10:
            strSort(); 
            break;
        case 11:
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
        printCentered("=== Sorting Menu Description ===", WIDTH);
        printCentered("The Sorting Menu allows you to choose", WIDTH);
        printCentered("from various sorting algorithms to", WIDTH);
        printCentered("organize data efficiently. It supports", WIDTH);
        printCentered("int, char, and string types.", WIDTH);
        printCentered("Includes popular algorithms like", WIDTH);
        printCentered("Bubble, Quick, and Merge Sort.", WIDTH);
        printf("\n");        
        printCentered("1) Heap Sort", WIDTH);
        printCentered("2) Radix Sort", WIDTH);
        printCentered("3) Quick Sort", WIDTH);
        printCentered("4) Merge Sort", WIDTH);
        printCentered("5) Random Sort", WIDTH);
        printCentered("6) Insertion Sort", WIDTH);
        printCentered("7) Counting Sort", WIDTH);
        printCentered("8) Selection Sort", WIDTH);
        printCentered("9) Bubble Sort", WIDTH);
        printCentered("10) Exit", WIDTH);
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
            clearScreen();
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
            clearInputBuffer();
        }
    } while (choice != 10); 
}

//searching func
void searchingMenu() {
    int choice, n, type;
    do {
        printf("\n");
        printCentered("=== Searching Menu ===", WIDTH);
        printCentered("The Searching Menu offers functionalities", WIDTH);
        printCentered("to find elements in arrays using", WIDTH);
        printCentered("methods like Linear Search and Binary", WIDTH);
        printCentered("Search. Supports int, char, and string", WIDTH);
        printCentered("data types.", WIDTH);
        printf("\n");
        printCentered("1) Linear Search", WIDTH);
        printCentered("2) Binary Search", WIDTH);
        printCentered("3) Exit", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        fgetsInput(&choice, "Invalid input. Please enter a valid choice.");

        switch (choice) {
        case 1: { // Linear Search
            clearScreen();
            printCentered("=== Linear Search ===", WIDTH);
            printf("\n");
            printCentered("Linear Search is one of the simplest search algorithms.", WIDTH);
            printCentered("It works by sequentially checking each element of the array", WIDTH);
            printCentered("until the desired element is found or the end is reached.", WIDTH);
            printf("\n");
            printCentered("Best suited for small or unsorted datasets where efficiency", WIDTH);
            printCentered("is not critical.", WIDTH);
            printf("\n");
            printCentered("In this program, you will:", WIDTH);
            printCentered("- Input an array of integers, characters, or strings.", WIDTH);
            printCentered("- Specify the element you wish to search for.", WIDTH);
            printCentered("- Get feedback on whether and where the element exists.", WIDTH);
            printf("\n");
            printf("Enter the number of elements: ");
            fgetsInput(&n, "Invalid input. Please enter a valid number.");

            printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
            fgetsInput(&type, "Invalid input. Please enter a valid choice.");

            void *arr;
            void *target;
            int isInt = 0, isChar = 0, isString = 0;

            if (type == 1) { // Integer array
                arr = malloc(n * sizeof(int));
                target = malloc(sizeof(int));
                isInt = 1;
            } else if (type == 2) { // Character array
                arr = malloc(n * sizeof(char));
                target = malloc(sizeof(char));
                isChar = 1;
            } else if (type == 3) { // String array
                arr = malloc(n * sizeof(char *));
                target = malloc(100 * sizeof(char));
                isString = 1;
            } else {
                printf("Invalid input.\n");
                break;
            }

            // Input elements
            printf("Enter the elements (Press Enter for Each):\n");
            if (isInt) {
                int *intArr = (int *)arr;
                for (int i = 0; i < n; i++) {
                    fgetsInput(&intArr[i], "Invalid input. Please enter an integer.");
                }
            } else if (isChar) {
                char *charArr = (char *)arr;
                for (int i = 0; i < n; i++) {
                    fgetsInputChar(&charArr[i], "Invalid input. Please enter a character.");
                }
            } else if (isString) {
                char **strArr = (char **)arr;
                for (int i = 0; i < n; i++) {
                    strArr[i] = malloc(100 * sizeof(char));
                    fgetsInputString(strArr[i], 100, "Invalid input. Please enter a string.");
                }
            }

            // Input target
            printf("Enter the element to search for: ");
            if (isInt) {
                fgetsInput((int *)target, "Invalid input. Please enter an integer.");
            } else if (isChar) {
                fgetsInputChar((char *)target, "Invalid input. Please enter a character.");
            } else if (isString) {
                fgetsInputString((char *)target, 100, "Invalid input. Please enter a string.");
            }

            // Perform linear search
            linSearch(arr, n, target, type);

            // Free allocated memory
            if (isString) {
                char **strArr = (char **)arr;
                for (int i = 0; i < n; i++) {
                    free(strArr[i]);
                }
            }
            free(arr);
            free(target);
            break;
        }
        case 2: { // Binary Search
            clearScreen();
            printCentered("=== Binary Search ===", WIDTH);
            printf("\n");
            printCentered("Binary Search is a highly efficient search algorithm used", WIDTH);
            printCentered("on sorted arrays. It works by repeatedly dividing the search", WIDTH);
            printCentered("space in half, eliminating half of the remaining elements", WIDTH);
            printCentered("with each step.", WIDTH);
            printf("\n");
            printCentered("Best suited for large datasets where efficiency is critical,", WIDTH);
            printCentered("but the array must be sorted for this algorithm to work.", WIDTH);
            printf("\n");
            printCentered("In this program, you will:", WIDTH);
            printCentered("- Input a sorted array of integers, characters, or strings.", WIDTH);
            printCentered("- Specify the element you wish to search for.", WIDTH);
            printCentered("- Get feedback on whether the element exists and its position.", WIDTH);
            printf("\n");
            printf("Enter the number of elements: ");
            fgetsInput(&n, "Invalid input. Please enter a valid number.");

            printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
            fgetsInput(&type, "Invalid input. Please enter a valid choice.");

            void *arr;
            void *target;
            int isInt = 0, isChar = 0, isString = 0;

            if (type == 1) { // Integer array
                arr = malloc(n * sizeof(int));
                target = malloc(sizeof(int));
                isInt = 1;
            } else if (type == 2) { // Character array
                arr = malloc(n * sizeof(char));
                target = malloc(sizeof(char));
                isChar = 1;
            } else if (type == 3) { // String array
                arr = malloc(n * sizeof(char *));
                target = malloc(100 * sizeof(char));
                isString = 1;
            } else {
                printf("Invalid input.\n");
                break;
            }

            // Input elements
            printf("Enter the elements (Press Enter for Each):\n");
            if (isInt) {
                int *intArr = (int *)arr;
                for (int i = 0; i < n; i++) {
                    fgetsInput(&intArr[i], "Invalid input. Please enter an integer.");
                }
            } else if (isChar) {
                char *charArr = (char *)arr;
                for (int i = 0; i < n; i++) {
                    fgetsInputChar(&charArr[i], "Invalid input. Please enter a character.");
                }
            } else if (isString) {
                char **strArr = (char **)arr;
                for (int i = 0; i < n; i++) {
                    strArr[i] = malloc(100 * sizeof(char));
                    fgetsInputString(strArr[i], 100, "Invalid input. Please enter a string.");
                }
            }

            // Input target
            printf("Enter the element to search for: ");
            if (isInt) {
                fgetsInput((int *)target, "Invalid input. Please enter an integer.");
            } else if (isChar) {
                fgetsInputChar((char *)target, "Invalid input. Please enter a character.");
            } else if (isString) {
                fgetsInputString((char *)target, 100, "Invalid input. Please enter a string.");
            }

            // Perform binary search
            binSearch(arr, n, target, type);

            // Free allocated memory
            if (isString) {
                char **strArr = (char **)arr;
                for (int i = 0; i < n; i++) {
                    free(strArr[i]);
                }
            }
            free(arr);
            free(target);
            break;
        }
        case 3:
            clearScreen();
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
        }
    } while (choice != 3);
}


void fgetsInput(int *value, const char *errorMsg) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (sscanf(buffer, "%d", value) == 1) return;
        printf("%s\n", errorMsg);
    }
}

void fgetsInputChar(char *value, const char *errorMsg) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (sscanf(buffer, " %c", value) == 1) return;
        printf("%s\n", errorMsg);
    }
}

void fgetsInputString(char *value, int size, const char *errorMsg) {
    while (fgets(value, size, stdin)) {
        value[strcspn(value, "\n")] = '\0';  // Remove trailing newline
        if (strlen(value) > 0) return;
        printf("%s\n", errorMsg);
    }
}



// Minor Menu's
// Updated treeMenu with tree visualization
void treeMenu() {
    int choice;
    TreeNode* root = NULL;

    do {
        clearScreen(); // Clear the screen for a fresh display
        printCentered("=== Tree Menu ===", WIDTH);
        printf("\n");
        printCentered("Current Tree:", WIDTH);

        if (root == NULL) {
            printCentered("[ Empty Tree ]", WIDTH);
        } else {
            printTree(root, 0); // Print the tree visually
        }

        printf("\n");
        printCentered("1) Insert", WIDTH);
        printCentered("2) Delete", WIDTH);
        printCentered("3) Inorder Traversal", WIDTH);
        printCentered("4) Preorder Traversal", WIDTH);
        printCentered("5) Postorder Traversal", WIDTH);
        printCentered("6) Find Height", WIDTH);
        printCentered("7) Count Nodes", WIDTH);
        printCentered("8) Count Leaves", WIDTH);
        printCentered("9) Find Ancestors", WIDTH);
        printCentered("10) Find Depth", WIDTH);
        printCentered("11) Exit", WIDTH);
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("\n");
                printCentered("Enter value to insert: ", WIDTH);
                scanf("%d", &value);
                root = insertInt(root, value);
                break;
            }
            case 2: {
                int value;
                printf("\n");
                printCentered("Enter value to delete: ", WIDTH);
                scanf("%d", &value);
                root = deleteInt(root, value);
                break;
            }
            case 3:
                printf("\n");
                printCentered("Inorder Traversal: ", WIDTH);
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("\n");
                printCentered("Preorder Traversal: ", WIDTH);
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("\n");
                printCentered("Postorder Traversal: ", WIDTH);
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("\n");
                printCenteredDynamic(WIDTH, "Height of the tree: %d", findHeight(root));
                break;
            case 7:
                printf("\n");
                printCenteredDynamic(WIDTH, "Total nodes: %d", countNodes(root));
                break;
            case 8:
                printf("\n");
                printCenteredDynamic(WIDTH, "Total leaves: %d", countLeaves(root));
                break;
            case 9: {
                int value;
                printf("\n");
                printCentered("Enter value to find ancestors: ", WIDTH);
                scanf("%d", &value);
                findAncestors(root, value);
                printf("\n");
                break;
            }
            case 10: {
                int value;
                printf("\n");
                printCentered("Enter value to find depth: ", WIDTH);
                scanf("%d", &value);
                printCenteredDynamic(WIDTH, "Depth of node %d: %d", value, findDepth(root, value));
                break;
            }
            case 11:
                printf("\n");
                printCentered("Exiting... Thank you!", WIDTH);
                break;
            default:
                printf("\n");
                printCentered("Invalid choice. Please try again.", WIDTH);
        }

    } while (choice != 11);
}


// Function to print the tree with L and R labels
void printTree(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }

    // Print the right subtree first (to visually align the tree structure)
    printTree(root->right, level + 1);

    // Print the current node with indentation based on the level
    for (int i = 0; i < level * 4; i++) {  // Indentation based on level
        printf(" ");
    }

    // Print the node data
    printf("[ %d ]", root->data);

    // Print left child label if it has left child
    if (root->left != NULL) {
        printf(" L\n");
    } else if (root->right != NULL) {
        printf(" R\n");
    } else {
        printf("\n");
    }

    // Print the left subtree
    printTree(root->left, level + 1);
}

// Helper: Print array for multiple data types
void printArrayMulti(void *arr, int n, const char *sortType, int iterations, int type) {
    char buffer[WIDTH];
    int length = 0;

    printf("\n");
    length += snprintf(buffer + length, sizeof(buffer) - length, "%s - Iteration %d: ", sortType, iterations);

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        for (int i = 0; i < n && length < sizeof(buffer) - 1; i++) {
            length += snprintf(buffer + length, sizeof(buffer) - length, "%d ", intArr[i]);
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        for (int i = 0; i < n && length < sizeof(buffer) - 1; i++) {
            length += snprintf(buffer + length, sizeof(buffer) - length, "%c ", charArr[i]);
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        for (int i = 0; i < n && length < sizeof(buffer) - 1; i++) {
            length += snprintf(buffer + length, sizeof(buffer) - length, "%s ", strArr[i]);
        }
    }

    int padding = (WIDTH - strlen(buffer)) / 2;
    if (padding < 0) padding = 0;
    printf("%*s%s\n", padding, "", buffer);
}

void printSortedArrayMulti(void *arr, int n, int iterations, int type) {
    printCentered("\nSorted Array:\n", WIDTH);
    printArrayMulti(arr, n, "Final Result", iterations, type);
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

//PrintCentered with Dynamic Content
void printCenteredDynamic(int width, const char *format, ...) {
    char buffer[200]; // Temporary buffer for the formatted message

    // Create the formatted string
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    // Use printCentered to print the formatted message
    printCentered(buffer, width);
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
    printf("\n");
    printCentered("Version 0.1: Initial Release!", WIDTH);
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
        clearInputBuffer();
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

// Heapify function for integers
void maxHeapifyInt(int arr[], int n, int i, int *iterations) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*iterations)++;
        printArrayMulti(arr, n, "Heapify (Integer)", *iterations, 1);
        maxHeapifyInt(arr, n, largest, iterations);
    }
}

// Heapify function for characters
void maxHeapifyChar(char arr[], int n, int i, int *iterations) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        char temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*iterations)++;
        printArrayMulti(arr, n, "Heapify (Character)", *iterations, 2);
        maxHeapifyChar(arr, n, largest, iterations);
    }
}

// Heapify function for strings
void maxHeapifyString(char *arr[], int n, int i, int *iterations) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && strcmp(arr[left], arr[largest]) > 0) largest = left;
    if (right < n && strcmp(arr[right], arr[largest]) > 0) largest = right;

    if (largest != i) {
        char *temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*iterations)++;
        printArrayMulti(arr, n, "Heapify (String)", *iterations, 3);
        maxHeapifyString(arr, n, largest, iterations);
    }
}

//min Heapify func for int
void minHeapifyInt(int arr[], int n, int i, int *iterations) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        (*iterations)++;
        printArrayMulti(arr, n, "Heapify (Integer - Min)", *iterations, 1);
        minHeapifyInt(arr, n, smallest, iterations);
    }
}

// min Heapify func for char
void minHeapifyChar(char arr[], int n, int i, int *iterations) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i) {
        char temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        (*iterations)++;
        printArrayMulti(arr, n, "Heapify (Character - Min)", *iterations, 2);
        minHeapifyChar(arr, n, smallest, iterations);
    }
}

//min Heapify func for string
void minHeapifyString(char *arr[], int n, int i, int *iterations) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && strcmp(arr[left], arr[smallest]) < 0) smallest = left;
    if (right < n && strcmp(arr[right], arr[smallest]) < 0) smallest = right;

    if (smallest != i) {
        char *temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        (*iterations)++;
        printArrayMulti(arr, n, "Heapify (String - Min)", *iterations, 3);
        minHeapifyString(arr, n, smallest, iterations);
    }
}



// Heap Sort function for multiple data types
void heapSort() {
    int type, heapType, n, iterations = 0;
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);
    clearInputBuffer(); 

    // Choose heap type (Min Heap or Max Heap)
    printf("Choose Heap Type: 1) Max Heap 2) Min Heap: ");
    scanf("%d", &heapType);
    clearInputBuffer();

    if (type == 1) { // Integer
        printf("Enter number of elements: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the integers: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        if (heapType == 1) { // Max Heap
            // Build the Max Heap
            for (int i = n / 2 - 1; i >= 0; i--) maxHeapifyInt(arr, n, i, &iterations);
            // Perform the sorting using Max Heap
            for (int i = n - 1; i > 0; i--) {
                int temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                iterations++;
                printArrayMulti(arr, n, "Heap Sort (Integer - Max)", iterations, 1);
                maxHeapifyInt(arr, i, 0, &iterations);
            }
        } else { // Min Heap
            // Build the Min Heap
            for (int i = n / 2 - 1; i >= 0; i--) minHeapifyInt(arr, n, i, &iterations);
            // Perform the sorting using Min Heap
            for (int i = n - 1; i > 0; i--) {
                int temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                iterations++;
                printArrayMulti(arr, n, "Heap Sort (Integer - Min)", iterations, 1);
                minHeapifyInt(arr, i, 0, &iterations);
            }
        }

        printSortedArrayMulti(arr, n, iterations, 1);

    } else if (type == 2) { // Character
        printf("Enter number of elements: ");
        scanf("%d", &n);
        char arr[n];
        printf("Enter the characters: ");
        for (int i = 0; i < n; i++) scanf(" %c", &arr[i]);

        if (heapType == 1) { // Max Heap for characters
            // Build the Max Heap
            for (int i = n / 2 - 1; i >= 0; i--) maxHeapifyChar(arr, n, i, &iterations);
            // Perform the sorting using Max Heap
            for (int i = n - 1; i > 0; i--) {
                char temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                iterations++;
                printArrayMulti(arr, n, "Heap Sort (Character - Max)", iterations, 2);
                maxHeapifyChar(arr, i, 0, &iterations);
            }
        } else { // Min Heap for characters
            // Build the Min Heap
            for (int i = n / 2 - 1; i >= 0; i--) minHeapifyChar(arr, n, i, &iterations);
            // Perform the sorting using Min Heap
            for (int i = n - 1; i > 0; i--) {
                char temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                iterations++;
                printArrayMulti(arr, n, "Heap Sort (Character - Min)", iterations, 2);
                minHeapifyChar(arr, i, 0, &iterations);
            }
        }

        printSortedArrayMulti(arr, n, iterations, 2);

    } else if (type == 3) { // String
        printf("Enter number of elements: ");
        scanf("%d", &n);
        clearInputBuffer();        
        char *arr[n];
        printf("Enter the strings (press enter for each string): ");
        for (int i = 0; i < n; i++) {
            arr[i] = malloc(100 * sizeof(char)); // Allocate memory for strings
            fgets(arr[i], 100, stdin);
            arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove newline
        }

        if (heapType == 1) { // Max Heap for strings
            // Build the Max Heap
            for (int i = n / 2 - 1; i >= 0; i--) maxHeapifyString(arr, n, i, &iterations);
            // Perform the sorting using Max Heap
            for (int i = n - 1; i > 0; i--) {
                char *temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                iterations++;
                printArrayMulti(arr, n, "Heap Sort (String - Max)", iterations, 3);
                maxHeapifyString(arr, i, 0, &iterations);
            }
        } else { // Min Heap for strings
            // Build the Min Heap
            for (int i = n / 2 - 1; i >= 0; i--) minHeapifyString(arr, n, i, &iterations);
            // Perform the sorting using Min Heap
            for (int i = n - 1; i > 0; i--) {
                char *temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                iterations++;
                printArrayMulti(arr, n, "Heap Sort (String - Min)", iterations, 3);
                minHeapifyString(arr, i, 0, &iterations);
            }
        }

        printSortedArrayMulti(arr, n, iterations, 3);

        for (int i = 0; i < n; i++) free(arr[i]); // Free allocated memory

    } else {
        printf("Invalid type chosen.\n");
    }
}


// Radix Sort - Count Sort (works for int, char, and string)
void countSortRadix(void *arr, int n, int exp, int* iterations, const char *sortType, int isMSD, int type) {
    void *output = malloc(n * sizeof(arr));  // Allocate memory for the output array
    int count[10] = {0};

    // Count occurrences of digits or characters
    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            count[(intArr[i] / exp) % 10]++;
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            count[(charArr[i] / exp) % 10]++;
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            count[(strArr[i][0] / exp) % 10]++;  // Compare first character in string
        }
    }

    // Convert count[] to position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        for (int i = n - 1; i >= 0; i--) {
            int value = intArr[i];
            int index = count[(value / exp) % 10] - 1;
            ((int *)output)[index] = value;
            count[(value / exp) % 10]--;
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        for (int i = n - 1; i >= 0; i--) {
            char value = charArr[i];
            int index = count[(value / exp) % 10] - 1;
            ((char *)output)[index] = value;
            count[(value / exp) % 10]--;
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        for (int i = n - 1; i >= 0; i--) {
            char *value = strArr[i];
            int index = count[(value[0] / exp) % 10] - 1;
            ((char **)output)[index] = value;
            count[(value[0] / exp) % 10]--;
        }
    }

    // Copy the sorted output back to the original array
    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            intArr[i] = ((int *)output)[i];
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            charArr[i] = ((char *)output)[i];
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = ((char **)output)[i];
        }
    }

    printArrayMulti(arr, n, sortType, *iterations, type);  // Print after each iteration

    free(output);  // Free allocated memory

    // For MSD: Recursively sort buckets if needed
    if (isMSD) {
        for (int i = 0; i < 10; i++) {
            int start = (i == 0) ? 0 : count[i - 1];
            int end = count[i];
            if (start < end) {  // Non-empty bucket
                countSortRadix(arr + start, end - start, exp / 10, iterations, sortType, isMSD, type);
            }
        }
    }
}

// LSD Radix Sort (works for int, char, and string)
void lsdRadixSort(void *arr, int n, int* iterations, const char *sortType, int type) {
    int max = 0;

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        max = intArr[0];
        for (int i = 1; i < n; i++) {
            if (intArr[i] > max)
                max = intArr[i];
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        max = charArr[0];
        for (int i = 1; i < n; i++) {
            if (charArr[i] > max)
                max = charArr[i];
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        max = strArr[0][0]; // Compare the first character of each string
        for (int i = 1; i < n; i++) {
            if (strArr[i][0] > max)
                max = strArr[i][0];
        }
    }
    
    // Perform LSD sorting for each digit (from least significant to most)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp, iterations, sortType, 0, type);  // LSD does not use recursion
}

// MSD Radix Sort (works for int, char, and string)
void msdRadixSort(void *arr, int n, int* iterations, const char *sortType, int type) {
    int max = 0;

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        max = intArr[0];
        for (int i = 1; i < n; i++) {
            if (intArr[i] > max)
                max = intArr[i];
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        max = charArr[0];
        for (int i = 1; i < n; i++) {
            if (charArr[i] > max)
                max = charArr[i];
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        max = strArr[0][0]; // Compare the first character of each string
        for (int i = 1; i < n; i++) {
            if (strArr[i][0] > max)
                max = strArr[i][0];
        }
    }

    // Perform MSD sorting by checking each digit starting from the most significant
    int exp = 1;
    while (max / exp > 9)
        exp *= 10;  // Find the most significant digit's place value

    countSortRadix(arr, n, exp, iterations, sortType, 1, type);  // MSD uses recursion
}

// Main Radix Sort function that works for int, char, and string
void radixSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    printf("Choose Radix Type (1 for LSD, 2 for MSD): ");
    scanf("%d", &type);
    clearInputBuffer();

    const char *sortType = "Radix Sort";

    if (type == 1) {
        lsdRadixSort(arr, n, &iterations, sortType, type);
    } else if (type == 2) {
        msdRadixSort(arr, n, &iterations, sortType, type);
    } else {
        printf("Invalid choice.\n");
        return;
    }

    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory if strings were used
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}



// Quick Sort
// Lomuto Partition for multiple data types (int, char, string)
int lomutoPartition(void *arr, int low, int high, int* iterations, const char *sortType, int type) {
    int pivotIndex = high;
    int i = low - 1;

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        int pivot = intArr[pivotIndex];
        for (int j = low; j < high; j++) {
            (*iterations)++;
            if (intArr[j] < pivot) {
                i++;
                int temp = intArr[i];
                intArr[i] = intArr[j];
                intArr[j] = temp;
                printArrayMulti(arr, high + 1, sortType, *iterations, 1);
            }
        }
        int temp = intArr[i + 1];
        intArr[i + 1] = intArr[pivotIndex];
        intArr[pivotIndex] = temp;
        return i + 1;
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        char pivot = charArr[pivotIndex];
        for (int j = low; j < high; j++) {
            (*iterations)++;
            if (charArr[j] < pivot) {
                i++;
                char temp = charArr[i];
                charArr[i] = charArr[j];
                charArr[j] = temp;
                printArrayMulti(arr, high + 1, sortType, *iterations, 2);
            }
        }
        char temp = charArr[i + 1];
        charArr[i + 1] = charArr[pivotIndex];
        charArr[pivotIndex] = temp;
        return i + 1;
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        char *pivot = strArr[pivotIndex];
        for (int j = low; j < high; j++) {
            (*iterations)++;
            if (strcmp(strArr[j], pivot) < 0) {
                i++;
                char *temp = strArr[i];
                strArr[i] = strArr[j];
                strArr[j] = temp;
                printArrayMulti(arr, high + 1, sortType, *iterations, 3);
            }
        }
        char *temp = strArr[i + 1];
        strArr[i + 1] = strArr[pivotIndex];
        strArr[pivotIndex] = temp;
        return i + 1;
    }
    return 0; // Invalid type
}

// Hoare Partition for multiple data types (int, char, string)
int hoarePartition(void *arr, int low, int high, int* iterations, const char *sortType, int type) {
    int pivotIndex = low;
    int i = low - 1, j = high + 1;

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        int pivot = intArr[pivotIndex];
        while (1) {
            do {
                i++;
                (*iterations)++;
            } while (intArr[i] < pivot);
            do {
                j--;
                (*iterations)++;
            } while (intArr[j] > pivot);
            if (i >= j)
                return j;
            int temp = intArr[i];
            intArr[i] = intArr[j];
            intArr[j] = temp;
            printArrayMulti(arr, high + 1, sortType, *iterations, 1);
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        char pivot = charArr[pivotIndex];
        while (1) {
            do {
                i++;
                (*iterations)++;
            } while (charArr[i] < pivot);
            do {
                j--;
                (*iterations)++;
            } while (charArr[j] > pivot);
            if (i >= j)
                return j;
            char temp = charArr[i];
            charArr[i] = charArr[j];
            charArr[j] = temp;
            printArrayMulti(arr, high + 1, sortType, *iterations, 2);
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        char *pivot = strArr[pivotIndex];
        while (1) {
            do {
                i++;
                (*iterations)++;
            } while (strcmp(strArr[i], pivot) < 0);
            do {
                j--;
                (*iterations)++;
            } while (strcmp(strArr[j], pivot) > 0);
            if (i >= j)
                return j;
            char *temp = strArr[i];
            strArr[i] = strArr[j];
            strArr[j] = temp;
            printArrayMulti(arr, high + 1, sortType, *iterations, 3);
        }
    }
    return 0; // Invalid type
}

// QuickSort Helper for multiple data types (int, char, string)
void quickSortHelper(void *arr, int low, int high, int* iterations, int partitionType, const char *sortType, int type) {
    if (low < high) {
        int pi;
        if (partitionType == 1)  // Lomuto Partition
            pi = lomutoPartition(arr, low, high, iterations, sortType, type);
        else  // Hoare Partition
            pi = hoarePartition(arr, low, high, iterations, sortType, type);
        quickSortHelper(arr, low, pi - 1, iterations, partitionType, sortType, type);
        quickSortHelper(arr, pi + 1, high, iterations, partitionType, sortType, type);
    }
}

// QuickSort for multiple data types (int, char, string)
void quickSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    printf("Choose Partition Type (1 for Lomuto, 2 for Hoare): ");
    scanf("%d", &type);
    clearInputBuffer();

    const char *sortType = "Quick Sort";

    quickSortHelper(arr, 0, n - 1, &iterations, type, sortType, type);

    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory if strings were used
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}


// Merge 
// Merge function for multiple data types (int, char, string)
void merge(void *arr, int l, int m, int r, int* iterations, const char *sortType, int type) {
    int n1 = m - l + 1;
    int n2 = r - m;
    void *L = malloc(n1 * sizeof(arr));  // Left half
    void *R = malloc(n2 * sizeof(arr));  // Right half

    // Copy data into temporary arrays L[] and R[]
    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        int *L_int = (int *)L;
        int *R_int = (int *)R;
        for (int i = 0; i < n1; i++) L_int[i] = intArr[l + i];
        for (int i = 0; i < n2; i++) R_int[i] = intArr[m + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            (*iterations)++;
            if (L_int[i] <= R_int[j]) {
                intArr[k] = L_int[i];
                i++;
            } else {
                intArr[k] = R_int[j];
                j++;
            }
            k++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 1);  // Print after each merge step
        }

        while (i < n1) {
            intArr[k] = L_int[i];
            i++;
            k++;
            (*iterations)++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 1);  // Print after adding remaining elements
        }

        while (j < n2) {
            intArr[k] = R_int[j];
            j++;
            k++;
            (*iterations)++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 1);  // Print after adding remaining elements
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        char *L_char = (char *)L;
        char *R_char = (char *)R;
        for (int i = 0; i < n1; i++) L_char[i] = charArr[l + i];
        for (int i = 0; i < n2; i++) R_char[i] = charArr[m + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            (*iterations)++;
            if (L_char[i] <= R_char[j]) {
                charArr[k] = L_char[i];
                i++;
            } else {
                charArr[k] = R_char[j];
                j++;
            }
            k++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 2);  // Print after each merge step
        }

        while (i < n1) {
            charArr[k] = L_char[i];
            i++;
            k++;
            (*iterations)++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 2);  // Print after adding remaining elements
        }

        while (j < n2) {
            charArr[k] = R_char[j];
            j++;
            k++;
            (*iterations)++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 2);  // Print after adding remaining elements
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        char **L_str = (char **)L;
        char **R_str = (char **)R;
        for (int i = 0; i < n1; i++) L_str[i] = strArr[l + i];
        for (int i = 0; i < n2; i++) R_str[i] = strArr[m + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            (*iterations)++;
            if (strcmp(L_str[i], R_str[j]) <= 0) {
                strArr[k] = L_str[i];
                i++;
            } else {
                strArr[k] = R_str[j];
                j++;
            }
            k++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 3);  // Print after each merge step
        }

        while (i < n1) {
            strArr[k] = L_str[i];
            i++;
            k++;
            (*iterations)++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 3);  // Print after adding remaining elements
        }

        while (j < n2) {
            strArr[k] = R_str[j];
            j++;
            k++;
            (*iterations)++;
            printArrayMulti(arr, r + 1, sortType, *iterations, 3);  // Print after adding remaining elements
        }
    }

    free(L); // Free temporary arrays
    free(R); // Free temporary arrays
}

// MergeSort Helper for multiple data types (int, char, string)
void mergeSortHelper(void *arr, int l, int r, int* iterations, const char *sortType, int type) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, iterations, sortType, type);
        mergeSortHelper(arr, m + 1, r, iterations, sortType, type);
        merge(arr, l, m, r, iterations, sortType, type);
    }
}

// MergeSort for multiple data types (int, char, string)
void mergeSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    const char *sortType = "Merge Sort";
    mergeSortHelper(arr, 0, n - 1, &iterations, sortType, type);

    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory if strings were used
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}



// Random Sort
// Random Sort (BogoSort) - Generic for int, char, and string
void randSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    // Shuffle and check for sorting
    int sorted = 0;
    unsigned int seed = (unsigned int)time(NULL); // Random seed based on current time
    srand(seed); // Initialize the random number generator using srand()
    const char *sortType = "Random Sort";

    while (!sorted) {
        // Shuffle array using rand()
        if (isInt) { // Integer array
            int *intArr = (int *)arr;
            for (int i = 0; i < n; i++) {
                int randomIndex = rand() % n;  // Use rand() for generating random index
                int temp = intArr[i];
                intArr[i] = intArr[randomIndex];
                intArr[randomIndex] = temp;
            }
        } else if (isChar) { // Character array
            char *charArr = (char *)arr;
            for (int i = 0; i < n; i++) {
                int randomIndex = rand() % n;  // Use rand() for generating random index
                char temp = charArr[i];
                charArr[i] = charArr[randomIndex];
                charArr[randomIndex] = temp;
            }
        } else if (isString) { // String array
            char **strArr = (char **)arr;
            for (int i = 0; i < n; i++) {
                int randomIndex = rand() % n;  // Use rand() for generating random index
                char *temp = strArr[i];
                strArr[i] = strArr[randomIndex];
                strArr[randomIndex] = temp;
            }
        }

        // Increment iteration counter
        iterations++;

        // Use printArrayMulti to display the current shuffle
        printArrayMulti(arr, n, sortType, iterations, type);

        // Check if sorted
        sorted = 1;
        if (isInt) {
            int *intArr = (int *)arr;
            for (int i = 1; i < n; i++) {
                if (intArr[i] < intArr[i - 1]) {
                    sorted = 0;
                    break;
                }
            }
        } else if (isChar) {
            char *charArr = (char *)arr;
            for (int i = 1; i < n; i++) {
                if (charArr[i] < charArr[i - 1]) {
                    sorted = 0;
                    break;
                }
            }
        } else if (isString) {
            char **strArr = (char **)arr;
            for (int i = 1; i < n; i++) {
                if (strcmp(strArr[i], strArr[i - 1]) < 0) {
                    sorted = 0;
                    break;
                }
            }
        }
    }

    // Display final sorted array
    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory if strings were used
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}

// Insertion Sort for multiple data types (int, char, string)
void insertSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    const char *sortType = "Insertion Sort";

    // Insertion Sort logic for different data types
    for (int i = 1; i < n; i++) {
        if (isInt) { // Integer array
            int *intArr = (int *)arr;
            int key = intArr[i];
            int j = i - 1;

            while (j >= 0 && intArr[j] > key) {
                intArr[j + 1] = intArr[j];
                j--;
            }
            intArr[j + 1] = key;
        } else if (isChar) { // Character array
            char *charArr = (char *)arr;
            char key = charArr[i];
            int j = i - 1;

            while (j >= 0 && charArr[j] > key) {
                charArr[j + 1] = charArr[j];
                j--;
            }
            charArr[j + 1] = key;
        } else if (isString) { // String array
            char **strArr = (char **)arr;
            char *key = strArr[i];
            int j = i - 1;

            while (j >= 0 && strcmp(strArr[j], key) > 0) {
                strArr[j + 1] = strArr[j];
                j--;
            }
            strArr[j + 1] = key;
        }

        iterations++;  // Increment iteration after each insertion step
        printArrayMulti(arr, n, sortType, iterations, type);  // Print array after each insertion step
    }

    printSortedArrayMulti(arr, n, iterations, type);  // Print final sorted array

    // Free memory for string arrays
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}


// Count Sort for multiple data types (int, char, string)
// Count Sort for multiple data types (int, char, string)
void countSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    int max;

    // Find max value (for int or char arrays)
    if (isInt) {
        int *intArr = (int *)arr;
        max = intArr[0];
        for (int i = 1; i < n; i++) if (intArr[i] > max) max = intArr[i];
    } else if (isChar) {
        char *charArr = (char *)arr;
        max = charArr[0];
        for (int i = 1; i < n; i++) if (charArr[i] > max) max = charArr[i];
    } else if (isString) {
        // For strings, calculate max based on the first character (simplified)
        char **strArr = (char **)arr;
        max = strArr[0][0];
        for (int i = 1; i < n; i++) if (strArr[i][0] > max) max = strArr[i][0];
    }

    // Create the count array for occurrences
    int count[max + 1];
    for (int i = 0; i <= max; i++) count[i] = 0;

    // Count the occurrences of each element (for int, char, or string arrays)
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) count[intArr[i]]++;
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) count[charArr[i]]++;
    } else if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) count[strArr[i][0]]++;  // Count based on the first character
    }

    iterations++;  // Increment iteration after count array is filled
    printArrayMulti(count, max + 1, "Counting Sort - Count Array", iterations, type);  // Print count array after counting

    // Update count array with cumulative counts
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    iterations++;  // Increment iteration after cumulative count
    printArrayMulti(count, max + 1, "Counting Sort - Cumulative Count", iterations, type);  // Print cumulative count array

    // Create output array to store sorted values
    int output[n];

    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = n - 1; i >= 0; i--) {
            output[count[intArr[i]] - 1] = intArr[i];
            count[intArr[i]]--;
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = n - 1; i >= 0; i--) {
            output[count[charArr[i]] - 1] = charArr[i];
            count[charArr[i]]--;
        }
    } else if (isString) {
        char **strArr = (char **)arr;
        for (int i = n - 1; i >= 0; i--) {
            output[count[strArr[i][0]] - 1] = (int)strArr[i];  // For simplicity, store as int (based on first character)
            count[strArr[i][0]]--;
        }
    }

    iterations++;  // Increment iteration after placing elements in output array
    printArrayMulti(output, n, "Counting Sort - Output Array", iterations, type);  // Print output array

    // Copy the output array back to the original array
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) intArr[i] = output[i];
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) charArr[i] = output[i];
    } else if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) strArr[i] = (char *)output[i];  // Convert back to string type
    }

    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory if strings were used
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}



// selection sort
// Selection Sort for multiple data types (int, char, string)
void selecSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    // Initial array print
    const char *sortType = "Selection Sort";
    printArrayMulti(arr, n, "Selection Sort - Initial Array", ++iterations, type);

    // Selection Sort Algorithm with display after each iteration
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Find the minimum element in unsorted array
        if (isInt) {
            int *intArr = (int *)arr;
            for (int j = i + 1; j < n; j++) {
                if (intArr[j] < intArr[minIdx]) {
                    minIdx = j;
                }
            }
            // Swap the found minimum element with the first element
            int temp = intArr[minIdx];
            intArr[minIdx] = intArr[i];
            intArr[i] = temp;
        } else if (isChar) {
            char *charArr = (char *)arr;
            for (int j = i + 1; j < n; j++) {
                if (charArr[j] < charArr[minIdx]) {
                    minIdx = j;
                }
            }
            // Swap the found minimum element with the first element
            char temp = charArr[minIdx];
            charArr[minIdx] = charArr[i];
            charArr[i] = temp;
        } else if (isString) {
            char **strArr = (char **)arr;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(strArr[j], strArr[minIdx]) < 0) {
                    minIdx = j;
                }
            }
            // Swap the found minimum element with the first element
            char *temp = strArr[minIdx];
            strArr[minIdx] = strArr[i];
            strArr[i] = temp;
        }

        iterations++;  // Increment iteration after each selection step
        printArrayMulti(arr, n, "Selection Sort - After Iteration", iterations, type);  // Print array after each selection step
    }

    // Final sorted array print
    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory for string arrays
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}


// Bubble Sort for multiple data types (int, char, string)
void bubbleSort() {
    int n, type, iterations = 0;
    getInput(&n);
    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    // Choosing the type of array
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);
    clearInputBuffer();

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        isString = 1;
    } else {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter the elements ");
    clearInputBuffer();
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &intArr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clearInputBuffer();
            }
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &charArr[i]) != 1) {
                printf("Invalid input. Please enter a character: ");
                clearInputBuffer();
            }
        }
    } else if (isString) {
        printf("(Press Enter for Each String): ");
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char)); // Allocate space for strings
            fgets(strArr[i], 100, stdin);
            strArr[i][strcspn(strArr[i], "\n")] = '\0';  // Remove newline character
        }
    }

    // Initial Array print
    const char *sortType = "Bubble Sort";
    printArrayMulti(arr, n, "Bubble Sort - Initial Array", ++iterations, type);

    // Bubble Sort Algorithm with display after each iteration
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (isInt) {
                int *intArr = (int *)arr;
                if (intArr[j] > intArr[j + 1]) {
                    // Swap adjacent elements if they are in the wrong order
                    int temp = intArr[j];
                    intArr[j] = intArr[j + 1];
                    intArr[j + 1] = temp;
                }
            } else if (isChar) {
                char *charArr = (char *)arr;
                if (charArr[j] > charArr[j + 1]) {
                    // Swap adjacent elements if they are in the wrong order
                    char temp = charArr[j];
                    charArr[j] = charArr[j + 1];
                    charArr[j + 1] = temp;
                }
            } else if (isString) {
                char **strArr = (char **)arr;
                if (strcmp(strArr[j], strArr[j + 1]) > 0) {
                    // Swap adjacent elements if they are in the wrong order
                    char *temp = strArr[j];
                    strArr[j] = strArr[j + 1];
                    strArr[j + 1] = temp;
                }
            }
        }
        // Display array after the iteration
        iterations++;
        printArrayMulti(arr, n, "Bubble Sort - After Iteration", iterations, type);  // Print array after each iteration
    }

    // Final sorted array print
    printSortedArrayMulti(arr, n, iterations, type);

    // Free memory for string arrays
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);  // Free the dynamically allocated memory
}

// Linear Search for multiple data types (int, char, string)
void linSearch(void *arr, int size, void *target, int type) {
    int found = 0;
    printf("\n");
    printCentered("Performing Linear Search...\n", WIDTH);
    printf("\n");

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        int intTarget = *(int *)target;
        for (int i = 0; i < size; i++) {
            if (intArr[i] == intTarget) {
                printCenteredDynamic(WIDTH, "Element %d found at index %d.", intTarget, i);
                found = 1;
                break;
            }
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        char charTarget = *(char *)target;
        for (int i = 0; i < size; i++) {
            if (charArr[i] == charTarget) {
                printCenteredDynamic(WIDTH, "Element '%c' found at index %d.", charTarget, i);

                found = 1;
                break;
            }
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        char *strTarget = (char *)target;
        for (int i = 0; i < size; i++) {
            if (strcmp(strArr[i], strTarget) == 0) {
                printCenteredDynamic(WIDTH, "Element \"%s\" found at index %d.", strTarget, i);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        if (type == 1) printf("Element %d not found in the array.\n", *(int *)target);
        else if (type == 2) printf("Element '%c' not found in the array.\n", *(char *)target);
        else if (type == 3) printf("Element \"%s\" not found in the array.\n", (char *)target);
    }
}

// Binary Search for multiple data types (int, char, string)
void binSearch(void *arr, int size, void *target, int type) {
    printf("\n");
    printCentered("Performing Binary Search...\n", WIDTH);
    printf("\n");
    // Sort the array before searching
    binaryInsertionSort(arr, size, type);

    int low = 0, high = size - 1, found = 0;

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        int intTarget = *(int *)target;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (intArr[mid] == intTarget) {
                printCenteredDynamic(WIDTH, "Element \"%d\" found at index %d.", intTarget, mid);
                found = 1;
                break;
            } else if (intArr[mid] < intTarget) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        char charTarget = *(char *)target;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (charArr[mid] == charTarget) {
                printCenteredDynamic(WIDTH, "Element \"%c\" found at index %d.", charTarget, mid);
                found = 1;
                break;
            } else if (charArr[mid] < charTarget) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        char *strTarget = (char *)target;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cmp = strcmp(strArr[mid], strTarget);
            if (cmp == 0) {
                printCenteredDynamic(WIDTH, "Element \"%s\" found at index %d.", strTarget, mid);
                found = 1;
                break;
            } else if (cmp < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    if (!found) {
        if (type == 1) printf("Element %d not found in the array.\n", *(int *)target);
        else if (type == 2) printf("Element '%c' not found in the array.\n", *(char *)target);
        else if (type == 3) printf("Element \"%s\" not found in the array.\n", (char *)target);
    }
}

// Binary Insertion Sort for multiple data types (int, char, string)
void binaryInsertionSort(void *arr, int size, int type) {
    printf("Sorting array using Binary Insertion Sort...\n");

    if (type == 1) { // Integer array
        int *intArr = (int *)arr;
        for (int i = 1; i < size; i++) {
            int key = intArr[i];
            int low = 0, high = i - 1;

            // Binary search for the correct position
            while (low <= high) {
                int mid = (low + high) / 2;
                if (intArr[mid] < key) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Shift elements to make space for the key
            for (int j = i - 1; j >= low; j--) {
                intArr[j + 1] = intArr[j];
            }
            intArr[low] = key;

            // Print array after each insertion
            printArrayMulti(intArr, size, "Binary Insertion Sort", i, 1);
        }
    } else if (type == 2) { // Character array
        char *charArr = (char *)arr;
        for (int i = 1; i < size; i++) {
            char key = charArr[i];
            int low = 0, high = i - 1;

            // Binary search for the correct position
            while (low <= high) {
                int mid = (low + high) / 2;
                if (charArr[mid] < key) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Shift elements to make space for the key
            for (int j = i - 1; j >= low; j--) {
                charArr[j + 1] = charArr[j];
            }
            charArr[low] = key;

            // Print array after each insertion
            printArrayMulti(charArr, size, "Binary Insertion Sort - Intermediate", i, 2);
        }
    } else if (type == 3) { // String array
        char **strArr = (char **)arr;
        for (int i = 1; i < size; i++) {
            char *key = strArr[i];
            int low = 0, high = i - 1;

            // Binary search for the correct position
            while (low <= high) {
                int mid = (low + high) / 2;
                if (strcmp(strArr[mid], key) < 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Shift elements to make space for the key
            for (int j = i - 1; j >= low; j--) {
                strArr[j + 1] = strArr[j];
            }
            strArr[low] = key;

            // Print array after each insertion
            printArrayMulti(strArr, size, "Binary Insertion Sort", i, 3);
        }
    }

    // Print final sorted array
    printSortedArrayMulti(arr, size, size, type);
}


// String Functions
void strGetChar() {
    clearScreen();
    printCentered("=== Position of Character ===", WIDTH);
    printCentered("Find the first occurrence of a character in a string.", WIDTH);
    printCentered("You will provide a character, and the program will display", WIDTH);
    printCentered("its 1-based position, if found.", WIDTH);

    char str[100];
    int pos;
    
    while (1) {  // Loop until a valid position is provided
        printf("Enter a string: ");
        scanf(" %[^\n]", str);
        printf("Enter position to get character (1-based): ");
        scanf("%d", &pos);

        if (pos > 0 && pos <= strlen(str)) {
            printf("Character at position %d: %c\n", pos, str[pos - 1]);
            break;  // Exit the loop when the position is valid
        } else {
            printCentered("Invalid position. Out of bounds. Please try again.", WIDTH);  // Error message
        }
    }
}


void strPutChar() {
    clearScreen();
    printCentered("=== Put Character ===", WIDTH);
    printCentered("Modify a character in a string by specifying its position.", WIDTH);
    printCentered("You will provide a new character to replace the old one,", WIDTH);
    printCentered("and the program will update and display the modified string.", WIDTH);

    char str[100];
    int pos;
    char ch;
    
    while (1) {  // Loop until a valid position is provided
        printf("Enter a string: ");
        scanf(" %[^\n]", str);
        printf("Enter position to replace character (1-based): ");
        scanf("%d", &pos);
        printf("Enter new character: ");
        scanf(" %c", &ch);

        if (pos > 0 && pos <= strlen(str)) {
            str[pos - 1] = ch;
            printf("Modified string: %s\n", str);
            break;  // Exit the loop when the position is valid
        } else {
            printCentered("Invalid position. Out of bounds. Please try again.", WIDTH);  // Error message
        }
    }
}


void length() {
    clearScreen();
    printCentered("=== Length of String ===", WIDTH);
    printCentered("Determine the number of characters in a string.", WIDTH);
    printCentered("The program will calculate and display the total length,", WIDTH);
    printCentered("excluding the null terminator.", WIDTH);

    char str[100];
    int len = 0;
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    while (str[len] != '\0') {
        len++;
    }
    printf("Length of the string: %d\n", len);
}

void pos() {
    clearScreen();
    printCentered("=== Position of Character ===", WIDTH);
    printCentered("Find the first occurrence of a character in a string.", WIDTH);
    printCentered("You will provide a character, and the program will display", WIDTH);
    printCentered("its 1-based position, if found.", WIDTH);

    char str[100], ch;
    int i, found = 0;
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("Enter character to find: ");
    scanf(" %c", &ch);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            printf("Character '%c' found at position %d\n", ch, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Character '%c' not found in the string.\n", ch);
    }
}

void concat() {
    clearScreen();
    printCentered("=== Concatenate Strings ===", WIDTH);
    printCentered("Combine two strings into a single string.", WIDTH);
    printCentered("The program will take two inputs, merge them,", WIDTH);
    printCentered("and display the concatenated result.", WIDTH);

    char str1[100], str2[100];
    int i = 0, j = 0;
    printf("Enter first string: ");
    scanf(" %[^\n]", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    while (str1[i] != '\0') i++;
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';

    printf("Concatenated string: %s\n", str1);
}

void substring() {
    clearScreen();
    printCentered("=== Substring Extraction ===", WIDTH);
    printCentered("Extract a portion of a string by specifying a start position", WIDTH);
    printCentered("and the desired length. The program will display the extracted", WIDTH);
    printCentered("substring if the range is valid.", WIDTH);

    char str[100], sub[100];
    int start, len, i;
    
    while (1) {  // Loop until valid range is provided
        printf("Enter a string: ");
        scanf(" %[^\n]", str);
        printf("Enter starting position (1-based): ");
        scanf("%d", &start);
        printf("Enter length of substring: ");
        scanf("%d", &len);
        
        if (start > 0 && start + len - 1 <= strlen(str)) {
            for (i = 0; i < len; i++) {
                sub[i] = str[start - 1 + i];
            }
            sub[i] = '\0';
            printf("Substring: %s\n", sub);
            break;  // Exit loop when valid range is provided
        } else {
            printCentered("Invalid range. Please try again.", WIDTH);  // Error message
        }
    }
}


void strInsert() {
    clearScreen();
    printCentered("=== Insert String ===", WIDTH);
    printCentered("Insert one string into another at a specified position.", WIDTH);
    printCentered("The program will merge the strings and display the updated", WIDTH);
    printCentered("result, maintaining the original order.", WIDTH);

    char str1[100], str2[100], result[200];
    int pos, i = 0, j = 0, k = 0;
    
    printf("Enter the main string: ");
    scanf(" %[^\n]", str1);  // Reads the main string, spaces are preserved
    printf("Enter the string to insert: ");
    scanf(" %[^\n]", str2);  // Reads the string to insert, spaces are preserved

    // Loop until the user provides a valid position
    do {
        printf("Enter the position to insert (1-based): ");
        scanf("%d", &pos);
        
        if (pos <= 0 || pos > strlen(str1) + 1) {  // Check for invalid position
            printCentered("Invalid position. Out of bounds. Please try again.", WIDTH);  // Display error
        }
    } while (pos <= 0 || pos > strlen(str1) + 1);  // Repeat until position is valid

    // Perform the insertion when position is valid
    while (i < pos - 1) result[k++] = str1[i++];  // Copy characters from the main string until the insertion point
    while (str2[j] != '\0') result[k++] = str2[j++];  // Insert the second string, preserving spaces
    while (str1[i] != '\0') result[k++] = str1[i++];  // Append the rest of the main string
    result[k] = '\0';  // Null-terminate the result string

    printf("Modified string: %s\n", result);
}



void strDel() {
    clearScreen();
    printCentered("=== Delete Substring ===", WIDTH);
    printCentered("Remove a portion of a string by specifying a start position", WIDTH);
    printCentered("and the length of the section to delete. The program will", WIDTH);
    printCentered("display the modified string.", WIDTH);

    char str[100];
    int start, len, i, j;
    
    while (1) {  // Loop until valid range is provided
        printf("Enter a string: ");
        scanf(" %[^\n]", str);
        printf("Enter starting position (1-based): ");
        scanf("%d", &start);
        printf("Enter length of portion to delete: ");
        scanf("%d", &len);

        if (start > 0 && start + len - 1 <= strlen(str)) {
            for (i = start - 1, j = start + len - 1; str[j] != '\0'; i++, j++) {
                str[i] = str[j];
            }
            str[i] = '\0';
            printf("Modified string: %s\n", str);
            break;  // Exit loop when valid range is provided
        } else {
            printCentered("Invalid range. Please try again.", WIDTH);  // Error message
        }
    }
}


void strComp() {
    clearScreen();
    printCentered("=== Compare Strings ===", WIDTH);
    printCentered("Perform a lexicographical comparison of two strings.", WIDTH);
    printCentered("The program will display the result indicating whether the", WIDTH);
    printCentered("first string is less than, equal to, or greater than the second.", WIDTH);

    char str1[100], str2[100];
    int i = 0, cmp = 0;
    printf("Enter first string: ");
    scanf(" %[^\n]", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            cmp = str1[i] - str2[i];
            break;
        }
        i++;
    }
    if (cmp == 0 && str1[i] != str2[i]) cmp = str1[i] - str2[i];
    printf("Comparison result: %d\n", cmp);
}

//string sorting is basically bubble sort*
void strSort() {
    clearScreen();
    printCentered("=== Sort String ===", WIDTH);
    printCentered("Arrange the characters of a string in alphabetical order.", WIDTH);
    printCentered("The program will sort the string in ascending order", WIDTH);
    printCentered("and display the sorted result.", WIDTH);
    char str[100], temp;
    int i, j;
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    for (i = 0; str[i] != '\0'; i++) {
        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("Sorted string: %s\n", str);
}

//arrays
void arrayMenu() {
    int choice, type;
    do {
        printf("\n");
        printCentered("=== Array Menu ===", WIDTH);
        printCentered("The Array Menu enables you to perform", WIDTH);
        printCentered("operations like traversal, insertion,", WIDTH);
        printCentered("deletion, searching, sorting, and", WIDTH);
        printCentered("merging on arrays of different data types.", WIDTH);
        printCentered("Supported types: int, char, and string.", WIDTH);
        printf("\n");        
        printCentered("1) Traverse", WIDTH);
        printCentered("2) Insert", WIDTH);
        printCentered("3) Delete", WIDTH);
        printCentered("4) Search", WIDTH);
        printCentered("5) Sort", WIDTH);
        printCentered("6) Merge", WIDTH);
        printCentered("7) Exit", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);
        clearInputBuffer();
        clearScreen();

        switch (choice) {
        case 1:
            traverseArray();
            break;
        case 2:
            insertArray();
            break;
        case 3:
            deleteArray();
            break;
        case 4:
            searchingMenu();
            break;
        case 5:
            sortingMenu();
            break;
        case 6:
            mergeArray();
            break;
        case 7:
            clearScreen();
            break;
        default:
            printCentered("Invalid choice. Please try again.", WIDTH);
        }
    } while (choice != 7);
}

void traverseArray() {
    printf("\n");
    printCentered("=== Traverse Array ===", WIDTH);
    printCentered("Displays all the elements of an array.", WIDTH);
    printCentered("Supports integer, character, and string data types.", WIDTH);
    printf("\n");

    int n, type;
    while (1) { // Ensure valid input for number of elements
        printf("Enter the number of elements: ");
        if (scanf("%d", &n) == 1 && n > 0) { // Validate positive integer input
            clearInputBuffer();
            break;
        }
        clearInputBuffer();
        printf("Invalid input. Please enter a positive integer.\n");
    }

    while (1) { // Ensure valid data type choice
        printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
        if (scanf("%d", &type) == 1 && (type == 1 || type == 2 || type == 3)) {
            clearInputBuffer();
            break;
        }
        clearInputBuffer();
        printf("Invalid input. Please choose 1 (Integer), 2 (Character), or 3 (String).\n");
    }

    if (type == 1) { // Integer
        int arr[n];
        printf("Enter the elements: ");
        for (int i = 0; i < n; i++) {
            while (scanf("%d", &arr[i]) != 1) { // Validate each input
                clearInputBuffer();
                printf("Invalid input. Please enter an integer: ");
            }
            clearInputBuffer();
        }
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } else if (type == 2) { // Character
        char arr[n];
        printf("Enter the characters: ");
        for (int i = 0; i < n; i++) {
            while (scanf(" %c", &arr[i]) != 1) { // Validate each input
                clearInputBuffer();
                printf("Invalid input. Please enter a character: ");
            }
            clearInputBuffer();
        }
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");

    } else if (type == 3) { // String
        char *arr[n];
        printf("Enter the strings (Press Enter for Each String): ");
        for (int i = 0; i < n; i++) {
            arr[i] = malloc(100 * sizeof(char)); // Allocate memory for each string
            if (!arr[i]) { // Check allocation success
                printf("Memory allocation failed. Exiting.\n");
                exit(1);
            }
            fgets(arr[i], 100, stdin); // Read the string input
            arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove trailing newline
        }
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%s ", arr[i]);
        }
        printf("\n");

        for (int i = 0; i < n; i++) { // Free memory
            free(arr[i]);
        }
    } else {
        printf("Invalid data type.\n");
    }
}

// Insert function with dynamic array size, supporting int, char, and string
void insertArray() {
    printf("\n");
    printCentered("=== Insert Into Array ===", WIDTH);
    printCentered("Adds a new element at a specified position.", WIDTH);
    printCentered("Checks for array overflow before insertion.", WIDTH);
    printCentered("Supports integer, character, and string data types.", WIDTH);
    printf("\n");

    int n, type;
    printf("Enter the number of elements: ");
    fgetsInput(&n, "Invalid input. Please enter a valid number.");
        
    // If n is too large, ask for confirmation
    if (n > 30) {
        char confirm;
        printCentered("That's quite a large number of elements.", WIDTH);
        printf("Are you sure you want to continue? (y/n): ");
        scanf(" %c", &confirm);
        clearInputBuffer(); // Clear any extra input
        if (confirm != 'y' && confirm != 'Y') {
            printf("Please enter a smaller number of elements.\n");
            return;
        }
    }

    // Ask for the data type (int, char, or string)
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    fgetsInput(&type, "Invalid input. Please enter a valid choice.");

    void *arr;
    void *element;
    int isInt = 0, isChar = 0, isString = 0;

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        memset(arr, 0, n * sizeof(int)); // Initialize with zeros
        element = malloc(sizeof(int));
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        memset(arr, 0, n * sizeof(char)); // Initialize with zeros
        element = malloc(sizeof(char));
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        memset(arr, 0, n * sizeof(char *)); // Initialize with zeros
        element = malloc(100 * sizeof(char)); // Assuming max string length of 100
        isString = 1;
    } else {
        printf("Invalid data type.\n");
        return;
    }

    // Input elements
    printf("Enter the elements (Press Enter for Each):\n");
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            fgetsInput(&intArr[i], "Invalid input. Please enter a valid element.");
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            fgetsInputChar(&charArr[i], "Invalid input. Please enter a valid element.");
        }
    } else if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char));
            fgetsInputString(strArr[i], 100, "Invalid input. Please enter a valid element.");
        }
    }

    // Show current state of the array with placeholders
    printf("Current Array: ");
    for (int i = 0; i < n; i++) {
        if (isInt) {
            printf("%d ", ((int *)arr)[i]);
        } else if (isChar) {
            printf("%c ", ((char *)arr)[i]);
        } else if (isString) {
            printf("%s ", ((char **)arr)[i]);
        }
    }
    printf("\n");

    // Proceed with insertion
    int position;
    printf("Enter the position to insert (1 to %d): ", n + 1);
    fgetsInput(&position, "Invalid position. Please enter a valid position.");
    if (position < 1 || position > n + 1) {
        printf("Invalid position.\n");
        free(arr);
        free(element);
        return;
    }

    // Insert the new element at the specified position
    if (isInt) {
        printf("Enter the integer element to insert: ");
        fgetsInput((int *)element, "Invalid input. Please enter an integer.");
        int *intArr = (int *)arr;
        for (int i = n; i >= position; i--) {
            intArr[i] = intArr[i - 1];
        }
        intArr[position - 1] = *(int *)element;
    } else if (isChar) {
        printf("Enter the character element to insert: ");
        fgetsInputChar((char *)element, "Invalid input. Please enter a character.");
        char *charArr = (char *)arr;
        for (int i = n; i >= position; i--) {
            charArr[i] = charArr[i - 1];
        }
        charArr[position - 1] = *(char *)element;
    } else if (isString) {
        printf("Enter the string element to insert: ");
        fgetsInputString((char *)element, 100, "Invalid input. Please enter a string.");
        char **strArr = (char **)arr;
        for (int i = n; i >= position; i--) {
            strArr[i] = strArr[i - 1];
        }
        strArr[position - 1] = strdup((char *)element);
    }

    n++; // Update the number of elements

    // Display the array after insertion
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        if (isInt) {
            printf("%d ", ((int *)arr)[i]);
        } else if (isChar) {
            printf("%c ", ((char *)arr)[i]);
        } else if (isString) {
            printf("%s ", ((char **)arr)[i]);
        }
    }
    printf("\n");

    // Free dynamically allocated memory
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);
    free(element);
}

// Delete function with dynamic array size, supporting int, char, and string
void deleteArray() {
    printf("\n");
    printCentered("=== Delete From Array ===", WIDTH);
    printCentered("Removes an element from a specified position.", WIDTH);
    printCentered("Checks for array underflow before deletion.", WIDTH);
    printCentered("Supports integer, character, and string data types.", WIDTH);
    printf("\n");

    int n, type;
    printf("Enter the number of elements: ");
    fgetsInput(&n, "Invalid input. Please enter a valid number.");

    if (n <= 0) {
        printf("Array underflow. No elements to delete.\n");
        return;
    }

    // Ask for the data type (int, char, or string)
    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    fgetsInput(&type, "Invalid input. Please enter a valid choice.");

    void *arr;
    int isInt = 0, isChar = 0, isString = 0;

    if (type == 1) { // Integer array
        arr = malloc(n * sizeof(int));
        memset(arr, 0, n * sizeof(int)); // Initialize with zeros
        isInt = 1;
    } else if (type == 2) { // Character array
        arr = malloc(n * sizeof(char));
        memset(arr, 0, n * sizeof(char)); // Initialize with zeros
        isChar = 1;
    } else if (type == 3) { // String array
        arr = malloc(n * sizeof(char *));
        memset(arr, 0, n * sizeof(char *)); // Initialize with zeros
        isString = 1;
    } else {
        printf("Invalid data type.\n");
        return;
    }

    // Input elements
    printf("Enter the elements (Press Enter for Each):\n");
    if (isInt) {
        int *intArr = (int *)arr;
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            fgetsInput(&intArr[i], "Invalid input. Please enter a valid element.");
        }
    } else if (isChar) {
        char *charArr = (char *)arr;
        for (int i = 0; i < n; i++) {
            printf("Element %d: ", i + 1);
            fgetsInputChar(&charArr[i], "Invalid input. Please enter a valid element.");
        }
    } else if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            strArr[i] = malloc(100 * sizeof(char));
            fgetsInputString(strArr[i], 100, "Invalid input. Please enter a valid element.");
        }
    }

    // Show current state of the array with placeholders
    printf("Current Array: ");
    for (int i = 0; i < n; i++) {
        if (isInt) {
            printf("%d ", ((int *)arr)[i]);
        } else if (isChar) {
            printf("%c ", ((char *)arr)[i]);
        } else if (isString) {
            printf("%s ", ((char **)arr)[i]);
        }
    }
    printf("\n");

    // Deletion logic
    int position;
    printf("Enter the position to delete (1 to %d): ", n);
    fgetsInput(&position, "Invalid position. Please enter a valid position.");

    if (position < 1 || position > n) {
        printf("Invalid position.\n");
        free(arr);
        return;
    }

    // Shift elements to delete the specified position
    for (int i = position - 1; i < n - 1; i++) {
        if (isInt) {
            ((int *)arr)[i] = ((int *)arr)[i + 1];
        } else if (isChar) {
            ((char *)arr)[i] = ((char *)arr)[i + 1];
        } else if (isString) {
            ((char **)arr)[i] = ((char **)arr)[i + 1];
        }
    }
    n--;

    // Display the array after deletion
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        if (isInt) {
            printf("%d ", ((int *)arr)[i]);
        } else if (isChar) {
            printf("%c ", ((char *)arr)[i]);
        } else if (isString) {
            printf("%s ", ((char **)arr)[i]);
        }
    }
    printf("\n");

    // Free dynamically allocated memory
    if (isString) {
        char **strArr = (char **)arr;
        for (int i = 0; i < n; i++) {
            free(strArr[i]);
        }
    }
    free(arr);
}

//merge array
void mergeArray() {
    printf("\n");
    printCentered("=== Merge Arrays ===", WIDTH);
    printCentered("Combines two arrays into a single array.", WIDTH);
    printCentered("Supports integer, character, and string data types.", WIDTH);
    printf("\n");
    int n1, n2, type;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    clearInputBuffer();
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    clearInputBuffer();

    printf("Choose Data Type: 1) Integer 2) Character 3) String: ");
    scanf("%d", &type);
    clearInputBuffer();

    if (type == 1) { // Integer
        int arr1[n1], arr2[n2], merged[n1 + n2];
        printf("Enter the elements of the first array: ");
        for (int i = 0; i < n1; i++) {
            scanf("%d", &arr1[i]);
        }
        printf("Enter the elements of the second array: ");
        for (int i = 0; i < n2; i++) {
            scanf("%d", &arr2[i]);
        }

        // Merge the arrays
        for (int i = 0; i < n1; i++) {
            merged[i] = arr1[i];
        }
        for (int i = 0; i < n2; i++) {
            merged[n1 + i] = arr2[i];
        }

        printf("Merged array: ");
        for (int i = 0; i < n1 + n2; i++) {
            printf("%d ", merged[i]);
        }
        printf("\n");
    } else if (type == 2) { // Character
        char arr1[n1], arr2[n2], merged[n1 + n2];
        printf("Enter the characters of the first array (Press Enter for each Character): ");
        for (int i = 0; i < n1; i++) {
            scanf(" %c", &arr1[i]);
        }
        printf("Enter the characters of the second array (Press Enter for each Character): ");
        for (int i = 0; i < n2; i++) {
            scanf(" %c", &arr2[i]);
        }

        // Merge the arrays
        for (int i = 0; i < n1; i++) {
            merged[i] = arr1[i];
        }
        for (int i = 0; i < n2; i++) {
            merged[n1 + i] = arr2[i];
        }

        printf("Merged array: ");
        for (int i = 0; i < n1 + n2; i++) {
            printf("%c ", merged[i]);
        }
        printf("\n");
    } else if (type == 3) { // String
        char *arr1[n1], *arr2[n2], *merged[n1 + n2];
        printf("Enter the strings of the first array (Press Enter for each String): ");
        for (int i = 0; i < n1; i++) {
            arr1[i] = malloc(100 * sizeof(char));
            fgets(arr1[i], 100, stdin);
            arr1[i][strcspn(arr1[i], "\n")] = '\0'; // Remove trailing newline
        }
        printf("Enter the strings of the second array (Press Enter for each String): ");
        for (int i = 0; i < n2; i++) {
            arr2[i] = malloc(100 * sizeof(char));
            fgets(arr2[i], 100, stdin);
            arr2[i][strcspn(arr2[i], "\n")] = '\0'; // Remove trailing newline
        }

        // Merge the arrays
        for (int i = 0; i < n1; i++) {
            merged[i] = arr1[i];
        }
        for (int i = 0; i < n2; i++) {
            merged[n1 + i] = arr2[i];
        }

        printf("Merged array: ");
        for (int i = 0; i < n1 + n2; i++) {
            printf("%s ", merged[i]);
        }
        printf("\n");

        // Free memory
        for (int i = 0; i < n1; i++) {
            free(arr1[i]);
        }
        for (int i = 0; i < n2; i++) {
            free(arr2[i]);
        }
    } else {
        printf("Invalid data type.\n");
    }
}

// LinkedList Menu implementation
void linkedListMenu() {
    int choice;
    do {
        printf("\n");
        printCentered("=== Linked List Menu ===", WIDTH);
        printCentered("1) Singular Linked List", WIDTH);
        printCentered("2) Doubly Linked List", WIDTH);
        printCentered("3) Circular Linked List", WIDTH);
        printCentered("4) Circular Doubly Linked List", WIDTH);
        printCentered("5) Back to Main Menu", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                singularLinkedList();
                break;
            case 2:
                doublyLinkedList();
                break;
            case 3:
                circularLinkedList();
                break;
            case 4:
                circularDoublyLinkedList();
                break;
            case 5:
                clearScreen();
                break;
            default:
                printCentered("Invalid choice. Please try again.", WIDTH);
                clearInputBuffer();
        }
    } while (choice != 5);
}

void initializeList(void **head, DataType type, int isDoubly, int isCircular) {
    if (*head != NULL) {
        printf("List already initialized. Clearing existing list...\n");
        // Clear list logic (e.g., freeing memory)
        // You can add logic here to free the existing list, if necessary
    }
    
    *head = NULL;  // Initialize the list by setting the head to NULL
    printf("List initialized.\n");

    // Print the list (it will be empty since head is NULL)
    printList(*head, type, isDoubly, isCircular);
}


// function for types of linked lists
void singularLinkedList() {
    SinglyNode *head = NULL;
    int choice;
    DataType type;
    
    // Ask user for the data type of the list
    printf("Choose data type for the Singular Linked List:\n");
    printf("1) INT\n2) CHAR\n3) STRING\nChoose: ");
    scanf("%d", &choice);
    clearInputBuffer();
    type = (choice == 1) ? DT_INT : (choice == 2) ? DT_CHAR : DT_STRING;
    clearScreen();
    do {        
        // Display available operations
        printf("\n");
        printCentered("=== Singular Linked List Operations ===", WIDTH);
        printCentered("1) Initialize List", WIDTH);
        printCentered("2) Insert Node", WIDTH);
        printCentered("3) Traverse List", WIDTH);
        printCentered("4) Search List", WIDTH);
        printCentered("5) Delete Node", WIDTH);
        printCentered("6) Reverse List", WIDTH);
        printCentered("7) Back to Linked List Menu", WIDTH);
        printf("\n");
        printf("Choose Option: ");
        scanf("%d", &choice);
        clearScreen();  // Clear the screen to prepare for the next action

        switch (choice) {
            case 1:
                initializeList((void **)&head, type, 0, 0);
                break;
            case 2:
                insertNode((void **)&head, type, 0, 0);
                break;
            case 3:
                traverseList(head, type, 0, 0);
                break;
            case 4:
                searchList(head, type, 0, 0);
                break;
            case 5:
                deleteNode((void **)&head, type, 0, 0);
                break;
            case 6:
                reverseList((void **)&head, type, 0, 0);
                break;
            case 7:
                clearScreen();
                break;
            default:
                printCentered("Invalid choice. Please try again.", WIDTH);
                clearInputBuffer();
        }
    } while (choice != 7);
}



void doublyLinkedList() {
    printf("Doubly Linked List  - To be implemented\n");
}

void circularLinkedList() {
    printf("Circular Linked List  - To be implemented\n");
}

void circularDoublyLinkedList() {
    printf("Circular Doubly Linked List  - To be implemented\n");
}

// Linked List operations
// Insert Node Function (Handles insertion at start, end, and specific index)
void insertNode(void **head, DataType type, int isDoubly, int isCircular) {
    void *newData;
    int choice, index;

    // Allocate memory for the data based on its type
    if (type == DT_INT) {
        newData = malloc(sizeof(int));
        printf("Enter an integer: ");
        scanf("%d", (int *)newData);
    } else if (type == DT_CHAR) {
        newData = malloc(sizeof(char));
        printf("Enter a character: ");
        scanf(" %c", (char *)newData);
    } else {
        newData = malloc(50);
        printf("Enter a string: ");
        scanf("%s", (char *)newData);
    }

    printf("\nChoose where to insert the node:\n");
    printf("1) At the end\n");
    printf("2) At a specific index\n");
    printf("3) At the start\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (isDoubly) {
        DoublyNode *newNode = (DoublyNode *)malloc(sizeof(DoublyNode));
        newNode->data = newData;
        newNode->next = NULL;
        newNode->prev = NULL;

        DoublyNode **dHead = (DoublyNode **)head;

        if (choice == 1) { // Insert at the end
            if (*dHead == NULL) {
                *dHead = newNode;
                if (isCircular) {
                    newNode->next = newNode;
                    newNode->prev = newNode;
                }
            } else {
                DoublyNode *tail = *dHead;
                while (!isCircular && tail->next != NULL) tail = tail->next;
                if (isCircular) tail = (*dHead)->prev;

                tail->next = newNode;
                newNode->prev = tail;
                if (isCircular) {
                    newNode->next = *dHead;
                    (*dHead)->prev = newNode;
                }
            }
        } else if (choice == 2) { // Insert at specific index
            printf("Enter the index to insert at (1-based index): ");
            scanf("%d", &index);

            // Validate the index (must be >= 1)
            if (index < 1) {
                printf("Index out of bounds.\n");
                free(newData);
                return;
            }

            if (index == 1 || *dHead == NULL) { // Insert at start if index is 1 or the list is empty
                newNode->next = *dHead;
                if (*dHead != NULL) {
                    (*dHead)->prev = newNode;
                }
                *dHead = newNode;
                if (isCircular) {
                    newNode->prev = (*dHead)->prev;
                    (*dHead)->prev->next = *dHead;
                }
            } else {
                DoublyNode *temp = *dHead;
                for (int i = 1; temp != NULL && i < index - 1; i++) {
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Index out of range.\n");
                    free(newData);
                    return;
                }

                newNode->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                newNode->prev = temp;

                if (isCircular && newNode->next == NULL) {
                    newNode->next = *dHead;
                    (*dHead)->prev = newNode;
                }
            }
        } else if (choice == 3) { // Insert at the start
            newNode->next = *dHead;
            if (*dHead != NULL) {
                (*dHead)->prev = newNode;
            }
            *dHead = newNode;
            if (isCircular) {
                newNode->prev = (*dHead)->prev;
                (*dHead)->prev->next = *dHead;
            }
        }
    } else { // Singly Linked List
        SinglyNode **sHead = (SinglyNode **)head;

        if (choice == 1) { // Insert at the end
            SinglyNode *newNode = (SinglyNode *)malloc(sizeof(SinglyNode));
            newNode->data = newData;
            newNode->next = NULL;

            if (*sHead == NULL) {
                *sHead = newNode;
                if (isCircular) {
                    newNode->next = newNode; // Circular linking
                }
            } else {
                SinglyNode *tail = *sHead;
                while (!isCircular && tail->next != NULL) tail = tail->next;
                if (isCircular) tail = (*sHead)->next;

                tail->next = newNode;
                if (isCircular) {
                    newNode->next = *sHead;
                }
            }
        } else if (choice == 2) { // Insert at specific index
            printf("Enter the index to insert at (1-based index): ");
            scanf("%d", &index);

            // Validate the index (must be >= 1)
            if (index < 1) {
                printf("Index out of bounds.\n");
                free(newData);
                return;
            }

            if (index == 1 || *sHead == NULL) { // Insert at start if index is 1 or the list is empty
                SinglyNode *newNode = (SinglyNode *)malloc(sizeof(SinglyNode));
                newNode->data = newData;
                newNode->next = *sHead;
                *sHead = newNode;
                if (isCircular) {
                    SinglyNode *tail = *sHead;
                    while (tail->next != *sHead) tail = tail->next;
                    tail->next = *sHead;
                }
            } else {
                SinglyNode *temp = *sHead;
                for (int i = 1; temp != NULL && i < index - 1; i++) {
                    temp = temp->next;
                }

                if (temp == NULL) {
                    printf("Index out of range.\n");
                    free(newData);
                    return;
                }

                SinglyNode *newNode = (SinglyNode *)malloc(sizeof(SinglyNode));
                newNode->data = newData;
                newNode->next = temp->next;
                temp->next = newNode;
                if (isCircular && newNode->next == NULL) {
                    newNode->next = *sHead;
                }
            }
        } else if (choice == 3) { // Insert at the start
            SinglyNode *newNode = (SinglyNode *)malloc(sizeof(SinglyNode));
            newNode->data = newData;
            newNode->next = *sHead;
            *sHead = newNode;
            if (isCircular) {
                SinglyNode *tail = *sHead;
                while (tail->next != *sHead) tail = tail->next;
                tail->next = *sHead;
            }
        }
    }

    printf("Node inserted successfully.\n");
    // Print the list after insertion
    printList(*head, type, isDoubly, isCircular);
}



void traverseList(void *head, DataType type, int isDoubly, int isCircular) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Traversing the list:\n");
    if (isDoubly) {
        DoublyNode *current = (DoublyNode *)head;
        do {
            if (type == DT_INT) {
                printf("[%d] ", *(int *)current->data);
            } else if (type == DT_CHAR) {
                printf("[%c] ", *(char *)current->data);
            } else {
                printf("[%s] ", (char *)current->data);
            }
            current = current->next;
        } while (current != NULL && (current != head || isCircular));
    } else {
        SinglyNode *current = (SinglyNode *)head;
        do {
            if (type == DT_INT) {
                printf("[%d] ", *(int *)current->data);
            } else if (type == DT_CHAR) {
                printf("[%c] ", *(char *)current->data);
            } else {
                printf("[%s] ", (char *)current->data);
            }
            current = current->next;
        } while (current != NULL && (current != head || isCircular));
    }

    printf("\n");
}


void searchList(void *head, DataType type, int isDoubly, int isCircular) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    void *searchValue = malloc((type == DT_STRING) ? 50 : sizeof(int));
    printf("Enter the value to search: ");
    if (type == DT_INT) {
        scanf("%d", (int *)searchValue);
    } else if (type == DT_CHAR) {
        scanf(" %c", (char *)searchValue);
    } else {
        scanf("%s", (char *)searchValue);
    }

    int position = 1;
    int found = 0;
    if (isDoubly) {
        DoublyNode *current = (DoublyNode *)head;
        do {
            if ((type == DT_INT && *(int *)current->data == *(int *)searchValue) ||
                (type == DT_CHAR && *(char *)current->data == *(char *)searchValue) ||
                (type == DT_STRING && strcmp((char *)current->data, (char *)searchValue) == 0)) {
                printf("Value found at position %d\n", position);
                found = 1;
                break;
            }
            current = current->next;
            position++;
        } while (current != NULL && (current != head || isCircular));
    } else {
        SinglyNode *current = (SinglyNode *)head;
        do {
            if ((type == DT_INT && *(int *)current->data == *(int *)searchValue) ||
                (type == DT_CHAR && *(char *)current->data == *(char *)searchValue) ||
                (type == DT_STRING && strcmp((char *)current->data, (char *)searchValue) == 0)) {
                printf("Value found at position %d\n", position);
                found = 1;
                break;
            }
            current = current->next;
            position++;
        } while (current != NULL && (current != head || isCircular));
    }

    if (!found) {
        printf("Value not found in the list.\n");
    }

    // Print the list after the search operation
    printf("\nCurrent list:\n");
    printList(head, type, isDoubly, isCircular);

    free(searchValue);
}


void deleteNode(void **head, DataType type, int isDoubly, int isCircular) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    void *deleteValue = malloc((type == DT_STRING) ? 50 : sizeof(int));
    printf("Enter the value to delete: ");
    if (type == DT_INT) {
        scanf("%d", (int *)deleteValue);
    } else if (type == DT_CHAR) {
        scanf(" %c", (char *)deleteValue);
    } else {
        scanf("%s", (char *)deleteValue);
    }

    if (isDoubly) {
        DoublyNode *current = (DoublyNode *)*head, *prev = NULL;
        do {
            if ((type == DT_INT && *(int *)current->data == *(int *)deleteValue) ||
                (type == DT_CHAR && *(char *)current->data == *(char *)deleteValue) ||
                (type == DT_STRING && strcmp((char *)current->data, (char *)deleteValue) == 0)) {
                if (prev) prev->next = current->next;
                if (current->next) current->next->prev = prev;
                if (current == *head) *head = current->next;
                if (isCircular && *head == current) *head = NULL;
                free(current->data);
                free(current);
                printf("Node deleted.\n");

                // Print the updated list after deletion
                printf("\nUpdated list:\n");
                printList(*head, type, isDoubly, isCircular);

                free(deleteValue);
                return;
            }
            prev = current;
            current = current->next;
        } while (current != NULL && (current != *head || isCircular));
    } else {
        SinglyNode *current = (SinglyNode *)*head, *prev = NULL;
        do {
            if ((type == DT_INT && *(int *)current->data == *(int *)deleteValue) ||
                (type == DT_CHAR && *(char *)current->data == *(char *)deleteValue) ||
                (type == DT_STRING && strcmp((char *)current->data, (char *)deleteValue) == 0)) {
                if (prev) prev->next = current->next;
                if (current == *head) *head = current->next;
                if (isCircular && *head == current) *head = NULL;
                free(current->data);
                free(current);
                printf("Node deleted.\n");

                // Print the updated list after deletion
                printf("\nUpdated list:\n");
                printList(*head, type, isDoubly, isCircular);

                free(deleteValue);
                return;
            }
            prev = current;
            current = current->next;
        } while (current != NULL && (current != *head || isCircular));
    }

    printf("Value not found.\n");
    free(deleteValue);
}


void reverseList(void **head, DataType type, int isDoubly, int isCircular) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (isDoubly) {
        DoublyNode *current = (DoublyNode *)*head;
        DoublyNode *temp = NULL;
        do {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // Move to the previous node
        } while (current != NULL && (current != *head || isCircular));

        if (temp) *head = temp->prev; // Update head to the new first node
    } else {
        SinglyNode *current = (SinglyNode *)*head;
        SinglyNode *prev = NULL, *next = NULL;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != NULL && (current != *head || isCircular));
        *head = prev;
    }

    printf("List reversed.\n");
    printList(*head, type, isDoubly, isCircular);
}

void printList(void *head, DataType type, int isDoubly, int isCircular) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List: ");

    if (isDoubly) {
        DoublyNode *current = (DoublyNode *)head;
        do {
            // Print data in node with appropriate formatting
            if (type == DT_INT) {
                printf("[%d]", *(int *)current->data);
            } else if (type == DT_CHAR) {
                printf("[%c]", *(char *)current->data);
            } else if (type == DT_STRING) {
                printf("[%s]", (char *)current->data);
            }

            // Print arrows based on the next and previous nodes
            if (current->next != NULL) {
                printf(" <-> ");  // Double arrows for doubly linked list
            } else {
                printf(" <-> NULL"); // End of the list
            }

            current = current->next;
        } while (current != NULL && (current != head || isCircular));

        printf("\n");
    } else {
        SinglyNode *current = (SinglyNode *)head;
        do {
            // Print data in node with appropriate formatting
            if (type == DT_INT) {
                printf("[%d]", *(int *)current->data);
            } else if (type == DT_CHAR) {
                printf("[%c]", *(char *)current->data);
            } else if (type == DT_STRING) {
                printf("[%s]", (char *)current->data);
            }

            // Print arrows for singly linked list
            if (current->next != NULL) {
                printf(" -> ");  // Single arrow for singly linked list
            } else {
                printf(" -> NULL"); // End of the list
            }

            current = current->next;
        } while (current != NULL && (current != head || isCircular));

        printf("\n");
    }
}

void stackMenu() {
    StackNode *top = NULL; // Initialize the stack as a linked list
    int size = 0, capacity = 0, isFixedSize = 0;
    DataType type;
    int choice;

    // Ask user if they want a fixed or dynamic size
    printf("Do you want a fixed-size stack?\n");
    printf("1) Yes\n");
    printf("2) No (Dynamic size)\n");
    printf("Choose: ");
    scanf("%d", &isFixedSize);
    clearInputBuffer();

    if (isFixedSize == 1) {
        printf("Enter the maximum capacity of the stack: ");
        scanf("%d", &capacity);
    } else {
        printf("Stack will be dynamic in size.\n");
    }

    // Ask user for data type
    printf("Choose data type:\n");
    printf("1) Integer\n");
    printf("2) Character\n");
    printf("3) String\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            type = DT_INT;
            break;
        case 2:
            type = DT_CHAR;
            break;
        case 3:
            type = DT_STRING;
            break;
        default:
            printf("Invalid choice. Defaulting to Integer.\n");
            type = DT_INT;
    }

    do {
        // Print the stack at the start of the menu
        printf("\n=== Current Stack ===\n");
        printStack(top, type);

        printf("\n=== Stack Menu ===\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Peek\n");
        printf("4) Reset Stack\n");
        printf("5) Exit\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFixedSize && size >= capacity) {
                    printf("Stack is full. Cannot push.\n");
                } else {
                    push(&top, type, &size);
                }
                break;
            case 2:
                pop(&top, type, &size);
                break;
            case 3:
                peek(top, type);
                break;
            case 4:
                resetStack(&top, &size);
                printf("Stack has been reset.\n");
                break;
            case 5:
                printf("Exiting Stack Menu.\n");
                clearScreen();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Ensure to clean up the stack at the end
    resetStack(&top, &size);
}


void push(StackNode **top, DataType type, int *size) {
    void *data = NULL;
    int valid = 0;

    // Validate input based on the selected data type
    while (!valid) {
        if (type == DT_INT) {
            data = malloc(sizeof(int));
            printf("Enter an integer: ");
            if (scanf("%d", (int *)data) == 1) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter an integer.\n");
                clearInputBuffer();
                free(data);
                data = NULL;
            }
        } else if (type == DT_CHAR) {
            data = malloc(sizeof(char));
            printf("Enter a character: ");
            if (scanf(" %c", (char *)data) == 1 && isalpha(*(char *)data)) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter a single character (a-z, A-Z).\n");
                clearInputBuffer();
                free(data);
                data = NULL;
            }
        } else if (type == DT_STRING) {
            data = malloc(50);
            printf("Enter a string: ");
            if (scanf("%s", (char *)data) == 1) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter a valid string.\n");
                clearInputBuffer();
                free(data);
                data = NULL;
            }
        }
    }

    // Push the validated data onto the stack
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    (*size)++;

    printf("Pushed: ");
    if (type == DT_INT) {
        printf("%d\n", *(int *)data);
    } else if (type == DT_CHAR) {
        printf("%c\n", *(char *)data);
    } else {
        printf("%s\n", (char *)data);
    }
}

void resetStack(StackNode **top, int *size) {
    while (*top != NULL) {
        StackNode *temp = *top;
        *top = (*top)->next;
        free(temp->data);
        free(temp);
    }
    *size = 0;
}
void pop(StackNode **top, DataType type, int *size) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    StackNode *temp = *top;
    *top = (*top)->next;
    printf("Popped: ");
    if (type == DT_INT) {
        printf("%d\n", *(int *)temp->data);
    } else if (type == DT_CHAR) {
        printf("%c\n", *(char *)temp->data);
    } else {
        printf("%s\n", (char *)temp->data);
    }
    free(temp->data);
    free(temp);
    (*size)--;
}


void peek(Stack *stack, DataType type) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }

    printf("Top of stack: ");
    if (type == DT_INT) {
        printf("%d\n", *(int *)stack->top->data);
    } else if (type == DT_CHAR) {
        printf("%c\n", *(char *)stack->top->data);
    } else {
        printf("%s\n", (char *)stack->top->data);
    }
}

int isEmpty(Stack *stack) {
    return stack->size == 0;
}

int isFull(Stack *stack) {
    return stack->size >= stack->capacity;
}

void printStack(StackNode *top, DataType type) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nVisual Representation of Stack:\n");
    StackNode *current = top;
    printf("    ----\n");
    while (current != NULL) {
        if (type == DT_INT) {
            printf("   | %2d |\n", *(int *)current->data);
        } else if (type == DT_CHAR) {
            printf("   |  %c |\n", *(char *)current->data);
        } else {
            printf("   | %s |\n", (char *)current->data);
        }
        printf("    ----\n");
        current = current->next;
    }
    printf("\n");
}


void queueMenu() {
    StackNode *front = NULL, *rear = NULL; // Initialize the queue as a linked list
    int size = 0, capacity = 0, isFixedSize = 0;
    DataType type;
    int choice;

    // Ask user if they want a fixed or dynamic size
    printf("Do you want a fixed-size queue?\n");
    printf("1) Yes\n");
    printf("2) No (Dynamic size)\n");
    printf("Choose: ");
    scanf("%d", &isFixedSize);
    clearInputBuffer();

    if (isFixedSize == 1) {
        printf("Enter the maximum capacity of the queue: ");
        scanf("%d", &capacity);
    } else {
        printf("Queue will be dynamic in size.\n");
    }

    // Ask user for data type
    printf("Choose data type:\n");
    printf("1) Integer\n");
    printf("2) Character\n");
    printf("3) String\n");
    printf("Choose: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            type = DT_INT;
            break;
        case 2:
            type = DT_CHAR;
            break;
        case 3:
            type = DT_STRING;
            break;
        default:
            printf("Invalid choice. Defaulting to Integer.\n");
            type = DT_INT;
    }

    do {
        // Print the queue at the start of the menu
        printf("\n=== Current Queue ===\n");
        printQueue(front, type);

        printf("\n=== Queue Menu ===\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Peek\n");
        printf("4) Reset Queue\n");
        printf("5) Exit\n");
        printf("Choose Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFixedSize && size >= capacity) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    enqueue(&front, &rear, type, &size);
                }
                break;
            case 2:
                dequeue(&front, &rear, type, &size);
                break;
            case 3:
                peekQueue(front, type);
                break;
            case 4:
                resetQueue(&front, &rear, &size);
                printf("Queue has been reset.\n");
                break;
            case 5:
                printf("Exiting Queue Menu.\n");
                clearScreen();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Ensure to clean up the queue at the end
    resetQueue(&front, &rear, &size);
}

void enqueue(StackNode **front, StackNode **rear, DataType type, int *size) {
    void *data = NULL;
    int valid = 0;

    // Validate input based on the selected data type
    while (!valid) {
        if (type == DT_INT) {
            data = malloc(sizeof(int));
            printf("Enter an integer: ");
            if (scanf("%d", (int *)data) == 1) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter an integer.\n");
                clearInputBuffer();
                free(data);
                data = NULL;
            }
        } else if (type == DT_CHAR) {
            data = malloc(sizeof(char));
            printf("Enter a character: ");
            if (scanf(" %c", (char *)data) == 1 && isalpha(*(char *)data)) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter a single character (a-z, A-Z).\n");
                clearInputBuffer();
                free(data);
                data = NULL;
            }
        } else if (type == DT_STRING) {
            data = malloc(50);
            printf("Enter a string: ");
            if (scanf("%s", (char *)data) == 1) {
                valid = 1;
            } else {
                printf("Invalid input. Please enter a valid string.\n");
                clearInputBuffer();
                free(data);
                data = NULL;
            }
        }
    }

    // Enqueue the validated data
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        // Queue is empty
        *front = *rear = newNode;
    } else {
        // Add to the end of the queue
        (*rear)->next = newNode;
        *rear = newNode;
    }

    (*size)++;
    printf("Enqueued: ");
    if (type == DT_INT) {
        printf("%d\n", *(int *)data);
    } else if (type == DT_CHAR) {
        printf("%c\n", *(char *)data);
    } else {
        printf("%s\n", (char *)data);
    }
}

void dequeue(StackNode **front, StackNode **rear, DataType type, int *size) {
    if (*front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    StackNode *temp = *front;
    *front = (*front)->next;

    // If front becomes NULL, set rear to NULL as well
    if (*front == NULL) {
        *rear = NULL;
    }

    printf("Dequeued: ");
    if (type == DT_INT) {
        printf("%d\n", *(int *)temp->data);
    } else if (type == DT_CHAR) {
        printf("%c\n", *(char *)temp->data);
    } else {
        printf("%s\n", (char *)temp->data);
    }

    free(temp->data);
    free(temp);
    (*size)--;
}

void peekQueue(StackNode *front, DataType type) {
    if (front == NULL) {
        printf("Queue is empty. Nothing to peek.\n");
        return;
    }

    printf("Front of queue: ");
    if (type == DT_INT) {
        printf("%d\n", *(int *)front->data);
    } else if (type == DT_CHAR) {
        printf("%c\n", *(char *)front->data);
    } else {
        printf("%s\n", (char *)front->data);
    }
}

void resetQueue(StackNode **front, StackNode **rear, int *size) {
    while (*front != NULL) {
        StackNode *temp = *front;
        *front = (*front)->next;
        free(temp->data);
        free(temp);
    }

    *rear = NULL;
    *size = 0;
}

void printQueue(StackNode *front, DataType type) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nVisual Representation of Queue:\n");
    StackNode *current = front;
    printf("    ----\n");
    while (current != NULL) {
        if (type == DT_INT) {
            printf("   | %2d |\n", *(int *)current->data);
        } else if (type == DT_CHAR) {
            printf("   |  %c |\n", *(char *)current->data);
        } else {
            printf("   | %s |\n", (char *)current->data);
        }
        printf("    ----\n");
        current = current->next;
    }
    printf("\n");
}

// Helper functions for insertion and deletion as you provided
TreeNode* insertInt(TreeNode* root, int value) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insertInt(root->left, value);
    } else if (value > root->data) {
        root->right = insertInt(root->right, value);
    }
    return root;
}

// Delete a node from the tree
TreeNode* deleteInt(TreeNode* root, int value) {
    if (root == NULL) {
        printf("Value not found in the tree.\n");
        return NULL;
    }
    if (value < root->data) {
        root->left = deleteInt(root->left, value);
    } else if (value > root->data) {
        root->right = deleteInt(root->right, value);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteInt(root->right, temp->data);
    }
    return root;
}

// Helper function to find the minimum node in a subtree
TreeNode* findMinNode(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


// Inorder Traversal
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder Traversal
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Find the height of the tree
int findHeight(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count total nodes
int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count total leaf nodes
int countLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// Find ancestors of a given node
void findAncestors(TreeNode* root, int value) {
    if (root == NULL) {
        return;
    }
    if ((root->left && root->left->data == value) || (root->right && root->right->data == value)) {
        printf("%d ", root->data);
        return;
    }
    if (value < root->data) {
        findAncestors(root->left, value);
        if (root->left) printf("%d ", root->data);
    } else {
        findAncestors(root->right, value);
        if (root->right) printf("%d ", root->data);
    }
}

// Find depth of a given node
int findDepth(TreeNode* root, int value) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == value) {
        return 0;
    }
    int depth = (value < root->data) ? findDepth(root->left, value) : findDepth(root->right, value);
    if (depth >= 0) {
        return depth + 1;
    }
    return -1;
}
