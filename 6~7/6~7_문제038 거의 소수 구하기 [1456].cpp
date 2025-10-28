#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long Min, Max;
	cin >> Min >> Max;

	// 1. Max <= 10^14이므로 10^7까지 소수 탐색을 위한 배열 선언
	vector<long> A(10000000 + 1);
	for (int i = 2; i <= 10000000; i++)
		A[i] = i;

	// 2. 10^7까지 에라토스테네스의 체를 수행
	for (int i = 2; (long)i * i <= 10000000; i++) {
		if (A[i] == 0)
			continue;
		for (int j = i + i; j <= 10000000; j += i)
			A[j] = 0;
	}

	int count = 0;
	// 3. 10^7까지의 소수만 확인
	for (int i = 2; i <= 10000000; i++)
		if (A[i] != 0) { // A[i]가 소수면
			long P = A[i];
			long temp = P; // temp는 P^1, P^2, P^3... 가 될 변수

			// 4. P^N 꼴을 세는 올바른 로직
			// (temp * P)가 Max를 넘는지 확인 (오버플로 방지)
			// P 자체가 int(i)에서 왔으므로 P <= Max / temp 로 비교
			while (P <= Max / temp) {
				temp *= P; // P^2, P^3, P^4 ...
				if (temp >= Min) // Min보다 크거나 같으면 카운트
					count++;
			}
		}


	cout << count << "\n";
}