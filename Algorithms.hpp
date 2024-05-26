#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Graph.hpp"

using namespace std;
namespace ariel{
    class Algorthims{
        private:
            /*here i will declare the private function that will help me in the solution*/


            /*this function get a graph and a starting vertex and runs the bellman_ford algorithm on it.
            it return a vector of int I can track the shortest path using it.*/
            static vector<size_t> bellman_ford(Graph& g, size_t start); 

            /*this function get a graph and a vertice an run the dfs algorthim on 
            *it , I used this to help me check if there is a cycle in the graph or no.
            the function return true if there is a cycle in the graph and false else.*/
            static bool DFS(Graph g,size_t current, vector<bool>& visited, vector<size_t>& parent, vector<size_t>& cycle);


            /*this function gets a graph ,a distances vector and a path vector
            * and relax all the edges , the function return the number of relaxtion 
            * preformed */
           static int RelaxEdges(Graph g, vector<int>& distances, vector<size_t>& path);

           /*
           * this function gets a graph and starting vertex and true if the graph 
           * is bipartite and false else , I used the BFS algorthim here
           * here i used number to represent the colors. more about this in the readme file
           */
           static bool isBiPartiteBFS(Graph& g, size_t start, vector<int>& color, vector<size_t>& setA, vector<size_t>& setB);  

        public:
            //Gets a graph, returns true if the graph is connected (otherwise returns false).
            static bool isConnected(Graph g);

            /*
            * The function receives a graph, a start vertex and an end vertex.
            * It returns the most light-weighted path (in case the graph is not weighted - the shortest) between the two vertices.
            * If there is no such route, the function will return -1.
            */
            static string shortestPath(Graph g, size_t a, size_t b);

            /*
            * Receives a graph and tried to print a cycle in it (if it succeeds, it will return 1).
            * If there are no circles in the graph, will return 0.
            */
            static string isContainsCycle(Graph g);

            /*
            * Gets a graph and returns the partition of the graph into a bipartite graph (if it succeeds, it will return 1).
            * If the graph cannot be partitioned, will return 0.
            *Using sort of BFS, splitting vertices into 2 sets by "coloring" them.
            * Adjacent vertices with the same color = the graph is not bipartite -> returns "0".
            * Otherwise, the graph is bipartite -> return a string with the 2 sets.
            */ 
            static string isBipartite(Graph g);

            /*
            * Gets a graph and tries to find a negative cycle (that is, a cycle whose sum of the weights of the sides is negative).
            * If such circle exists, will print it, and return 1. otherwise, there are no negative circles, return 0.
            */ 
            static string negativeCycle(Graph g);


    };
}

