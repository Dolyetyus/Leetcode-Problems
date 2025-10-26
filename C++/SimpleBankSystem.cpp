class Bank {
public:
    vector<long long>& accounts; 
    int size;

    Bank(vector<long long>& balance): 
        accounts(balance), size(balance.size()) {}
    
    bool transfer(int account1, int account2, long long money) {
        if (account1>size || account2>size) return false;
        if (accounts[account1-1]<money) return false;
        accounts[account1-1] -= money;
        accounts[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account>size) return false;
        accounts[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account>size) return false;
        if (accounts[account-1]<money) return false;
        accounts[account-1] -= money;
        return true;
    }
};
