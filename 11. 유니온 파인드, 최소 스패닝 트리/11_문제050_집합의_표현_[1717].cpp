#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;

int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

bool checkSame(int a, int b) {
	return find(a) == find(b);
}

void _union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
		parent[b] = a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	for (int i = 1; i <= M; i++) {
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode)
			cout << (checkSame(a, b) ? "YES" : "NO") << "\n";
		else
			_union(a, b);
	}
}
