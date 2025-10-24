#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> A;
vector<bool> visited;

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i : A[v])
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		A[start].push_back(end);
		A[end].push_back(start);
	}

	for (int i = 1; i <= N; i++)
		sort(A[i].begin(), A[i].end());

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			BFS(i);
			count++;
		}
	}

	cout << count << "\n";
}