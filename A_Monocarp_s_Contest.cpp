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
        int n;
        cin >> n;
        vector<int> a(n);
        int temp = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0)temp++;
        }
        if (temp < 2) {
            cout << -1 <<endl;
        }
        else {
            int ans = 0;
            if (a[0] == 1)ans++;
            if (a[n - 1] == 1)ans++;
            cout << ans <<endl;
        }
    }
    return 0;
}