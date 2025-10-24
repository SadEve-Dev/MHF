#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<char> result;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	stack<int> S;
	int num = 1; // 1부터 push 시작

	for (int i = 0; i < N; i++) {	
		// A[i]는 이번에 뽑아야 할(만들어야 할) 숫자

		// 1. A[i]까지 오름차순으로 스택에 push
		// (num이 A[i]보다 작거나 같으면 A[i]가 될 때까지 push)
		while (num <= A[i]) {
			S.push(num++);
			result.push_back('+');
		}

		// 2. A[i]를 스택에서 pop
		// (while이 끝난 시점에 스택의 top은 반드시 A[i]여야 함)
		if (S.top() == A[i]) {
			S.pop();
			result.push_back('-');
		}
		else {
			// 만약 top이 A[i]가 아니라면(A[i]보다 큰 수라면)
			// 이 수열은 만들 수 없음
			cout << "NO\n";
			return 0;
		}
	}

	// 3. 결과 출력
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
}
