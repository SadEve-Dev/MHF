#include <iostream>

using namespace std;

long gcd(long A, long B) {
	if (B == 0)
		return A;
	else
		return gcd(B, A % B);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long A, B;
	cin >> A >> B;

	for (long i = 1; i <= gcd(A, B); i++)
		cout << 1;

}