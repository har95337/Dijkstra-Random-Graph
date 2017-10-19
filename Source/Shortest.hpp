#ifndef Shortest_H
#define Shortest_H

#include <vector>
#include <queue>
#include <map>
#include "Graph.hpp"

using namespace std;

class Shortest
{
	public: 
		static vector<int> dijkstra(Graph &graph, int source, int target);

		static double path_length(Graph &graph, int source, vector<int> dijkstra_output);
};

#endif