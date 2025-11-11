#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;

void multiLine (string codeLine, int &chaName, bool &multiLine) {

     if (!multiLine) {
        return;
     }

     for (int i = 0; i < codeLine.length(); i++) {

         if (codeLine[i] == '*' && codeLine[i + 1] == '/') {
            chaName = i + 2;
            multiLine = false;
            return;
         }
     }

   chaName = codeLine.length();
}



bool tokenGeneration (string codeLine, int lineNum, bool multLine) {
   unordered_map<string, string> tokenLookup = {
      {"int", "Keyword"},
      {"void", "Keyword"},
      {"main", "Keyword"},
      {"string", "Keyword"},
      {"while", "Keyword"},
      {"for", "Keyword"},
      {"endl", "Keyword"},
      {"cout", "Keyword"},
      {"float", "Keyword"},
      {"long", "Keyword"},
      {"bool", "Keyword"},
      {"char", "Keyword"},
      {"short", "Keyword"},
      {"if", "Keyword"},
      {"else", "Keyword"},
      {"switch", "Keyword"},
      {"case", "Keyword"},
      {"do", "Keyword"},
      {"default", "Keyword"},
      {"continue", "Keyword"},
      {"break", "Keyword"},
      {"goto", "Keyword"},
      {"nullptr", "Keyword"},
      {"new", "Keyword"},
      {"delete", "Keyword"},
      {"sizeof", "Keyword"},
      {"class", "Keyword"},
      {"struct", "Keyword"},
      {"this", "Keyword"},
      {"public", "Keyword"},
      {"private", "Keyword"},
      {"protected", "Keyword"},
      {"const", "Keyword"},
      {"static", "Keyword"},
      {"auto", "Keyword"},
      {"return", "Keyword"},
      {"=", "Operator"},
      {"+", "Operator"},
      {"-", "Operator"},
      {"/", "Operator"},
      {"*", "Operator"},
      {"++", "Operator"},
      {"--", "Operator"},
      {"<", "Operator"},
      {"<=", "Operator"},
      {">", "Operator"},
      {">=", "Operator"},
      {"||", "Operator"},
      {"&&", "Operator"},
      {"!", "Operator"},
      {"(", "Punctuation"},
      {")", "Punctuation"},
      {"{", "Punctuation"},
      {"}", "Punctuation"},
      {"[", "Punctuation"},
      {"]", "Punctuation"},
      {";", "Punctuation"},
      {"<<", "Punctuation"},
      {">>", "Punctuation"},
      {"true", "Constant"},
      {"false", "Constant"},
      {"==", "Operator"},
      {"!=", "Operator"},
      {"+=", "Operator"},
      {"-=", "Operator"},
      {"*=", "Operator"},
      {"/=", "Operator"},
      {"%", "Operator"},
      {".", "Punctuation"}
   };

   string currentWord = "";
   int chaName = 0;

   if(codeLine.find("#include") != string::npos ||
      codeLine.find("#define") != string::npos||
      codeLine.find("using") != string::npos) {
         return false;
   }

   if (codeLine[0] == '/' && codeLine[1] == '/') {
         return false;
   }

   if (codeLine[0] == '/' && codeLine[1] == '*') {
          chaName = 2;
          multLine = true;
          multiLine(codeLine, chaName, multLine);
          if(multLine == true) {
            return true;
          }
   }

   if (codeLine.empty()) {
      return false;
   }

   if (multLine) {

      multiLine(codeLine, chaName, multLine);

      if(chaName == codeLine.length()) {
         return true;
          }
   }

   cout << endl << "Tokens of line " << lineNum << endl;

   for (int i = chaName; i < codeLine.length(); i++) {

       if (codeLine[i] == '/' && codeLine[i + 1] == '/') {
          break;
       }

       if (codeLine[i] == '/' && codeLine[i + 1] == '*') {
          chaName = i + 2;
          multLine = true;
          multiLine(codeLine, chaName, multLine);
          if(chaName == codeLine.length()) {
            break;
          } else {
          i = chaName;
          }
       }


      if (codeLine[i] == ' ' || codeLine[i] == '\t') {

         continue;
      }

      if (isalpha(codeLine[i]) || codeLine[i] == '_') {

         currentWord = "";

         while (i< codeLine.length() && (isalnum(codeLine[i]) || codeLine[i] == '_')) {

            currentWord += codeLine[i];
            i++;
         }

         if (tokenLookup.count(currentWord)) {
            cout << currentWord << " is " << tokenLookup[currentWord] << "." << endl;
         }else {
            cout << currentWord << " is Identifier." << endl;
         }
         i--;
         continue;
      }

      if (isdigit(codeLine[i])) {

         currentWord = "";

         while(i < codeLine.length() && (isdigit(codeLine[i]) || codeLine[i] == '.')) {

            currentWord += codeLine[i];
            i++;
         }
         cout << currentWord << " is Constant." << endl;
         i--;
         continue;
      }

      if (i + 1 < codeLine.length()) {

         string twoChar = codeLine.substr(i, 2);

         if (tokenLookup.count(twoChar)) {

            cout << twoChar << " is " << tokenLookup[twoChar] << "." << endl;
            i++;
            continue;
         }
      }

      if (codeLine[i] == '"') {

         currentWord = "";
         cout << codeLine[i] << " is Punctuation." << endl;
         i++;
         while (i < codeLine.length() && codeLine[i] != '"') {

              currentWord += codeLine[i];
              i++;
            }

         cout << currentWord << " is Constant." << endl;
         cout << codeLine[i] << " is Punctuation." << endl;
         continue;
      }

      if (codeLine[i] == '\'') {

         cout << codeLine[i] << " is Punctuation." << endl;
         i++ ;
         cout << codeLine[i] << " is Constant." << endl;
         i++;
         cout << codeLine[i] << " is Punctuation." << endl;
         continue;
      }

      string oneChar(1, codeLine[i]);

      if (tokenLookup.count(oneChar)) {
          cout << oneChar << " is " << tokenLookup[oneChar] << "." <<  endl;
      } else {
         cout << oneChar << " is Unknown." << endl;
      }

   }

  return multLine;

}



int main () {

   string fileName = "Code.txt";
   ifstream inputCodeFile(fileName);

   string line;

   cout << "Tokens of all contents of " << fileName << endl;
   int lineNum = 1;
   bool mulLine = false;

   while(getline(inputCodeFile, line)) {

      bool currentMul = tokenGeneration(line, lineNum, mulLine);
      mulLine = currentMul;
      lineNum += 1;
   }


 return 0;
}
