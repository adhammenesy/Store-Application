#include <iostream>
#include <windows.h>
#include <string> 

using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void printLine(char c, int width, int color) {
    setColor(color);
    for (int i = 0; i < width; ++i) cout << c;
    cout << endl;
}

void printContent(string content, int width, int color, int align = 1) {
    setColor(color);
    cout << "X";
    int padding = (width - 2 - content.length()) / 2;
    int paddingExtra = (width - 2 - content.length()) % 2;

    if (align == 1) {
        for (int i = 0; i < padding; ++i) cout << " ";
        cout << content;
        for (int i = 0; i < padding + paddingExtra; ++i) cout << " ";
    }
    else if (align == 0) {
        cout << " " << content;
        for (int i = 0; i < width - 2 - content.length() - 1; ++i) cout << " ";
    }
    cout << "X\n";
}

int main() {
    const int WIDTH = 100;
    int choices;

    printLine('X', WIDTH, 14);
    for (int i = 0; i < 2; ++i) printContent("", WIDTH, 14);
    printContent("********************", WIDTH, 11);
    printContent("Black's Store", WIDTH, 11);
    printContent("********************", WIDTH, 11);
    printContent("", WIDTH, 14);
    printContent("Welcome To Our Store Please Enter The", WIDTH, 10);
    printContent("Number Of Method You Want", WIDTH, 10);
    printContent("", WIDTH, 14);
    printContent("Methods:", WIDTH, 10);
    printContent("[1].Signin", WIDTH, 10);
    printContent("[2].Signup", WIDTH, 10);
    printContent("[3].Create Store", WIDTH, 10);
    printContent("[4].Delete Store", WIDTH, 10);
    printContent("[5].Store Info", WIDTH, 10);
    for (int i = 0; i < 2; ++i) printContent("", WIDTH, 14);
    printLine('X', WIDTH, 14);
    setColor(7);

    printContent("Enter your choice (1-5): ", WIDTH, 10);
    cin >> choices;

    if (choices == 1) {
        string username, display_name, email, password;

        printContent("Username: ", WIDTH, 10, 0);
        cin.ignore();
        getline(cin, username);

        printContent("Display Name: ", WIDTH, 10, 0);
        getline(cin, display_name);

        printContent("Email: ", WIDTH, 10, 0);
        getline(cin, email);

        printContent("Password: ", WIDTH, 10, 0);
        getline(cin, password);

        printContent("Thank you for signing in!", WIDTH, 10);
    }
    else if (choices == 2) {
        string email, password;

        printContent("Email: ", WIDTH, 10, 0);
        cin.ignore();
        getline(cin, email);

        printContent("Password: ", WIDTH, 10, 0);
        getline(cin, password);

        printContent("Thank you for signing in!", WIDTH, 10);
        
    }
    else if (choices == 3) {
        string name, bio, content, country;

        printContent("Store Name: ", WIDTH, 10, 0);
        cin.ignore();
        getline(cin, name);

        printContent("Store Bio: ", WIDTH, 10, 0);
        getline(cin, bio);

        printContent("Store Content: ", WIDTH, 10, 0);
        getline(cin, content);

        printContent("Store Country: ", WIDTH, 10, 0);
        getline(cin, country);

        printContent("Thank you for Creating Store in!", WIDTH, 10);
    }
    else if (choices == 4) {
        string name;

        printContent("Store Name: ", WIDTH, 10, 0);
        cin.ignore();
        getline(cin, name);

        printContent("Done success deleteing store!", WIDTH, 10);
    }
    else if (choices == 5) {
        string name;

        printContent("Store Name: ", WIDTH, 10, 0);
        cin.ignore();
        getline(cin, name);
        printContent("Displaying store info...", WIDTH, 10);
        setColor(20);
        cout << "name: Black\nBio: Store For Buy And Sell\nContent: Discord\nCountry: Egypt";
    }
    else {
        printContent("Invalid choice, please try again!", WIDTH, 12);
    }

    setColor(7);
    return 0;
}
