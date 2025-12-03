#include <iostream>
#include <vector>

using namespace std;

int N;

int TopDown(int n) {

}

int BottomUp(int n) {
	vector<int> F(N + 1, 0);
	F[1] = 1;
	for (int i = 2; i <= N; i++)
		F[i] = F[i - 1] + F[i - 2];
	return F[N];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	
	cout << BottomUp(N);
}