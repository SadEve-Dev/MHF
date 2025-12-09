#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100001;
const int MAX_K = 17; // 2^17 > 100,000

int N, M;
vector<int> tree[MAX];
int D[MAX];
int P[MAX_K + 1][MAX];
bool V[MAX];

/**
 * @brief BFS를 통해 트리의 깊이(Depth)와 직계 부모(2^0)를 설정
 * @param node 시작 노드(루트)
 */
void bfs(int node) {
    queue<int> Q;
    Q.push(node);
    V[node] = true;
    D[node] = 0; // 루트 깊이 0

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int next : tree[now])
            if (!V[next]) {
                Q.push(next);
                V[next] = true;
                P[0][next] = now;
                D[next] = D[now] + 1; // 부모 깊이 + 1
            }
    }
}

/**
 * @brief 최소 공통 조상(LCA)을 찾는 함수
 * @param a 첫 번째 노드 번호
 * @param b 두 번째 노드 번호
 * @return 두 노드의 최소 공통 조상 노드 번호
 */
int lca(int a, int b) {
    // a의 깊이가 더 깊으면 swap
    if (D[a] > D[b]) swap(a, b);

    // 1. 깊이 맞추기 (b를 a와 같은 깊이로 끌어올림)
    for (int k = MAX_K; k >= 0; k--)
        if (D[b] - D[a] >= (1 << k))
            b = P[k][b];

    if (a == b) return a;

    // 2. 동시에 부모를 찾아 올라가기
    for (int k = MAX_K; k >= 0; k--)
        if (P[k][a] != P[k][b]) {
            a = P[k][a];
            b = P[k][b];
        }

    // 최종 LCA는 현재 노드들의 바로 위 부모
    return P[0][a];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    bfs(1);

    // P[k][n] 값 계산 (Binary Lifting)
    for (int k = 1; k <= MAX_K; k++)
        for (int n = 1; n <= N; n++)
            if (P[k - 1][n] != 0) // 부모가 존재할 때만 갱신
                P[k][n] = P[k - 1][P[k - 1][n]];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
