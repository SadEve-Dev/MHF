#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long> D;
const int mod = 1000000000;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	// 완전 순열 벡터 D 초기화
	D.resize(N + 1); D[1] = 0;  D[2] = 1;

	// 완전 순열 점화식 D_n = (n - 1) * (D_(n-1) + D_(n-2))
	for (int i = 3; i <= N; i++)
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % mod;

	cout << D[N];
}