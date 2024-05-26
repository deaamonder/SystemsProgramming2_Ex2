#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace ariel{ //used in demo.cpp
    class Graph{
        private:
            vector<vector<int>> neighborsMatrix;
            bool NegativeCycles;
            bool Cycles;

        public:
            Graph(){NegativeCycles=false; Cycles=false; neighborsMatrix={};}
            Graph(vector<vector<int>> matrix){Graph(); loadGraph(matrix);}

            void loadGraph(vector<vector<int>>& matrix);
            //function that print the graph
            void printGraph();

            //function that return the weight of edge in weighted graph
            int getEdgeWeight(size_t a, size_t b) const;

            //getters and setters
            size_t get_numOfVertex();
            bool hasCycles() const;
            bool hasNegativeCycles() const;
            //set a boolean value to hasCycles
            void setCycles(bool value);
            //set a boolean value to hasNegativeCycles
            void setNegativeCycles(bool value);

            //friend helper function 
            friend int numOfEdges(Graph g);

            //friend operators 
            friend Graph operator+(Graph& g1,Graph& g2);
            friend Graph operator+=(Graph& g1,Graph& g2);
            friend Graph operator+(Graph& g);//unary plus
            friend Graph operator-(Graph& g1,Graph& g2);
            friend Graph operator-= (Graph& g1,Graph& g2);
            friend Graph operator-(Graph& g);//unary minus
            friend bool operator<(Graph& g1, Graph& g2);
            friend bool operator> (Graph& g1, Graph& g2);
            friend bool operator<=(Graph& g1, Graph& g2);
            friend bool operator>=(Graph& g1, Graph& g2);
            friend bool operator==(Graph& g1, Graph& g2);
            friend bool operator!=(Graph& g1, Graph& g2);
            friend void operator++(Graph& g);
            friend void operator--(Graph& g);
            friend void operator*=(Graph& g, int s);
            friend void operator/=(Graph& g, int s);
            friend Graph operator*(Graph& g1,Graph& g2);
            friend ostream& operator<<(ostream& out,Graph& g);
    };
}