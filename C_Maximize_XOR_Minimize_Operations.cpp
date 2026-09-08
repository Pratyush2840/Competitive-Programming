#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = 1e9 + 7;
void solve() {
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long S = x + y;
        long long cur = 0;
        long long rem = x;
        for (int bit = 29; bit >= 0; bit--) {
            long long val = 1 << bit;
            if ((S & val) && val <= rem) {
                cur |= val;
                rem -= val;
            }
        }
        cout << S << " " << x - cur << '\n';
    }
    return 0;
}