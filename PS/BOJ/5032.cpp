#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int e, f, c;
    cin >> e >> f >> c;
    e += f;
    int ans = 0;
    while(e >= c){
        ans += e / c;
        e = (e % c) + (e / c);
    }
    cout << ans;
    return 0;
}