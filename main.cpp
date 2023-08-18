#include "AdjacencyList.h"

int main()
{
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    map<int, string> websites;
    //Create a graph object
    AdjacencyList* Created_Graph = new AdjacencyList();
    for(int i = 0; i < no_of_lines; i++)
    {
        cin >> from;
        cin >> to;
        // Do Something
       Created_Graph->InsertVertex(from, to); //help with weight
    }
    Created_Graph->PageRank(power_iterations);
}