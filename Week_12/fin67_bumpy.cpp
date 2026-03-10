#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU{
    vector<int> p;
    DSU(int n){ p.resize(n+1); for(int i=1;i<=n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b) p[a]=b;
    }
};

struct Edge{
    int u,v,w,id;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<Edge> e(M);

    for(int i=0;i<M;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].id=i;
    }

    // -------- find K --------
    auto sorted=e;

    sort(sorted.begin(),sorted.end(),
        [](Edge a,Edge b){return a.w<b.w;});

    DSU dsu(N);

    int K=0;

    for(auto &x:sorted){
        dsu.unite(x.u,x.v);
        if(dsu.find(1)==dsu.find(N)){
            K=x.w;
            break;
        }
    }

    cout<<K<<"\n";

    // -------- compress components (<K) --------
    DSU dsu2(N);

    for(auto &x:e)
        if(x.w<K)
            dsu2.unite(x.u,x.v);

    unordered_map<int,int> mp;
    int idx=0;

    for(int i=1;i<=N;i++){
        int r=dsu2.find(i);
        if(!mp.count(r)) mp[r]=++idx;
    }

    int V=idx;

    vector<vector<pair<int,int>>> g(V+1);

    for(auto &x:e){
        if(x.w==K){
            int a=mp[dsu2.find(x.u)];
            int b=mp[dsu2.find(x.v)];
            if(a!=b){
                g[a].push_back({b,x.id});
                g[b].push_back({a,x.id});
            }
        }
    }

    int s=mp[dsu2.find(1)];
    int t=mp[dsu2.find(N)];

    // -------- bridge --------
    vector<int> tin(V+1),low(V+1);
    set<int> bridges;
    int timer=0;

    function<void(int,int)> dfs=[&](int u,int pe){

        tin[u]=low[u]=++timer;

        for(auto [v,id]:g[u]){

            if(id==pe) continue;

            if(!tin[v]){

                dfs(v,id);

                low[u]=min(low[u],low[v]);

                if(low[v]>tin[u])
                    bridges.insert(id);

            }else{
                low[u]=min(low[u],tin[v]);
            }
        }
    };

    for(int i=1;i<=V;i++)
        if(!tin[i])
            dfs(i,-1);

    // -------- check path --------
    vector<int> vis(V+1);
    queue<int> q;

    vector<int> parent(V+1), pedge(V+1);

    q.push(s);
    vis[s]=1;

    while(!q.empty()){

        int u=q.front(); q.pop();

        if(u==t) break;

        for(auto [v,id]:g[u]){

            if(!vis[v]){

                vis[v]=1;
                parent[v]=u;
                pedge[v]=id;

                q.push(v);
            }
        }
    }

    bool ok=false;

    int cur=t;

    while(cur!=s){

        if(bridges.count(pedge[cur]))
            ok=true;

        cur=parent[cur];
    }

    cout<<(ok?'Y':'N')<<"\n";
}