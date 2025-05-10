#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "TASK"
#define gcd __gcd
#define X first
#define Y second
#define ub upper_bound
#define lb lower_bound
const int mod= 1e9+7;
const int maxn=1e6+1;
const int base=293;
typedef long long ll;
const int ooi=1e9+9;
const ll ool=1e18+9;
struct trip{
    int fi,se,th;
    trip(int _fi=0,int _se=0,int _th=0) : fi(_fi),se(_se),th(_th) {}
};
int getbit(int i,int x){return (x>>(i-1))&1;}
ll bpow(ll a,ll b,ll m){
    ll ds=1;
    while(b>0){
        if(b%2) ds=(ds*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return ds;
}
ll inv(ll a,ll m){
    return bpow(a,m-2,m)%m;
}
int n;
int x[maxn];bool ok=0;
void back(int h){
    if(ok) return;
    if(h>n){
        ll f=1,g=0;
        rei(i,1,n) {
            f*=x[i];
            g+=x[i];
        }
        if(f%g==0){
            rei(i,1,n) cout<<x[i];
            ok=1;
        }
        return;
    }
    //if(ok) return ;
    if(ok!=1){rei(i,1,9){
        x[h]=i;
        back(h+1);
    }}
}
int main(){
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        ok=0;
        back(1);
        cout<<"\n";
    }
    return 0;
}
