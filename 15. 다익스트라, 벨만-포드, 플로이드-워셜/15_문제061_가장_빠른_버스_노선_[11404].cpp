#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int N, M; // N: 도시 수, M: 버스 수

vector<vector<long>> D;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	// 거리 배열 초기화
	D.resize(N + 1, vector<long>(N + 1, INT_MAX));
	for (int i = 1; i <= N; i++) D[i][i] = 0;

	// 입력
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		D[s][e] = min(D[s][e], (long)v);
	}

	// 플로이드 워셜
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	// 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (D[i][j] == INT_MAX) cout << "0 ";
			else cout << D[i][j] << " ";
		cout << "\n";
	}
}