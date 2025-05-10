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
int id=0;
int n,m;
int a[maxn];
int bd[maxn],kt[maxn];
int gt[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
    id+=1;
    bd[u]=id;
    gt[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    kt[u]=id;
}
int b[maxn];
/*struct st{  
    ll lz[4*maxn];
    ll s[4*maxn];
    void build(int r=1,int lo=1,int hi=id){
        if(lo==hi){
            s[r]=b[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r];
    }
    void down(int r){
        lz[2*r]+=lz[r];
        lz[2*r+1]+=lz[r];
        lz[r]=0;
    }
    void up(int r,int lo,int hi){
        int mid=(lo+hi)/2;
        s[r]=s[2*r]+s[2*r+1]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,2*r+1,mid+1,hi);
        up(r,lo,hi);
    }
    ll get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r]+lz[r]*(hi-lo+1);
        int mid=(lo+hi)/2;
        down(r);
        ll L=get(u,v,2*r,lo,mid);
        ll R=get(u,v,2*r+1,mid+1,hi);
        up(r,lo,hi);
        return L+R;
    }
}st;*/
struct ST{
    ll s[4*maxn],lz[4*maxn];
    void build(int r=1,int lo=1,int hi=id){
        if(lo==hi){
            s[r]=b[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    void down(int r){
        lz[2*r]+=lz[r];
        lz[2*r+1]+=lz[r];
        lz[r]=0;
    }
    void up(int r,int lo,int hi){
        int mid=(lo+hi)/2;
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
    }
    void upd(int u,int v,int d,int r=1,int lo=1,int hi=id){
        if(u>hi||lo>v) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=d;
            return; 
        }
        int mid=(lo+hi)/2;
        down(r);
 
        upd(u,v,d,2*r,lo,mid);
        upd(u,v,d,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r]+(hi-lo+1)*lz[r];
        int mid=(lo+hi)/2;
        down(r);
        ll L=getans(u,v,2*r,lo,mid);
        ll R=getans(u,v,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
        return R+L;
    }
}st;
void truyvanp(int u,int x){
    st.upd(bd[u]+1,kt[u],x);
}
void truyvanu(int u){
    cout<<st.getans(bd[u],bd[u])<<"\n";
}
int main(){
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    rei(i,2,n){
        int j,x;cin>>x>>j;
        a[i]=x;
        adj[i].pb(j);
        adj[j].pb(i);
    }    
    dfs(1,0);
    rei(i,1,id){
        b[i]=a[gt[i]];
    }st.build();

    while(m--){
        char loai;
        cin>>loai;
        if(loai=='p'){
            int u,p;cin>>u>>p;
            truyvanp(u,p);
        }
        else{
            int u;cin>>u;
            truyvanu(u);
        }
    }
    return 0;
}