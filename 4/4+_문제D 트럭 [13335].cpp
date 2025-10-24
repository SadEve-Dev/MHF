#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, w, L;
queue<int> truck;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w >> L;

	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		truck.push(weight);
	}

	vector<int> bridge(w, 0);
	int res = 0;
	int current_weight = 0; // 현재 다리 위 무게

	while (true) {
		res++; // 1. 시간 경과

		// 2. 다리 끝 트럭 하차
		current_weight -= bridge[w - 1];

		// 3. 다리 위 트럭 이동
		for (int i = w - 1; i > 0; i--)
			bridge[i] = bridge[i - 1];
		bridge[0] = 0;

		// 4. 새 트럭 진입
		if (!truck.empty())
			if (current_weight + truck.front() <= L) {
				bridge[0] = truck.front();
				current_weight += truck.front();
				truck.pop();
			}

		// 5. 종료 조건
		if (truck.empty() && current_weight == 0)
			break;
	}

	cout << res << "\n";

	return 0;
}