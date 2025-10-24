#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res=0;
	cin >> N;

	stack<int> S;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0)
			S.pop();
		else
			S.push(num);
	}

	while (!S.empty()) {
		res += S.top();
		S.pop();
	}

	cout << res;

}