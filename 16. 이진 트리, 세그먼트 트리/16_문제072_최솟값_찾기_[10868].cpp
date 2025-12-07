#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<long> tree;
int base = 1; // 리프 노드 시작 인덱스

/**
 * @brief 구간 [s, e]의 최소값을 반복문으로 구한다.
 * @param s 시작 인덱스 (트리 인덱스)
 * @param e 끝 인덱스 (트리 인덱스)
 * @return long 구간 최소값
 */
long getMin(int s, int e) {
	long res = LONG_MAX;
	while (s <= e) {
		if (s % 2 == 1) res = min(res, tree[s++]);
		if (e % 2 == 0) res = min(res, tree[e--]);
		s /= 2;
		e /= 2;
	}
	return res;
}

/**
 * @brief 트리의 internal 노드를 두 자손 노드의 최소값으로 초기화한다.
 */
void setTree() {
	for (int i = base - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	// base 구하기: N보다 큰 가장 작은 2의 거듭제곱
	while (base < N)
		base *= 2;
	tree.resize(base * 2);

	// 리프 노드 입력 (base + 0 부터 base + N - 1 까지)
	for (int i = 0; i < N; i++)
		cin >> tree[base + i];
	
	setTree();

	// 최솟값 찾기
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << getMin(base + s - 1, base + e - 1) << "\n";
	}
}