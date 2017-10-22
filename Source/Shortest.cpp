#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <functional>
#include <map>

#include "Graph.hpp"
#include "Shortest.hpp"

using namespace std;

vector<int> Shortest::dijkstra(Graph &graph, int source, int target)
{
	vector<double> dist(graph.V());
	dist[source] = 0.0;

	vector<int> prev(graph.V(), -1);
	vector<int> S;
	// This priority queue tracks (weight, index) and uses the comparison operator greater to make a min heap
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

	pq.push(make_pair(0.0, source));

	for (int v = 0; v < graph.V(); v++)
	{
		if (v != source) 
		{
			dist[v] = DBL_MAX;
		}
			pq.push(make_pair(dist[v], v));
	}



	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		vector<int> neighbors = graph.neighbors(u);

		if (u == target)
		{
			while(prev[u] != -1)
			{
				S.push_back(u);
				u = prev[u];
			}
			break;
		}


		for (auto v : neighbors)
		{
			double alt = dist[u] + graph.edge_weight(u, v);
			bool visited = (find(prev.begin(), prev.end(), v) != prev.end()); 
			if (alt < dist[v] && !visited)
			{
				dist[v] = alt;
				prev[v] = u;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	reverse(S.begin(), S.end());
	return S;
}

double Shortest::path_length(Graph &graph,int source,  vector<int> dijkstra_output)
{
	double path_length = 0.0;
	bool first_time = true;
	for (int i = 0; i < dijkstra_output.size(); i++)
	{
		if (first_time == true)
		{
			path_length += graph.edge_weight(0, dijkstra_output.at(i));
			first_time = false;
		}
		else {
			path_length += graph.edge_weight(dijkstra_output.at(i - 1), dijkstra_output.at(i));
		}
	}
	return path_length;
}