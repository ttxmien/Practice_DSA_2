#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> board(n);
    
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    int dx[] = {0, 1, 1, 1};
    int dy[] = {1, 0, 1, -1};
    
    auto isWinning = [&](int r, int c, char color) -> bool {
        for (int dir = 0; dir < 4; dir++) {
            int count = 1;

            for (int i = 1; i < 5; i++) {
                int nr = r + i*dx[dir];
                int nc = c + i*dy[dir];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == color) {
                    count++;
                } 
                else break;
            }

            for (int i = 1; i < 5; i++) {
                int nr = r - i*dx[dir];
                int nc = c - i*dy[dir];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == color) {
                    count++;
                } 
                else break;
            }
            
            if (count >= 5) return true;
        }
        return false;
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                
                if (isWinning(i, j, 'B')) {
                    cout << "B " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }

                if (isWinning(i, j, 'W')) {
                    cout << "W " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}