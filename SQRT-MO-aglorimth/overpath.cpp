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
int n,m;
int a[maxn];
int cnt[maxn];
int depth[maxn];
int pre[maxn];
void dfscalcd(int u,int dad){
    rei(i,0,(int)dsbig){
        if(a[u]!=dsbig[i]) d[i][u]=d[i][dad];
        else d[i][u]=d[i][dad]+1;
    }
    for(int v:adj[u]) if(v!=dad){
        depth[v]=depth[u]+1;
        pre[v]=u;
        dfscalcd(v,u);
    }
}
void ver1(int u,int v){
    w=lca(u,v);
    int l=depth[u]+depth[v]-2*depth[w]+1;
    vector<int> gt;
    gt.pb(a[u]);
    while(u!=w){
        u=pre[u];
        gt.pb(a[u]);
    }
    while(v!=w){
        v=pre[v];
        gt.pb(a[v]);
    }// cho vector gt tim pt xuat hien hon mot nua 
    // sap xep vector nay tang dan va dem cac doan bang nhau

}
void ver2(int u,int v){
    w=lca(u,v);
    L=depth[u]+depth[v]-2*depth[w]+1;
    rei(i,0,dsbig.size()-1){
        sl=d[i][u]-d[i][pre[w]]+d[i][v]-d[i][w];
        if(2*sl>L){
            cout<<dsbig[i]<<"\n";
        }
        return ;
    }
    cout<<"-1\n";
    return ;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    int t=sqrt(n);
    rei(i,1,n) cnt[a[i]]++;
    rei(i,1,n) if(cnt[i]>=T) dsbig.pb(i);
    dfscalcd(1,0);
    cin>>m;
    while(m--){
        cin>>u>>v;
        if(dis(u,v)<2*t) ver1(u,v);
        else ver2(u,v);
    }
    return 0;
}