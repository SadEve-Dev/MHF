	#include <iostream>
	#include <vector>
	#include <queue>
	#include <algorithm>
	#include <utility>

	using namespace std;

	vector<vector<int>> A;
	vector<bool> visited;
	vector<int> res;

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
					res[i]++;
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
		for (int i = 0; i < M; i++) {
			int start, end;
			cin >> start >> end;
			A[start].push_back(end);
		}

		for (int i = 1; i <= N; i++)
			sort(A[i].begin(), A[i].end());
	
		res.resize(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			visited.assign(N + 1, false);
			BFS(i);
		}
	
		int max = *max_element(res.begin(), res.end());
		for (int i = 1; i < res.size(); i++)
			if (res[i] == max)
				cout << i << " ";
		
	}