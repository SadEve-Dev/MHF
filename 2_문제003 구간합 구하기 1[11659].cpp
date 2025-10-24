#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0, a[100001] = {};

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	for (int i = 0; i < M; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		cout << a[end] - a[--start] << "\n";
	}

	return 0;
}