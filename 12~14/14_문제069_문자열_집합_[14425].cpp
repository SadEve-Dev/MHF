#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<string> s(N);
	vector<string> arr(M);

	for (int i = 0; i < N + M; i++)
		if (i < N)
			cin >> s[i];
		else
			cin >> arr[i - N];
	
	unordered_set<string> hash_set;
	for (int i = 0; i < N; i++) // 해시 셋에 s 저장
		hash_set.insert(s[i]);

	int cnt = 0;
	for (int i = 0; i < M; i++)
		if (hash_set.find(arr[i]) != hash_set.end()) // 검사할 문자열이 s에 있으면
			++cnt;

	cout << cnt;
}