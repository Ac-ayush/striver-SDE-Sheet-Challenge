#include<bits/stdc++.h>
//CodeStudio wants ans in sorted order so use Set instead 

void prepareAdjList(vector<pair<int, int>> &edges , unordered_map<int , set<int>> &adjList ){
	
	for(int i=0 ; i<edges.size() ; i++)
	{
		int u = edges[i].first ;
		int v = edges[i].second ;
		
		//bcz given graph is undirected so No need of direction 
		adjList[u].insert(v) ;
		adjList[v].insert(u) ;
		
	}
}
void bfs( unordered_map<int , set<int> > &adjList , 
		unordered_map<int , bool> &visited , vector<int> &ans , int node )
{
	queue<int> q ;
	q.push(node) ;        //puting 1st node in Q
	visited[node] = 1 ;
	
	while( !q.empty() )
	{
	    int frontNode = q.front() ;    //1. take q.front as front node 
		q.pop() ;                      //2. pop front of Q
		
		ans.push_back(frontNode) ;     //3. store frontNode into Ans 
		
		//traverse all neighbour nodes of frontNode
		for( auto i : adjList[frontNode] )
		{
			if( !visited[i] )
			{                          //4. if neighbour node is not visited
			    q.push(i) ;            //   push it into Q
				visited[i] = true ;    //5. mark nodes as visited
			}
		}
	}
}


  //main Code//
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int , set<int> > adjList ; 
	vector<int> ans ; 
	unordered_map<int , bool> visited ; //default all will FALSE 
	
	//Prepare Adjacency list 
	prepareAdjList( edges , adjList) ; 
	
	//traverse all components of a graph (for Disconnected graph )
	for(int i=0 ; i<vertex ; i++)
	{
		if( !visited[i] )	//1.if source node is not visited 
			bfs( adjList , visited , ans , i) ;	//i is NODE
	}
	return ans ; 
}
