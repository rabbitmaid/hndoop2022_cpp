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



int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

