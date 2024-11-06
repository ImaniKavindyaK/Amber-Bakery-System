#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct User {
    string username;
    string password;
    string role;
};

vector<User> users = {
    {"admin", "admin123", "admin"},
    {"cashier", "cashier123", "cashier"}
};

vector<User> cashierUsers = {
    {"cashier1", "cashier123", "cashier"},
    {"cashier2", "cashier456", "cashier"}
};

struct BakeryItem {
    string name;
    string description;
    string category;
    float price;
};

vector<BakeryItem> bakeryItems = {
    {"Chocolate Cake", "Hot chocolate cake", "Cakes", 1500},
    {"Custard", "Homemade custard", "Desserts", 199},
    {"French Baguette", "Freshly baked baguette", "Breads", 250},
    {"Chocolate Chip Cookies", "Choco melted cookies", "Cookies", 529},
    {"Milkshake", "Vanilla milkshake", "Beverages", 400}
};

void displayBakeryItems() {
    cout << "\nAvailable Bakery Items:" << endl;
    cout << setw(20) << "Name" << setw(30) << "Description" << setw(15) << "Category" << setw(10) << "Price" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const BakeryItem& item : bakeryItems) {
        cout << setw(20) << item.name << setw(30) << item.description << setw(15) << item.category << setw(10) << fixed << setprecision(2) << item.price << endl;
    }
}

void addBakeryItem() {
    BakeryItem newItem;
    cout << "\nEnter the name of the bakery item: ";
    getline(cin, newItem.name);
    cout << "Enter the description: ";
    getline(cin, newItem.description);
    cout << "Enter the category: ";
    getline(cin, newItem.category);
    cout << "Enter the price: ";
    cin >> newItem.price;
    cin.ignore();
    bakeryItems.push_back(newItem);
    cout << "Item added successfully" << endl;
}

void searchBakeryItems() {
    string searchCriteria;
    cout << "\nEnter the name or category to search for: ";
    getline(cin, searchCriteria);

    cout << "\nSearch Results:" << endl;
    for (const BakeryItem& item : bakeryItems) {
        if (item.name.find(searchCriteria) != string::npos || item.category.find(searchCriteria) != string::npos) {
            cout << setw(20) << item.name << setw(30) << item.description << setw(15) << item.category << setw(10) << fixed << setprecision(2) << item.price << endl;
        }
    }
}

void createBill() {
    vector<BakeryItem> order;
    string itemName;
    int quantity;
    float totalBill = 0;

    displayBakeryItems();

    while (true) {
        cout << "\nEnter the name of the item to add to the order (or 'done' to finish): ";
        getline(cin, itemName);

        if (itemName == "done") {
            break;
        }

        BakeryItem* item = nullptr;
        for (BakeryItem& bakeryItem : bakeryItems) {
            if (bakeryItem.name == itemName) {
                item = &bakeryItem;
                break;
            }
        }

        if (item != nullptr) {
            cout << "Enter the quantity: ";
            cin >> quantity;
            cin.ignore();

            totalBill += item->price * quantity;
            order.push_back(*item);
        }
        else {
            cout << "Item not found " << endl;
        }
    }

    cout << "\nOrder Summary:" << endl;
    for (const BakeryItem& item : order) {
        cout << setw(20) << item.name << setw(30) << item.description << setw(15) << item.category << setw(10) << fixed << setprecision(2) << item.price << endl;
    }
    cout << "\nTotal Bill: Rs" << fixed << setprecision(2) << totalBill << endl;
}

void processOrder() {
    vector<BakeryItem> order;
    string itemName;
    int quantity;
    float totalBill = 0;

    displayBakeryItems();

    while (true) {
        cout << "\nEnter the name of the item to add to the order (or 'done' to finish): ";
        getline(cin, itemName);

        if (itemName == "done") {
            break;
        }

        BakeryItem* item = nullptr;
        for (BakeryItem& bakeryItem : bakeryItems) {
            if (bakeryItem.name == itemName) {
                item = &bakeryItem;
                break;
            }
        }

        if (item != nullptr) {
            cout << "Enter the quantity: ";
            cin >> quantity;
            cin.ignore();

            totalBill += item->price * quantity;
            order.push_back(*item);
        }
        else {
            cout << "Item not found " << endl;
        }
    }

    cout << "\nOrder Summary:" << endl;
    for (const BakeryItem& item : order) {
        cout << setw(20) << item.name << setw(30) << item.description << setw(15) << item.category << setw(10) << fixed << setprecision(2) << item.price << endl;
    }
    cout << "\nTotal Bill: Rs" << fixed << setprecision(2) << totalBill << endl;
}

void displayAdminMenu() {
    cout << "\nAmber Bakery Admin Panel" << endl;
    cout << "1. Display Bakery Items" << endl;
    cout << "2. Add Bakery Item" << endl;
    cout << "3. Search Bakery Items" << endl;
    cout << "4. Process Orders" << endl;
    cout << "5. Logout" << endl;
    cout << "6. Exit" << endl;
}

void displayCashierMenu() {
    cout << "\nAmber Bakery Cashier Panel" << endl;
    cout << "1. View Bakery Items" << endl;
    cout << "2. Create Bill" << endl;
    cout << "3. Logout" << endl;
}

int main() {
    int choice;
    string username, password;

    cout << "Welcome to Amber Bakery" << endl;

    while (true) {
        cout << "Please log in to continue." << endl;
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        bool validLogin = false;
        string userRole = "";

        for (const User& user : users) {
            if (user.username == username && user.password == password) {
                validLogin = true;
                userRole = user.role;
                break;
            }
        }

        for (const User& user : cashierUsers) {
            if (user.username == username && user.password == password) {
                validLogin = true;
                userRole = user.role;
                break;
            }
        }

        if (validLogin) {
            cout << "Login successful! " << endl;

            if (userRole == "admin") {
                while (true) {
                    displayAdminMenu();
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice) {
                    case 1:
                        displayBakeryItems();
                        break;
                    case 2:
                        addBakeryItem();
                        break;
                    case 3:
                        searchBakeryItems();
                        break;
                    case 4:
                        processOrder();
                        break;
                    case 5:
                        cout << "Logged out." << endl;
                        break;
                    case 6:
                        cout << "Exiting...." << endl;
                        return 0;
                    default:
                        cout << "Invalid choice. Please select a valid option." << endl;
                    }

                    if (choice == 5) {
                        break;
                    }
                }
            }
            else if (userRole == "cashier") {
                while (true) {
                    displayCashierMenu();
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice) {
                    case 1:
                        displayBakeryItems();
                        break;
                    case 2:
                        createBill();
                        break;
                    case 3:
                        cout << "Logged out." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please select a valid option." << endl;
                    }

                    if (choice == 3) {
                        break;
                    }
                }
            }
        }
        else {
            cout << "Invalid username or password. Please try again." << endl;
        }
    }

    return 0;
}