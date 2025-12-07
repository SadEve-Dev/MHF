#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long> F;

/**
 * @brief 피보나치 수열을 Top-Down (재귀 + 메모이제이션) 방식으로 계산한다.
 * @param n 현재 계산할 피보나치 항의 순서
 * @return n번째 피보나치 수 F[n]
 */
long TopDown(int n) {
	if (n <= 1) return 1;
	if (F[n] > 0) return F[n];
	F[n] = TopDown(n - 1) + TopDown(n - 2);
	return F[n];
}

/**
 * @brief 피보나치 수열을 Bottom-Up (반복문 + 동적 계획법) 방식으로 계산한다.
 */
void BottomUp() {
	F[1] = 1;
	for (int i = 2; i <= N; i++)
		F[i] = F[i - 1] + F[i - 2];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	F.resize(N + 1);
	BottomUp();
	cout << F[N];
}