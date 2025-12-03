#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> D;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	D.resize(N + M + 1, vector<int>(N + M + 1));
	for (int i = 0; i <= N + M; i++)
		for (int j = 0; j <= i; j++)
			if (j == 0 || j == i)
				D[i][j] = 1;
			else {
				D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
				if (D[i][j] > 1000000000)
					D[i][j] = 1000000001;
			}

	if (D[N + M][M] < K)
		cout << "-1\n";
	else
		while (N > 0 || M > 0)
			if (D[N - 1 + M][M] >= K) {
				cout << "a";
				N--;
			}
			else {
				cout << "z";
				K -= D[N - 1 + M][M];
				M--;
			}
}