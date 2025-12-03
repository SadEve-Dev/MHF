#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;

vector<vector<int>> builds; // 건물 인접 리스트
vector<int> t; // 건축 소요 시간
vector<int> ind; // 진입 차수
vector<int> res;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;

	// 초기화
	builds.resize(N + 1);
	t.resize(N + 1, 0);
	ind.resize(N + 1, 0);
	res.resize(N + 1, 0);

	// 건축 정보 입력
	for (int i = 1; i <= N; i++) {
		cin >> t[i];
		while (true) {
			int x;
			cin >> x;
			if (x == -1)
				break;
			builds[x].push_back(i);
			ind[i]++;
		}
	}

	// 큐 초기화
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!ind[i]) q.push(i);
	
	// 위상 정렬
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : builds[now]) {
			ind[next]--;
			res[next] = max(res[next], res[now] + t[now]);
			if (ind[next] == 0) q.push(next);
		}
	}

	// 결과 출력
	for (int i = 1; i <= N; i++)
		cout << res[i] + t[i] << "\n";
}