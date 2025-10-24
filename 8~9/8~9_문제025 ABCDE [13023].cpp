#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<bool> visited;
bool arrive = false;

void DFS(int index, int depth) {
	if (depth >= 5 || arrive) {
		arrive = true;
		return;
	}
	visited[index] = true;
	for (int i : A[index])
		if (!visited[i])
			DFS(i, depth + 1);
	visited[index] = false;
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

	for (int i = 1; i <= N; i++) {
		DFS(i, 1);
		if (arrive)
			break;
	}

	cout << (arrive ? "1" : "0") << "\n";
}	