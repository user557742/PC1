#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;
const int mod = 1e9+7;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
ll gt[maxn];
int n;
ll bpow(ll a,ll b){
    ll ds=1;
    while(b>0){
        if(b%2) ds=(ds*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ds;
}
ll ckn(ll u,ll v){
    ll ms=(gt[u]*gt[v-u])%mod;
    return (gt[v]*bpow(ms,mod-2))%mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gt[0]=1;
    rei(i,1,maxn-1) gt[i]=(gt[i-1]*i)%mod;
    cin>>n;
    while(n--){
        ll a,b;cin>>a>>b;
        cout<<ckn(b,a)<<"\n";
    }
    return 0;
}