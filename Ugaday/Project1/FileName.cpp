#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);

    while (true) {
        int secretNumber = distrib(gen);
        int guess, attempts = 0;

        cout << "Число от 1 до 100\n";

        while (true) {
            cout << "Введите число: ";
            if (!(cin >> guess)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод\n";
                continue;
            }

            attempts++;

            if (guess < secretNumber) {
                cout << "Число больше\n";
            }
            else if (guess > secretNumber) {
                cout << "Число меньше\n";
            }
            else {
                cout << "Вы угадали число за " << attempts << " попыток.\n";
                break;
            }
        }

        cout << "Ещё раз? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            cout << "Спасибо за игру!\n";
            break;
        }
    }

    return 0;
}
