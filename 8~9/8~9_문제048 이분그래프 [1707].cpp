	#include <iostream>
	#include <vector>

	using namespace std;

	vector<vector<int>> A;
	vector<bool> visited;
	vector<int> check;
	bool isEven;

	void DFS(int index) {
		visited[index] = true;
		for (int i : A[index])
			if (!visited[i]) {
				check[i] = (check[index] + 1) % 2;
				DFS(i);
			}
			else if (check[index] == check[i])
				isEven = false;
	}

	int main() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int K, V, E;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> V >> E;

			A.assign(V + 1, vector<int>());
			visited.assign(V + 1, false);
			check.assign(V + 1, 0);
		
			for (int j = 0; j < E; j++) {
				int start, end;
				cin >> start >> end;
				A[start].push_back(end);
				A[end].push_back(start);
			}

			isEven = true;
			for (int j = 1; j <= V; j++)
				if (isEven)
					DFS(j);
				else
					break;

			cout << (isEven ? "YES" : "NO") << "\n";
		}
	}