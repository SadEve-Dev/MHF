#include <iostream>
#include <vector>

using namespace std;

int T, N, K;
vector<vector<int>> D;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	D.resize(15, vector<int>(15));
	for (int i = 0; i < 15; i++) {
		D[i][1] = 1;
		D[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
		for (int j = 2; j < 15; j++)
			D[i][j] = D[i][j - 1] + D[i - 1][j];

	cin >> T;
	while (T--) {
		cin >> K >> N;
		cout << D[K][N] << "\n";
	}
}