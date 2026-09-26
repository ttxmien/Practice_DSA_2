#include <iostream>
#include <algorithm>
using namespace std;

string process(string sub, int k) {
    string s;
    for (int i = 0; i < k; i++) s += sub;
    
    int n = s.size();
    int step = k % n;
    rotate(s.begin(), s.end() - step, s.end());

    if (k % 2 == 1) reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        s[i] = 'a' + (s[i] - 'a' + k + i) % 26;
    }

    int mid = (n + 1) / 2;
    string left = s.substr(0, mid);
    string right = s.substr(mid);

    string res;
    for (int i = 0; i < (int)right.size(); i++) {
        res += left[i];
        res += right[i];
    }
    if (left.size() > right.size()) res += left.back();

    return res;
}

string decode(string &s, int &pos) {
    string res;

    while (pos < (int)s.size()) {
        if (s[pos] == '}') {
            pos++;
            break;
        }
        if (islower(s[pos])) res += s[pos++];
        else {
            int k = 0;
            while (isdigit(s[pos])) k = k * 10 + (s[pos++] - '0');
            pos++;
            string sub = decode(s, pos);
            res += process(sub, k);
        }
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    int pos = 0;
    cout << decode(s, pos);
    return 0;
}