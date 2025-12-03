#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

struct pos { int x, y; };
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
vector<vector<int>> map;
vector<vector<bool>> vis;
vector<int> par;
vector<vector<pos>> islands;
int island_id = 1;

struct edge {
	int s, e, v;
	bool operator> (const edge o) const {
		return v > o.v;
	}
};

priority_queue<edge, vector<edge>, greater<edge>> pq;

vector<pos> BFS(int i, int j) {
	// 자료 구조 
	queue<pos> q;
	vector<pos> island;

	// 1. 시작점
	q.push({ i, j });
	vis[i][j] = true;
	map[i][j] = island_id;
	island.push_back({ i, j });

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		// 4방향 탐색
		for (int d = 0; d < 4; d++) {
			pos next = { now.x + dx[d], now.y + dy[d] };
			// 다음 좌표가 맵 밖이면 continue
			if (next.x < 0 || next.y < 0 || next.x >= N || next.y >= M) continue;
			// 바다가 아니고 방문하지 않았다면
			if (map[next.x][next.y] && !vis[next.x][next.y]) {
				map[next.x][next.y] = island_id;
				vis[next.x][next.y] = true;
				island.push_back({ next.x, next.y });
				q.push(next);
			}
		}
	}
	return island;
}

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b)
		par[b] = a;
}

void makeBridges() {
	for (const auto& island : islands) {
		for (const auto& now : island) {
			pos p = { now.x, now.y };
			int now_id = map[p.x][p.y];
			for (int d = 0; d < 4; d++) {
				int len = 0;
				pos next = { p.x + dx[d], p.y + dy[d] };
				while (next.x >= 0 && next.y >= 0 && next.x < N && next.y < M) {
					int next_id = map[next.x][next.y];
					if (next_id == now_id) break;
					if (next_id != 0) {
						if (len >= 2) pq.push({ now_id, next_id, len });
						break;
					}
					next.x += dx[d]; next.y += dy[d]; len++;
				}
			}
		}
	}
}

void kruskal() {
	// 부모 초기화
	par.resize(island_id);
	for (int i = 0; i < par.size(); i++)
		par[i] = i;

	int use = 0, res = 0;
	while(!pq.empty()) {
		edge now = pq.top();
		pq.pop();
		if (find(now.s) != find(now.e)) {
			unite(now.s, now.e);
			res += now.v;
			use++;
		}
	}

	// 마지막 id는 island_id - 1이므로 - 2로 계산
	cout << (use == island_id - 2 ? res : -1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	map.resize(N, vector<int>(M));
	vis.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// 섬 개수와 면적 측정 후 섬 목록에 넣음
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] && !vis[i][j]) {
				islands.push_back(BFS(i, j));
				island_id++;
			}

	// 다리 생성
	makeBridges();

	// MST 수행 및 결과 출력
	kruskal();
}