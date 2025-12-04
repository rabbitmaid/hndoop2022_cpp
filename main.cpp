#include <iostream>
using namespace std;

class BankAccount {

    public:
      string name;
      string pin;

    private:
      int amount;

    public:
      // setter 
      void setAmount(int amt) {
         if(amt <= 0) {
             amount = 0;
         }

         amount = amt;
      }

      // getter
      int getAmount() {
        return amount;
      }

    virtual void deposit(string name1, string pin1, int amt1) = 0;
    virtual void withdraw(string name2, string pin2, int amt2) = 0;
    virtual void displayInfo(string name3, string pin3) = 0;
    virtual void changePin(string name4, string oldPin, string newPin) = 0;
};


class MyBankAccount : public BankAccount {

    public: 
      MyBankAccount() {
          name = "Ngong";
          pin = "p";
          setAmount(0);
      }

      void deposit(string name1, string pin1, int amt1) override {
         if(name1 == name && pin1 == pin) {
            
            if(amt1 > 0) {
                int currentBalance = getAmount();
                int newBalance = currentBalance + amt1;
                setAmount(newBalance);
            }else {
                cout << "You are too poor";
            }
         }
         else {
            cout << "User name and pin code do not match" << endl;
         }
      }


      void withdraw(string name2, string pin2, int amt2) override {
         if(name2 == name && pin2 == pin) {
            
            if(amt2 > 0) {
                int currentBalance = getAmount();

                if(currentBalance < amt2) {

                    cout << "Insufficient Balance" << endl;

                }else {
                    int newBalance = currentBalance - amt2;
                    setAmount(newBalance);
                }
                
            }else {
                cout << "You are too poor" << endl;
            }
         }
         else {
            cout << "User name and pin code do not match" << endl;
         }
      }


      void displayInfo(string name3, string pin3) override {
         if(name3 == name && pin3 == pin) {
            
            cout << "Account Information" << endl;
            cout << "Name: " << name << endl;
            cout << "Account Balance: " << getAmount() << endl;
         }
         else {
            cout << "User name and pin code do not match" << endl;
         }
      }


       void changePin(string name4, string oldPin, string newPin) override {
         if(name4 == name && oldPin == pin) {
            pin = newPin;
         }
         else {
            cout << "User name and pin code do not match" << endl;
         }
      }


};


int main() {
  
    MyBankAccount bank;

    string name;
    string pin;
    int choice;
    int amount;
    string newPin;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your pin: ";
    cin >> pin;

    do{
        printf("\n");
        cout << "1) Deposit " << endl;
        cout << "2) Withdrawal " << endl;
        cout << "3) See Information " << endl;
        cout << "4) Change Pin " << endl;
        cout << "0) Exit " << endl;
        cout << "Select an option: ";
        cin >> choice;
        printf("\n");

        switch(choice) {

            case 1:
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                printf("\n");
                bank.deposit(name, pin, amount);
            break;

            case 2: 
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                printf("\n");
                bank.withdraw(name, pin, amount);
            break;

            case 3: 
                bank.displayInfo(name, pin);
            break;

            case 4:
                cout << "Enter your new pin: ";
                cin >> newPin;
                printf("\n");
                bank.changePin(name, pin, newPin);
            break;

            case 0:
            break;

            default: 
                cout << "Invalid Choice" << endl;
        }
    }
    while(choice != 0);

    return 0;
}

