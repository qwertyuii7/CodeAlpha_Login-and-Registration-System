#include<bits/stdc++.h>
using namespace std;
class generate{

    public:
    bool login(const string& username, const string& password) {
        hash<string> hasher;
        size_t hashedPassword = hasher(password); 
        ifstream file("users.txt");
        if (!file.is_open()) {
            cout << "Error: Unable to open users.txt file." << endl;
            return false;
        }
        string storedUsername;
        size_t storedHashedPassword;
        while (file >> storedUsername >> storedHashedPassword) {
            if (storedUsername == username && storedHashedPassword == hashedPassword) {
                cout << "Login successful!" << endl;
                file.close();
                return true;
            }
        }
        cout << "Invalid username or password." << endl;
        file.close();
        return false;
    }
    bool isDuplicateUsername(const string& username) {
        ifstream file("users.txt");
        string storedUsername;
        size_t tempPassword;
        while (file >> storedUsername >> tempPassword) {
            if (storedUsername == username) {
                return true; 
            }
        }
        return false; 
    }
    bool isValidUsername(const string& username) {
        for (char ch : username) {
            if (!isalnum(ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }
    bool isvalidpassword(const string & password){
        if(password.length()<8)return false;
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

        for (char ch : password) {
            if (isupper(ch)) hasUpper = true;
            else if (islower(ch)) hasLower = true;
            else if (isdigit(ch)) hasDigit = true;
            else if (ispunct(ch)) hasSpecial = true;  
        }
        return hasUpper && hasLower && hasDigit && hasSpecial;
    }
    int systemFunc(){
        string username;
        string password;
        cout<<"Enter username";
        cin>> username;
        if (isValidUsername(username)) {
            cout << "Valid username " << endl;
        } else  {
            cout << "Invalid username  (No special characters allowed)" << endl;
            cin>>username;
        }
        
        if (isDuplicateUsername(username)) {
            
            cout << "Username already exists. Please choose a different one." << endl;
        }
        cout<<"Enter password"<<endl;
        cin.ignore();
        getline(cin,password);
        int x =password.length();
        if(isvalidpassword(password)){
            cout<<" Password validated "<<endl;

        }else{
            cout<<"Password isn't strong enough"<<endl;
            getline(cin,password);
        }
        hash<string> hasher;    
        size_t hashedpassword =hasher(password);

        ofstream file("users.txt",ios::app);

        if(file.is_open()){

            file << username << " " << hashedpassword << endl;
            file.close();
        }else{
            cout<<"Error: Could not open file for writing."<<endl;
        }
        return 0;     
    }


};
int main() {
    generate g;
    int choice;
    string uname, pass;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.systemFunc();
                break;

            case 2:
                cout << "Enter username: ";
                cin >> uname;
                cout << "Enter password: ";
                cin.ignore();
                getline(cin, pass);
                g.login(uname, pass);
                break;

            case 3:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

