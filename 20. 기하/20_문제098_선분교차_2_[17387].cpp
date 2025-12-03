#include <iostream>
#include <vector>

using namespace std;

struct pos { long x, y; };
struct lines {
	pos start;
	pos end;
};

vector<lines> L(2);

bool isCross(pos a, pos b, pos c, pos d);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 2; i++)
		cin
		>> L[i].start.x >> L[i].start.y
		>> L[i].end.x >> L[i].end.y;

	cout << (isCross(L[0].start, L[0].end, L[1].start, L[1].end) ? "1" : "0");
}

int ccw(pos p1, pos p2, pos p3) {
	long res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

bool isOverlap(pos p1, pos p2, pos p3, pos p4) {
	if (min(p1.x, p2.x) <= max(p3.x, p4.x) && min(p3.x, p4.x) <= max(p1.x, p2.x)
		&& min(p1.y, p2.y) <= max(p3.y, p4.y) && min(p3.y, p4.y) <= max(p1.y, p2.y))
		return true;
	return false;
}

bool isCross(pos a, pos b, pos c, pos d) {
	int abc = ccw(a, b, c),
		abd = ccw(a, b, d),
		cda = ccw(c, d, a),
		cdb = ccw(c, d, b);

	if (abc * abd == 0 && cda * cdb == 0)
		return isOverlap(a, b, c, d);
	else if (abc * abd <= 0 && cda * cdb <= 0)
		return true;
	else
		return false;
}