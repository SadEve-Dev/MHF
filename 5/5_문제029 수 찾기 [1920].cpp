#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> M;
	sort(A.begin(), A.end());
	for (int i = 0; i < M; i++) {
		bool find = false;
		int target;
		cin >> target;
		int start = 0, end = A.size() - 1;
		while (start <= end) {
			int mid = (start + end) / 2, key = A[mid];
			if (key > target)
				end = mid - 1;
			else if (key < target)
				start = mid + 1;
			else {
				find = true;
				break;
			}
		}
		cout << (find ? "1" : "0") << "\n";
	}

}