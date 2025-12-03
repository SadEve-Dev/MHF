#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

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

void _union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
		par[b] = a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == '\n')
				cin >> c;

			// 문자 -> 가중치 변환
			int v = 0;
			if (c >= 'a' && c <= 'z')
				v = c - 'a' + 1;
			if (c >= 'A' && c <= 'Z')
				v = c - 'A' + 27;

			sum += v;
			if (i != j && v != 0)
				pq.push({ i, j, v });
		}
	}

	// 부모 초기화
	par.resize(N + 1);
	for (int i = 0; i <= N; i++)
		par[i] = i;

	int res = 0, use = 0; // res = MST 가중치, use = MST의 간선 수
	while (!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e)) {
			_union(now.s, now.e);
			res += now.v;
			use++;
		}
	}

	// MST면 "전체 가중치 합 - MST 가중치" 아니면 -1
	cout << (use == N - 1 ? sum - res : -1);
}