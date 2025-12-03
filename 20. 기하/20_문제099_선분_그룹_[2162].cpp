#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

struct pos { long x, y; };
struct line { pos start; pos end; };

// 전역 변수 선언만 유지 (main에서 동적 할당)
vector<int> parent;
vector<line> L;


// 경로 압축 (Path Compression)
int find(int i) {
    return parent[i] < 0 ? i : parent[i] = find(parent[i]);
}

// 랭크(크기) 기반 Union
void Union(int i, int j) {
    int p = find(i);
    int q = find(j);
    if (p == q)
        return;
    parent[p] += parent[q];
    parent[q] = p;
}

// CCW 함수 (구조체 pos 사용으로 간결화)
int CCW(pos p1, pos p2, pos p3) {
    long res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    return res > 0 ? 1 : res < 0 ? -1 : 0;
}

// 선분이 일직선상에서 겹치는지 확인
bool isOverlap(pos a, pos b, pos c, pos d) {
    if (min(a.x, b.x) <= max(c.x, d.x) && min(c.x, d.x) <= max(a.x, b.x)
        && min(a.y, b.y) <= max(c.y, d.y) && min(c.y, d.y) <= max(a.y, b.y))
        return true;
    return false;
}

// 두 선분의 교차 여부 확인
bool isCross(pos a, pos b, pos c, pos d) {
    int abc = CCW(a, b, c);
    int abd = CCW(a, b, d);
    int cda = CCW(c, d, a);
    int cdb = CCW(c, d, b);

    if (abc * abd == 0 && cda * cdb == 0) // 일직선상에 있는 경우
        return isOverlap(a, b, c, d);
    else if (abc * abd <= 0 && cda * cdb <= 0) // 일반적인 교차
        return true;

    return false;
}


int main() {
    // 입출력 최적화는 유지
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    // N+1 크기로 동적 할당 (1번 인덱스부터 N까지 사용)
    parent.assign(N + 1, -1);
    L.resize(N + 1);

    // 선분 입력 및 교차 확인 -> Union
    for (int i = 1; i <= N; i++) {
        // i번째 선분을 L[i]에 제대로 입력 (L[i]는 start와 end를 가짐)
        cin >> L[i].start.x >> L[i].start.y >> L[i].end.x >> L[i].end.y;

        for (int j = 1; j < i; j++) {
            // 새로 들어온 선분 L[i]와 기존 선분 L[j]를 비교
            if (isCross(L[i].start, L[i].end, L[j].start, L[j].end))
                Union(i, j);
        }
    }

    int group_count = 0;
    int max_size = 0;

    // 결과 계산
    for (int i = 1; i <= N; i++)
        if (parent[i] < 0) { // 루트 노드 (대표 노드)인 경우
            group_count++;
            max_size = max(max_size, -parent[i]); // -parent[i]는 그룹의 크기
        }

    // 결과 출력
    cout << group_count << "\n";
    cout << max_size << "\n";
}