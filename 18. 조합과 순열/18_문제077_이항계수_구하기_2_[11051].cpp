#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> D;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	D.resize(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		D[i][1] = i;
		D[i][0] = 1;
		D[i][i] = 1;
	}

	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j]) % 10007;

	cout << D[N][K];
}