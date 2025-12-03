#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> A;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	A.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int cnt = 0;
	for (int i = N - 1; i >= 0; i--)
		if (A[i] <= K) {
			cnt += K / A[i];
			K %= A[i];
		}

	cout << cnt;
}	