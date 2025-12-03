#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, result = 0;
	string nums;

	cin >> N;
	cin >> nums;

	for (int i = 0; i < nums.length(); i++)
		result += nums[i] - '0';

	cout << result << endl;

	return 0;
}

