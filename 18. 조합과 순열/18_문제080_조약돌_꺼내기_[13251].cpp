#include <iostream>
#include <vector>

using namespace std;

int M, K, N; // 조약돌 색깔 개수, 뽑는 횟수, 전체 조약돌 개수
vector<int> color; // 각 색깔별 조약돌 개수 저장

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> M;
	color.resize(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> color[i];
		N += color[i];
	}

	cin >> K;

	double res = 0;

	// 각 색깔별로 확률 계산
	for (int i = 0; i < M; i++) 
		if (color[i] >= K) {
			double prob = 1.0; // 확률 초기화
			for (int j = 0; j < K; j++)
				prob *= (double)(color[i] - j) / (N - j); // 남은 현재 색깔 돌 수 /	남은 전체 돌 수
			res += prob;
		}

	cout.precision(15);
	cout << res;
}