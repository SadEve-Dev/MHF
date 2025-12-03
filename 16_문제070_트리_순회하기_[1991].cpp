#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> tree;

void VLR(int node);
void LVR(int node);
void LRV(int node);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	tree.resize(N, vector<int> (2));

	for (int i = 0; i < N; i++) {
		char V, L, R;
		cin >> V >> L >> R;
		int node = V - 'A';
		tree[node][0] = (L != '.' ? L - 'A' : -1);
		tree[node][1] = (R != '.' ? R - 'A' : -1);
	}

	VLR(0);
	cout << "\n";
	LVR(0);
	cout << "\n";
	LRV(0);

}

void VLR(int node) {
	if (node == -1)
		return;
	cout << (char)(node + 'A');
	VLR(tree[node][0]);
	VLR(tree[node][1]);
}

void LVR(int node) {
	if (node == -1) return;
	LVR(tree[node][0]);
	cout << (char)(node + 'A');
	LVR(tree[node][1]);

}

void LRV(int node) {
	if (node == -1) return;
	LRV(tree[node][0]);
	LRV(tree[node][1]);
	cout << (char)(node + 'A');
}