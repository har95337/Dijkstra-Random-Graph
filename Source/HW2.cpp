// HW2.cpp : Defines the entry point for the console application.
// This file is my top level main to run Graph and Shortest
#include "Graph.hpp"
#include "Shortest.hpp"
#include <iostream>

using namespace std;

int main()
{
	Graph graph_a(50, 0.2);
	Graph graph_b(50, 0.4);


	vector<double> average_a(graph_a.V() - 1);
	vector<double> average_b(graph_b.V() - 1);

	cout << "Printing Graph with Density of 0.2" << endl;
	graph_a.print_Graph();
	cout << endl << "Neighbors of Each Node for Graph containing density of 0.2"<< endl << "-----------------------------------------" << endl;
	graph_a.print_neighbors();
	cout << "----------------------------------------------------------" << endl;

	cout << "Information for paths for Graph A containing density of 0.2" << endl << "-----------------------------------------" << endl;

	for (int i = 1; i < graph_a.V(); i++)
	{
		vector<int> dijkstra_holder = Shortest::dijkstra(graph_a, 0, i);
		cout << i << ": "; 
		for (int j = 0; j < dijkstra_holder.size(); j++)
		{
			cout << dijkstra_holder[j] << " ";
		}
		cout << endl;
		average_a[i - 1] = Shortest::path_length(graph_a, 0, dijkstra_holder);
		cout << "Path Length of " << i << ": " << Shortest::path_length(graph_a, 0, dijkstra_holder) << endl;
	}
	
	double average_total_a = 0.0;
	for (int x = 0; x < average_a.size(); x++)
	{
		average_total_a += average_a[x];
	}

	cout << endl << "Average of Graph Paths: " << average_total_a / average_a.size() << endl;
	cout << "Average number of neighbors per node: " << graph_a.number_neighbors() / graph_a.V() << endl;
	cout << "Total number of neighbors: " << graph_a.number_neighbors() << endl;


	cout << "Printing Graph with density of 0.4" << endl;
	graph_b.print_Graph();
	cout << endl << "Neighbors of Each Node for Graph containing density of 0.4" << endl << "-----------------------------------------" << endl;
	graph_b.print_neighbors();
	cout << "----------------------------------------------------------" << endl;

	cout << "Information for paths for Graph A containing density of 0.4" << endl << "-----------------------------------------" << endl;

	for (int i = 1; i < graph_b.V(); i++)
	{
		vector<int> dijkstra_holder = Shortest::dijkstra(graph_b, 0, i);
		cout << i << ": ";
		for (int j = 0; j < dijkstra_holder.size(); j++)
		{
			cout << dijkstra_holder[j] << " ";
		}
		cout << endl;
		average_b[i - 1] = Shortest::path_length(graph_b, 0, dijkstra_holder);
		cout << "Path Length of " << i << ": " << Shortest::path_length(graph_b, 0, dijkstra_holder) << endl;
	}

	double average_total_b = 0.0;
	for (int x = 0; x < average_b.size(); x++)
	{
		average_total_b += average_b[x];
	}

	cout << endl << "Average of Graph Paths: " << average_total_b / average_b.size() << endl;
	cout << "Average number of neighbors per node: " << graph_b.number_neighbors() / graph_b.V() << endl;
	cout << "Total number of neighbors: " << graph_b.number_neighbors() << endl;
	getchar();

	return 0;
}

