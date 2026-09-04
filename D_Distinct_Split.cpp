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
        int n ;
        cin>>n;
        string str;
        cin>>str;
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int freq[26] = {0};
        freq[str[0] - 'a'] =1;
        prefix[0] = 1;
        for(int i = 1 ; i < n ; i++){
            if(freq[str[i] - 'a'] == 0){
                freq[str[i] - 'a'] = 1;
                prefix[i] = prefix[i-1] + 1;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }
        int freq2[26] = {0};
        freq2[str.back() - 'a'] =1;
        suffix[n-1] = 1;
        for(int i = n-2 ; i >= 0; i--){
            if(freq2[str[i] - 'a'] == 0){
                freq2[str[i] - 'a'] = 1;
                suffix[i] = suffix[i +1] + 1;
            }
            else{
                suffix[i] = suffix[i+1];
            }
        }
        int ans =0;
        for(int i = 0 ; i < n-1 ; i++){
            //if(n == 10)cout<<prefix[i]<<" "<<suffix[i]<<endl;
            ans = max(ans , prefix[i] + suffix[i+1]);
        }

        cout<<ans<<endl;
    }

    return 0;
}