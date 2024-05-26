#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;
namespace ariel{
    void Graph::loadGraph(vector<vector<int>>& graph){
        for(size_t i=0;i<graph.size();i++){
            if(graph.size() != graph[i].size()){
                cout << "the matrix is not square" << endl;
                return;
            }
            
        }
        this->neighborsMatrix = graph;
        this->NegativeCycles = false;
        this->Cycles = false;
    }

    void Graph::printGraph(){
        for (size_t i = 0; i < this->neighborsMatrix.size(); i++) {
            cout << "[";
            for (size_t j = 0; j < this->neighborsMatrix.size(); j++) {
                cout << this->neighborsMatrix[i][j];
                if (j < this->get_numOfVertex() - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
            if (i < this->get_numOfVertex() - 1) {
                cout << ", ";
            }
        }
    }

    size_t Graph::get_numOfVertex(){
        return neighborsMatrix.size();
    }

    int Graph::getEdgeWeight(size_t verA, size_t verB) const{
        return this->neighborsMatrix[verA][verB];
    }

    bool Graph::hasCycles() const{
        return this->Cycles;
    }

    bool Graph::hasNegativeCycles() const{
        return this->NegativeCycles;
    }

    void Graph::setCycles(bool value){
        this->Cycles = value;
    }

    void Graph::setNegativeCycles(bool value){
        this->NegativeCycles = value;
        this->Cycles = value;
    }

    //a function that count the number of edges
    int numOfEdges(Graph g){
        int count =0;
        for(size_t i=0; i<g.get_numOfVertex(); i++){
            for(size_t j=0; j<g.get_numOfVertex(); j++){
                if(g.neighborsMatrix[i][j]!=0){
                    count ++;
                }
            }
        }
        return count;
    }

    //overloading the operators
    Graph operator+(Graph& g1,Graph& g2){
        if(g1.get_numOfVertex() != g2.get_numOfVertex()){
            cerr << "the graphs must be the same size !";
            exit(1);
        }
        size_t size = g1.get_numOfVertex();
        vector<vector<int>> result(size, vector<int>(size));
        for(size_t i =0; i<size; i++){
            for(size_t j=0; j<size; j++){
                result[i][j] = g1.neighborsMatrix[i][j] + g2.neighborsMatrix[i][j];
            }
        }
        Graph res_graph(result);
        res_graph.Cycles = g1.hasCycles() || g2.hasCycles();
        res_graph.NegativeCycles = g1.hasNegativeCycles() || g2.hasNegativeCycles();
        return res_graph;
    }

    Graph operator+=(Graph& g1, Graph& g2){
        if(g1.get_numOfVertex() != g2.get_numOfVertex()){
            cerr << "the graphs must be the same size !";
            exit(1);
        }
        int size = g1.get_numOfVertex();
        for(size_t i=0; i<size; i++){
            for(size_t j=0; j<size; j++){
                g1.neighborsMatrix[i][j] = g1.neighborsMatrix[i][j] + g2.neighborsMatrix[i][j];
            }
        }
        return g1;
    }

    Graph operator+(Graph& g){
        return g;
    }

    Graph operator-(Graph& g1,Graph& g2){
        //same as + but - .

        if(g1.get_numOfVertex() != g2.get_numOfVertex()){
            cerr << "the graphs must be the same size !";
            exit(1);
        }
        size_t size = g1.get_numOfVertex();
        vector<vector<int>> result(size, vector<int>(size));
        for(size_t i =0; i<size; i++){
            for(size_t j=0; j<size; j++){
                result[i][j] = g1.neighborsMatrix[i][j] - g2.neighborsMatrix[i][j];
            }
        }
        Graph res_graph(result);
        res_graph.Cycles = g1.hasCycles() || g2.hasCycles();
        res_graph.NegativeCycles = g1.hasNegativeCycles() || g2.hasNegativeCycles();
        return res_graph;
    }

    Graph operator-=(Graph& g1,Graph& g2){
        //same as += but -= .

        if(g1.get_numOfVertex() != g2.get_numOfVertex()){
            cerr << "the graphs must be the same size !";
            exit(1);
        }
        int size = g1.get_numOfVertex();
        for(size_t i=0; i<size; i++){
            for(size_t j=0; j<size; j++){
                g1.neighborsMatrix[i][j] = g1.neighborsMatrix[i][j] - g2.neighborsMatrix[i][j];
            }
        }
        return g1;
    }

    Graph operator-(Graph& g){
        return g;
    }

    bool operator==(Graph& g1 ,Graph& g2){
        bool res1 = g1.get_numOfVertex() == g2.get_numOfVertex();
        bool res2 = true;
        if(res1){
            for(size_t i =0; i<g1.get_numOfVertex(); i++){
                for(size_t j =0; j<g2.get_numOfVertex(); j++){
                    if(g1.neighborsMatrix[i][j] != g2.neighborsMatrix[i][j]){
                        res2 =false;
                        break;
                    }
                }
            }
        }
        return res1 && res2;
    }

    bool operator<(Graph& g1 ,Graph& g2){
        bool res = true;
        if(g1.get_numOfVertex() < g2.get_numOfVertex()){
            for(size_t i=0; i<g1.get_numOfVertex(); i++){
                for(size_t j=0; j<g1.get_numOfVertex(); j++){
                    if(g1.neighborsMatrix[i][j] != g2.neighborsMatrix[i][j]){
                        res=false;
                        break;
                    }
                }
            }
        }
        else if(g1.get_numOfVertex() > g2.get_numOfVertex()){
            res = false;
        }
        else{
            if(numOfEdges(g1)>=numOfEdges(g2)){
                res = false;
            }
        }
        return res;
    }

    bool operator>(Graph& g1, Graph& g2){
        //the same as < but >.

        bool res = true;
        if(g1.get_numOfVertex() > g2.get_numOfVertex()){
            for(size_t i=0; i<g2.get_numOfVertex(); i++){
                for(size_t j=0; j<g2.get_numOfVertex(); j++){
                    if(g1.neighborsMatrix[i][j] != g2.neighborsMatrix[i][j]){
                        res=false;
                        break;
                    }
                }
            }
        }
        else if(g1.get_numOfVertex() < g2.get_numOfVertex()){
            res = false;
        }
        else{
            if(numOfEdges(g1)<=numOfEdges(g2)){
                res = false;
            }
        }
        return res;
    }

    bool operator<=(Graph& g1, Graph& g2){
        return g1<g2 || g1==g2;
    }

    bool operator>=(Graph& g1, Graph& g2){
        return g1>g2 || g1==g2;
    }

    bool operator!=(Graph& g1, Graph& g2){
        return !(g1==g2);
    }

    void operator++(Graph& g){
        for(size_t i=0; i<g.get_numOfVertex(); i++){
            for(size_t j=0; j<g.get_numOfVertex(); j++){
                if(g.neighborsMatrix[i][j] != 0){
                    g.neighborsMatrix[i][j]++;
                }
            }
        }
    }

    void operator--(Graph& g){
        for(size_t i=0; i<g.get_numOfVertex(); i++){
            for(size_t j=0; j<g.get_numOfVertex(); j++){
                if(g.neighborsMatrix[i][j] != 0){
                    g.neighborsMatrix[i][j]--;
                }
            }
        }
    }

    void operator*=(Graph& g, int s){
        for(size_t i=0; i<g.get_numOfVertex(); i++){
            for(size_t j=0; j<g.get_numOfVertex(); j++){
                g.neighborsMatrix[i][j] *= s;
            }
        }
    }

    void operator/=(Graph& g, int s){
        for(size_t i=0; i<g.get_numOfVertex(); i++){
            for(size_t j=0; j<g.get_numOfVertex(); j++){
                g.neighborsMatrix[i][j] *= s;
            }
        }
    }

    Graph operator*(Graph& g1, Graph& g2){
        if(g1.get_numOfVertex() != g2.get_numOfVertex()){
            cerr << "graphs must be the same size !" << endl;
            exit(1);
        }
        vector<vector<int>> result(g1.get_numOfVertex(), vector<int>(g1.get_numOfVertex()));;
        for(size_t i=0; i<g1.get_numOfVertex(); i++){
            for(size_t j=0; j<g1.get_numOfVertex(); j++){
                for(size_t k=0; k<g1.get_numOfVertex(); k++){
                    result[i][j] += g1.neighborsMatrix[i][k] * g2.neighborsMatrix[k][j];
                }
            }
        }
        Graph res(result);
        res.Cycles = g1.hasCycles() || g2.hasCycles();
        res.NegativeCycles = g1.hasNegativeCycles() || g2.hasNegativeCycles();
        return res;
    }

    ostream& operator<<(ostream& out, ariel::Graph& g) {
        for (size_t i = 0; i < g.neighborsMatrix.size(); i++) {
            out << "[";
            for (size_t j = 0; j < g.neighborsMatrix.size(); j++) {
                out << g.neighborsMatrix[i][j];
                if (j < g.get_numOfVertex() - 1) {
                    out << ", ";
                }
            }
            out << "]" << endl;
            if (i < g.get_numOfVertex() - 1) {
                out << ", ";
            }
        }
        return out;
    }
}