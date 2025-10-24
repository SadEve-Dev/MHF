#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, score = 0, max = 0, total = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> score;
		total += score;
		if (score > max)
			max = score;
	}

	cout << (double)(total * 100.0 / max / N) << endl;
	return 0;
}