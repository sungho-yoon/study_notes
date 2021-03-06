#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, m, k;
int d[301][301];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        for (int j = m; j >= t1; --j)
            for (int x = k; x >= t2; --x)
                d[j][x] = max(d[j][x], d[j - t1][x - t2] + 1);
    }
    cout << d[m][k];
    return 0;
}