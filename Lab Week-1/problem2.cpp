#include<iostream>

using namespace std;

void opChecker(string inputText){
    char operators[6] = {'+', '-', '*', '/', '%', '='};

    bool hasOp = false;
    int count = 1;

    for (char c : inputText) {
       for(int i = 0; i < 6; i++) {
         if(c == operators[i]) {
            cout << "The operator "<< count << " is " << c << " ." << endl;
            hasOp = true;
            count++;
         }
       }
    }

    if (!hasOp) {
      cout << "There are no Operator in the given string." << endl;
    } else {
      cout << "There are exactly " << count - 1 << " operators" << endl;
    }
}

int main() {
   string input;
   cout << "Give an input:";
   getline(cin, input);
   cout << endl;

   opChecker(input);

 return 0;

}
