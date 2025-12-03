#include <iostream>
#include <vector>

using namespace std;

int N;

struct pos { long x, y; };
vector<pos> L;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	L.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> L[i].x >> L[i].y;

	// 마지막 점과 처음 점 연결 후 CCW 계산 포함
	L[N].x = L[0].x;
	L[N].y = L[0].y;

	double res = 0;
	for (int i = 0; i < N; i++)
		res += (L[i].x * L[i + 1].y) - (L[i + 1].x * L[i].y);

	// 소수점 1자리수로 출력
	cout << fixed;
	cout.precision(1);
	cout << abs(res) / 2.0;
}