#include <iostream>
#include <vector>

using namespace std;

int N;
const int mod = 10007;
vector<long> D;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	D.resize(N + 1);

	D[1] = 1;
	D[2] = 2;
	
	for (int i = 3; i <= N; i++)
		D[i] = (D[i - 1] + D[i - 2]) % mod;

	cout << D[N];
}