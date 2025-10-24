	#include <iostream>
	#include <queue>
	#include <algorithm>
	#include <vector>

	using namespace std;

	int N, M;
	int d[] = { 0, -1, 0, 1 };
	vector<vector<int>> board;
	vector<vector<bool>> visited;

	int BFS(int x, int y) {
		queue<pair<int, int>> q;
		q.push({x, y});
		visited[x][y] = true;
		int area = 1;
		while(!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = now.first + d[i],
					nextY = now.second + d[3 - i];
			
				if (nextX < 1 || nextY < 1 || nextX > N || nextY > M)
					continue;

				if (board[nextX][nextY] == 1 && !visited[nextX][nextY]) {
					q.push({ nextX, nextY });
					visited[nextX][nextY] = true;
					area++;
				}
			}
		}
		return area;
	}

	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	
		cin >> N >> M;
		board.resize(N + 1, vector<int>(M + 1));
		visited.resize(N + 1, vector<bool>(M + 1, false));
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				cin >> board[i][j];

		int max_area = 0, count = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (board[i][j] == 1 && !visited[i][j]) {
					count++;
					max_area = max(max_area, BFS(i, j));
				}

		cout << count << "\n" << max_area << "\n";
	}		