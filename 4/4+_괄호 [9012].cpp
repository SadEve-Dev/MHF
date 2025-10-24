#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solve(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(')
			stk.push('(');
		else if (c == ')')
			if (!stk.empty())
				stk.pop();
			else
				return "NO";
	}
	if (stk.empty())
		return "YES";
	else
		return "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		cout << solve(s) << endl;
	}
}