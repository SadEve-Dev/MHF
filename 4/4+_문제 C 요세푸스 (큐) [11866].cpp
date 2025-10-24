#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
				q.push(q.front());
				q.pop();
		}
		cout << q.front() << (q.size() != 1 ? ", " : ">\n");
		q.pop();
	}
}