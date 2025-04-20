#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int mod=1e9+7;
const int maxn = 2e3+1;
string a;
int n;
string dp[maxn][maxn];
string solve(int i,int j){
    if(dp[i][j].size()>0) return dp[i][j];
    if(i==j){
        return string(1,a[i]);
    }
    if(j==i+1) if(a[i]==a[j]){
        return string(2,a[i]);
    }
    string ds;
    string l=solve(i+1,j);
    string r=solve(i,j-1);
    if(l.size()<r.size()) ds=r;
    else ds=l;
    if(a[i]==a[j]){
        string tmp=string(1,a[i])+solve(i+1,j-1)+string(1,a[i]);
        if(tmp.size()>ds.size()) ds=tmp;
    }
    dp[i][j]=ds;
    return ds;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a;
    n=a.size();
    a=" "+a;
    cout<<solve(1,n);
    return 0;
}
