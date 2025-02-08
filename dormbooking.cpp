#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ฟังก์ชันเช็คว่ามี Username นี้แล้วหรือไม่
bool isUserExists(string username) {
    ifstream file("users.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username) return true;
    }
    return false;
}

// ฟังก์ชันสมัครบัญชี
void signUp() {
    string username, password, confirmPassword;

    cout << "\n===== SIGN UP =====\n";
    cout << "Username: ";
    cin >> username;

    if (isUserExists(username)) {
        cout << "❌ Username นี้มีอยู่แล้ว! ลองใหม่\n";
        return;
    }

    cout << "Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "❌ รหัสผ่านไม่ตรงกัน! ลองใหม่\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "✅ สมัครสมาชิกสำเร็จ!\n";
}

// ฟังก์ชันล็อกอิน
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

// ฟังก์ชันหน้า Home
void homePage(string loggedInUser) {
    int choice;
    while (true) {
        cout << "\n===== HOME PAGE =====\n";
        cout << "[1] Search 🏠\n";
        cout << "[2] เช็คประวัติการจอง 📜\n";
        cout << "[3] Zone 1 🏢\n";
        cout << "[4] Zone 2 🏢\n";
        cout << "[5] Zone 3 🏢\n";
        cout << "[0] Logout 🚪\n";
        cout << "เลือกเมนู: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "🔎 ค้นหาหอพัก...\n";
                break;
            case 2:
                cout << "📜 ประวัติการจองของคุณ...\n";
                break;
            case 3:
                cout << "🏢 ไปที่ Zone 1\n";
                break;
            case 4:
                cout << "🏢 ไปที่ Zone 2\n";
                break;
            case 5:
                cout << "🏢 ไปที่ Zone 3\n";
                break;
            case 0:
                cout << "🔴 ออกจากระบบ...\n";
                return;
            default:
                cout << "⚠️ กรุณาเลือกเมนูที่ถูกต้อง!\n";
        }
    }
}

// ฟังก์ชันเริ่มต้นโปรแกรม
void startApp() {
    int choice;
    string loggedInUser;

    while (true) {
        cout << "\n===== ระบบจองหอพัก =====\n";
        cout << "[1] Login 🔑\n";
        cout << "[2] Sign Up 📝\n";
        cout << "[0] Exit 🚪\n";
        cout << "เลือกเมนู: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (login(loggedInUser)) {
                    cout << "✅ เข้าสู่ระบบสำเร็จ!\n";
                    homePage(loggedInUser);
                } else {
                    cout << "❌ Username หรือ Password ไม่ถูกต้อง!\n";
                }
                break;
            case 2:
                signUp();
                break;
            case 0:
                cout << "🔴 ออกจากโปรแกรม...\n";
                return;
            default:
                cout << "⚠️ กรุณาเลือกเมนูที่ถูกต้อง!\n";
        }
    }
}

// ฟังก์ชัน main
int main() {
    startApp();
    return 0;
}
