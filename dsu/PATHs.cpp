#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505;
const ll mod = 998244353;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i = (a); i <= (b); ++i)
#define red(i,a,b) for(int i = (a); i >= (b); --i)
#define fi first
#define se second

int n, k;
int a[maxn][maxn];
map<int,int> dp[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    rei(i,1,n) rei(j,1,n) cin >> a[i][j];
    if(a[1][1] != -1){
        int r = ((a[1][1] % k) + k) % k;
        dp[1][1][r] = 1;
    }
    rei(i,1,n) rei(j,1,n){
        //if(i==1 && j==1) continue;
        if(a[i][j] == -1) continue; 
        if(i > 1){
            for(auto &p : dp[i-1][j]){
                int pr = p.fi;
                ll cnt = p.se;
                int nr = (int)((1LL * pr * a[i][j] % k + k) % k);
                dp[i][j][nr] = (dp[i][j][nr] + cnt) % mod;
            }
        }
        if(j > 1){
            for(auto &p : dp[i][j-1]){
                int pr = p.fi;
                ll cnt = p.se;
                int nr = (int)((1LL * pr * a[i][j] % k + k) % k);
                dp[i][j][nr] = (dp[i][j][nr] + cnt) % mod;
            }
        }
    }
    ll ans = dp[n][n].count(0) ? dp[n][n][0] : 0;
    cout << ans << "\n";
    return 0;
}
