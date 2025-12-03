#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

struct edge { 
	int s, e, v;
	bool operator> (const edge& o) const {
		return v > o.v;
	}
};

priority_queue<edge, vector<edge>, greater<edge>> pq;
vector<int> par;

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

int _union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
		par[b] = a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	// 부모 초기화
	par.resize(N + 1);
	for (int i = 0; i <= N; i++)
		par[i] = i;
	
	// 간선 정보 입력
	for (int i = 0; i < M; i++) {
		edge E;
		cin >> E.s >> E.e >> E.v;
		pq.push(E);
	}

	// 최소 신장 트리의 가중치 계산
	int use = 0, res = 0;
	while (use < N - 1) {
		edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e)) {
			_union(now.s, now.e);
			res += now.v;
			use++;
		}
	}

	cout << res;
}