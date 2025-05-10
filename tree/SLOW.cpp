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
int n;
vector<int> adj[maxn];
int bd[maxn],pos[maxn],kt[maxn];
int id=0;
void dfs(int u,int dad){
    id++;
    bd[u]=id;
    pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    kt[u]=id;
}
struct ST{
    int s[4*maxn+1];
    int lz[4*maxn+1];
    void down(int r){
        lz[2*r+1]+=lz[r];
        lz[2*r]+=lz[r];
        lz[r]=0;
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v) {
            lz[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
    }
    int get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return lz[r]*(hi-lo+1)+s[r];
        int mid=(lo+hi)/2;
        down(r);
        int L=get(u,v,2*r,lo,mid);
        int R=get(u,v,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
        return L+R;
    }
}st;
int main(){
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    rei(i,1,n){
        int p;cin>>p;
        cout<<st.get(bd[p],bd[p])<<"\n";
        st.upd(bd[p],kt[p],1);
    }
    return 0;
}