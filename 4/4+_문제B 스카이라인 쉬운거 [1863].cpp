#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res = 0;
	cin >> N;

	int x;
	vector<int> Y(N); // 수정: 벡터 크기 N으로 초기화
	for (int i = 0; i < N; i++)
		cin >> x >> Y[i];

	stack<int> stk;
	for (int i = 0; i < N; i++) {
		while (!stk.empty() && stk.top() > Y[i])
			stk.pop();

		// 수정: 논리 오류 및 런타임 에러 수정 (&& -> ||)
		if (Y[i] != 0 && (stk.empty() || stk.top() < Y[i])) {
			stk.push(Y[i]);
			res++;
		}
	}

	cout << res << endl;
}