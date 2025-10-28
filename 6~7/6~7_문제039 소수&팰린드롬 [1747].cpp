#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, MAX = 10000000;
	cin >> N;

	vector<long> prime(MAX + 1, 0);
	for (int i = 2; i <= MAX; i++)
		prime[i] = i;

	// 소수 거르기
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i] == 0)
			continue;
		for (int j = i + i; j <= MAX; j += i)
			prime[j] = 0;
	}

	// 팰린드롬 수 찾기
	int res;
	for (int i = N; i <= MAX; i++) {
		if (prime[i] == 0)
			continue;

		string s = to_string(prime[i]);
		bool chk = true;

		for (int j = 0; j < s.size() / 2; j++)
			if (s[j] != s[s.size() - j - 1]) {
				chk = false;
				break;
			}

		if (chk) {
			res = i;
			break;
		}
	}

	cout << res << "\n";
}