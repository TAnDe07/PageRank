//
// Created by tanaD on 10/25/2022.
//

#ifndef COP3530PAGERANK_ADJACENCYLIST_H
#define COP3530PAGERANK_ADJACENCYLIST_H

#endif //COP3530PAGERANK_ADJACENCYLIST_H
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class AdjacencyList {
private:
    //Think about what member variables you need to initialize
    map<string,  vector<pair<string, float>>> graph;

public:
    //Think about what helper functions you will need in the algorithm
    void InsertVertex (string from, string to);
    float CalcWeight (string from, map<string,  vector<pair<string, float>>> &graph);
    vector<pair<string, float>> PageRank(int n);
    bool SearchKey(string to, map<string,  vector<pair<string, float>>> graph);
};

bool AdjacencyList::SearchKey(std::string from, map<std::string, vector<pair<std::string, float>>> graph) {
    map<string,  vector<pair<string, float>>> :: iterator itr;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        //if the key exists, add pair (to, rank) to key
        if (itr->first == from) {
           return true;
        }
    }
    return false;
}
void AdjacencyList::InsertVertex(string from, string to) {
    bool exists = false;
    vector<pair<string, float>> temp;
    //if empty insert first element in graph
    if (graph.empty()) {
        temp.emplace_back(from, CalcWeight(from, graph));
        graph[to] = temp;
        graph[from] = {};
    }
    //if graph is not empty
    else if (!graph.empty()) {
        map<string,  vector<pair<string, float>>> :: iterator itr;
        //look for the key (from) in graph,
        for (itr = graph.begin(); itr != graph.end(); itr++) {
            //if the key exists, add pair (to, rank) to key
            if (itr->first == to) {
                exists = true;
                itr->second.emplace_back(from, CalcWeight(from, graph));
                //if to (key) does not exist in graph, create empty element
                if (!SearchKey(from, graph)) {
                    graph[from] = {};
                }
                break;
            }
        }
        //if the key does not exist, add a new key
        if (!exists) {
            temp.emplace_back(from, CalcWeight(from, graph));
            graph[to] = temp;
            //if to (key) does not exist in graph, create empty element
            if (!SearchKey(from, graph)) {
                graph[from] = {};
            }

        }
    }
}

//fix after lecture
float AdjacencyList::CalcWeight(std::string from, map<string,  vector<pair<string, float>>> & graph) {
    int occurrence = 1;
    float rank = 0;
    if (graph.empty()) {
        return 1.0/occurrence;
    }
    else {
        map<string, vector<pair<string, float>>>::iterator itr;
        for (itr = graph.begin(); itr != graph.end(); itr++) {
            for (int i = 0; i < itr->second.size(); ++i) {
                if (itr->second.at(i).first == from) {
                    occurrence++;
                }
            }
        }
        rank = 1.0/occurrence;

        for (itr = graph.begin(); itr != graph.end(); itr++) {
            for (int i = 0; i < itr->second.size(); ++i) {
                if (itr->second.at(i).first == from) {
                    itr->second.at(i).second = rank;
                }
            }
        }
    }
        return rank;
}

//change to void
vector<pair<string, float>> AdjacencyList::PageRank(int n){
    float normalRank = 1.0/graph.size();
    float finalRank = 0;
    float tempRank = 0;
    vector<pair<string, float>> sortedRank;
    vector<float> rankNum;
    int index = 0;
    for(auto member: graph) {
        sortedRank.emplace_back(member.first, normalRank);
        rankNum.push_back(normalRank);
    }

    map<string, vector<pair<string, float>>>::iterator itr;
    for (int k = 1; k < n; ++k) {
        for (itr = graph.begin(); itr != graph.end(); itr++) {
            for (int i = 0; i < itr->second.size(); ++i) {
                for (int j = 0; j < sortedRank.size(); ++j) {
                    if (itr->second.at(i).first == sortedRank.at(j).first) {
                        tempRank = rankNum.at(j);
                        break;
                    }
                }
                finalRank +=(itr->second.at(i).second * tempRank);
            }
            sortedRank.at(index).first = itr->first;
            sortedRank.at(index).second = finalRank;
            index++;
            finalRank = 0;
        }
        for (int i = 0; i < sortedRank.size(); ++i) {
            rankNum.at(i) = sortedRank.at(i).second;
        }
        index = 0;

    }

    for(auto member: sortedRank) {
        cout << member.first << " ";
        cout << fixed << setprecision(2) << member.second << endl;
    }
return sortedRank;
}
// This class and method are optional. To accept the input, you can use this method:

