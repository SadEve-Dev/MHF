#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N; // 수열의 크기 N 입력

	vector<int> A(N); // N개의 원소를 가질 수열 A
	for (int i = 0; i < N; i++)
		cin >> A[i]; // 수열의 원소 입력

	vector<int> res(N); // 오큰수(NGE) 결과를 저장할 벡터
	stack<int> S;      // 아직 오큰수를 찾지 못한 원소의 *인덱스*를 저장할 스택

	S.push(0); // 첫 번째 원소(인덱스 0)를 스택에 PUSH

	// 두 번째 원소(인덱스 1)부터 마지막 원소까지 순회
	for (int i = 1; i < N; i++) {
		// 스택이 비어있지 않고, 현재 원소(A[i])가 
		// 스택의 top 인덱스가 가리키는 원소(A[S.top()])보다 클 동안 반복
		while (!S.empty() && A[i] > A[S.top()]) {
			// 스택 top 인덱스에 해당하는 원소의 오큰수는 현재 원소(A[i])
			res[S.top()] = A[i];
			S.pop(); // 오큰수를 찾았으므로 스택에서 제거
		}
		// 현재 원소(A[i])의 오큰수를 찾기 위해 인덱스 i를 스택에 PUSH
		S.push(i);
	}

	// 모든 원소를 순회한 후에도 스택에 남아있는 인덱스들
	while (!S.empty()) {
		// 스택에 남은 인덱스들은 오른쪽에 더 큰 수가 없는 경우
		res[S.top()] = -1; // 오큰수가 없으므로 -1
		S.pop();
	}

	// 결과 벡터(res)의 모든 원소 출력
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}