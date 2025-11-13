#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int amount;       // количество разных товаров
  double price[20]; // цена каждого товара
  int num[20];      // количество каждого товара
  int maxAmount = sizeof(num) / sizeof(num[0]);

  cout << "\nWelcome to GitHub Supermarket" << endl;

  do {
    cout << "Please provide an amount of goods you want to buy: ";
    cin >> amount;

    if (amount > maxAmount) {
      cout << "Error: max amount of goods is " << maxAmount
           << ", try again\n\n";
    } else if (amount < 0) {
      cout << "Error: amount can't be lower than 0\n\n";
    }
  } while (amount > maxAmount || amount < 0);

  cout << "Nice! Let's figure out the prices\n" << endl;

  // справочник кодов и цен
  int codes[]{2146, 5764, 6487, 1345, 7843};
  double prices[]{2.5, 3.2, 7.6, 1.2, 5.7};
  int size = sizeof(codes) / sizeof(codes[0]);

  for (int i = 0; i < amount; i++) {
    int inputMethod;
    cout << "Item " << i + 1 << ": Choose input method:\n";
    cout << "1. Enter price manually\n";
    cout << "2. Enter product code\n";
    cin >> inputMethod;

    if (inputMethod == 1) {
      cout << "Enter the price of item " << i + 1 << ": ";
      cin >> price[i];
    } else if (inputMethod == 2) {
      int code;
      bool found = false;

      while (!found) {
        cout << "Please provide a code: ";
        cin >> code;

        for (int j = 0; j < size; j++) {
          if (codes[j] == code) {
            price[i] = prices[j];
            cout << "Recognized. Price: " << price[i] << endl;
            found = true;
            break;
          }
        }

        if (!found)
          cout << "Product not found. Try again.\n";
      }
    } else {
      cout << "Invalid choice. Try again.\n";
      i--; // повторить итерацию
      continue;
    }

    cout << "How many of this item did you buy? ";
    cin >> num[i];
    cout << endl;
  }

  // расчёт итоговой стоимости
  double cheque = 0;
  for (int i = 0; i < amount; i++) {
    cheque += price[i] * num[i];
  }

  // скидки
  if (cheque > 1000) {
    cout << "Congratulations! You get 15% discount.\n";
    cheque *= 0.85;
  } else if (cheque > 500) {
    cout << "Congratulations! You get 10% discount.\n";
    cheque *= 0.9;
  }

  cout << fixed << setprecision(2);
  cout << "Payable: " << cheque << endl;

  return 0;
}