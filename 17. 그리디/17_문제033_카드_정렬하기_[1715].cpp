#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

/**
 * @brief 카드 묶음을 합치는 최소 비교 횟수를 계산한다.
 * 큐에 원소가 1개 남을 때까지 가장 작은 두 묶음을 합치고 비용을 누적한다.
 * @return 최소 비교 횟수
 */
int greedy() {
	int res = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		int sum = a + b;
		res += sum;
		pq.push(sum);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		pq.push(x);
	}

	cout << greedy();
}