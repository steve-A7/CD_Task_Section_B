#include<iostream>


using namespace std;

void commentChecker(string input){
   string commentText = "";

   bool firstSlash = false;
   bool isComment = false;

   for(int i = 0; i < input.length(); i++) {
      char c = input[i];
      if(firstSlash) {
         if(c == '/') {
            i++;
            while(i < input.length()) {
               commentText += input[i];
               i++;
            }

            cout << "Comment Found: " << commentText << "." << endl;
            isComment = true;
            break;
         } else {
            firstSlash = false;
            continue;
         }

      }

      if(c == '/') {
        firstSlash = true;
      }
   }

   if(!isComment) {
      cout << "No comment was found in the text." << endl;
   }
}

int main() {
   string input;
   cout << "Give an input:";
   getline(cin, input);
   cout << endl;

   commentChecker(input);

 return 0;
}
