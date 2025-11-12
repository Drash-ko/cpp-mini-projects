#include <iostream>
using namespace std;

int main() {
    // CLI Calculator
    int a, b, operation;

    cout << "Welcome to the calculator.\n";

    // Ввод чисел
    cout << "Please write the first number: ";
    cin >> a;
    cout << "Please write the second number: ";
    cin >> b;

    // Выбор операции
    cout << "Now choose a mathematical operation:\n"
         << "1. Addition\n"
         << "2. Subtraction\n"
         << "3. Divide\n"
         << "4. Multiply\n";
    cin >> operation;

    // Выполнение выбранной операции
    switch (operation) {
        case 1:
            cout << "Result: " << a << " + " << b << " = " << a + b << endl;
            break;
        case 2:
            cout << "Result: " << a << " - " << b << " = " << a - b << endl;
            break;
        case 3:
            cout << "Result: " << a << " / " << b << " = " << (float)a / b << endl;
            break;
        case 4:
            cout << "Result: " << a << " * " << b << " = " << a * b << endl;
            break;
        default:
            cout << "Write an operation number from 1 to 4" << endl;
    }

    return 0;
}
