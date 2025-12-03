#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm> // swap 사용을 위해 추가
using namespace std;

int N, M;
int kmax;
vector<vector<int>> tree;
vector<int> D;
int P[21][100001]; // 전역 배열
vector<bool> V;

// 깊이와 2^0 부모를 설정
void BFS(int node) {
	queue<int> Q;
	Q.push(node);
	V[node] = true;
	D[node] = 0; // 루트 깊이 0

	while (!Q.empty()) {
		int now = Q.front(); Q.pop();
		for (int next : tree[now])
			if (!V[next]) {
				Q.push(next);
				V[next] = true;
				P[0][next] = now;
				D[next] = D[now] + 1; // 부모 깊이 + 1
			}
	}
}

// 최소 공통 조상 찾기
int excuteLCA(int a, int b) {
	// a의 깊이가 더 깊으면 swap
	if (D[a] > D[b]) swap(a, b);

	// 1. 깊이 맞추기 (b를 a와 같은 깊이로 끌어올림)
	for (int k = kmax; k >= 0; k--)
		if ((D[b] - D[a]) >= (1 << k))
			b = P[k][b];

	if (a == b) return a;

	// 2. 동시에 부모를 찾아 올라가기
	for (int k = kmax; k >= 0; k--)
		if (P[k][a] != P[k][b]) {
			a = P[k][a];
			b = P[k][b];
		}

	// 최종 LCA는 현재 노드들의 바로 위 부모
	return P[0][a];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	tree.resize(N + 1);
	D.resize(N + 1);
	// P 배열은 전역 선언되어 있어 resize 불필요
	V.resize(N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	int tmp = 1;
	kmax = 0;
	while (tmp <= N) {
		tmp <<= 1;
		kmax++;
	}

	BFS(1);

	// P[k][n] 값 계산 (Binary Lifting)
	for (int k = 1; k <= kmax; k++)
		for (int n = 1; n <= N; n++)
			P[k][n] = P[k - 1][P[k - 1][n]];

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int LCA = excuteLCA(a, b);
		cout << LCA << "\n";
	}
}