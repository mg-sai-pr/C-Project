#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct date {
    int day, month, year;
};

struct transaction {
    std::string name;
    int ammount;
    date date;
    std::string catagory;
};

using namespace std;

int main(){
//format date 
string formatDate(const date& d) {
    ostringstream ss;
    ss << (d.day< 10 ? "0" : "") << d.day << "-" << (d.month < 10 ? "0" : "") << d.month << "-" << d.year;
    return ss.str();
}

//Save to custom file
void  savetran(const vector<transactions>& transactions, const string &filename) {

    ofstream out(filename);
    for (const auto &t : transactions) {
        out << "NAME:" << t.name
            << "AMMOUNT:" << t.ammount
            << "DATE:" << formatDate(t.date)
            << "CATEGORY:" << t.catagory << endl;
    }
    
}

    cout << "HELLO TO THE TRANSCATION MANAGER" << endl;
    cout << "--------------------------------" << endl;
    cout << " " << endl;
    cout << "PLEASE CHOOSE ONE OF THE FOLLOWING OPTIONS" << endl;
    cout << "--------------------------------" << endl;
    cout << "1. CREATE A TRANSACTION" << endl;
    cout << "2. VIEW A TRANSACTION" << endl;
    cout << "3. DELETE A TRANSACTION" << endl;
    cout << "4. EXIT" << endl;
    cout << "PLEASE TYPE THE NUMBER OF YOUR CHOICE --> " << endl; cin >> choice;

    if(choice >= 1 && choice <= 4){
        choicebool = true;
    }
    else{
        cout << "INVALID INPUT" << endl;
        return 0;
    }

    switch (choice)
    {
        case 1:
            cout << "CREATE A TRANSACTION" << endl;
            cout << "---------------------" << endl;
            cout << "PLEASE TYPE THE NAME OF THE TRANSACTION:", cin >> nametrans;
            cout << "AMMOUNT:", cin >> ammount;
            cout << "DATE:", cin >> date;
            cout << "CATEGORY:", cin >> datecatagory; 
            break;
        case 2:
            cout << "VIEW A TRANSACTION" << endl;
            break;
        case 3:
            cout << "DELETE A TRANSACTION" << endl;
            break;
        case 4:
            cout << "EXIT" << endl;
            break;
    }

    return 0;
}