#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;

/**
 * @brief 구분자를 기준으로 문자열을 분리
 * @param s 분리할 문자열
 * @param c 구분자 문자
 * @return 분리된 문자열들의 벡터
 */
vector<string> split(string s, char c) {
	vector<string> res;
	stringstream ss(s);
	string data;
	while (getline(ss, data, c))
		res.push_back(data);
	return res;
}

/**
 * @brief 더하기로만 이루어진 문자열의 합계를 계산
 * @param s 더하기와 숫자로 이루어진 문자열
 * @return 문자열의 총합
 */
int sum(string s) {
	int res = 0;
	vector<string> parts = split(s, '+');
	for (string part : parts)
		res += stoi(part);
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int res = 0;
	// 뺄셈(-)을 기준으로 전체 문자열을 분리
	vector<string> S = split(s, '-');

	// 첫 번째 그룹은 더하고, 나머지 그룹은 모두 뺀다.
	for (int i = 0; i < S.size(); i++) {
		int x = sum(S[i]); // '+' 그룹의 총합을 구한다.
		if (i == 0) res += x; // 첫번째 항만 양수로 더한다
		else res -= x; // 나머지 항은 음수로 더한다.
	}

	cout << res << '\n';
}