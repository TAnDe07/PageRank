/*#include "AdjacencyList.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the not_so_simple_graph directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test


TEST_CASE("Graph1", "[flag]")
{
	AdjacencyList g;
    //Graph with |E| = 1
	g.InsertVertex("URL0", "URL1");
    g.PageRank(2);


    std:: vector<pair<string, float>> pageRank  = {{"URL0", 0}, {"URL1" , 1}};
    std:: vector<pair<string, float>> actualPageRank =   g.PageRank(2);
    REQUIRE(actualPageRank == pageRank);
    REQUIRE(actualPageRank.size() == pageRank.size());
    REQUIRE(1 == 1);
}

TEST_CASE("Graph2", "[flag]")
{
    AdjacencyList g;
    //Simple Graph, a node with no inDegree
    g.InsertVertex("URL0", "URL1");
    g.InsertVertex("URL0","URL2");
    g.InsertVertex("URL1", "URL3");
    g.InsertVertex("URL1", "URL4");
    g.PageRank(3);

    std:: vector<pair<string, float>> pageRank  = {{"URL0",.6}, {"URL1",.1}, {"URL2",.1}, {"URL3",.1}, {"URL4",.1}};
    std:: vector<pair<string, float>> actualPageRank =   g.PageRank(3);
    REQUIRE(actualPageRank == pageRank);
    REQUIRE(actualPageRank.size() == pageRank.size());
    REQUIRE(1 == 1);
}

TEST_CASE("Graph3", "[flag]")
{
    AdjacencyList g;
    //Vertices pointing to each other
    g.InsertVertex("URL0", "URL1");
    g.InsertVertex("URL1","URL0");

    std:: vector<pair<string, float>> pageRank = {{"URL0", 0.5},{"URL1", 0.5}};
    std:: vector<pair<string, float>> actualPageRank =   g.PageRank(10000);
    REQUIRE(actualPageRank == pageRank);
    REQUIRE(actualPageRank.size() == pageRank.size());
    REQUIRE(1 == 1);
}

TEST_CASE("Graph4", "[flag]")
{
    AdjacencyList g;
    //Vertices pointing to each other, and vertices pointing to other vertices
    g.InsertVertex("URL0", "URL1");
    g.InsertVertex("URL1","URL4");
    g.InsertVertex("URL1","URL5");
    g.InsertVertex("URL4","URL3");
    g.InsertVertex("URL4","URL5");
    g.InsertVertex("URL2","URL4");
    g.InsertVertex("URL3","URL2");
    g.InsertVertex("URL3","URL5");
    g.InsertVertex("URL5","URL3");

    std:: vector<pair<string, float>> pageRank = {{"URL0", 0},{"URL1", 0.17}, {"URL3", 0.08},{"URL4", 0.25},{"URL5", 0.25},{"URL6", 0.25}};
    std:: vector<pair<string, float>> actualPageRank =   g.PageRank(2);
    REQUIRE(actualPageRank == pageRank);
    REQUIRE(actualPageRank.size() == pageRank.size());
    REQUIRE(1 == 1);
}

TEST_CASE("Graph5", "[flag]")
{
    AdjacencyList g;
    //ALL vertices pointing to one vertex
    g.InsertVertex("URL0", "URL1");
    g.InsertVertex("URL2","URL1");
    g.InsertVertex("URL3","URL1");
    g.InsertVertex("URL4","URL1");
    g.InsertVertex("URL5","URL1");
    g.InsertVertex("URL6","URL1");
    g.InsertVertex("URL7","URL1");
    g.InsertVertex("URL8","URL1");
    g.InsertVertex("URL9","URL1");

    std:: vector<pair<string, float>> pageRank = {{"URL0", 0},{"URL1", 1}, {"URL3", 0},{"URL4", 0},{"URL5", 0},{"URL6", 0},{"URL7", 0},{"URL8", 0},{"URL9", 0}};
    std:: vector<pair<string, float>> actualPageRank =   g.PageRank(2);
    REQUIRE(actualPageRank == pageRank);
    REQUIRE(actualPageRank.size() == pageRank.size());
    REQUIRE(1 == 1);
}

*/
