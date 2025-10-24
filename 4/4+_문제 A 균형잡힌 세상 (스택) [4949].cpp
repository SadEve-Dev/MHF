#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;

string solve() {
	stack<char> stk;
	for (auto c : s)
		if (c == '(' || c == '[')
			stk.push(c);
		else if (c == ')') {
			if (stk.empty() || stk.top() != '(')
				return "no";
			stk.pop();
		}
		else if (c == ']') {
			if (stk.empty() || stk.top() != '[')
				return "no";
			stk.pop();
		}
	return (stk.empty() ? "yes" : "no");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (getline(cin, s), s != "." )
		cout << solve() << endl;
	return 0;
}