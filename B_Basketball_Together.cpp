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
        int n , d;
        cin>>n>>d;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        sort(arr.begin() , arr.end());
        int i = n-1;
        int ans =0;
        int cnt = n;
        while(i >= 0){
            int z = (d + arr[i])/arr[i];
            //cout<<z<<" ";
            if(z <= cnt){
                ans++;
                cnt -= z;
            }
            else{
                break;
            }
            i--;
        }
        cout<<ans<<endl;
    

    return 0;
}