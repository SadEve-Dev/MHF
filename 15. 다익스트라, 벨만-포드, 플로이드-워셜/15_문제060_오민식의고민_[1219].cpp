#include <iostream>
#include <climits>
#include <vector>
#include <tuple>

using namespace std;
using edge = tuple<int, int, int>;

int N, M, s, e;
vector<long> dist, cityMoney;
vector<edge> edges;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> s >> e >> M;

	dist.resize(N, LONG_MIN);
	cityMoney.resize(N);

	for (int i = 0; i < M; i++) {
		int start, end, price;
		cin >> start >> end >> price;
		edges.push_back({ start, end, price });
	}

	for (int i = 0; i < N; i++)
		cin >> cityMoney[i];

	dist[s] = cityMoney[s]; // 변형된 벨만포드 알고리즘 수행
	for (int i = 0; i <= N + 100; i++)
		for (int j = 0; j < M; j++) {
			int start = get<0>(edges[j]),
				end = get<1>(edges[j]),
				price = get<2>(edges[j]);

			if (dist[start] == LONG_MIN)
				continue;
			else if (dist[start] == LONG_MAX)
				dist[end] = LONG_MAX;
			else if (dist[end] < dist[start] + cityMoney[end] - price) {
				dist[end] = dist[start] + cityMoney[end] - price;
				if (i >= N - 1)
					dist[end] = LONG_MAX;
			}
		}

	if (dist[e] == LONG_MIN)
		cout << "gg";
	else if (dist[e] == LONG_MAX)
		cout << "Gee";
	else
		cout << dist[e];
}