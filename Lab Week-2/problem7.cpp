#include<iostream>

using namespace std;

string concatenatedString(string firstName, string lastName) {
   string concatenated = "";
    for(int i= 0; i < firstName.length(); i++) {
     concatenated += firstName[i];
    }
    concatenated += " ";
    for(int i= 0; i < lastName.length(); i++) {
     concatenated += lastName[i];
    }

    return concatenated;
}

int main() {
    string firstName, lastName;
    cout << "Enter First Name: ";
    getline(cin, firstName);
    cout << "Enter Last Name: ";
    getline(cin, lastName);

    string fullName = concatenatedString(firstName, lastName);
    cout << "The Full Name is " << fullName << endl;

    return 0;
}
