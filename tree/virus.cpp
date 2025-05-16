#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+1;
int bd[maxn],kt[maxn],pos[maxn];
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back 
int a[maxn];
vector<int> adj[maxn];
int id=0;int n;
void dfsa(int u,int dad){
    id++; 
    bd[u]=id;pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfsa(v,u);
    }
    kt[u]=id;
}
void dfsb(int u,int dad){
    id++;
    a[u]=id;
    for(int v:adj[u]) if(v!=dad) dfsb(v,u);
}
struct IT{
    int s[4*maxn+1];
    //int lz[4*maxn+1];
    void build(int r=1,int lo=1,int hi=id){
        if(lo==hi){
            s[r]=a[pos[lo]];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r];
    }
    void upd(int k,int x,int r=1,int lo=1,int hi=id){
        if(lo==hi){
            s[r]=x;
            return;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    int get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
}st;
// tạo 2 cây dfs A , B 
// lưu thứ tự topo của 2 cây
// nén cây A,B thành mảng 
// xét u đếm số mỗi đỉnh u lưu thêm giá trị posb[u];
pair<int,int> g[maxn];
int ra,rb;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n){
        int u;cin>>u;
        if(u==0) ra=i;
        else{
            adj[u].pb(i);
            adj[i].pb(u);
        }
    }dfsa(ra,0);
    id=0;
    rei(i,1,n) adj[i].clear();
    rei(i,1,n){
        int u;cin>>u;
        if(u==0) rb=i;
        else{
            adj[u].pb(i);
            adj[i].pb(u);
        }
    }
    dfsb(rb,0);
    rei(i,1,n) g[i]={a[i],i};
    sort(g+1,g+n+1);
    int ds=0;   
    for(int i=n;i>=1;i--){
        int u=g[i].second;
        ds+=st.get(bd[u]+1,kt[u]);
        st.upd(bd[u],1);
    }
    cout<<ds;
}