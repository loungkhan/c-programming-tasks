#include <iostream>

using namespace std;

int main() {
  double num1, num2;
  char operation;
  while (true) {
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /) or 'q' to quit: ";
    cin >> operation;

    if(operation == 'q') {
      cout << "Exiting the program..." << endl;
      break;
    }

    cout << "Enter second number: ";
    cin >> num2;

    switch (operation) {
      case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        break;
      case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        break;
      case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        break;
      case '/':
        if (num2 == 0) {
          cout << "Error: Division by zero" << endl;
        } else {
          cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
        break;
      default:
        cout << "Error: Invalid operator" << endl;
    }
  }
  return 0;
}
