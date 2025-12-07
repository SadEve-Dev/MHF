#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct edge { int s, e, v; };

int N, M;
vector<edge> E;
vector<long> D;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	D.resize(N + 1, LONG_MAX);

	for (int i = 0; i < M; i++) {
		edge e;
		cin >> e.s >> e.e >> e.v;
		E.push_back(e);
	}

	// 벨만-포드: N-1번 모든 간선을 확인하여 최단 거리 갱신
	D[1] = 0;
	for (int i = 1; i < N; i++)
		for (int j = 0; j < E.size(); j++) {
			edge now = E[j];
			if (D[now.s] != LONG_MAX && D[now.e] > D[now.s] + now.v)
				D[now.e] = D[now.s] + now.v;
		}

	// N번째 반복에서도 값이 갱신된다면 음수 사이클이 존재함
	bool isCycle = false;
	for (int i = 0; i < E.size(); i++) {
		edge now = E[i];
		if (D[now.s] != LONG_MAX && D[now.e] > D[now.s] + now.v) {
			isCycle = true;
			break;
		}
	}

	if (isCycle) cout << "-1\n";
	else
		for (int i = 2; i <= N; i++)
			if (D[i] == LONG_MAX) cout << "-1\n";
			else cout << D[i] << "\n";
}