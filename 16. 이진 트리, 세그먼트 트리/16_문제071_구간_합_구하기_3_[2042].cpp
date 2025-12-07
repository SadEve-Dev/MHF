#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<long> tree;
int base; // 리프 노드의 시작 인덱스

long getSum(int s, int e) {
	long total = 0;
	while (s <= e) {
		if (s % 2 == 1) total += tree[s++];
		if (e % 2 == 0) total += tree[e--];
		s /= 2;
		e /= 2;
	}
	return total;
}

void change(int i, long V) {
	for (long diff = V - tree[i]; i > 0; i /= 2)
		tree[i] += diff;
}

void setTree() {
	// base - 1부터 1까지 역순으로 채움
	for (int i = base - 1; i > 0; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	// 1. base(리프 시작점) 구하기: N보다 큰 가장 작은 2의 거듭제곱
	base = 1;
	while (base < N) base *= 2;

	// 2. 트리 사이즈: base * 2
	tree.resize(base * 2);

	// 3. 입력 (0번 인덱스부터 채우기)
	for (int i = 0; i < N; i++)
		cin >> tree[base + i];
	setTree();

	for (int i = 0; i < M + K; i++) {
		long mode, a, b;
		cin >> mode >> a >> b;
		// a는 1부터 시작하므로 base + a - 1
		a += base - 1;
		if (mode == 1)
			change(a, b);
		else if (mode == 2)
			cout << getSum(a, base + b - 1) << "\n";
	}
}