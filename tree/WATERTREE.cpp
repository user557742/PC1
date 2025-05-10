#include<bits/stdc++.h>
using namespace std;
const int maxn = 500001;
typedef long long ll;
vector<int> adj[maxn];
int n,m;
int bd[maxn],kt[maxn],pos[maxn];
struct st{

};
void truyvan1(){

}
void truyvan2(){

}
void truyvan3(){

}
int  main(){
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[u].push_back(u);
    }
    cin>>m;
    while(m--){
        int loai;cin>>loai;
        if(loai==1) truyvan1();
        if(loai==2) truyvan2();
        if(loai==3) truyvan3();
    }
}
