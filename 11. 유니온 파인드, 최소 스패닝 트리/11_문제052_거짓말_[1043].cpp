#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
vector<int> par;
vector<int> trueP;
vector<vector<int>> party;

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

	cin >> N >> M >> T;

	// 진실을 아는 사람들 입력
	trueP.resize(T);
	for (int i = 0; i < T; i++)
		cin >> trueP[i];

	// 파티 입력 : 0-based
	party.resize(M);
	for (int i = 0; i < M; i++) {
		int size;
		cin >> size;
		for (int j = 0; j < size; j++) {
			int x;
			cin >> x;
			party[i].push_back(x);
		}
	}

	// union-find 부모 초기화
	par.resize(N + 1);
	for (int i = 0; i <= N; i++) par[i] = i;

	// 파티 그룹화
	for (int i = 0; i < M; i++)
		for (int j = 1; j < party[i].size(); j++)
			_union(party[i][0], party[i][j]);

	int res = M;
	for (int i = 0; i < M; i++) {
		int root = find(party[i][0]);
		for (int j = 0; j < T; j++)
			if (root == find(trueP[j])) {
				res--;
				break;
			}
	}
	cout << res;
}