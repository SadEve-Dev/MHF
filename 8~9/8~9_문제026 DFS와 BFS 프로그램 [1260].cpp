#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<bool> visited;

/**
 * @brief 깊이 우선 탐색 (DFS)
 * @param v 시작 노드
 */
void DFS(int v) {
	// 1. 방문 여부 체크 (이미 방문했다면 즉시 종료)
	if (visited[v])
		return;

	// 2. 방문 처리 및 출력
	visited[v] = true;

	cout << v << " ";

	// 3. 연결된 다음 노드 탐색
	for (int i : map[v])
		if (!visited[i]) // 아직 방문하지 않은 노드라면
			DFS(i); // 재귀 호출
}

/**
 * @brief 너비 우선 탐색 (BFS)
 * @param start 시작 노드
 */
void BFS(int start) {
	queue<int> q;

	// 1. 시작 노드를 큐에 넣고 방문 처리
	q.push(start);
	visited[start] = true;

	// 2. 큐가 빌 때까지 반복
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		cout << v << " ";

		// 3. 현재 노드와 연결된 다음 노드들 탐색
		for (int i : map[v])
			if (!visited[i]) { // 아직 방문하지 않은 노드라면
				q.push(i); // 큐에 추가
				visited[i] = true; // 큐에 넣을 때 방문 처리
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	map.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		map[start].push_back(end);
		map[end].push_back(start);
	}

	// 정점 번호가 작은 것을 먼저 방문하기 위해 인접 리스트 정렬
	for (int i = 1; i <= N; i++)
		sort(map[i].begin(), map[i].end());

	// V부터 DFS 수행
	DFS(V);

	cout << "\n";

	visited.assign(N + 1, false);

	BFS(V);

	return 0;
}