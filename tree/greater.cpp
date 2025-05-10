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
int id=0;
ll p[maxn];
int pos[maxn];
vector<int> adj[maxn];int bd[maxn],kt[maxn];
void dfs(int u,int dad){
    id++;
    bd[u]=id;
    pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    kt[u]=id;
}
pair<ll,int> tmp[maxn];
struct ST{
    int s[maxn];
    void intit(){

    }
    void upd(int k,int x,int r=1,int lo=1,int hi=id){
        if(lo==hi){
            s[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r];
    }
    int get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
} st;

void inp(){
    cin>>n;
    rei(i,1,n) cin>>p[i];
    rei(i,1,n-1){
        int j;cin>>j;
        adj[j].pb(i+1);
        adj[i+1].pb(j);
    }
    rei(i,1,n) tmp[i]={p[i],i};
    sort(tmp+1,tmp+n+1);

}
int ds[maxn];
int main(){
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    inp();
    dfs(1,0);
    red(j,n,1){
        int i=tmp[j].Y;
        ds[i]=st.get(bd[i],kt[i]);
        st.upd(bd[i],1);
    }
    rei(i,1,n) cout<<ds[i]<<"\n";
    return 0;
}