#include <iostream>
#include <vector>

using namespace std;

struct pos {	int x, y;	};

vector<pos> p(3);
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; i++)
		cin >> p[i].x >> p[i].y;
	
	// (x1y2 + x2y3 + x3y3) - (x2y1 + x3y2 + x1y3)
	int cross = (p[0].x * p[1].y + p[1].x * p[2].y + p[2].x * p[0].y)
		- (p[1].x * p[0].y + p[2].x * p[1].y + p[0].x * p[2].y);

	int res = cross > 0 ? 1 : cross < 0 ? -1 : 0;

	cout << res;
}