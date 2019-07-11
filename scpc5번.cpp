#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> P;
deque<pair<long long, long long>> SW;
long long L, R;
bool solve(long long l) {
    int c = 0;
    SW.clear();
    //L - l ~ L + l사이에 y최소값이 l이상인가 L - l, L + l을 안보는 이유는 양 끝점은 볼 필요 없기 때문
    //x순서대로 저장되는데 y값 오름차순으로 저장되도록
    for (; c < P.size() && P[c].first < L + l; c++)
        if (P[c].first > L - l) {
            while (SW.size() && SW.back().second >= P[c].second)
                SW.pop_back();
            SW.push_back(P[c]);
        }
    if (SW.front().second >= l) return true;
    //c점을 마지막으로 하는 2 * l구간 확인
    for (; c < P.size() && P[c].first < R + l; c++) {
        //c로부터 2 * l이상 거리인점 제외
        while (SW.size() && SW.front().first <= P[c].first - 2 * l)
            SW.pop_front();
        if (SW.empty() || SW.front().second >= l) return true;
        while (SW.size() && SW.back().second >= P[c].second)
            SW.pop_back();
        SW.push_back(P[c]);
    }
    //끝점 확인
    while (SW.size() && SW.front().first <= R - l) SW.pop_front();
    return SW.empty() || SW.front().second >= l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++) {
        long long s = 1, e = 1e14;
        cin >> L >> R >> N;
        P.clear();
        P.emplace_back(L *= 2, 1e15);
        P.emplace_back(R *= 2, 1e15);
        while (N--) {
            long long x, y;
            cin >> x >> y;
            P.emplace_back(2 * x, abs(2 * y));
        }
        sort(P.begin(), P.end());
        while (s <= e) {
            long long m = (s + e) >> 1;
            if (solve(m))
                s = m + 1;
            else
                e = m - 1;
        }
        cout << "Case #" << t + 1 << '\n'
             << e << '\n';
    }
    return 0;
}