
#include <bits/stdc++.h>

using namespace std;

class BankAccount {

    private:
        long accountNumber;
        
        string accountHolder;
        
        double balance;
        
        string username;
        
        string password;
        
        long mobileNo;
        
    
    public:
        BankAccount(long accNum, string accHolder, double initialBalance, string uname, string pwd, long mno) {
            
            accountNumber = accNum;
            
            accountHolder = accHolder;
            
            balance = initialBalance;
            
            username = uname;
            
            password = pwd;
            
            mobileNo = mno;
        }
    
        long getAccountNumber()  { return accountNumber; }
        
        string getUsername()  { return username; }
        
        double getBalance() { return balance; }
    
        bool verifyCredentials(string& uname,string& pwd)  {
            
            return (username == uname && password == pwd);
            
        }
    
        void deposit(double amount) {
            
            balance += amount;
            
            cout << "Deposit successful. New balance: ₹" << balance << endl;
        }
    
        bool withdraw(double amount) {
            
            if (balance >= amount) {
                
                balance -= amount;
                
                cout << "Withdrawal successful. New balance: ₹" << balance << endl;
                
                return true;
            } 
            else {
                
                cout << "Insufficient balance." << endl;
                
                return false;
            }
        }
        
        void displayDetails() {
            
            cout << "Account Number: " << accountNumber << endl;
            
            cout << "Account Holder: " << accountHolder << endl;
            
            cout << "Balance: ₹" << balance << endl;
            
            cout << "Mobile No: " << mobileNo << endl;
        }
        
        bool transfer(BankAccount& recipient, double amount) {
            
            if (withdraw(amount)) {
                
                recipient.deposit(amount);
                
                cout << "Transferred ₹" << amount << " to " << recipient.getUsername() << endl;
                
                return true;
                
            } 
            else {
                
                cout << "Transfer failed. Insufficient balance." << endl;
                
                return false;
            }
        }
};

class Bank {
    
    private:
        vector<BankAccount> accounts;
        
    public:
        BankAccount* findAccount(int accNum) {
            
            for (auto& account : accounts) {
                
                if (account.getAccountNumber() == accNum) {
                    
                    return &account;
                }
            }
            return nullptr;
        }
    
    public:
        void signUp(long accNum, string accHolder, double initialBalance, string uname, string pwd, long mno) {
            
            accounts.push_back(BankAccount(accNum, accHolder, initialBalance, uname, pwd, mno));
            
            cout << "Account created successfully." << endl;
        }
    
        BankAccount* login(string& uname, string& pwd) {
            
            for (auto& account : accounts) {
                
                if (account.verifyCredentials(uname, pwd)) {
                    
                    std::cout << "Login successful." << endl;
                    
                    return &account;
                }
            }
            
            cout << "Invalid credentials. Login failed." << endl;
            
            return nullptr;
        }
        
};

int main() {
    
    Bank bank;
    
    BankAccount* currentAccount = nullptr;
    
    long accountNumber;
    
    long mobileNo;
    
    string accountHolder, username, password;
    
    double initialBalance;
    
    int choice;
    
    double amount;

    do {
        cout << "\n===== Bank Application Menu =====" << endl;
        
        cout << "1. New to Bank ? Sign Up" << endl;
        
        cout << "2. Login to your Bank Account" << endl;
        
        cout << "3. Deposit Money" << endl;
        
        cout << "4. Withdraw Money" << endl;
        
        cout << "5. Check Balance" << endl;
        
        cout << "6. Transfer Money" << endl;
        
        cout << "7. Display Account Details" << endl;
        
        cout << "8. Log Out" << endl;
        
        cout << "9. Exit" << endl;
        
        cout << "===============================" << endl;
        
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        cout<< "-------------------------------\n";
        switch (choice) {
            case 1:
                cout << "Enter Account Number: ";
                
                cin >> accountNumber;
                
                cin.ignore();  // Ignore the newline character in the input buffer
            
                cout << "Enter Account Holder: ";
                
                getline(cin, accountHolder);
            
                cout << "Enter Initial Balance: ₹";
                
                cin >> initialBalance;
                
                cout << "Enter username: ";
                
                cin >> username;
                
                cout << "Enter password: ";
                
                cin >> password;
                
                cout << "Enter Moblie Number: ";
                
                cin >> mobileNo;
                
                cin.ignore();
                
                bank.signUp(accountNumber, accountHolder, initialBalance, username, password, mobileNo);
                
                break;
                
            case 2:
                cout << "Enter username: ";
                
                cin >> username;
                
                cout << "Enter password: ";
                
                cin >> password;
                
                currentAccount = bank.login(username, password);
                
                break;

            case 3:
                if (currentAccount) {
                    
                    cout << "Enter the amount to deposit: ";
                    
                    cin >> amount;
                    
                    currentAccount->deposit(amount);
                    
                } 
                else {
                    
                    cout << "Please log in first." << std::endl;
                }
                break;

            case 4:
                if (currentAccount) {
                    
                    cout << "Enter the amount to withdraw: ";
                    
                    cin >> amount;
                    
                    currentAccount->withdraw(amount);
                    
                } 
                else {
                    
                    cout << "Please log in first." << std::endl;
                }
                break;
            
            case 5:
                if (currentAccount) {
                    
                    cout << "Account balance: ₹" << currentAccount->getBalance() << endl;
                    
                } else {
                    cout << "Please log in first." << endl;
                }
                break;
            
            case 6:
                if (currentAccount) {
                    
                    int recipientAccountNumber;
                    
                    cout << "Enter recipient's account number: ";
                    
                    cin >> recipientAccountNumber;
                    
                    BankAccount* recipientAccount = bank.findAccount(recipientAccountNumber);
                    
                    if (recipientAccount) {
                        
                        cout << "Enter the amount to transfer: ";
                        
                        cin >> amount;
                        
                        currentAccount->transfer(*recipientAccount, amount);
                    } 
                    else {
                        cout << "Recipient account not found." << endl;
                    }
                }
                else {
        
                        cout << "Please log in first." << endl;
                }
                break;

            case 7:
                if (currentAccount) {
                    
                    currentAccount->displayDetails();
                    
                } 
                else {
                    
                    cout << "Please log in first." << endl;
                }
                break;
            
            case 8:
                if (currentAccount) {
                    
                currentAccount = nullptr;
            
                cout << "You have been logged out.\n";
                
                }
                else {
                    
                    cout << "Please log in first." << endl;
                }
                
                break;

            case 9:
                cout << "Thank you for using the Bank Application!" << endl;
                
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                
                break;
        }

    } while (choice != 9);

    return 0;
}

