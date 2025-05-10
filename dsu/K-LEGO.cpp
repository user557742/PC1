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
int n,k;
int x[maxn];
set<vector<int>>s;
int pre=0;
void solve(int h,int lpos){
    if(h>n){
        vector<int> el;
        rei(i,1,k) el.push_back(x[i]);
        s.insert(el);
        return ;
    }
    if(h==1){
        rei(i,1,k){
            int mau=x[i];
            x[i]=h;
            solve(h+1,i);
            x[i]=mau;
        } 
    }
    if(lpos>1){
        int np=lpos-1;
        int mau=x[np];
        x[np]=h;
        solve(h+1,np);
        x[np]=mau;

    }
    if(lpos<k){
        int np=lpos+1;
        int mau=x[np];
        x[np]=h;
        solve(h+1,np);
        x[np]=mau;

    }
}
void sub1(){
    solve(1,0);
    cout<<s.size();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    sub1();
    return 0;
}