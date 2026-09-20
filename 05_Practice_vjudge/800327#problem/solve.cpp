#include <iostream>
#include <string>
using namespace std;

long long calculate(const string& s) {
    long long result = 0;
    long long curr = 0;
    char op = '+';

    for (int i = 0; i <= (int)s.size(); i++) {
        if (i < s.size() && isdigit(s[i])) {
            curr = curr * 10 + (s[i] - '0');
        } else {
            if (op == '+') result += curr;
            else result -= curr;
            if (i < s.size()) op = s[i];
            curr = 0;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << calculate(S) << "\n";
    }
    return 0;
}