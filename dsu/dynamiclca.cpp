#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
const int mod=1e9+7;

using ll = long long;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
int n,q;
vector<int> adj[maxn];
int depth[maxn],st[maxn],id=0;
pair<int,int> rmq[25][2*maxn];
void dfs(int u,int dad){
	st[u]=id;
	rmq[0][id++]={depth[u],u};
	for(int v:adj[u]) if(v!=dad){
		depth[v]=depth[u]+1;
		dfs(v,u);
		rmq[0][id++]={depth[u],u};
	}
}
void prepare(){
	int k=__lg(id);
	rei(i,1,k){
		for(int j=0;j+(1<<i)-1<=id;j++) rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
	}
}
int get_lca(int u,int v){
	int l=st[u],r=st[v];
	if(l>r) swap(l,r);
	int i=__lg(r-l+1);
	return min(rmq[i][l],rmq[i][r-(1<<i)+1]).second;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	dfs(1,0);
	prepare();
	while(q--){
        int a,b,c;cin>>a>>b>>c;
        int ab=get_lca(a,b);
        int bc=get_lca(b,c);
        int ca=get_lca(c,a);
        cout<<(ab^bc^ca)<<"\n";
	}
	return 0;
}