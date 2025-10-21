#include<iostream>


using namespace std;

int main() {
   string input;
   cout << "Give an input:";
   cin>> input;
   cout << endl << endl;

   bool isNumCons = true;

   for (char c: input) {
     if(c < 48 || c > 57) {
      isNumCons = false;
      break;
     }
   }

   if(isNumCons) {
      cout << "The given input is an numeric constant" << endl;
   } else {
      cout << "The given input is not an numeric constant" << endl;
   }

   return 0;

}
