#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct t {
	int start, end;
	bool operator<(const t o) const {
		if (end != o.end)
			return end < o.end;
		return start < o.start;
	}
};

int N;
vector<t> A;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].start;
		cin >> A[i].end;
	}

	sort(A.begin(), A.end());

	int res = 0, end = -1;
	for (int i = 0; i < N; i++)
		if (A[i].start >= end) {
			end = A[i].end;
			res++;
		}
	
	cout << res;
}
