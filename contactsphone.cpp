#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

string name[50];
string phoneNo[50];
string mobileNo[50];
string faxNo[50];
string email[50];
string address[50];
int counter = -1;

int validateContact(string tmpName) {
    for (int i = 0; i <= counter; i++) {
        if (name[i] == tmpName) {
            return 0;
        }
    }
    return 1;
}

void pauseScreen() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void addContact() {
    string tmpName;
    cin.ignore();  // Clear input buffer
    cout << "Enter Name: ";
    getline(cin, tmpName);

    if (validateContact(tmpName)) {
        counter++;
        name[counter] = tmpName;
    } else {
        cout << "\nContact already exists with this name.\n";
        return;
    }

    cout << "Enter Phone No: ";
    getline(cin, phoneNo[counter]);
    cout << "Enter Mobile No: ";
    getline(cin, mobileNo[counter]);
    cout << "Enter Fax No: ";
    getline(cin, faxNo[counter]);
    cout << "Enter Email: ";
    getline(cin, email[counter]);
    cout << "Enter Address: ";
    getline(cin, address[counter]);
}

void print(int tmpCounter) {
    if (name[tmpCounter] == "")
        return;

    cout << "\n--- Contact Info ---\n";
    cout << "Name     : " << name[tmpCounter] << endl;
    cout << "Phone No : " << phoneNo[tmpCounter] << endl;
    cout << "Mobile   : " << mobileNo[tmpCounter] << endl;
    cout << "Fax      : " << faxNo[tmpCounter] << endl;
    cout << "Email    : " << email[tmpCounter] << endl;
    cout << "Address  : " << address[tmpCounter] << endl;
    cout << "----------------------\n\n";

    pauseScreen();
}

void printAll() {
    if (counter > -1) {
        for (int i = 0; i <= counter; i++) {
            if (name[i] != "") {
                print(i);
            }
        }
    } else {
        cout << "No contacts to display.\n";
        pauseScreen();
    }
}

void updateContact(int tmpCounter) {
    string tmpName;
    cin.ignore();
    cout << "Enter New Name: ";
    getline(cin, tmpName);

    if (tmpName != name[tmpCounter] && !validateContact(tmpName)) {
        cout << "\nAnother contact exists with this name.\n";
        return;
    }

    name[tmpCounter] = tmpName;

    cout << "Enter Phone No: ";
    getline(cin, phoneNo[tmpCounter]);
    cout << "Enter Mobile No: ";
    getline(cin, mobileNo[tmpCounter]);
    cout << "Enter Fax No: ";
    getline(cin, faxNo[tmpCounter]);
    cout << "Enter Email: ";
    getline(cin, email[tmpCounter]);
    cout << "Enter Address: ";
    getline(cin, address[tmpCounter]);
}

void deleteContact(int tmpCounter) {
    name[tmpCounter] = "";
    phoneNo[tmpCounter] = "";
    mobileNo[tmpCounter] = "";
    faxNo[tmpCounter] = "";
    email[tmpCounter] = "";
    address[tmpCounter] = "";
    cout << "Contact deleted successfully.\n";
}

int findCounter() {
    if (counter < 0)
        return -1;

    string tmpName;
    cin.ignore();
    cout << "Enter Name to Search: ";
    getline(cin, tmpName);

    for (int i = 0; i <= counter; i++) {
        if (name[i] == tmpName) {
            return i;
        }
    }
    return -1;
}

// Swap all fields between two indices
void swap(int i, int j) {
    std::swap(name[i], name[j]);
    std::swap(phoneNo[i], phoneNo[j]);
    std::swap(mobileNo[i], mobileNo[j]);
    std::swap(faxNo[i], faxNo[j]);
    std::swap(email[i], email[j]);
    std::swap(address[i], address[j]);
}

// Partition function for Quick Sort
int partition(int low, int high) {
    string pivot = name[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (name[j] < pivot) {
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return i + 1;
}

// Quick Sort implementation
void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {
    char op;

    do {
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. List Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "7. Sort Contacts (By Name)\n\n";
        cout << "Enter Option (1-7): ";
        cin >> op;

        switch (op) {
        case '1':
            addContact();
            cout << "Contact added successfully.\n";
            pauseScreen();
            break;
        case '2':
            printAll();
            break;
        case '3': {
            int tmpCounter = findCounter();
            if (tmpCounter > -1)
                print(tmpCounter);
            else
                cout << "Contact not found!\n";
            pauseScreen();
            break;
        }
        case '4': {
            int tmpCounter = findCounter();
            if (tmpCounter > -1)
                updateContact(tmpCounter);
            else
                cout << "Contact not found!\n";
            pauseScreen();
            break;
        }
        case '5': {
            int tmpCounter = findCounter();
            if (tmpCounter > -1)
                deleteContact(tmpCounter);
            else
                cout << "Contact not found!\n";
            pauseScreen();
            break;
        }
        case '6':
            cout << "Exiting program...\n";
            break;
        case '7':
            if (counter >= 0) {
                quickSort(0, counter);
                cout << "Contacts sorted successfully.\n";
            } else {
                cout << "No contacts to sort.\n";
            }
            pauseScreen();
            break;
        default:
            cout << "Invalid option. Try again.\n";
            pauseScreen();
        }
    } while (op != '6');

    return 0;
}
