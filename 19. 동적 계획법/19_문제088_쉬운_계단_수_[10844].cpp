#include <iostream>
#include <vector>

using namespace std;

int N; // 계단 수의 길이
const int MOD = 1000000000;
vector<vector<int>> D; // DP 테이블: D[i][j]는 길이가 i이고 끝자리가 j인 계단 수의 개수

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	D.resize(N + 1, vector<int>(10, 0));

	// 길이가 1인 경우 초기화 (Base Case)
	// 길이가 1인 계단 수는 1, 2, ..., 9 이므로 9개. (0으로 시작하는 수는 제외)
	for (int i = 1; i < 10; i++) D[1][i] = 1;

	// 길이가 2부터 N까지 DP 테이블 채우기
	for (int i = 2; i <= N; i++) {
		// 끝자리가 0인 경우: 앞자리는 반드시 1이어야 함 (0의 이웃은 1뿐)
		D[i][0] = D[i - 1][1] % MOD;

		// 끝자리가 9인 경우: 앞자리는 반드시 8이어야 함 (9의 이웃은 8뿐)
		D[i][9] = D[i - 1][8] % MOD;

		// 끝자리가 1부터 8인 경우: 앞자리는 j-1 또는 j+1일 수 있음
		for (int j = 1; j <= 8; j++)
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % MOD;
	}

	int res = 0;
	for (int j = 0; j <= 9; j++)
		res = (res + D[N][j]) % MOD;

	cout << res;
}