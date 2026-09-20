#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int N;
char map[MAXN + 10][MAXN + 10];

char ans;//구매자 이름 Buyer's name
int areacnt;//구매자 영역 개수 Number of buyer's area

bool visit[MAXN + 10][MAXN + 10];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int BFS(int sr, int sc, char color) {
    queue<pair<int,int>> q;
    q.push({sr, sc});
    visit[sr][sc] = true;

    int cnt = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = cur.first + dr[k];
            int nc = cur.second + dc[k];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (visit[nr][nc] || map[nr][nc] != color) continue;

            visit[nr][nc] = true;
            q.push({nr, nc});
            cnt++;
        }
    }
    return cnt;
}

void InputData() {
	cin >> N;
	for (int h = 0; h < N; h++) {
		cin >> map[h];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();// 입력받는 부분 Input

	// 여기서부터 작성 Write from here

    int zone[3] = {0};
    int area[3] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                char c = map[i][j];
                
                int id;
                if (c == 'R') id = 0;
                else if (c == 'G') id = 1;
                else id = 2;

                int size = BFS(i, j, c);

                zone[id]++;
                area[id] += size;
            }
        }
    }

    int best = 0;
    for (int i = 1; i < 3; i++) {
        if (zone[i] > zone[best]) best = i;
        else if (zone[i] == zone[best]) {
            if (area[i] > area[best]) best = i;
        }
    }

    ans = (best==0 ? 'R' : best==1 ? 'G' : 'B');
    areacnt = zone[best];

	cout << ans << " " << areacnt << "\n";// 출력하는 부분 Output
	return 0;
}
