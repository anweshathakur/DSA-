// project 4 
//simpleinventory system

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct inventory{
    std::string itemname ;
    int itemquantity;
    float itemprice;
};

void init_inventory() {
    // Only create inventory.txt if it doesn't exist or is empty
    ifstream fin("inventory.txt");
    if (!fin.good() || fin.peek() == ifstream::traits_type::eof()) {
        ofstream fout("inventory.txt");
        fout << "item name\tquantity\tprice\n";
        fout << "tomato\t50\t0.5\n";
        // ... add others
        fout.close();
    }
    fin.close();
}

void display(){
    ifstream fin("inventory.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}


void sell(){
    
    string item;
    int qty;
    cout << "Enter item name to sell: ";
    cin >> item;
    cout << "Enter quantity: ";
    cin >> qty;
    // Read inventory.txt, find item, decrease quantity, write back
    // If quantity reaches zero, remove item or set quantity to zero
}




void restock(){
    
    string item;
    int qty;
    float price;
    cout << "Enter item name to restock/add: ";
    cin >> item;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price per item: ";
    cin >> price;
    // Read inventory, update or add item, write back to file
}

void discounts(){
    string season;
    cout << "Enter discount type (summer/winter): ";
    cin >> season;
    // Read inventory, adjust prices, write back
}

int main() {
    init_inventory(); // ensures inventory file exists
    int choice1, choice2;
    cout << "Welcome to our grocery store!\n";
    cout << "Select an option:\n1. Customer\n2. Employee\n";
    cin >> choice1;
    if (choice1 == 1) {
        cout << "1. View items\n";
        cin >> choice2;
        switch (choice2) {
            case 1: display(); break;
            
            default: cout << "Invalid response\n";
        }
    } else if (choice1 == 2) {
        cout << "1. View items\n 2. discounts \n4. Restock\n5. Exit\n";
        cin >> choice2;
        switch (choice2) {
            case 1: display(); break;
            case 3: discounts(); break;
            case 4: restock(); break;
            case 5: break;
            default: cout << "Invalid option\n";
        }
    }
    return 0;
}





    


