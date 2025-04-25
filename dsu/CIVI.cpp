#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+1;
const int mod=1e9+7;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

int n,m,q;
vector<int> adj[maxn];

struct dsu{
    int sz[maxn],pre[maxn],gt[maxn];
    void ms(int i){
        sz[i]=1;
        pre[i]=i;
        gt[i]=1;
    }
    int find(int u){
        return (u==pre[u]) ? u : pre[u]=find(pre[u]);
    }
    void kh(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
}t;

vector<int> tplt[maxn];
int stplt;
bool vis[maxn];

void dfs(int u){
    tplt[stplt].pb(u);
    vis[u]=1;
    for(int v:adj[u]) if(!vis[v]) dfs(v);
}

int d[maxn],ok[maxn];

pair<int,int> tdk(vector<int> ls,int st){
    for(int x:ls) d[x]=0,ok[x]=0;
    queue<int> q;
    q.push(st);ok[st]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:adj[u]) if(!ok[v]){
            ok[v]=1;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
    int dd=0;
    for(int x:ls) if(dd<d[x]){
        dd=d[x];
        st=x;
    }
    return mp(dd,st);
}

int timduongkinh(vector<int> ls){
    pair<int,int> dcd=tdk(ls,ls[0]);
    pair<int,int> qd=tdk(ls,dcd.se);
    return qd.fi;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    rei(i,1,n) t.ms(i);
    while(m--){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        t.kh(u,v);
    }

    rei(i,1,n) if(!vis[i]){
        stplt++;
        dfs(i);
    }

    rei(i,1,stplt){
        int r=t.find(tplt[i][0]);
        t.gt[r]=timduongkinh(tplt[i]);
    }

    while(q--){
        int l;cin>>l;
        if(l==1){
            int u;cin>>u;
            u=t.find(u);
            cout<<t.gt[u]<<"\n";
        }else{
            int u,v;cin>>u>>v;
            u=t.find(u);
            v=t.find(v);
            if(u!=v){
                int ngt=max({t.gt[u],t.gt[v],(t.gt[u]+1)/2+(t.gt[v]+1)/2+1});
                t.kh(u,v);
                int r=t.find(u);
                t.gt[r]=ngt;
            }
        }
    }
    return 0;
}
