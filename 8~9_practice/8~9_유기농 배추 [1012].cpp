#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M, N, K;
int D[] = { 0, -1, 0, 1 };

vector<vector<int>> field;
vector<vector<bool>> vis;

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	vis[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.first + D[i],
				nextY = now.second + D[3 - i];

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M)
				continue;

			if (field[nextX][nextY] == 1 && !vis[nextX][nextY]) {
				q.push({ nextX, nextY });
				vis[nextX][nextY] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		
		cin >> M >> N >> K;
		field.assign(N, vector<int>(M, 0));
		vis.assign(N, vector<bool>(M, false));
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		int count = 0;
		for (int x = 0; x < N; x++)
			for (int y = 0; y < M; y++)
				if (field[x][y] == 1 && !vis[x][y]) {
					BFS(x, y);
					count++;
				}

		cout << count << "\n";
	}
}