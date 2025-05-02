// cho hai số n và x hãy tìm mảng a1^a2^.....^an sao cho = x sao cho tổng chỏ nhất
// tư tưởng xét từng bit của x nếu bit của x để chọn   
// nx vì mọi số đều dương nên mọi bit số đều có ít nhất một bit bật
// vì để giảm tổng ta muốn bit 1 x của số nào đó xuất hiện càng sớm càng tốt
// nếu bit thứ nhất của x= 1 
    // n lẻ bật n bit rồi làm gì ds=n+x-1;
    // n chẵn : bật n-1 bit rồi tìm bit bật gần nhất của 1 nếu không còn thì phải có 2 bit bật
// nếu bit thứ nhât của x= 0
    // n lẻ bật n-1 bit rồi tìm bit bật gần nhất của 1 nếu không còn thì phải có 2 bit bật
    // n chăn
    // 2 : 1
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
int getbit(int i,ll x){
    return (x>>(i-1))&1;
}
ll getans(ll n,ll x){
    if(n==1&&x==0) return -1;
    int i=getbit(1,x);
    if(i==1){
        if(n%2==1) return n-1+x;
        else{
            int m=-1;
            rei(j,2,64) if(getbit(j,x)==1) m=j;
            if(m!=-1){
                return n+x-2;
            } 
            else{
                return n+x+2;
            }
        }
    }
    else{
        if(n%2==0) return x+n;
        else{
            
            int m=-1;
            rei(j,2,64) if(getbit(j,x)==1) m=j;
            if(m!=-1){
                return n-1+x;
            } 
            else{
                return n+x-1+4;
            }
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll x,n;cin>>n>>x;
        cout<<getans(n,x)<<"\n";
    }
    return 0;
}

