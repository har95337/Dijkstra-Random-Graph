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
		// Runs Dijkstra's Algorithm on a graph and requires a source and target
		// Returns vector of all previous nodes visited to reach desitination
		static vector<int> dijkstra(Graph &graph, int source, int target);

		// Gets the path length from a given source to a certain point
		// Basically this function takes the output from dijkstra and adds the index's contents
		static double path_length(Graph &graph, int source, vector<int> dijkstra_output);
};

#endif