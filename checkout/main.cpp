#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int amount;       // количество разных товаров
  cout << "\nWelcome to GitHub Supermarket" << endl;

  do {
    cout << "Please provide an amount of goods you want to buy: ";
    cin >> amount;

    if (amount <= 0) {
      cout << "Error: invalid amount\n\n";
    }
  } while (amount <= 0);

  cout << "Nice! Let's figure out the prices\n" << endl;
  double price[amount]; // цена каждого товара
  int num[amount];      // количество каждого товара

  // справочник кодов и цен
  int codes[]{2146, 5764, 6487, 1345, 7843};
  double prices[]{2.5, 3.2, 7.6, 1.2, 5.7};
  int size = sizeof(codes) / sizeof(codes[0]);

  for (int i = 0; i < amount; i++) {
    int inputMethod;
    do {
    cout << "Item " << i + 1 << ": Choose input method:\n";
    cout << "1. Enter price manually\n";
    cout << "2. Enter product code\n";
    cin >> inputMethod;
    if (inputMethod != 1 && inputMethod != 2) {
      cout << "Error: Enter a valid input method number\n\n";
    }
    } while (inputMethod != 1 && inputMethod != 2);

    if (inputMethod == 1) {
      do {
      cout << "Enter the price of item " << i + 1 << ": ";
      cin >> price[i];
      if (price[i] <= 0) {
        cout << "Error: Invalid price\n\n" ;
      }
      } while (price[i] <= 0);
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
    }

    do {
    cout << "How many of this item did you buy? ";
    cin >> num[i];
    cout << endl;

    if (num[i] <= 0) {
      cout << "Error: invalid amount\n\n";
    }
    } while (num [i] <= 0);
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