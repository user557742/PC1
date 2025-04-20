#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =2e5+1;
int A,B,n;
ll dp[1<<20][21];
vector<pair<int,int>> adj[maxn];
int d[1000][1000];
bool ok[maxn];
struct canh{
    int u,v,l;
} q[maxn];
bool cmp(canh x,canh y){
    return make_pair(x.u,x.v)<make_pair(y.u,y.v);
}
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
void sub2(){
    for(int i=1;i<n;i++){
        d[q[i].u][q[i].v]=q[i].l;
        d[q[i].v][q[i].u]=q[i].l;
    }
    for(int x=0;x<(1<<n);x++) for(int i=1;i<=n;i++) dp[x][i]=1e18;
    for(int i=1;i<=n;i++) dp[(1<<(i-1))][i]=0;
    for(int x=0;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(getbit(i,x)){
            for(int j=1;j<=n;j++) if(!getbit(j,x)){
                int y=x|(1<<(j-1));
                if(d[i][j]>0) dp[y][j]=min(dp[y][j],dp[x][i]+1ll*A*d[i][j]);
                else dp[y][j]=min(dp[y][j],dp[x][i]+B); 
            }
        }
    }
    ll ds=1e18;
    for(int i=1;i<=n;i++) ds=min(ds,dp[(1<<n)-1][i]+B);
    cout<<ds;
}
void sub3(){
    if(B<A) {
        cout<<1ll*(n-1)*B;
        return ;
    }
    ll ds=0;
    for(int i=1;i<n;i++){
        if(q[i].l*A<=B){
            if(ok[q[i].u]){
                ds+=A*q[i].l;
                ok[q[i].v]=1;
                ok[q[i].u]=1;
            }
            else{
                ds+=B;
            }
        }
    }
    cout<<ds;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>A>>B;
    for(int i=1;i<n;i++){
        cin>>q[i].u>>q[i].v>>q[i].l;
    }
    sort(q+1,q+n,cmp);
    //if(n<=20) sub2();
    sub3();
    return 0;
}