#include <iostream>
using namespace std;

int N; // 상자의 크기
int Box[150][150];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Box[i][j];
		}
	}
}
int main() {
	int ans = -1;
	InputData(); // 입력 받는 부분

	// 여기서부터 작성

    int row[150] = {0};
    int col[150] = {0};
    int total = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            row[i] += Box[i][j];
            col[j] += Box[i][j];
            total += Box[i][j];
        }
    }

    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < N; i++) {
        if (row[i] > maxRow) maxRow = row[i];
        if (col[i] > maxCol) maxCol = col[i];
    }

    int T = max(maxRow, maxCol);
    ans = N * T - total;

	cout << ans << endl;// 출력하는 부분
	return 0;
}