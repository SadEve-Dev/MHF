	#include <iostream>
	#include <vector>

	using namespace std;

	int N;
	vector<vector<long>> D;

	int main() {
		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

		cin >> N;

		D.resize(N + 1, vector<long>(2));

		D[1][1] = 1;
		D[1][0] = 0;

		for (int i = 2; i <= N; i++) {
			D[i][0] = D[i - 1][0] + D[i - 1][1];
			D[i][1] = D[i - 1][0];
		}

		cout << D[N][0] + D[N][1];
	}