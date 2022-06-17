/*
EXPLAINATION : 
    Bipartite Graph : 
    1. wo graph jisme parent node aur child node ka color same nhi hona chahiye ( baap aur bete ka color agar same he to graph biparte nhi hoga )
    2. graph me ODD cycle nhi hona chahiye (agar odd cycle hoga to kisi na kisi parent node aur child node ka color same ho jayega )
      
        
    simply hme 1 conditions check karna he :-
    1. baap(parent) aur bete(child) ka color same nhi hona chahiye. agar same he to Family(Graph) Bipartite NHI he.
    
    NOTE : ham code me color ko 0 aur 1 se represent kar rahe he 
    Approach : using dfs
        --> create a visited vector(jisme initially saare Node Unvisited rahege )
        --> create a color vector (jisme initially saare nodes ka color 0 hoga)
    
        --> if node is not visited to dfs krke check krlo
        -->DFS : 
              --> pahle curr node ko visited mark kardo 
              --> abb uske neighbour(child) par traverse krO 
                --> child ka color baap ke color ka opposite mark karo (Baap gora beta KALA (Racism hogya ji)
                --> agar beta visited nhi he to uske liye dfs call karke check karlo 
                        --> kya bete(child) aur baap(parent) ka color same he
                                --> if Yess return False (Graph se not Bipartite)
*/

class Solution {
   bool DFSisBipartite(int node, vector<int> adj[], vector<bool> &visited, vector<int> &color)
    {
        visited[node] = true;
        
        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                color[nbr] = !color[node];      //child ka color parent se alag hoga 
                if (!DFSisBipartite(nbr, adj, visited, color))
                    return false;
            }
            else
            {
                if (node != nbr && color[node] == color[nbr])       //agar baap aur bete ka color same he matlab Graph is not Bipartite 
                    return false;
            }
        }
        return true;
    }
    
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<bool> visited(V , 0) ;   
	    vector<int> color(V , 0) ;      //ye node ka color store karega 
	    
	    for(int i=0 ; i<V ; i++)
	    {
	        if( !visited[i] )
	        {
	            if( !DFSisBipartite( i , adj , visited , color) ) 
	                return false ; 
	        }
	    }
	    return true ; 
	}
};
