#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  
#include <algorithm>

using namespace std;

struct Account {
    string name;
    int age;
};

struct Trade {
    int id;
    string type;
    string asset;
    double quantity;
    double price;
    double totalValue;

    void display() const {
        cout << "Trade ID: " << id
             << ", Type: " << type
             << ", Asset: " << asset
             << ", Quantity: " << quantity
             << ", Price: $" << fixed << setprecision(2) << price
             << ", Total Value: " << fixed << setprecision(2) << totalValue << " pesos" << endl;
    }
};

class TradingManagementSystem {
private:
    vector<Trade> trades;
    int nextId = 1;
    const double usdToPesos = 55.95;
    const double btcToPesos = 3440202.99;

public:
    void createTrade(const string& type, const string& asset, double quantity) {
        double price = (asset == "USD") ? usdToPesos : btcToPesos;
        double totalValue = quantity * price;
        Trade newTrade = { nextId++, type, asset, quantity, price, totalValue };
        trades.push_back(newTrade);
        cout << "Trade created successfully!" << endl;
    }

    void readTrades() const {
        if (trades.empty()) {
            cout << "No trades available." << endl;
            return;
        }
        for (const auto& trade : trades) {
            trade.display();
        }
    }

    void updateTrade(int id, const string& type, const string& asset, double quantity) {
        for (auto& trade : trades) {
            if (trade.id == id) {
                trade.type = type;
                trade.asset = asset;
                trade.quantity = quantity;
                trade.price = (asset == "USD") ? usdToPesos : btcToPesos;
                trade.totalValue = quantity * trade.price;
                cout << "Trade updated successfully!" << endl;
                return;
            }
        }
        cout << "Trade ID not found." << endl;
    }

    void deleteTrade(int id) {
        auto it = remove_if(trades.begin(), trades.end(), [id](const Trade& trade) {
            return trade.id == id;
        });
        if (it != trades.end()) {
            trades.erase(it, trades.end());
            cout << "Trade deleted successfully!" << endl;
        } else {
            cout << "Trade ID not found." << endl;
        }
    }

    void displayCurrentPrice() const {
        cout << fixed << setprecision(2); 
        cout << "Current price of USD: " << usdToPesos << " pesos" << endl;
        cout << "Current price of BTC: " << btcToPesos << " pesos" << endl;
    }
};

int main() {
    vector<Account> accounts;  
    Account currentAccount;
    TradingManagementSystem tms;
    int choice;


    bool startTrading = false;
    do {
        cout << "\n Account " << endl;
        cout << "1. Create New Account\n";
        cout << "2. Start Trading\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1: {
             
                cout << "Enter your name: ";
                getline(cin, currentAccount.name);
                cout << "Enter your age: ";
                cin >> currentAccount.age;
                cin.ignore(); 
                accounts.push_back(currentAccount);
                cout << "Account created successfully!" << endl;
                break;
            }
            case 2: {
              
                if (accounts.empty()) {
                    cout << "No accounts available. Please create an account first." << endl;
                } else {
                    cout << "Select account to use:" << endl;
                    for (int i = 0; i < accounts.size(); ++i) {
                        cout << i + 1 << ". " << accounts[i].name << " (Age: " << accounts[i].age << ")" << endl;
                    }
                    int accountChoice;
                    cout << "Enter account number: ";
                    cin >> accountChoice;
                    if (accountChoice > 0 && accountChoice <= accounts.size()) {
                        currentAccount = accounts[accountChoice - 1];
                        cout << "Using account: " << currentAccount.name << " (Age: " << currentAccount.age << ")" << endl;
                        startTrading = true;
                    } else {
                        cout << "Invalid account selection." << endl;
                    }
                }
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (!startTrading);

   
    do {
        cout << "\n Trading System " << endl;
        cout << "1. Create Trade\n";
        cout << "2. Read Trades\n";
        cout << "3. Update Trade\n";
        cout << "4. Delete Trade\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string type, asset;
                double quantity;
                tms.displayCurrentPrice();  
                cout << "Choose asset to trade (USD/BTC): ";
                cin >> asset;
                cout << "Enter trade type (buy/sell): ";
                cin >> type;
                cout << "Enter quantity of " << asset << " you want to trade: ";
                cin >> quantity;
                tms.createTrade(type, asset, quantity);
                break;
            }
            case 2:
                tms.readTrades();
                break;
            case 3: {
                int id;
                string type, asset;
                double quantity;
                cout << "Enter trade ID to update: ";
                cin >> id;
                cout << "Choose asset to update (USD/BTC): ";
                cin >> asset;
                cout << "Enter new trade type (buy/sell): ";
                cin >> type;
                cout << "Enter new quantity of " << asset << ": ";
                cin >> quantity;
                tms.updateTrade(id, type, asset, quantity);
                break;
            }
            case 4: {
                int id;
                cout << "Enter trade ID to delete: ";
                cin >> id;
                tms.deleteTrade(id);
                break;
            }
            case 5:
                cout << "Thank you for using Trading System"<<endl;
                cout << "Exiting..." << endl;

                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
