#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;
int N, M, K;
vector<long> tree;
int base = 1;

/**
 * @brief 구간 [s, e]의 곱을 모듈러 연산하여 반환한다.
 * @param s 시작 인덱스 (트리 배열 기준)
 * @param e 끝 인덱스 (트리 배열 기준)
 * @return long long 구간 곱 결과
 */
long getMulti(int s, int e) {
	long res = 1;
	while (s <= e) {
		if (s % 2 == 1) res = (res * tree[s++]) % MOD;
		if (e % 2 == 0) res = (res * tree[e--]) % MOD;
		s /= 2;
		e /= 2;
	}
	return res;
}

/**
 * @brief 특정 리프 노드의 값을 변경하고, 조상 노드들을 갱신한다.
 * @param i 변경할 리프 노드의 인덱스 (트리 배열 기준)
 * @param v 변경할 새로운 값
 */
void change(int i, int v) {
	tree[i] = v;
	while (i > 1) {
		i /= 2;
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
	}
}

/**
 * @brief 초기 트리 구성
 */
void setTree() {
	for (int i = base - 1; i > 0; i--)
			tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	
	// base 구하기: N보다 큰 2의 거듭제곱
	while (base < N) base *= 2;

	// 곱셈의 항등원 1로 초기화 (빈 공간이 0이면 곱셈 결과 망가짐)
	tree.resize(base * 2, 1);
	
	// 리프 노드 데이터 입력
	for (int i = 0; i < N; i++)
		cin >> tree[base + i];

	setTree();

	for (int i = 0; i < M + K; i++) {
		int mode, a, b;
		cin >> mode >> a >> b;

		a += base - 1; // 입력받은 순서 a를 트리 인덱스로 변환

		if (mode == 1) change(a, b);
		if (mode == 2) cout << getMulti(a, base + b - 1) << "\n";
	}
}