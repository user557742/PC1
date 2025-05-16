#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6+1;
int a[N];
int n;
long long f[N];
vector<int> adj[N];
long long s[N];
int pre[N];
void dfs(int u,int dad){
	f[u]=a[u];
	for(int v:adj[u]) if(v!=dad){
		pre[v]=u;
		dfs(v,u);
		f[u]+=f[v];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	long long ds=1e18;
	int kq=0;
	for(int u=1;u<=n;u++){
		long long gt=0;
		long long T=0;
		for(int v:adj[u]) if(pre[v]==u){
			gt=max(gt,f[v]);
			T+=f[v];
		}
		gt=max(gt,s[n]-a[u]-T);
		if(ds>gt){
			ds=gt;
			kq=u;
		}
	}
	cout<<kq;
}