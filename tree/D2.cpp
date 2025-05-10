#include         <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// hungbucu-snipet
#define            TASK   "test"
#define              ll   long long
#define             ull   unsigned ll
#define              db   long double
#define             pLL   pair<ll, ll>
#define             pLI   pair<ll, int>
#define             pIL   pair<int, ll>
#define             pII   pair<int, int>
#define             vec   vector
#define              vL   vec<ll>
#define             vvL   vec<vL>
#define              vI   vec<int>
#define             vvI   vec<vI>
#define            vvvI   vec<vvI>
#define           vvvvI   vec<vvvI>
#define              vD   vec<db>
#define             vvD   vec<vD>
#define             vLL   vec<pLL>
#define             vLI   vec<pLI>
#define             vIL   vec<pIL>
#define             vII   vec<pII>
#define            vvII   vec<vII>
#define              vS   vec<string>
#define             vvS   vec<vS>
#define              vB   vec<bool>
#define             vvB   vec<vB>
#define            umap   unordered_map
#define          gphash   gp_hash_table
#define            mset   multiset
#define            pque   priority_queue
#define          all(a)   a.begin(), a.end()
#define         rall(a)   a.rbegin(), a.rend()
#define       stt(a, n)   a.begin(), a.begin() + n
#define       stf(a, n)   a.begin() + n, a.end()
#define              eb   emplace_back
#define              pb   push_back
#define              pf   push_front
#define            popb   pop_back
#define            popf   pop_front
#define             ins   insert
#define             asg   assign
#define             rev   reverse
#define              fi   first
#define              se   second
#define              th   third
#define              ub   upper_bound
#define              lb   lower_bound
#define             ite   iterator
#define           fs(n)   fixed << setprecision(n)
#define rei(i,a,b) for(int i=a;i<=b;i++)

using         namespace   std;
using         namespace   __gnu_pbds;

const ll          llINF = 1e18;
const int        intINF = 1e9;
const ll            MOD = 20032024;
const ll            maxn = 1e5+1;

template<   class T   >   
using       ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define            oset   ordered_set

template<     class A, 
              class B, 
              class C >   struct triple {
    A fi; B se; C th;

    triple() {}
    triple(A a,B b,C c) : fi(a), se(b), th(c) {}
};
#define            tIII   triple<int, int, int>
#define            tLLL   triple<ll, ll, ll>
#define            vIII   vec<tIII>
#define           vvIII   vec<vIII>
#define            vLLL   vec<tLLL>

mt19937                   rd(chrono::high_resolution_clock::now().time_since_epoch().count());
ll     Rand(ll L, ll R)   { return uniform_int_distribution<ll>(L, R)(rd); }
inline int     read() { 
    char c;    while (c = getchar(), c < '0' || c > '9'); int n = c - '0';
    while            (c = getchar(), c >= '0' && c <= '9') n = 10 * n + c - '0';
    return         n; }

vI          prime, lpf;
void  primeSieve(int n)   { prime.asg(1, 2); lpf.asg(n + 1, 2); lpf[0] = lpf[1] = 1;
                            for (int i = 3; i <= n; i += 2) { if (lpf[i] == 2) { lpf[i] = i; prime.pb(i); } 
                            for (int j = 0; j < (int)prime.size() && i * prime[j] <= n && prime[j] <= lpf[i]; ++ j) lpf[i * prime[j]] = prime[j]; 
                          } }
vvI                dvs;
void    dvsSieve(int n)   { dvs.asg(n + 1, vI());
                            for (int i = 1; i <= n; ++ i) {
                            for (int j = i; j <= n; j += i) 
                            dvs[j].pb(i);  
                          } }

template<   class T   >   bool maximize(T &a, T b) { if (b > a) return a = b, 1; return 0; }
template<   class T   >   bool minimize(T &a, T b) { if (b < a) return a = b, 1; return 0; }

ll      gcd(ll a, ll b)   { return b ? gcd(b, a % b) : a; }
ll      lcm(ll a, ll b)   { return a / gcd(a, b) * b; }

ll  bpow(ll n, ll p,
            ll m = MOD)   { ll r = 1; for (n %= m; p; p >>= 1) { if (p & 1) (r *= n) %= m; (n *= n) %= m; } return r; }
ll         inv(ll n, 
            ll m = MOD)   { return bpow(n, m - 2, m); }

ll          mask(int i)   { return i < 0 ? 0 : 1LL << i; }
bool   bit(ll n, int i)   { return n >> i & 1LL; }
#define        popcount   __builtin_popcountll
#define             clz   __builtin_clzll
#define             ctz   __builtin_ctzll
//__________________________________________________________________________________________________//
int n;
vI adj[maxn];
int m,q;
int d[maxn];
pII rmq[20][maxn];
int depth[maxn];
int id=0;
int st[maxn];
int pre[maxn];
int nex[maxn];
void dfs(int u,int dad){
    st[u]=id;
    rmq[0][id++]={depth[u],u};
    for(int v:adj[u]) if(v!=dad){
        pre[v]=u;
        nex[u]=v;
        depth[v]=depth[u]+1;
        dfs(v,u);
        rmq[0][id++]={depth[v],v};
    }
}
void prepare(){
    int k=__lg(id);
    rei(i,1,k){
        for(int j=0;j+(1<<i)+1<=id;j++) rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
    }
}
int lca(int u,int v){
    int l=st[u],r=st[v];
    if(l>r)swap(l,r);
    int i=__lg(r-l+1);
    return min(rmq[i][l],rmq[i][r-(1<<i)+1]).se;
}
void cong(int u,int dad){
    //cout<<u<<" ";
    for(int v:adj[u]) if(v!=dad){
        
        
        cong(v,u);
        d[v]+=d[u];
    }
}
int main() {

    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>q;
    rei(i,1,n-1) {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int lim=n;
    rei(i,2,lim){
        if(adj[i].size()==1){
            n++;
            adj[i].push_back(n);
            adj[n].push_back(i);
        }
    }
    dfs(1,0);
    prepare();
    while(m--){
        int u,v,val;cin>>u>>v>>val;
        int w=lca(u,v);
        //cout<<w<<" ";
        d[w]-=val;
        d[pre[w]]-=val;
        d[u]+=val;
        d[v]+=val;
    }
    cong(1,0);
    rei(i,1,n){
        cout<<d[i]<<" ";    
    }
    cout<<"\n";
    while(q--){
        int u,v;cin>>u>>v;
        int w=lca(u,v);
        cout<<d[u]+d[v]-2*d[w]+d[w]-d[pre[w]]<<"\n";
    }
    return 0;
}