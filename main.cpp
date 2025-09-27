#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// -------------------- Structs --------------------
struct Date {
    int day, month, year;
};

struct Transaction {
    string name;
    int amount;
    Date date;
    string category;
};

// -------------------- Functions --------------------

// Format Date as DD-MM-YYYY
string formatDate(const Date &d) {
    ostringstream ss;
    ss << (d.day < 10 ? "0" : "") << d.day << "-"
       << (d.month < 10 ? "0" : "") << d.month << "-"
       << d.year;
    return ss.str();
}

// Save all transactions to custom format file
void saveTransactions(const vector<Transaction> &transactions, const string &filename) {
    ofstream out(filename);
    for (const auto &t : transactions) {
        out << "NAME:" << t.name
            << "|AMOUNT:" << t.amount
            << "|DATE:" << formatDate(t.date)
            << "|CATEGORY:" << t.category << "\n";
    }
    out.close();
}

// Load transactions from custom format file
vector<Transaction> loadTransactions(const string &filename) {
    vector<Transaction> transactions;
    ifstream in(filename);
    if (!in) return transactions; // file may not exist yet

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        Transaction t;
        stringstream ss(line);
        string token;

        getline(ss, token, '|'); t.name = token.substr(5);        // NAME:
        getline(ss, token, '|'); t.amount = stoi(token.substr(7)); // AMOUNT:
        getline(ss, token, '|'); // DATE:DD-MM-YYYY
        t.date.day = stoi(token.substr(5,2));
        t.date.month = stoi(token.substr(8,2));
        t.date.year = stoi(token.substr(11,4));
        getline(ss, token, '|'); t.category = token.substr(9);     // CATEGORY:

        transactions.push_back(t);
    }
    in.close();
    return transactions;
}

// -------------------- Main Program --------------------
int main() {
    vector<Transaction> transactions = loadTransactions("transactions.mgsai");
    int choice;

    while (true) {
        cout << "\nHELLO TO THE TRANSACTION MANAGER\n";
        cout << "--------------------------------\n";
        cout << "1. CREATE A TRANSACTION\n";
        cout << "2. VIEW TRANSACTIONS\n";
        cout << "3. EXIT\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            Transaction t;
            cout << "\nCREATE A TRANSACTION\n";
            cout << "---------------------\n";
            cout << "Transaction Name: "; cin >> t.name;
            cout << "Amount: "; cin >> t.amount;
            cout << "Date (DD MM YYYY): "; cin >> t.date.day >> t.date.month >> t.date.year;
            cout << "Category: "; cin >> t.category;

            transactions.push_back(t);
            saveTransactions(transactions, "transactions.mgsai");

            cout << "\nTransaction Saved!\n";

        } else if (choice == 2) {
            if (transactions.empty()) {
                cout << "\nNo transactions found.\n";
            } else {
                cout << "\nALL TRANSACTIONS:\n";
                for (const auto &t : transactions) {
                    cout << t.name << " | " << t.amount << " | "
                         << formatDate(t.date) << " | " << t.category << endl;
                }
            }

        } else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
