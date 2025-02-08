#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if the username already exists
bool isUserExists(string username) {
    ifstream file("users.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username) return true;
    }
    return false;
}

// Function to sign up
void signUp() {
    string username, password, confirmPassword;

    while (true) {
        cout << "\n===== SIGN UP =====\n";
        cout << "Username: ";
        cin >> username;

        if (isUserExists(username)) {
            cout << " This username already exists! Try again\n";
            continue;
        }

        cout << "Password: ";
        cin >> password;
        cout << "Confirm Password: ";
        cin >> confirmPassword;

        if (password != confirmPassword) {
            cout << " Passwords do not match! Try again\n";
            continue;
        }

        ofstream file("users.txt", ios::app);
        file << username << " " << password << endl;
        file.close();

        cout << " Sign-up successful!\n";
        return;
    }
}

// Function to log in
bool login(string& loggedInUser) {
    string username, password, user, pass;

    cout << "\n===== LOGIN =====\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            loggedInUser = username;
            return true;
        }
    }

    return false;
}

// Function to display Zone page
void zonePage(int zone) {
    int choice;
    string zones[3][5] = {
        {"Uniloft Chiangmai", "Home Hills", "Baan Im Rak", "Sanguanmalee Mansion", "Kai Golden Place"},
        {"Phufa Place", "The Greenery Landmark", "Pojai Apartment", "Kiang Doi Place", "Baan Pranee (Jed Yod)"},
        {"Warisa Apartment", "P.S. Mansion", "Baan Tarnkam", "Tarnthong Place Apartment Chiangmai", "Thongtara Monte"}
    };

    while (true) {
        cout << "\n===== Zone " << zone << " =====\n";
        cout << "[0] Home  (Return to Home)\n";
        cout << "[9] Back  (Go back to previous menu)\n";

        for (int i = 0; i < 5; i++) {
            cout << "[" << i+1 << "] " << zones[zone-1][i] << "\n";
        }
        
        cout << "[6] Continue  Go to Zone " << (zone < 3 ? zone+1 : 1) << "\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 0) {
            return;
        } else if (choice == 9) {
            return;
        } else if (choice >= 1 && choice <= 5) {
            cout << "\nViewing details for: " << zones[zone-1][choice-1] << "\n";
        } else if (choice == 6 && zone < 3) {
            zonePage(zone+1);
        } else if (choice == 6 && zone == 3) {
            return;
        } else {
            cout << " Please select a valid option!\n";
        }
    }
}

// Function to display Home page
void homePage(string loggedInUser) {
    int choice;
    while (true) {
        cout << "\n===== HOME PAGE =====\n";
        cout << "[1] Search \n";
        cout << "[2] Check booking history \n";
        cout << "[3] Zone 1 \n";
        cout << "[4] Zone 2 \n";
        cout << "[5] Zone 3 \n";
        cout << "[0] Logout \n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << " Searching for dormitories...\n";
                break;
            case 2:
                cout << " Your booking history...\n";
                break;
            case 3:
                zonePage(1);
                break;
            case 4:
                zonePage(2);
                break;
            case 5:
                zonePage(3);
                break;
            case 0:
                cout << " Logging out...\n";
                return;
            default:
                cout << " Please select a valid option!\n";
        }
    }
}

// Function to start the application
void startApp() {
    int choice;
    string loggedInUser;

    while (true) {
        cout << "\n===== Dormitory Booking System =====\n";
        cout << "[1] Login \n";
        cout << "[2] Sign Up \n";
        cout << "[0] Exit \n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login(loggedInUser)) {
                    cout << " Login successful!\n";
                    homePage(loggedInUser);
                } else {
                    cout << " Invalid username or password!\n";
                }
                break;
            case 2:
                signUp();
                break;
            case 0:
                cout << " Exiting the program...\n";
                return;
            default:
                cout << " Please select a valid option!\n";
        }
    }
}

// Main function
int main() {
    startApp();
    return 0;
}
