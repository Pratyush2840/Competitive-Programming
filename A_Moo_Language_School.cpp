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
        int n ,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ans= 0;
        for(int i = 0 ; i < n;i+=k){
            int zero = 0;
            for(int j = i;j< i+k;j++){
                if(s[j] == '0'){
                    zero =1;
                }
            }
            if(zero == 0){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}