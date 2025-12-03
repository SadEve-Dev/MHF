#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

struct edge {
	int v;
	int w;
	bool operator> (const edge& o) const {
		return w > o.w;
	}
};

// V: 정점 개수 E: 간선 개수 K: 시작점 번호
int V, E, K;
vector<int> minD; // 최단 거리
vector<bool> vis; // 방문 여부
vector<vector<edge>> adj; // 인접리스트


void Dijkstra(int start) {
	priority_queue<edge, vector<edge>, greater<edge>> pq; // 우선순위 큐
	pq.push({ start, 0});
	minD[start] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();

		if (vis[now.v])
			continue;
		vis[now.v] = true;

		for (auto next : adj[now.v])
			if (minD[now.v] != INF && minD[next.v] > minD[now.v] + next.w) {
				minD[next.v] = minD[now.v] + next.w;
				pq.push({ next.v, minD[next.v] });
			}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;

	minD.resize(V + 1, INF);
	adj.resize(V + 1);
	vis.resize(V + 1, false);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	Dijkstra(K);

	for (int i = 1; i <= V; i++)
		if (minD[i] == INF)
			cout << "INF\n";
		else
			cout << minD[i] << "\n";
}
