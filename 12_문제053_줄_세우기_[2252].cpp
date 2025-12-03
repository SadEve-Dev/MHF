#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> link;
vector<int> indegree;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	// 1. 초기화
	link.resize(N + 1);
	indegree.resize(N + 1);

	// 간선 입력
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		link[s].push_back(e);
		indegree[e]++;
	}

	// 위상 정렬 큐 초기화
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0) q.push(i);

	// 위상 정렬
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int next : link[now]) {
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}