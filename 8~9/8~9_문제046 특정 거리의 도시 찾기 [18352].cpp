#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> A;
vector<int> visit; // 거리(distance) 저장용

void BFS(int index) {
	queue<int> q;
	q.push(index);
	visit[index] = 0; // 시작점 거리는 0

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i : A[now])
			if (visit[i] == -1) { // 미방문 노드(-1)일 경우
				q.push(i);
				visit[i] = visit[now] + 1; // 거리 1 증가
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;
	
	A.resize(N + 1);
	visit.resize(N + 1, -1); // -1 (미방문 상태)로 초기화
	
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		A[start].push_back(end);
	}

	BFS(X);
	vector<int> res;
	for (int i = 1; i <= N; i++)
		if (visit[i] == K) // 거리가 K인 도시를 res에 추가
			res.push_back(i);

	if (res.empty()) // 거리가 K인 도시가 없으면
		cout << -1 << "\n";
	else { // 있으면
		sort(res.begin(), res.end());
		for (int i : res)
			cout << i << "\n";
	}
}