#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> area(n);
    for (int i = 0; i < n; i++) {
        cin >> area[i];
    }
    
    int left = 1;
    int right = *max_element(area.begin(), area.end());
    int result = 0;
    while (left <= right) {
        int mid = (left + right)/2;
        long long totalPie = 0;
        for (int a : area) totalPie += a/mid;
        if (totalPie >= m) {
            result = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    
    cout << result << endl;
    return 0;
}
