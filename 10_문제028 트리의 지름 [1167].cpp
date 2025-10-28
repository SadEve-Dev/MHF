#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using edge = pair<int, int>;
int V;

vector<bool> vis;
vector<int> dist;
vector<vector<edge>> tree;

void BFS(int index) {
	queue<int> Q;
	Q.push(index);
	vis[index] = true;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (edge next : tree[now])
			if (!vis[next.first]) {
				vis[next.first] = true;
				dist[next.first] = dist[now] + next.second;
				Q.push(next.first);
			}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V;

	tree.resize(V + 1);
	dist.resize(V + 1, 0);
	vis.resize(V + 1, false);

	for (int i = 0; i < V; i++) {
		int S;
		cin >> S;
		while (true) {
			int N, D;
			cin >> N;
			if (N == -1)
				break;
			cin >> D;
			tree[S].push_back(edge{ N, D });
		}
	}

	BFS(1);

	int Max = 1;
	for (int i = 2; i <= V; i++)
		if (dist[Max] <= dist[i])
			Max = i;

	dist.assign(V + 1, 0);
	vis.assign(V + 1, false);

	BFS(Max);

	sort(dist.begin(), dist.end());
	cout << dist[V] << "\n";
}