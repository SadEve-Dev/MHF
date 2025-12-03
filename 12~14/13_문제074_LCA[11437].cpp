#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> vis;

void BFS(int node) {
	queue<int> Q;
	Q.push(node);
	vis[node] = true;
	int level = 1, now_size = 1, cnt = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int next : tree[now])
			if (!vis[next]) {
				Q.push(next);
				vis[next] = true;
				parent[next] = now;
				depth[next] = level;
			}
		cnt++;
		if (cnt == now_size) {
			cnt = 0;
			now_size = Q.size();
			level++;
		}
	}
}

int excuteLCA(int a, int b) {

	if (depth[a] < depth[b]) {
		a += b;
		b = a - b;
		a -= b;
	}

	while (depth[a] != depth[b])
		a = parent[a];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	tree.resize(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1);
	vis.resize(N + 1, false);
	
	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	BFS(1);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = excuteLCA(a, b);
		cout << LCA << "\n";
	}
}