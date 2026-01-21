#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>

using namespace std;

static void printIntSet(const set<int>& s) {
    cout << "{";
    bool first = true;
    for (int x : s) {
        if (!first) cout << ",";
        cout << x;
        first = false;
    }
    cout << "}";
}

int main() {
    const char STATES[]   = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
    const int  N_STATES   = sizeof(STATES) / sizeof(STATES[0]);
    const char ALPHABET[] = {'a','b'};
    const int  N_ALPHA    = sizeof(ALPHABET) / sizeof(ALPHABET[0]);
    const char startState = 'A';
    set<char> acceptStates = {'B','D','F','I','K','L','M','N','O','P','R','S','T','U'};
   
    map<char, set<int>> nfaSubset;
    nfaSubset['A'] = {1,2,5,6,8};
    nfaSubset['B'] = {9,10,11,19,20};                 
    nfaSubset['C'] = {3,6,7,8};
    nfaSubset['D'] = {10,11,19,20,21,22};
    nfaSubset['E'] = {12};
    nfaSubset['F'] = {2,4,5,6,8,9,10,11,19,22};
    nfaSubset['G'] = {6,7,8};
    nfaSubset['H'] = {13,14,17};
    nfaSubset['I'] = {9,10,11,19,20,21,22};
    nfaSubset['J'] = {3,6,7,8,12};
    nfaSubset['K'] = {10,11,15,16,19,21,22};
    nfaSubset['L'] = {10,11,16,18,19,21,22};
    nfaSubset['M'] = {2,4,5,6,8,9,10,11,13,14,17,19,22};
    nfaSubset['N'] = {9,10,11,15,16,19,20,21,22};
    nfaSubset['O'] = {3,6,7,8,10,11,12,16,18,19,21,22};
    nfaSubset['P'] = {2,4,5,6,8,9,10,11,13,14,17,19,20,21,22};
    nfaSubset['Q'] = {6,7,8,12};
    nfaSubset['R'] = {9,10,11,13,14,17,19,22};
    nfaSubset['S'] = {10,11,15,16,19,20,21,22};
    nfaSubset['T'] = {10,11,12,16,18,19,21,22};
    nfaSubset['U'] = {10,11,13,14,17,19,20,21,22};
    nfaSubset['V'] = {};

   
    map<char, map<char, char>> trans;

    trans['A']['a'] = 'B'; trans['A']['b'] = 'C';
    trans['B']['a'] = 'D'; trans['B']['b'] = 'E';
    trans['C']['a'] = 'F'; trans['C']['b'] = 'G';
    trans['D']['a'] = 'D'; trans['D']['b'] = 'E';
    trans['E']['a'] = 'H'; trans['E']['b'] = 'V';
    trans['F']['a'] = 'I'; trans['F']['b'] = 'J';
    trans['G']['a'] = 'B'; trans['G']['b'] = 'G';
    trans['H']['a'] = 'K'; trans['H']['b'] = 'L';
    trans['I']['a'] = 'D'; trans['I']['b'] = 'E';
    trans['J']['a'] = 'M'; trans['J']['b'] = 'G';
    trans['K']['a'] = 'D'; trans['K']['b'] = 'E';
    trans['L']['a'] = 'D'; trans['L']['b'] = 'E';
    trans['M']['a'] = 'N'; trans['M']['b'] = 'O';
    trans['N']['a'] = 'D'; trans['N']['b'] = 'E';
    trans['O']['a'] = 'P'; trans['O']['b'] = 'Q';
    trans['P']['a'] = 'N'; trans['P']['b'] = 'O';
    trans['Q']['a'] = 'R'; trans['Q']['b'] = 'G';
    trans['R']['a'] = 'S'; trans['R']['b'] = 'T';
    trans['S']['a'] = 'D'; trans['S']['b'] = 'E';
    trans['T']['a'] = 'U'; trans['T']['b'] = 'E';
    trans['U']['a'] = 'S'; trans['U']['b'] = 'T';
    trans['V']['a'] = 'V'; trans['V']['b'] = 'V';

    cout << "DFA Construction\n\n";


    cout << "1) Mapping (DFA state -> NFA subset)\n";
    for (int i = 0; i < N_STATES; i++) {
        char s = STATES[i];
        cout << "   " << s << " : ";
        printIntSet(nfaSubset[s]);
        cout << "\n";
    }
    cout << "\n";

    cout << "2) DFA Components\n";
    cout << "   States    = { ";
    for (int i = 0; i < N_STATES; i++) {
        cout << STATES[i] << (i + 1 < N_STATES ? ", " : " ");
    }
    cout << "}\n";

    cout << "   Alphabet  = { ";
    for (int i = 0; i < N_ALPHA; i++) {
        cout << ALPHABET[i] << (i + 1 < N_ALPHA ? ", " : " ");
    }
    cout << "}\n";

    cout << "   Start     = " << startState << "\n";

    cout << "   Accepting = { ";
    bool first = true;
    for (int i = 0; i < N_STATES; i++) {
        char s = STATES[i];
        if (acceptStates.count(s)) {
            if (!first) cout << ", ";
            cout << s;
            first = false;
        }
    }
    cout << " }\n\n";
   
    cout << "3) Transition Table\n";
    cout << left << setw(10) << "State"
         << setw(10) << "on a"
         << setw(10) << "on b"
         << "Accept?\n";
    cout << string(45, '-') << "\n";

    for (int i = 0; i < N_STATES; i++) {
        char s = STATES[i];
        cout << left << setw(10) << s
             << setw(10) << trans[s]['a']
             << setw(10) << trans[s]['b']
             << (acceptStates.count(s) ? "Yes" : "No")
             << "\n";
    }
    cout << "\n";


    map<char, int> dist;
    for (int i = 0; i < N_STATES; i++) dist[STATES[i]] = -1;

    queue<char> q;
    dist[startState] = 0;
    q.push(startState);

    while (!q.empty()) {
        char u = q.front(); q.pop();
        for (int i = 0; i < N_ALPHA; i++) {
            char sym = ALPHABET[i];
            char v = trans[u][sym];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    map<int, set<char>> level;
    for (int i = 0; i < N_STATES; i++) {
        char s = STATES[i];
        if (dist[s] >= 0) level[dist[s]].insert(s);
    }

   
    cout << "4) DFA Representation by Edges (grouped when both symbols go to same target):\n";

  
    for (auto &kv : level) {
        for (char s : kv.second) {
            char toA = trans[s]['a'];
            char toB = trans[s]['b'];

            if (toA == toB) {
                cout << s << " --a,b--> " << toA << "\n";
            } else {
                cout << s << " --a--> " << toA << "\n";
                cout << s << " --b--> " << toB << "\n";
            }
        }
    }
    return 0;
}
