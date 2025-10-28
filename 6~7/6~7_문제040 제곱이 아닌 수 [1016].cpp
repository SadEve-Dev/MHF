#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long MIN, MAX;
	cin >> MIN >> MAX;

	vector<bool> isPow(MAX - MIN + 1, false);

	for (long i = 2; i <= sqrt(MAX); i++) {
		long pow = i * i;
		long start_num = (MIN + pow - 1) / pow;

		for (long j = start_num * pow; j <= MAX; j += pow) {
			long index = j - MIN;
			if (!isPow[index])
				isPow[index] = true;
		}
	}

	int count = 0;
	for (long i = 0; i < MAX - MIN + 1; i++)
		if (!isPow[i])
			count++;

	cout << count << "\n";
}