#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> A;
vector<vector<bool>> visited; // visited 배열 추가

static int go[] = { 0, 1, 0, -1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true; // 시작점 방문 처리

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int x = now.first + go[k];
			int y = now.second + go[3-k];

			// 벽뚫 방지
			// (A.size() == N + 1, A[1].size == M + 1)
			if (x < 1 || y < 1 || x >= A.size() || y >= A[1].size())
				continue;

			// 길(1)이고, 방문 안 한(!visited) 경우에만 탐색
			if (A[x][y] == 1 && !visited[x][y]) {
				visited[x][y] = true; // 방문 처리
				A[x][y] = A[now.first][now.second] + 1;
				q.push({ x, y });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	A.resize(N + 1, vector<int>(M + 1));
	visited.resize(N + 1, vector<bool>(M + 1)); // visited 배열 크기 초기화

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++)
			A[i][j] = s[j - 1] - '0';
	}

	BFS(1, 1);

	cout << A[N][M] << "\n";
}