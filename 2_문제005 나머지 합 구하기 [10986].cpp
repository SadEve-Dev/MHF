#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	long result = 0; // int -> long 변경
	cin >> N >> M;

	vector<long> D(N + 1, 0);
	vector<long> C(M, 0);

	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		D[i] += D[i - 1];
	}

	// D[0] (값이 0)의 나머지는 0이므로 C[0]을 1 증가
	C[0]++;

	// D[1] ~ D[N]의 나머지를 각각 카운트
	for (int i = 1; i <= N; i++)
		C[D[i] % M]++;

	// C[i] (같은 나머지를 가진 누적합의 개수) 중에서 2개를 뽑는 조합의 합
	for (int i = 0; i < M; i++)
		if (C[i] > 1)
			result += (C[i] * (C[i] - 1) / 2);

	cout << result << endl;
}