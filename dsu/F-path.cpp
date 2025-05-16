#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =501;
const int maxk =1e7+1;
const int mod = 998244353;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int n,k;
int a[maxn][maxn];
ll dp[maxn][maxn][401];
int tt[maxk];
int d[maxk];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    rei(i,1,n) rei(j,1,n) cin>>a[i][j];
    int m=0;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            //cout<<i<<" ";
            m++;d[m]=i;
            if(i!=k/i){
                m++;
                d[m]=k/i;
            }
        }
    }
    //cout<<"\n";
    sort(d+1,d+m+1);
    rei(i,1,m) tt[d[i]]=i;
    rei(i,1,n) rei(j,1,n) a[i][j]=__gcd(a[i][j],k);
    dp[1][1][tt[a[1][1]]]=1;
    //cout<<"\n";
    rei(i,1,n){
        rei(j,1,n) if(a[i][j]!=-1){
            rei(x,1,m) {
                int g=d[x];
                if(a[i+1][j]!=-1){
                    int ng=__gcd(1ll*g*a[i+1][j],1ll*k);
                    dp[i+1][j][tt[ng]]=(dp[i][j][x]+dp[i+1][j][tt[ng]])%mod;
                }if(a[i][j+1]!=-1){
                    int ng=__gcd(1ll*g*a[i][j+1],1ll*k);
                    dp[i][j+1][tt[ng]]=(dp[i][j][x]+dp[i][j+1][tt[ng]])%mod;
                }

            }
        }
    }
    cout<<dp[n][n][m];
    return 0;
}