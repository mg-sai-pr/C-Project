#include <iostream>

#include <string>

using namespace std;

int main(){

    int choice;
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

    if(choice == 1){
        cout << "CREATE A TRANSACTION" << endl;
    }

    return 0;
}