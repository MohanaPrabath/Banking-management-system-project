#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bank_Account {
private:
    string Account_Number;
    string Account_Holder_name;
    double Balance;

public:
    Bank_Account(string Acc_Number, string Holder_Name, double Initial_Balance) {
        Account_Number = Acc_Number;
        Account_Holder_name = Holder_Name;
        Balance = Initial_Balance;
    }

    string getAccount_Number() const {
        return Account_Number;
    }

    double getBalance() const {
        return Balance;
    }
    string getAccountHolder_Name() const {
        return Account_Holder_name;
    }

    void deposit(double amount) {
        if (amount > 0) {
            Balance += amount;
            cout << "Deposit successful. Current Balance: " << Balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (Balance >= amount) {
                Balance -= amount;
                cout << "Withdrawal successful. Current Balance: " << Balance << endl;
            } else {
                cout << "Insufficient funds. Cannot withdraw." << endl;
            }
        } else {
            cout << "Invalid amount for withdrawal." << endl;
        }
    }
};

int main() {
    vector<Bank_Account> accounts;
    cout << "-------------------------" << endl;
    cout << "Banking Management System" << endl;
    cout << "-------------------------" << endl;
    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Exit\n";
        int choice;
        cout<<"choice between this:";
        cin >> choice;

        if (choice == 1) {
            string Acc_Number, Holder_Name;
            double Initial_Balance;

            cout << "Enter Account Number: ";
            cin >> Acc_Number;

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, Holder_Name);

            cout << "Enter Initial Balance: ";
            cin >> Initial_Balance;

            accounts.push_back(Bank_Account(Acc_Number, Holder_Name, Initial_Balance));
            cout << "Account created successfully." << endl;
        } else if (choice == 2) {
            string Acc_Number;
            double amount;

            cout << "Enter Account Number: ";
            cin >> Acc_Number;

            int index = -1;
            for (size_t i = 0; i < accounts.size(); ++i) {
                if (accounts[i].getAccount_Number() == Acc_Number) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                accounts[index].deposit(amount);
            } else {
                cout << "Account not found." << endl;
            }
        } else if (choice == 3) {
            string Acc_Number;
            double amount;

            cout << "Enter Account Number: ";
            cin >> Acc_Number;

            int index = -1;
            for (size_t i = 0; i < accounts.size(); ++i) {
                if (accounts[i].getAccount_Number() == Acc_Number) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                accounts[index].withdraw(amount);
            } else {
                cout << "Account not found." << endl;
            }
        } else if (choice == 4) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
