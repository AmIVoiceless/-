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

        cout << "����� �� 1 �� 100\n";

        while (true) {
            cout << "������� �����: ";
            if (!(cin >> guess)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����\n";
                continue;
            }

            attempts++;

            if (guess < secretNumber) {
                cout << "����� ������\n";
            }
            else if (guess > secretNumber) {
                cout << "����� ������\n";
            }
            else {
                cout << "�� ������� ����� �� " << attempts << " �������.\n";
                break;
            }
        }

        cout << "��� ���? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            cout << "������� �� ����!\n";
            break;
        }
    }

    return 0;
}
