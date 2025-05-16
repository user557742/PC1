// dp[u] khoang cach lon nhat tu dinh u den cac con trong cay con goc u
// dp[u]= max(dp[vj]) +1
// moi lan reroot ta xem xet su dong gop cua dinh vj vao goc u roi chuyen goc 
// neu goc khong con v thi dap an ntn
// th1: neu v khong dong gop vao ket qua thi du mat v dp[u] van khong thay doi / co nhieu duong lon nhat di cung co do dai bang v
// th2: neu duong di v la dai nhat va duy nhat thi khi khong con v ds chinh la duong di dai nhi


#include <iostream>
#include <vector>
using namespace std;
const int maxn =2e5+1;
#define rei(i,a,b) for(int i=a;i<=b;i++)
int n;
int dp[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
int ans[maxn];
void calc(int u,int dad){
    for(int v:adj[u]) if(v!=dad){
        int dpu=dp[u];
        int dpv=dp[v];
        //int cnt=0;
        int timnhi=0;
        //int r=0;
        if(dp[u]>dp[v]+1){
            dp[v]=max(dp[v],dp[u]+1);
            //dp[u]=dp[u];
        }
        else{
            for(int x:adj[u]) if(x!=dad){
                if(x!=v){
                    timnhi=max(dp[x]+1,timnhi);
                }
            }
            if(timnhi==dp[u]){
                dp[v]=max(dp[v],dp[u]+1);
                //dp[u]=dp[u];
            }
            else{
                
                dp[u]=timnhi;
                dp[v]=max(dp[v],dp[u]+1);
            }
        }
        ans[v]=dp[v];
        calc(v,u);
        dp[u]=dpu;
        dp[v]=dpv;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    ans[1]=dp[1];
    calc(1,0);
    rei(i,1,n) cout<<ans[i]<<" ";
}