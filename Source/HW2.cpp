// HW2.cpp : Defines the entry point for the console application.
//

#include "Graph.hpp"
#include "Shortest.hpp"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	Graph graph(10, 0.2);
	vector<double> average(graph.V() - 1);

	//cout << "Adjacency Matrix" << endl << "---------------------------------------------" << endl;
	//graph.print_Graph();
	//cout << endl;
	cout << "Neighbors of Each Node" << endl << "-----------------------------------------" << endl;
	graph.print_neighbors();

	cout << "----------------------------------------------------------" << endl;
	for (int i = 1; i < graph.V(); i++)
	{
		vector<int> dijkstra_holder = Shortest::dijkstra(graph, 0, i);
		cout << i << ": "; 
		for (int j = 0; j < dijkstra_holder.size(); j++)
		{
			cout << dijkstra_holder[j] << " ";
		}
		cout << endl;
		average[i - 1] = Shortest::path_length(graph, 0, dijkstra_holder);
		cout << "Path Length of " << i << ": " << Shortest::path_length(graph, 0, dijkstra_holder) << endl;
	}
	
	double average_total = 0.0;
	for (int x = 0; x < average.size(); x++)
	{
		average_total += average[x];
	}

	cout << "Average of Graph Paths: " << average_total / average.size() << endl;
	cout << "Average number of neighbors per node: " << graph.number_neighbors() / graph.V();
	getchar();

	return 0;
}

