#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
vector<vector<int>> D;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	D.resize(31, vector<int>(31));
	for (int i = 0; i < 31; i++) {
		D[i][1] = i;
		D[i][0] = 1;
		D[i][i] = 1;
	}

	for (int i = 2; i < 31; i++)
		for (int j = 1; j < 31; j++)
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j];

	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << D[M][N] << "\n";
	}
}