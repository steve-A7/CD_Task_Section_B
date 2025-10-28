#include<iostream>


using namespace std;

void commentChecker(string input){
   string commentText = "";

   bool firstSlash = false;
   bool isComment = false;

   for(int i = 0; i < input.length(); i++) {
      char c = input[i];
      if(firstSlash) {
         if(c == '*') {
            isComment = true;
            i++;
            while(i < input.length() - 1) {
               if(input[i] == '*' && input[i + 1] == '/') {
                i ++;
                break;
               }
               commentText += input[i];
               i++;
            }

            cout << "Comment Found: " << commentText << "." << endl;
            firstSlash = false;
            commentText = "";

         } else {
            firstSlash = false;
         }

      }

      if(c == '/') {
        firstSlash = true;
      } else {
        firstSlash = false;
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
