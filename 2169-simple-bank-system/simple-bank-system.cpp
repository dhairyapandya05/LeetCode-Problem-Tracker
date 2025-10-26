class Bank {
private:
    vector<long long> balances;  

    bool isValid(int account) {
        return (account >= 1 && account <= balances.size());
    }

public:
    Bank(vector<long long>& balance) {
        balances = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if (isValid(account1) && isValid(account2) && balances[account1 - 1] >= money) {
            balances[account1 - 1] -= money;
            balances[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money) {
        if (isValid(account)) {
            balances[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(int account, long long money) {
        if (isValid(account) && balances[account - 1] >= money) {
            balances[account - 1] -= money;
            return true;
        }
        return false;
    }

    void display() {
        cout << "Balances: ";
        for (long long b : balances)
            cout << b << " ";
        cout << endl;
    }
};
