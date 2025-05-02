// đề bài tìm một hoán vị có độ dài n sao cho phần tử thứ i là p[i]
// tìm một dãy hoán vị sao cho số lượng gcd(p[i],i)=1 đúng là k
// in ra nó (n<=10^6)
// input : n , k (1<=k<=n<=10^16) 
// OUT :in ra dãy số 
// sub1:(n<=10) dpbitmask dp[x][i] là số vị trí thỏa mãn thuộc tập hợp con có vị trí cuối là i
// dp[x][i] --> dp[y][j] (j không thuộc x)
// dp[y][j] = dp[x][i]+(__gcd(buildtin_popcount(y),j)==1); 
// nếu dp[(1<<n)-1][i]==k truy vấn ngược nếu dp[((1<<n)-1)&&(~(1<<(i-1)))][j]+1=dp[(1<<n)-1][i] push vào vector
// đảo ngược rôi in ra la xong
// sub2(n<=10^6) : 
// nx : trong tất cả các hoán vị vị trí 1 luôn có gcd(p[1],1)=1
// 1 2 3 4 5 6 7 8 9 10
// 2 3 4 5 1 6 7 8 9 10
// tôi nghĩ rằng không thể có -1 và luôn có thể tạo ra dãy thỏa mãn
// solve sub2: ta chỉ thay đổi k số đầu tiên p[1]=2 , ... p[i]=i+1 , p[k]=1 còn lại p[j]=j (j>k)
// in ra kết quả là xong
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
int p[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    rei(i,1,n) p[i]=i;
    rei(i,1,k-1) p[i]=i+1;
    p[k]=1;
    rei(i,1,n) cout<<p[i]<<" "; 
    return 0;
}
