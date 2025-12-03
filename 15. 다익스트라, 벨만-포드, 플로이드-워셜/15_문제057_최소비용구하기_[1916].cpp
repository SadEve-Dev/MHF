#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct edge {
	int v;
	int w;
	bool operator> (const edge& o) const {
		return w > o.w;
	}
};

// V: 정점 개수 E: 간선 개수 K: 시작점 번호
int N, M;
vector<int> dist; // 최단 거리
vector<bool> vis; // 방문 여부
vector<vector<edge>> adj; // 인접리스트


int Dijkstra(int start, int end) {
	priority_queue<edge, vector<edge>, greater<edge>> pq; // 우선순위 큐
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		
		if (now.w > dist[now.v])
			continue;

		if (!vis[now.v]) {
			vis[now.v] = true;
			for (edge n : adj[now.v]) { // 선택노드 + 비용 < 타켓노드인 경우 값을 갱신하는 부분
				if (dist[n.v] > dist[now.v] + n.w) {
					dist[n.v] = dist[now.v] + n.w;
					pq.push({ n.v, dist[n.v] });
				}
			}
		}
	}
	return dist[end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	dist.resize(N + 1, INT_MAX);
	adj.resize(N + 1);
	vis.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	int start, end;
	cin >> start >> end;
	cout << Dijkstra(start, end);
}