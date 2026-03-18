#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

void addEdges(int u, int v, bool isDirected, unordered_map<int, list<int>> &adj){
    adj[u].push_back(v);
     if(!isDirected){
        adj[v].push_back(u);
     }
}

void printGraph(unordered_map<int, list<int>> &adj){

    cout<<"Printing the adjacency list:-"<<endl;
    unordered_map<int, list<int>>::iterator itr;
    for(itr = adj.begin() ; itr != adj.end() ; itr++){
        cout<<itr->first<<"->";
        cout<<'[';
        list<int>::iterator itr1;
        for(itr1 = itr->second.begin() ; itr1 != itr->second.end() ; itr1++){
            cout<<*itr1;
            if(next(itr1) != itr->second.end()){
                cout<<", ";
            }
        }
        cout<<']';
        putchar('\n');
    }
}

int main(){
    unordered_map<int, list<int>> adj;
    int num;
    bool isDirected;
    cout<<"Enter the number of edges in the graph: ";
    cin>>num;
    cout<<"Is it a directed graph? ";
    cin>>isDirected;
    for(int i = 0 ; i < num ; i++){
     int u, v;
     cout<<"Enter the first node for "<<(i + 1)<<"th edge: ";
     cin>>u;
     cout<<"Enter the second node for "<<(i + 1)<<"th edge: ";
     cin>>v;
     addEdges(u, v, isDirected, adj);
    }

    printGraph(adj);

    return 0;
}