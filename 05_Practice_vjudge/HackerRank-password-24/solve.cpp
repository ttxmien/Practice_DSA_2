#include <iostream>
using namespace std;

int countBits(long long x) {
    int cnt = 0;
    while (x) x &= x - 1, cnt++;
    return cnt;
}

int main() {
    long long x;
    cin >> x;

    int targetBits = countBits(x);
    long long a = x - 1;
    while (a > 0 && countBits(a) != targetBits) a--;

    long long b = x + 1;
    while (countBits(b) != targetBits) b++;

    cout << (a > 0 ? a : 0) << ' ' << b;
}
