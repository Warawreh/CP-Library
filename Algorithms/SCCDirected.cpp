/*
Name: Strongly Connected components Undirected Graph
Description: Compress an undirected graph to components where each two nodes in a component can reach each other
Time: O(N) 
Space: O(N)
*/

vector<vector<int>> g, rg;
vector<bool> vis;
vector<int> order, component;

void dfs1(int u) {
    vis[u] = true;

    for (auto v : g[u])
        if (!vis[v])
            dfs1(v);

    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    component.push_back(u);

    for (auto v : rg[u])
        if (!vis[v])
            dfs2(v);
}

//In main

vis = vector<bool>(n,0);
for (int i = 0; i < n; i++)
    if (!vis[i])
        dfs1(i);

vis = vector<bool>(n,0);
reverse(order.begin(), order.end());

vector<int> id(n),sz;
int at = 0;
for (auto v : order)
    if (!vis[v]) {
        dfs2 (v);

        sz.push_back(component.size());
        for(int u : component){
            id[u] = at;
        }
        at++;

        component.clear();
    }