#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int D[] = {0, 1, 0, -1};

vector<vector<int>> map;
vector<vector<bool>> vis;

void BFS(int X, int Y, int H) {
	queue<pair<int, int>> q;
	q.push({ X, Y });
	vis[X][Y] = true;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.first + D[i],
				nextY = now.second + D[3 - i];

			if (nextX < 1 || nextY < 1 || nextX > N || nextY > N)
				continue;

			if (map[nextX][nextY] > H && !vis[nextX][nextY]) {
				q.push({ nextX, nextY });
				vis[nextX][nextY] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	int maxH = 0;
	map.resize(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			maxH = max(maxH, map[i][j]);
		}

	int res = 0;
	for (int floodH = 0; floodH < maxH; floodH++) {
		vis.assign(N + 1, vector<bool>(N + 1, false));

		int count = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (map[i][j] > floodH && !vis[i][j]) {
					count++;
					BFS(i, j, floodH);
				}
		res = max(res, count);
	}

	cout << res << "\n";
}