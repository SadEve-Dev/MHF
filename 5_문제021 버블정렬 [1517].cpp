#include <iostream>
#include <vector>

using namespace std;

// 전역 변수 선언
vector<int> A;
long long result = 0; // Swap 횟수(Inversion) 저장 (long long 필수)

// 함수 원형
void mergeSort(int L, int R);
void merge(int L, int M, int R);

// mergeSort 함수
void mergeSort(int L, int R) {
	if (L < R) {
		int M = L + (R - L) / 2;
		mergeSort(L, M);
		mergeSort(M + 1, R);
		merge(L, M, R);
	}
}

// merge 함수
void merge(int L, int M, int R) {
	vector<int> temp;
	temp.reserve(R - L + 1);
	int i = L, j = M + 1;

	while (i <= M && j <= R)
		// 1. A[i] <= A[j] (Inversion 아님)
		if (A[i] <= A[j])
			temp.push_back(A[i++]);
	    // 2. A[i] > A[j] (Inversion 발생)
		else {
			// [핵심] 왼쪽 배열의 남은 개수 (M - i + 1) 만큼 result에 더함
			result += (long long)(M - i + 1);
			temp.push_back(A[j++]);
		}

	// 왼쪽 배열에 남은 요소들 마저 삽입
	while (i <= M)
		temp.push_back(A[i++]);

	// 오른쪽 배열에 남은 요소들 마저 삽입
	while (j <= R)
		temp.push_back(A[j++]);

	// 정렬된 temp 배열을 원본 A에 복사
	for (int k = 0; k < temp.size(); k++)
		A[L + k] = temp[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	mergeSort(0, N - 1);

	cout << result << "\n";

	return 0;
}