#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>  // Add this line to include the <algorithm> header

using namespace std;

// ... (rest of the code remains unchanged)


// Structure to store customer detail
struct Customer {
    int roomNumber;
    string name;
    string address;
    double bill;
};

// Function prototypes
void displayMenu();
void bookRoom(vector<Customer> &customers);
void searchCustomer(const vector<Customer> &customers);
void displayAllotment(const vector<Customer> &customers);
void modifyRecord(vector<Customer> &customers);
void deleteRecord(vector<Customer> &customers);
void displayBill(const vector<Customer> &customers);

int main() {
    vector<Customer> customers;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookRoom(customers);
                break;
            case 2:
                searchCustomer(customers);
                break;
            case 3:
                displayAllotment(customers);
                break;
            case 4:
                modifyRecord(customers);
                break;
            case 5:
                deleteRecord(customers);
                break;
            case 6:
                displayBill(customers);
                break;
            case 7:
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}

void displayMenu() {
    cout << "===== Simple Hotel Management System =====\n";
    cout << "1. Book a Room\n";
    cout << "2. Search Customer Details\n";
    cout << "3. View Allotted Rooms\n";
    cout << "4. Modify Customer Record\n";
    cout << "5. Delete Customer Record\n";
    cout << "6. Display Customer Bill\n";
    cout << "7. Exit\n";
}

void bookRoom(vector<Customer> &customers) {
    Customer newCustomer;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, newCustomer.name);
    cout << "Enter Customer Address: ";
    getline(cin, newCustomer.address);
    cout << "Enter Room Number: ";
    cin >> newCustomer.roomNumber;
    cout << "Enter Bill Amount: $";
    cin >> newCustomer.bill;

    customers.push_back(newCustomer);

    cout << "Room booked successfully!\n";
}

void searchCustomer(const vector<Customer> &customers) {
    int roomNumber;
    cout << "Enter Room Number to search: ";
    cin >> roomNumber;

    for (const auto &customer : customers) {
        if (customer.roomNumber == roomNumber) {
            cout << "Customer Details:\n";
            cout << "Name: " << customer.name << endl;
            cout << "Address: " << customer.address << endl;
            cout << "Room Number: " << customer.roomNumber << endl;
            cout << "Bill Amount: $" << fixed << setprecision(2) << customer.bill << endl;
            return;
        }
    }

    cout << "Customer not found for Room Number " << roomNumber << endl;
}

void displayAllotment(const vector<Customer> &customers) {
    cout << "Allotted Rooms:\n";
    for (const auto &customer : customers) {
        cout << "Room Number: " << customer.roomNumber << " - " << customer.name << endl;
    }
}

void modifyRecord(vector<Customer> &customers) {
    int roomNumber;
    cout << "Enter Room Number to modify: ";
    cin >> roomNumber;

    for (auto &customer : customers) {
        if (customer.roomNumber == roomNumber) {
            cout << "Enter new Customer Name: ";
            cin.ignore();
            getline(cin, customer.name);
            cout << "Enter new Customer Address: ";
            getline(cin, customer.address);
            cout << "Enter new Bill Amount: $";
            cin >> customer.bill;

            cout << "Record modified successfully!\n";
            return;
        }
    }

    cout << "Customer not found for Room Number " << roomNumber << endl;
}

void deleteRecord(vector<Customer> &customers) {
    int roomNumber;
    cout << "Enter Room Number to delete: ";
    cin >> roomNumber;

    auto it = remove_if(customers.begin(), customers.end(),
                        [roomNumber](const Customer &customer) {
                            return customer.roomNumber == roomNumber;
                        });

    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "Record deleted successfully!\n";
    } else {
        cout << "Customer not found for Room Number " << roomNumber << endl;
    }
}

void displayBill(const vector<Customer> &customers) {
    int roomNumber;
    cout << "Enter Room Number to display bill: ";
    cin >> roomNumber;

    for (const auto &customer : customers) {
        if (customer.roomNumber == roomNumber) {
            cout << "Bill Amount for Room Number " << roomNumber << ": $" << fixed << setprecision(2) << customer.bill << endl;
            return;
        }
    }

    cout << "Customer not found for Room Number " << roomNumber << endl;
}