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
        vi arr1(n);
        vi arr2(n);
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i = 0 ; i < n ; i++){
            cin>> arr1[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin>> arr2[i];
        }
        int cnt =1;
        for(int i = 0 ; i <n;i++){
            if(i < n-1  && arr1[i] == arr1[i+1]){
                cnt++;
            }
            else{
                if(mp1[arr1[i]] < cnt){
                    mp1[arr1[i]] = cnt;
                }
                cnt = 1;
            }
        }
        cnt =1;
        for(int i = 0 ; i <n;i++){
            if(i < n-1  && arr2[i] == arr2[i+1]){
                cnt++;
            }
            else{
                if(mp2[arr2[i]] < cnt){
                    mp2[arr2[i]] = cnt;
                }
                cnt = 1;
            }
        }
        int ans=0;
        for(auto it : mp1){
            int number = it.first;
            int count = it.second;
            int count2 = mp2[number];
            ans = max(ans, count + count2);
        }
        for(auto it : mp2){
            int number = it.first;
            int count = it.second;
            int count2 = mp1[number];
            ans = max(ans,count + count2);
        }
        cout<<ans<<endl;
    }

    return 0;
}