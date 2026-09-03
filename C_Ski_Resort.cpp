#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int MOD = 1e9 + 7;

ll solve(int n, int k, int q, vector<int>& arr) {
    ll ans = 0;
    ll len = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= q) {
            len++;
        } 
        else {
            if (len >= k) {
                ll z = len - k + 1;
                ans += z * (z + 1) / 2;
            }
            len = 0;
        }
    }
    if(len >= k){
        ll z = len - k +1;
        ans += z * (z +1)/2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vi arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << solve(n, k, q, arr) << '\n';
    }

    return 0;
}