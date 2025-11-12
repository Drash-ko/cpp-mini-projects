#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int amount; // количество разных товаров
    cout << "\nWelcome to GitHub Supermarket" << endl;
    cout << "Please provide an amount of goods you want to buy: ";
    cin >> amount;

    double price[100]; // цена каждого товара
    int num[100];      // количество каждого товара

    cout << "Nice! Let's figure out the prices" << endl;

    // ввод данных по каждому товару
    for (int i = 0; i < amount; i++) {
        cout << "Enter the price of item " << i + 1 << ": ";
        cin >> price[i];
        cout << "How many of this item did you buy? ";
        cin >> num[i];
    }

    // расчет итоговой стоимости каждого товара
    double totalPrice[100];
    for (int i = 0; i < amount; i++) {
        totalPrice[i] = price[i] * num[i];
    }

    // подсчет общей суммы
    double cheque = 0;
    for (int i = 0; i < amount; i++) {
        cheque += totalPrice[i];
    }

    // скидки
    if (cheque > 1000) {
        cout << "Congratulations! You have been awarded a 15% discount for spending over 1000." << endl;
        cheque *= 0.85;
    } else if (cheque > 500) {
        cout << "Congratulations! You have been awarded a 10% discount for spending over 500." << endl;
        cheque *= 0.9;
    }

    cout << fixed << setprecision(2);
    cout << "Payable: " << cheque << endl;

    return 0;
}
