#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // swap
using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> vis;

/**
 * @brief BFS를 사용하여 각 노드의 깊이(depth)와 부모(parent)를 기록
 * @param node 루트 노드 번호
 */
void bfs(int node) {
    queue<int> Q;
    Q.push(node);
    vis[node] = true;
    depth[node] = 0;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int next : tree[now])
            if (!vis[next]) {
                vis[next] = true;
                parent[next] = now;
                depth[next] = depth[now] + 1;
                Q.push(next);
            }
    }
}

/**
 * @brief 두 노드의 최소 공통 조상(LCA)을 찾는 함수 (O(N))
 * @param a 첫 번째 노드
 * @param b 두 번째 노드
 * @return LCA 노드 번호
 */
int lca(int a, int b) {
    // 항상 a의 깊이가 더 깊거나 같도록 설정
    if (depth[a] < depth[b]) swap(a, b);

    // 1. 깊이가 같아질 때까지 a를 올림
    while (depth[a] != depth[b])
        a = parent[a];

    // 2. 두 노드가 같아질 때까지 함께 올림
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    tree.resize(N + 1);
    depth.resize(N + 1);
    parent.resize(N + 1);
    vis.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    bfs(1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
