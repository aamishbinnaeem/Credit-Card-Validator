#include <iostream>
#include <string>

using namespace std;

bool isValid(const string& input);
string cardType(const string& input);
void displayMenu();

int main() {
    int user_choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> user_choice;

        switch (user_choice) {
            case 1:
            case 2:
            case 3:
            case 4: {
                const int SIZE = 16;
                string input;

                cout << "Enter card number: ";
                cin >> input;

                if (input.size() != SIZE) {
                    cerr << "Invalid card number length." << endl;
                    break;
                }

                if (isValid(input)) {
                    cout << "Card is VALID!" << endl;
                    cout << "Card Type: " << cardType(input) << endl;
                } else {
                    cout << "Card is INVALID!" << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (user_choice != 5);

    return 0;
}

void displayMenu() {
	
    cout << "\nWhich card type do you want to check:\n";
    cout << "1- Visa\n";
    cout << "2- Mastercard\n";
    cout << "3- American Express\n";
    cout << "4- Other type\n";
    cout << "5- Exit\n";
}

bool isValid(const string& input) {
    const int SIZE = input.size();
    int card[SIZE];

    for (int i = 0; i < SIZE; i++) {
        card[i] = input[i] - '0';
    }

    int evenSum = 0, oddSum = 0;

    for (int i = SIZE - 2; i >= 0; i -= 2) {
        int num = card[i] * 2;
        if (num > 9) num -= 9;
        evenSum += num;
    }

    for (int i = SIZE - 1; i >= 0; i -= 2) {
        oddSum += card[i];
    }

    int sum = evenSum + oddSum;

    return (sum % 10 == 0);
}

string cardType(const string& input) {
    if (input[0] == '4') {
        return "Visa";
    } else if (input[0] == '5' && input[1] >= '1' && input[1] <= '5') {
        return "Mastercard";
    } else if (input[0] == '3' && (input[1] == '4' || input[1] == '7')) {
        return "American Express";
    } else {
        return "Unknown";
    }
}


