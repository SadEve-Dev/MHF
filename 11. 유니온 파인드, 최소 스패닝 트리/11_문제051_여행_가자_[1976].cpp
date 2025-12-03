#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;

int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void _union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	parent.resize(N + 1);
	for (int i = 1; i <= N; i++) parent[i] = i;

	// 배열 저장 없이 입력값 1이면 바로 union 계산
	int link;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> link;
			if (link) _union(i, j);
		}

	// 배열 저장 없이 바로 비교
	int start, next;
	cin >> start;
	int root = find(start);

	for (int i = 1; i < M; i++) {
		cin >> next;
		if (root != find(next)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}