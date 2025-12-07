#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;

vector<int> A(N), L(N), R(N);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    
    A.resize(N); // 입력 수열
    L.resize(N); // L[i]: i번째 원소 A[i]로 끝나는 연속합 중 최댓값 (제거 X 상태)
    R.resize(N); // R[i]: i번째 원소 A[i]로 끝나는 연속합 중 최댓값 (제거 O 상태)

    // 입력
    for (int i = 0; i < N; i++) cin >> A[i];

    // 초기값 설정
    L[0] = A[0];
    R[0] = 0; // i=1에서 R[0] + A[1] 계산 시 A[0]을 제거한 효과를 내기 위해 0으로 설정

    int res = L[0];

    // DP 계산
    for (int i = 1; i < N; i++) {
        L[i] = max(A[i], L[i - 1] + A[i]);
        R[i] = max(R[i - 1] + A[i], L[i - 1]);
        res = max({ res, L[i], R[i] });
    }
    
    cout << res;
}