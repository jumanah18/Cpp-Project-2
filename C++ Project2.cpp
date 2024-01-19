#include <iostream> 
#include <string>   
#include <random>  
#include <algorithm> //Library for the (all_of) function in the ID, batchYear 
using namespace std;   
  
    // Function that counts the number of strings in the full name   
    int countSpaces(const string& str) {   
    int count = 0;   
    for (char c : str) {   
        if (c == ' ') {   
            count++;   
        }   
    }   
    return count;   
    }
    string randomfournumbers() {   
    random_device rd;   
    mt19937 gen(rd());   
    uniform_int_distribution<int> distribution(0000, 9999);   
    return to_string(distribution(gen));   
    }  

    int main() {   
    int attempts = 0;   
    string firstName, middleName, lastName, fullName, ID, password, batchYear, username, Email, cc;
    char Position;

    while (true) { 
    cout << "Enter the full name: "; 
    getline(cin, fullName);
    cout << "Enter an ID: ";  
    getline(cin, ID);
    cout << "Enter the academic position: ";  
    cin.get(Position);
    cin.ignore(); 

    // Splitting the full name into parts:
    size_t firstSpace = fullName.find(' '); 
    size_t lastSpace = fullName.rfind(' '); 
    
    firstName = fullName.substr(0, firstSpace);
    middleName = fullName.substr(firstSpace + 1, lastSpace - firstSpace - 1); 
    lastName = fullName.substr(lastSpace + 1);
    // Convert first character of first name and middle name to uppercase 
    
    firstName[0] = toupper(firstName[0]);
    middleName[0] = toupper(middleName[0]); 
    for (char &c : lastName) {
        c = toupper(c);    
    }  

    if (countSpaces(fullName) != 2) { 
        cout << "Information entered incorrectly. Please try again." << endl;
        attempts++;
        continue;  
    }
    
    // Generate password ++  Convert the first character of middle name, last name to lowercase        
    char firstLetter =firstName[0];
    char middleLetter =tolower(middleName[0]);  
    char lastLetter =tolower(lastName[0]); 
        
    string password = string(1, firstLetter) + string(1, middleLetter) + string(1, lastLetter);
    string passCode;
    if (ID.size() >= 10) 
    passCode = ID.substr(4, 6);

    cc= middleName[0]+ lastName[0];
    for (char& c :cc){
        c=tolower (c);
    }
    
        if (ID.size() != 10 || !all_of(ID.begin(), ID.end(), ::isdigit)) {
            cout << "Information entered incorrectly. Please try again." << endl;
            attempts++;
            continue;
        }

    if (!(Position == 'E' ||  Position == 'e'  || Position == 'S' || Position == 's' )) {
        cout << "Information entered incorrectly. Please try again." << endl;
        attempts++;
        continue;
    }
    
    switch (Position) {  
        case 'E':
        case 'e': 
        cout << "Username: " << firstName[0] << middleName[0] << lastName << endl; 
        // Convert first character of first name and middle name to lowercase
        firstName[0] = tolower(firstName[0]);
        middleName[0] = tolower(middleName[0]); 
        for (char &c : lastName) {
            c =tolower (c); } 
        cout << "Email: " << firstName[0]<< middleName[0]<< lastName << "@iau.edu.sa" << endl;
        break;
        
        case 'S':
        case 's': 
        cout << "Enter batch year: "; 
        getline(cin, batchYear);

        if (batchYear.size() != 4 || (stoi(batchYear) < 2013 || stoi(batchYear) > 2023) || !all_of(batchYear.begin(), batchYear.end(), ::isdigit)) {
        cout << "Information entered incorrectly. Please try again." << endl;
        attempts++;
        continue;
        }

        
        //Username + Email            
        string lastfournumbers = randomfournumbers(); 
        string lasttwonumbers = batchYear.substr(2, 2);             
        username = "2" + lasttwonumbers + "000" + lastfournumbers; 
        Email = username + "@iau.edu.sa";
        cout << "Username: " << username << endl;
        cout << "Email: " << Email << endl;             
        break; 
        }
        //Final output for the password + attempts count
        cout << "Password: " << password << "_" << passCode << endl;
        if (attempts == 0) {
            cout << "User information entered successfully, after 1 attempt." << endl;
        } else {
            cout << "User information entered successfully, after " << attempts + 1 << " attempts." << endl;
        }
        break;
    }
    return 0;
}