#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int a = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = a;
    }
}                                       //for task 1  


void fillArray(int** arr, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 41 + 10; 
        }
    }
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        std::cout << endl;
    }
}                                       //for task 2

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    else {
        std::cout << "division by zero" << std::endl;
        return 0;
    }
}                                       //for task 3
int main() {

    /*task 1 */

    int* arr = new int[12]; 
    std::cout << "enter znacheniya v massive: " << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cin >> arr[i]; 
    }

    std::cout << "poluchenny massiv: " << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << arr[i] << " " << std::endl;
    }
 

    swap(arr, 12);
    std::cout << "pozle zameny yacheek: " << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << arr[i] << " " << std::endl;
    }
    
    delete[] arr; 

    /* task 2 */

    int rows = 0;
    int cols = 0;
    std::cout << "enter the number of rows: " << std::endl;
    std::cin >> rows;
    std::cout << "enter the number of cols: " << std::endl;
    std::cin >> cols;
    int** array = new int* [rows]; 
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols]; 
    }
    fillArray(array, rows, cols); 
    std::cout << "dvumerniy dinamicheskiy massiv:" << std::endl;
    printArray(array, rows, cols); 
    for (int i = 0; i < rows; i++) {
        delete[] array[i]; 
    }
    delete[] array;

    /* task 3 */

    int num1, num2;
    char op; //знак операции
    
    int (*operation)(int, int);

    while (true) {
        std::cout << "enter two numbers and the sign: " << std::endl;
        std::cin >> num1 >> num2 >> op;

        if (op == ' ') {
            break; 
        }

       
        switch (op) {
        case '+':
            operation = &add;
            break;
        case '-':
            operation = &subtract;
            break;
        case '*':
            operation = &multiply;
            break;
        case '/':
            operation = &divide;
            break;
        default:
            std::cout << "another operation needed" << std::endl;
            continue;
        }

        
        std::cout << "result is " << operation(num1, num2) << std::endl;
    }
}
