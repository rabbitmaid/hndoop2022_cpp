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

};



int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

