#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

enum { a = 0, b, c };

void BFS();

static int Sender[] = { 0, 0, 1, 1, 2, 2 };
static int Receiver[] = { 1, 2, 0, 2, 0, 1 };

static bool visited[201][201]; //A B의 무게만 있으면 C의 무게가 고정되므로 2개로만 체크 가능
static bool answer[201];
static int cap[3]; // A B C 물통의 최대 용량

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> cap[a] >> cap[b] >> cap[c];
    BFS();

    for (int i = 0; i < 201; i++)
        if (answer[i]) cout << i << " ";
}

void BFS() {
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0)); // A=0, B=0 (C=cap[2])
    visited[0][0] = true;
    answer[cap[c]] = true; // 초기 상태 (A=0)
    while (!queue.empty()) {
        pair <int, int> p = queue.front();
        queue.pop();
        int A = p.first;
        int B = p.second;
        int C = cap[c] - A - B; // C는 전체 물의 양(cap[2])에서 A와 B를 뺀 것
        for (int k = 0; k < 6; k++) { // 6가지 경우의 수 (A->B, A->C, B->A, ...)
            int next[] = { A, B, C };
            int from = Sender[k];
            int to = Receiver[k];

            // 'from'에서 'to'로 옮길 물의 양 계산
            // 'from'에 있는 물의 양과 'to'에 남은 용량 중 더 적은 양
            int moveAmount = min(next[from], cap[to] - next[to]);

            next[from] -= moveAmount;
            next[to] += moveAmount;

            if (!visited[next[a]][next[b]]) { // A와 B의 물의 양으로 방문 여부 체크
                visited[next[a]][next[b]] = true;
                queue.push(make_pair(next[a], next[b]));
                if (next[a] == 0) // A의 물의 양이 0일 때
                    answer[next[c]] = true; // C의 물의 양을 정답으로 기록
            }
        }
    }
}