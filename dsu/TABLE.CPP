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
struct FT{
    vector<ll> s;
    int n;
    void init(int _n){
        n=_n;
        s.resize(n+1,0);
    }
    void upd(int u,int x){
        while(u<=n){
            s[u]+=x;
            u+=u&(-u);
        }
    }
    ll get_ans(int u){
        ll ds=0;
        while(u>0){
            ds+=s[u];
            u-=u&(-u);
        }
        return ds;
    }
};
struct FT2d{
    vector<FT> g;
    int n,m;
    void init(int _n,int _m){
        n=_n;
        m=_m;
        g.resize(n+1);
        rei(i,1,n) g[i].init(m);
    }
    void upd(int u,int v,int x){
        while(u<=n){
            g[u].upd(v,x);
            u+=u&(-u);
        }
    }
    ll get_ans(int u,int v){
        ll ds=0;
        while(u>0){
            ds+=g[u].get_ans(v);
            u-=u&(-u);
        }
        return ds;
    }
    void updhcn(int u,int v,int x,int y,int w){
        upd(u,v,w);
        upd(x+1,v,-w);
        upd(u,y+1,-w);
        upd(x+1,y+1,w); 
    }
    ll getds(int u,int v,int x,int y){
        return get_ans(x,y)-get_ans(x,v-1)-get_ans(u-1,y)+get_ans(u-1,v-1);
    }
}t;
int n,m,q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    t.init(n,m);
    rei(i,1,n){
        rei(j,1,m){
            int x;cin>>x;
            t.updhcn(i,j,i,j,x);
        }
    }
    while(q--){
        int l;cin>>l;
        if(l==1){
            int u,v,x,y,w;cin>>u>>v>>x>>y>>w;
            t.updhcn(u,v,x,y,w);
        }
        else{
            int u,v,x,y;cin>>u>>v>>x>>y;
            cout<<t.getds(u,v,x,y)<<"\n";
        }
    }
    return 0;
}