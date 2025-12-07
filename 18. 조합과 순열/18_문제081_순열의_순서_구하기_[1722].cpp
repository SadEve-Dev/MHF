#include <iostream>
#include <vector>

using namespace std;

int N, mode;
vector<long> F; // 팩토리얼
vector<int> P; // 순열 조합
vector<bool> vis; // 방문 여부

/**
 * @brief k번째 순열을 구하여 출력하는 함수
 */
void getPermutation() {
    // k번째 순열 구하기
    long k; cin >> k;
    for (int i = 1; i <= N; i++) // 1번째 자리부터 N번째 자리까지
        for (int j = 1; j <= N; j++) // 1부터 N까지 숫자 시도
            if (!vis[j]) // 쓰지 않은 숫자라면
                // 현재 자리에 j를 넣었을 때 만들 수 있는 경우의 수 = (N-i)!
                if (k > F[N - i]) // k가 (N-i)!보다 작으면
                    k -= F[N - i];
                else {
                    P[i] = j;
                    vis[j] = true;
                    cout << j << " ";
                    break;
                }
}

/**
 * @brief 주어진 순열이 사전 순으로 몇 번째인지 구하는 함수
 */
void findRank() {
    long res = 1; // 순서는 1부터 시작
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        for (int j = 1; j < P[i]; j++) // 현재 수보다 작은 미사용 숫자 카운트
            if (!vis[j])
                res += F[N - i];
        vis[P[i]] = true;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> mode;

    // 팩토리얼 미리 계산 (20! 까지)
    F.resize(21, 1);
    for (int i = 1; i <= 20; i++)
        F[i] = F[i - 1] * i;

    P.resize(N + 1); // 결과 또는 입력 저장용
    vis.resize(21, false); // 숫자 사용 여부 체크

    if (mode == 1) getPermutation();
    else findRank();

}