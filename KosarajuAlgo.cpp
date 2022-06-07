#include <bits/stdc++.h>
using namespace std;

// Topological Sort :
void topoDfs(int node, stack<int> &st, vector<bool> &visited,
             unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
            topoDfs(nbr, st, visited, adj);
    }
    st.push(node);
}

// dfs
void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &transpose)
{
    visited[node] = true;
    for (auto nbr : transpose[node])
    {
        if (!visited[nbr])
            dfs(nbr, visited, transpose);
    }
}

//****SOLUTION****//
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // create adj ist
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // kyuki ye shirf Directed graph he
    }

    // 1. Topological Sort
    stack<int> st;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoDfs(i, st, visited, adj);
    }

    // 2. Transpose the list  && mark unvisited all nodes
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) // suppose i is U node here
    {
        visited[i] = false;
        for (auto nbr : adj[i])
        { // nbr is V node here
            transpose[nbr].push_back(i);
        }
    }

    // 3. call DFS on basis on Topological ordering
    int count = 0; // No. of SCC
    while (!st.empty())
    {
        int top = st.top();
        st.pop(); // make sure to pop the element

        if (!visited[top])
        {
            dfs(top, visited, transpose); // transpose is new Adj List
            count++;
        }
    }
    return count;
}

int main()
{

    int n;
}

/*
gfg : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/#
codeStudio : https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

*/