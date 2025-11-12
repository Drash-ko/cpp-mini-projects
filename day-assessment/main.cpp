#include <iostream>
using namespace std;

int main() {
  // Day Assessment Program
  int productivity, mood, energy;
  const int MIN = 1, MAX = 5;
  int attempt = 0;
  char retry;

  cout << "Welcome to the day assessment program!" << endl;

  do {
    // Ввод productivity
    do {
      cout << "Please provide an assessment for your today's productivity "
              "(1-5): ";
      cin >> productivity;
      if (productivity < MIN || productivity > MAX) {
        cout << "Incorrect value! Enter a number between 1 and 5." << endl;
      }
    } while (productivity < MIN || productivity > MAX);

    // Ввод mood
    do {
      cout << "What about today's mood? (1-5): ";
      cin >> mood;
      if (mood < MIN || mood > MAX) {
        cout << "Incorrect value! Enter a number between 1 and 5." << endl;
      }
    } while (mood < MIN || mood > MAX);

    // Ввод energy
    do {
      cout << "Describe your energy level throughout the day (1-5): ";
      cin >> energy;
      if (energy < MIN || energy > MAX) {
        cout << "Incorrect value! Enter a number between 1 and 5." << endl;
      }
    } while (energy < MIN || energy > MAX);

    // Рассчет среднего
    int averageValue = (productivity + mood + energy) / 3;

    // Вывод оценки
    switch (averageValue) {
    case 1:
    case 2:
      cout << "Oh dear, your day isn't going well!" << endl;
      break;
    case 3:
      cout << "Average result, but don't give up!" << endl;
      break;
    case 4:
      cout << "You've had a pretty good day, congratulations!" << endl;
      break;
    case 5:
      cout << "You're having a great day! Keep it up!" << endl;
      break;
    }

    if (productivity == 5 || mood == 5 || energy == 5) {
      cout << "Fortunately, your day had some bright moments, appreciate that."
           << endl;
    }

    // Повтор программы
    cout << "Do you want to take the test again? (y/n): ";
    cin >> retry;
    ++attempt;

  } while (retry == 'y' || retry == 'Y');

  cout << "Thank you for participating! The test was taken " << attempt
       << " times." << endl;

  return 0;
}
