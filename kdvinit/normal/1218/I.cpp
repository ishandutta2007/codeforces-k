/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 8e3+5;

vector<int> adj[N];
int num_vertex;



/****************SCC Starts*****************/

//KDVinit's Implementation for Tarjan's Algorithm (GFG)
//Global Variables for SCC,
//This will additionally use N = max, adj[N] for edges,
//and Vertexes are defined from 1 -> num_vertex.

//Outputs of the Tarjan's Algorithm
vector<int> SCC_Nodes;          //Nodes from main graph that are heads of SCC.
vector<int> SCC_Component[N];   //Vertexes in the SCC Component of a head node.
int SCC_par[N];                 //SCC Head of a node from original graph.
int SCC_Topo[N];                //Vertex of SCC, Topologically Sorted.
int SCC_Topo_Index[N];           //Index of vertex v in the topological sort.

//Note - Adj List may store multiple edges between 2 vertex
vector<int> SCC_adj[N];         //Adj list in SCC compressed, outgoing edges.
vector<int> SCC_incoming[N];    //Adj list in SCC compressed, incoming edges.

//Helpers
int disc[N], low[N], In_stk[N], SCC_time;
stack<int> stk;

//Helper DFS for SCC
void SCC_DFS(int chi)
{
    //Assigns the low and disc values
    SCC_time++; disc[chi]=SCC_time; low[chi]=SCC_time;
    stk.push(chi); In_stk[chi]=1;       //Put them in Stack

    //Runs DFS
    for(auto x: adj[chi])
    {
        if(disc[x]==-1) { SCC_DFS(x); low[chi] = min(low[chi], low[x]); }
        else if(In_stk[x]==1) low[chi] = min(low[chi], disc[x]);
    }

    //if low = disc, it is the head node, and thus extracts the subtree
    if(low[chi]==disc[chi])
    {
        int w; SCC_Nodes.push_back(chi); SCC_Component[chi].push_back(chi);
        while(stk.top()!=chi)
        {
            w=stk.top(); stk.pop(); In_stk[w]=0;
            SCC_par[w]=chi; SCC_Component[chi].push_back(w);
        }
        stk.pop(); In_stk[chi]=0; SCC_par[chi]=chi;
    }
}

void SCC_Toposort()         //Topologically sorts the newly for DAG of SCC
{
    int in_deg[num_vertex+1] = {0};
    for(int i=1; i<=num_vertex; i++) in_deg[i] = SCC_incoming[i].size();

    queue<int> topo_qu; int topo_cnt=0;
    for(int i=1; i<=num_vertex; i++) if(in_deg[i]==0) topo_qu.push(i);

    while(!topo_qu.empty())
    {
        int node = topo_qu.front(); topo_qu.pop();
        SCC_Topo[++topo_cnt] = (node);
        for(auto x: SCC_adj[node]) { in_deg[x]--; if(in_deg[x]==0) topo_qu.push(x); }
    }

    for(int i=1; i<=num_vertex; i++) SCC_Topo_Index[SCC_Topo[i]]=i;
}

//Main Function for SCC.
void SCC_Compress()
{
    //Initializes Containers (for multiple testcases)
    while(!stk.empty()) stk.pop(); SCC_Nodes.clear(); SCC_time=0;
    for(int i=1; i<=num_vertex; i++) { disc[i]=-1; In_stk[i]=0; SCC_adj[i].clear(); }

    //SCC_DFS from vertex unvisited
    for(int i=1; i<=num_vertex; i++) if(disc[i]==-1) SCC_DFS(i);

    //To add edges to SCC Compressed
    for(int i=1; i<=num_vertex; i++)
    {
        for(auto x: adj[i])
        {
            int su = SCC_par[i], sv = SCC_par[x];   //Head of SCC comp
            if(su==sv) continue;                    //Belong to same comp
            SCC_adj[su].push_back(sv);              //Can possible add multiple edges between 2 vertex
            SCC_incoming[sv].push_back(su);
        }
    }

    //Topologically sorts the newly for DAG of SCC
    SCC_Toposort();
}

/*****************SCC Ends*****************/

int n;

void Take_both(int u, int v)
{
    v+=n;
    adj[2*u].push_back(2*v);
    adj[2*v].push_back(2*u);
    adj[2*u+1].push_back(2*v+1);
    adj[2*v+1].push_back(2*u+1);
}

void Take_only1(int u, int v)
{
    v+=n;
    adj[2*u].push_back(2*v+1);
    adj[2*v].push_back(2*u+1);
    adj[2*u+1].push_back(2*v);
    adj[2*v+1].push_back(2*u);
}

void Add_Imp(int u, int v)
{
    adj[u].push_back(v);
}

void solve()
{
    cin>>n;

    num_vertex = (4*n)+1;
    //Row = [1...n]
    //Col = [n+1...n+n]

    int a[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char x; cin>>x; int y = x-'0';
            a[i][j]=y;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char x; cin>>x; int y = x-'0';
            a[i][j]^=y;
        }
    }

    int b[n+1];
    for(int i=1; i<=n; i++) { char x; cin>>x; b[i]=x-'0'; }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==0)
            {
                if(b[i]==0 && b[j]==0) continue;
                else if(b[i]==1 && b[j]==1) Take_both(i, j);
                else if(b[i]==1 && b[j]==0) Add_Imp(2*(n+j), 2*(n+j)+1);
                else Add_Imp(2*i, 2*i+1);
            }
            else
            {
                if(b[i]==0 && b[j]==0) { cout<<-1<<endl; return; }
                else if(b[i]==1 && b[j]==1) Take_only1(i, j);
                else if(b[i]==1 && b[j]==0) Add_Imp(2*(n+j)+1, 2*(n+j));
                else Add_Imp(2*i+1, 2*i);
            }
        }
    }

    SCC_Compress();

    vector<int> rc;
    for(int i=1; i<=(2*n); i++)
    {
        int x = SCC_par[2*i];
        int y = SCC_par[2*i+1];
        if(x==y) { cout<<-1<<endl; return; }
        if(SCC_Topo_Index[x]>SCC_Topo_Index[y]) rc.push_back(i);
    }

    cout<<rc.size()<<endl;
    for(int x: rc)
    {
        if(x<=n) cout<<"row"<<" "<<(x-1)<<endl;
        else  cout<<"col"<<" "<<(x-n-1)<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}