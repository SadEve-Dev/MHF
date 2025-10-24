#include <iostream>
#include <vector>
#include <queue>
#include <string>

int N;
enum { R = 0, G, B };
int D[] = { 0, 1, 0, -1 };

using namespace std;

vector<vector<int>> A1;
vector<vector<int>> A2;
vector<vector<bool>> vis;

int BFS(vector<vector<int>>& A,int X, int Y, int color) {
	queue<pair<int, int>> q;
	q.push({ X, Y });
	vis[X][Y] = true;
	int area = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nX = now.first + D[i],
				nY = now.second + D[3 - i];
			
			if (nX < 1 || nY < 1 || nX > N || nY > N)
				continue;

			if (A[nX][nY] == color && !vis[nX][nY]) {
				q.push({ nX, nY });
				vis[nX][nY] = true;
			}
		}
		
	}
	return 1;
}

int countArea(vector<vector<int>>& A) {
	int area = 0;
	for (int x = 1; x <= N; x++)
		for (int y = 1; y <= N; y++)
			for (int color = R; color <= B; color++)
				if (A[x][y] == color && !vis[x][y])
					area += BFS(A, x, y, color);
	return area;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	A1.resize(N + 1, vector<int>(N + 1, -1));
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= N; j++)
			A1[i][j] = ((s[j-1] == 'R' ? R : s[j-1] == 'G' ? G : B));
	}

	vis.resize(N + 1, vector<bool>(N + 1, false));
	
	cout << countArea(A1) << " ";

	A2.assign(A1.begin(), A1.end());
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (A2[i][j] == G)
				A2[i][j] = R;
	vis.assign(N + 1, vector<bool>(N + 1, false));

	cout << countArea(A2) << "\n";

}