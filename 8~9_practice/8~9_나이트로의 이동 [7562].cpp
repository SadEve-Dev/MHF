#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int l, T;
int dx[] = { 2, 1, -2, -1, -2, -1, 2, 1 };
int dy[] = { 1, 2, 1, 2, -1, - 2, -1, -2 };
vector<vector<bool>> vis;
vector<vector<int>> res;

void BFS(int X, int Y) {
	queue<pair<int, int>> q;
	q.push({ X, Y });
	vis[X][Y] = true;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nX = now.first + dx[i],
				nY = now.second + dy[i];

			if (nX < 0 || nY < 0 || nX >= l || nY >= l)
				continue;

			if (!vis[nX][nY]) {
				q.push({ nX, nY });
				res[nX][nY] = res[now.first][now.second] + 1;
				vis[nX][nY] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> l;
		vis.assign(l, vector<bool>(l, false));
		res.assign(l, vector<int>(l, 0));
		int startX, startY, arriveX, arriveY;
		cin >> startX >> startY;
		cin >> arriveX >> arriveY;
		BFS(startX, startY);
		cout << res[arriveX][arriveY] << "\n";
	}

}