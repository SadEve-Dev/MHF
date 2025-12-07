#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> Neg;
priority_queue<int> Pos;
int one = 0, zero = 0;

/**
 * @brief priority_queue의 top 원소를 가져오고 pop 하는 함수
 * @param pq 비교자만 다른 int 타입 priority_queue
 * @return 큐의 가장 우선순위가 높은(top) 원소의 값
 */
template<typename Comp>
int getTop(priority_queue<int, vector<int>, Comp>& pq) {
	int res = pq.top(); pq.pop();
	return res;
}

int greedy() {
	int res = 0;
	// 양수 PQ 계산
	while (Pos.size() > 1)
		res += getTop(Pos) * getTop(Pos);
	if (!Pos.empty()) // 하나 남으면 더하기
		res += getTop(Pos);
	
	// 음수 PQ 계산 (음수끼리 곱하여 양수로 만듦)
	while (Neg.size() > 1) 
		res += getTop(Neg) * getTop(Neg);
	if (!Neg.empty() && zero == 0) // 음수 하나 남고 0이 없음 더함
		res += getTop(Neg);

	res += one; // 1들 더하기 처리

	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x > 1) Pos.push(x);
		else if (x < 0) Neg.push(x);
		else if (x == 1) one++;
		else if (x == 0) zero++;
	}

	cout << greedy();
}