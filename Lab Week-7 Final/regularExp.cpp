#include<iostream>
#include <map>

using namespace std;

bool rEEvaluateClosure(string str, map<char, int> alphabet) {
  char onlyAcceptState = '\0';
   for (int i = 0; i < str.length(); i++) {
     if(str[i] == ' ') {
      continue;
     }
     if(alphabet.find(str[i]) != alphabet.end()) {
        if(alphabet.at('a') == 0 && alphabet.at('b') == 0) {
          alphabet[str[i]] += 1;
          onlyAcceptState = str[i];
        } else {
           if(onlyAcceptState == str[i]) {
            alphabet[str[i]] += 1;
         } else {
            return false;
        }
        }
     } else {
        return false;
     }
   }
 return true;
}

bool rEEvaluateOR(string str, map<char, int> alphabet) {
    char seenAlpha = '\0';

    for (char c : str) {
        if (c == ' ') continue;

        if (alphabet.find(c) == alphabet.end()) {
            return false;
        }

        if (seenAlpha == '\0') {
            seenAlpha = c;
        } else {
            return false;
        }
    }
    return seenAlpha != '\0';
}

bool rEEvaluateConcat(string str, map<char, int> alphabet) {
    string filtered = "";

    for (char c : str) {
        if(c == ' ') {
         continue;
        }

        if (alphabet.find(c) != alphabet.end()) {
            filtered += c;
        } else {
            return false;
        }
    }

    return filtered == "ab";
}

bool rEEvaluateORStar(string str, map<char, int> alphabet) {
    for (char c : str) {
        if (c == ' ') continue;

        if (alphabet.find(c) == alphabet.end())
            return false;
    }
    return true;
}



int main () {
    string str;
    map<char, int> alphabet;
    alphabet['a'] = 0;
    alphabet['b'] = 0;

    cout << "Enter a string with only a's and b's: ";
    getline(cin, str);

    if (rEEvaluateConcat(str, alphabet)) {
        cout << "Accepted by regular expression: (ab)" << endl;
    }
    else if (rEEvaluateOR(str, alphabet)) {
        cout << "Accepted by regular expression: (a + b)" << endl;
    }
    else if (rEEvaluateClosure(str, alphabet)) {
        cout << "Accepted by regular expression: a* or b*" << endl;
    }
    else if (rEEvaluateORStar(str, alphabet)) {
        cout << "Accepted by regular expression: (a + b)*" << endl;
    }
    else {
        cout << "The string is not accepted by any regular expression" << endl;
    }

    return 0;
}
