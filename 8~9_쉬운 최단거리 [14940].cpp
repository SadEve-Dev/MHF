#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int D[] = { 0, 1, 0, -1 };

vector<vector<int>> map;
vector<vector<bool>> vis;
vector<vector<int>> res;

void BFS(int X, int Y) {
	queue<pair<int, int>> q;
	q.push({ X, Y });
	vis[X][Y] = true;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = now.first + D[i],
				nextY = now.second + D[3-i];

			if (nextX < 1 || nextY < 1 || nextX > N || nextY > M)
				continue;

			if (map[nextX][nextY] == 1 && !vis[nextX][nextY]) {
				q.push({ nextX, nextY });
				res[nextX][nextY] = res[now.first][now.second] + 1;
				vis[nextX][nextY] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	map.resize(N + 1, vector<int>(M + 1));
	res.resize(N + 1, vector<int>(M + 1, -1));
	
	int startX, startY;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				res[i][j] = 0;
				startX = i;
				startY = j;
			}
			else if (map[i][j] == 0)
				res[i][j] = 0;
			
		}

	vis.resize(N + 1, vector<bool>(M + 1, false));
	BFS(startX, startY);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cout << res[i][j] << (j < M ? " " : "\n");
		
	
}