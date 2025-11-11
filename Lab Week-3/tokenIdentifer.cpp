#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main () {

   string fileName = "Code.txt";
   ifstream inputCodeFile(fileName);

   string line;

   cout << "The contents of " << fileName << endl;
   while(getline(inputCodeFile, line)) {
      cout << line << endl;
   }

 return 0;
}
