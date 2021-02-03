/* Author: fffzlfk */
#include <bits/stdc++.h>
using namespace std;
class CurrentAccount {
    int id;
	string password;
    string name;
    double balance, annualIntersetRate;
    int lastTime;

   public:
    CurrentAccount(string _name, int _id, string _password, double _balance,
                   double _rate)
        : name(_name),
          id(_id),
          password(_password),
          balance(_balance),
          annualIntersetRate(_rate) {
        lastTime = 0;
    }

    void SaveMoney(double money, int time) {
        balance = balance +
                  balance * (time - lastTime) * annualIntersetRate / 365 +
                  money;
        lastTime = time;
    }

    void WithDrawalMoney(double money, int time) {
        balance =
            balance + balance * (time - lastTime) * annualIntersetRate / 365;
        balance -= money;
        lastTime = time;
    }

    double GetAnnualInterest() { return balance * annualIntersetRate; }

    void PrintAccount() {
        cout << "Account Name = " << name << '\n';
        cout << "Account Id = " << id << '\n';
        cout << "Balance = " << balance << '\n';
        cout << "Annual Interest Rate = " << annualIntersetRate << '\n';
    }
};

int main() {
    CurrentAccount ca("Zhang San", 20201001, "123456", 8000.0, 0.012);
    ca.SaveMoney(1000, 60);
    ca.WithDrawalMoney(3000, 100);
    ca.SaveMoney(5000, 120);
    ca.PrintAccount();
    cout << ca.GetAnnualInterest() << endl;
    return 0;
}
