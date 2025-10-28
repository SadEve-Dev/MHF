#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> res;
vector<bool> vis;
vector<vector<int>> tree;

void DFS(int n) {
	vis[n] = true;
	for (int i : tree[n])
		if (!vis[i]) {
			res[i] = n;
			DFS(i);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vis.resize(N + 1);
	tree.resize(N + 1);
	res.resize(N + 1);

	for (int i = 1; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n2);
	}

	DFS(1);
	for (int i = 2; i <= N; i++)
		cout << res[i] << "\n";
}