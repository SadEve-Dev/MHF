#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int M, N;

vector<int> primes;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	primes.resize(N + 1, 0);
	for (int i = 2; i <= N; i++)
		primes[i] = i;

	for (int i = 2; i <= sqrt(N); i++) {
		if (primes[i] == 0)
			continue;
		for (int j = i + i; j <= N; j += i)
			primes[j] = 0;
	}

	for (int i = M; i <= N; i++)
		if (primes[i] != 0)
			cout << primes[i] << "\n";
}
