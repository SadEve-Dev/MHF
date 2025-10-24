#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N, D[] = { 0, -1, 0, 1 };

vector<vector<int>> map;
vector<vector<int>> vis;

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	vis[x][y] = true;
	int area = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.first + D[i],
				nextY = now.second + D[3 - i];

			if (nextX < 1 || nextY < 1 || nextX > N || nextY > N)
				continue;

			if (map[nextX][nextY] == 1 && !vis[nextX][nextY]) {
				q.push({ nextX, nextY });
				area++;
				vis[nextX][nextY] = true;
			}
		}
	}

	return area;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	map.resize(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++)
			map[i][j] = s[j-1] - '0';
	}

	vis.resize(N + 1, vector<int>(N + 1, false));
	vector<int> res;
	int count = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (map[i][j] == 1 && !vis[i][j]) {
				count++;
				res.push_back(BFS(i, j));
			}
	
	sort(res.begin(), res.end());
	
	cout << count << "\n";
	for (int i : res)
		cout << i << "\n";
}