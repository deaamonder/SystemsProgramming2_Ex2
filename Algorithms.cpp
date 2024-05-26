#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "Algorithms.hpp"

using namespace std;
namespace ariel{
    bool Algorthims::isBiPartiteBFS(Graph& g, size_t start, vector<int>& color, vector<size_t>& setA, vector<size_t>& setB){
        queue<size_t> q;
        color[start] = 1; 
        setA.push_back(start);
        q.push(start);
        
        //the BFS
        while(!q.empty()){
            size_t vertex = q.front();
            q.pop();

            for(size_t neighbor=0; neighbor<g.get_numOfVertex(); ++neighbor){
                if(g.getEdgeWeight(vertex,neighbor)!=0){
                    if(color[neighbor] == 0){//not visited yet
                        if(color[vertex] == 1){
                            color[neighbor] = -1;
                        }
                        else{
                            color[neighbor] = 1;
                        }
                        q.push(neighbor);


                        //add neighbor to the set(A or B)
                        if(color[neighbor]==-1){
                            setB.push_back(neighbor);
                        }
                        else{
                            setA.push_back(neighbor);
                        }
                    }
                    else if(color[vertex] == color[neighbor]){
                        return false;
                    }
                }
            }
        }
        //if we got here it mean that the graph i bipartite
        return true;
    }

    bool Algorthims::DFS(Graph g, size_t current, vector<bool>& visited, vector<size_t>& parent, vector<size_t>& cycle){
        visited[current] = true;

        for(size_t neighbor=0; neighbor<g.get_numOfVertex(); ++neighbor){
            int w = g.getEdgeWeight(current,neighbor);

            if(w!=0 && parent[current] != neighbor){
                if(visited[neighbor]){
                    size_t curr = current;
                    while(curr != neighbor){
                        cycle.push_back(curr);
                        curr = parent[curr];
                    }
                    cycle.push_back(neighbor);
                    cycle.push_back(current);
                    return true;
                }
                else{
                    parent[neighbor] = current; // neighbor not visited yet
                    if(DFS(g,neighbor,visited,parent,cycle)){
                        return true;
                    }
                }
            }
        }
        //if we got here it mean that no cycles found after running the dfs
        return false;
    }

    int Algorthims::RelaxEdges(Graph g, vector<int>& distances, vector<size_t>& path){
        int result = 0;
        int AIN_SOF = INT32_MAX;
        for(size_t vertex=0; vertex<g.get_numOfVertex(); vertex++){
            for(size_t neighbor =0; neighbor<g.get_numOfVertex(); neighbor++){
                int w = g.getEdgeWeight(vertex,neighbor);
                //relaxtion step
                if(w != 0 && distances[vertex]!= AIN_SOF && distances[vertex]+w<distances[neighbor]){
                    distances[neighbor] = distances[vertex] + w;
                    path[neighbor] = vertex;
                    result++;
                }
            }
        }
        return result;
    }

    vector<size_t> Algorthims::bellman_ford(Graph& g , size_t start){
        vector<int> dis(g.get_numOfVertex(),INT32_MAX);
        vector<size_t> path(g.get_numOfVertex(),INT32_MAX);
        dis[start] = 0;

        //relax (V-1) times
        for(int i=0; i<g.get_numOfVertex()-1; ++i){
            if(RelaxEdges(g, dis, path) == 0){
                return path;
            }
        }

        //last check for negative cycles
        if(RelaxEdges(g,dis,path) > 0){
            g.setNegativeCycles(true);
        }

        if(isContainsCycle(g)!="0" || g.hasNegativeCycles()){
            return vector<size_t>(); //return an empty vector in other words
                                    //the algorthim faild
        }

        return path;
    }
    
    /*
    * to check if the graph is conected I will use the DFS algorthim
    * if the algorthim visit all the vertices of the graph it means that the 
    * graph is connected.
    */
    bool Algorthims::isConnected(Graph g){
        size_t numOfVertices = g.get_numOfVertex();

        if(numOfVertices <= 1){
            return true; //if the graph is empty or has only 1 vetex -> is connected.
        }  

        vector<bool> visited(numOfVertices,false);
        stack<size_t> s;
        s.push(0);

        //run the dfs algorthim
        while(!s.empty()){
            size_t vertex = s.top();
            s.pop();

            visited[vertex] = true;

            for(size_t n=0; n<g.get_numOfVertex(); ++n){
                if(g.getEdgeWeight(vertex,n) != 0 && !visited[n]){
                    s.push(n);//add the neighbor to the stack
                }
            }
        }

        //check if all vertices are visited
        for(size_t i =0; i<visited.size(); i++){
            if(!visited[i]){return false;}
        }
        //if we got here it mean that all the vertices are visited
        return true;
    }

    
    /*I will use the bellman-ford algorithm to find the shortest path*/
    string Algorthims::shortestPath(Graph g, size_t a, size_t b){
        vector<size_t> path = bellman_ford(g,a);

        if (path.empty() || path[b] == INT32_MAX || path[b] == INT32_MIN || path[b] == 0 || g.get_numOfVertex()<= 1) {
            return "-1";
        }

        string ans = to_string(b);
        size_t i = b;
        //we want to start from b and reach a
        while(path[i] != a){
            i = path[i];
            ans.insert(0,to_string(i) + "->");
        }
        ans.insert(0,to_string(a) + "->");
        return ans;
    }
    

    string Algorthims::isContainsCycle(Graph g){
        vector<size_t> cycle;
        vector<size_t> parent(g.get_numOfVertex(),INT32_MAX);
        vector<bool> visited(g.get_numOfVertex(),false);

        for(size_t i=0; i<g.get_numOfVertex(); ++i){
            if(!visited[i]){
                //use the DFS function I create to check if there is a cycle
                if(DFS(g,i,visited,parent,cycle)){
                    string ans = "the cycle is: ";
                    size_t iCycle = 0;//declared outside the for loop because we want to use it outside the loop
                    for(;iCycle<cycle.size()-1;++iCycle){
                        ans += to_string(cycle[iCycle]) + "->";
                    }
                    ans += to_string(cycle[iCycle]);
                    g.setCycles(true);
                    return ans;                
                }
            }
        }
        return "0";
    }

    string Algorthims::isBipartite(Graph g){
        string ans;
        vector<int> color(g.get_numOfVertex(),0);
        vector<size_t> setA;
        vector<size_t>setB;

        //running the isBiPartiteBFS
        for(size_t i=0; i<g.get_numOfVertex(); ++i){
            if(color[i] == 0){
                if(!isBiPartiteBFS(g,i,color,setA,setB)){
                    return "the graph is not BiPartite";
                }
            }
        }
        
        //if we got here it mean the graph is bipartite
        ans += "the graph isBiPartite A={";
        for(size_t i=0; i<setA.size(); ++i){
            ans+=to_string(setA[i]);
            if(i<setA.size()-1){
                ans+=", ";
            }
        }
        ans+= "}, B={";
        for(size_t i=0; i<setB.size(); ++i){
            ans+=to_string(setB[i]);
            if(i<setB.size()-1){
                ans+=", ";
            }
        }
        ans+="}";
        return ans;
    }

    string Algorthims::negativeCycle(Graph g){
        //runs bellman_ford then check if NegativeCycle is true or not
        bellman_ford(g,0);
        if(g.hasNegativeCycles()){
            return "the Graph have negative cycles";
        }
        return "the Graph dont have negative cycles";
    }
}
