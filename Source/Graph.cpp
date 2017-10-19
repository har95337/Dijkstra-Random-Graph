#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <algorithm>

#include "Graph.hpp"

using namespace std;
Graph::Graph(int vert_count, double density)
{
	Graph::vert_count = vert_count;

	matrix = vector<vector<int>> (vert_count, vector<int>(vert_count));
	
	default_random_engine generator;
	uniform_real_distribution<double> density_distribution(0.0,1.0);
	uniform_int_distribution<int> weight_distribution(0,10);
	
	for(int i = 0; i < vert_count; ++i)
	{
		for(int j = 0; j < vert_count; ++j)
		{
			double prob = density_distribution(generator);
			if((prob <= density) && (i != j))
			{
				int new_weight = weight_distribution(generator);
				add_edge(i, j, new_weight);
			}
		}
	}
}

vector<int> Graph::neighbors(int x)
{
	vector<int> container(matrix.size());
	
	for(int i = 0; i < matrix.size(); i++)
	{
		if(matrix[x][i] != 0.0) container[i] = i;
		else container[i] = -1;
	}
	container.erase(remove(container.begin(), container.end(), -1), container.end());
	container.shrink_to_fit();
	return container;
}

inline void Graph::add_edge(int x, int y, int weight)
{
	matrix[x][y] = matrix[y][x] = weight;
	edge_count++;
}

inline bool Graph::adjacent(int x, int y)
{
	if((matrix[x][y] != 0.0) && (matrix[y][x] != 0.0))
	{
		return true;
	}
	return false;
}

inline void Graph::delete_edge(int x, int y)
{
	matrix[x][y] = matrix[y][x] = 0;
	edge_count--;
}

void Graph::print_Graph()
{
	for (int i = 0; i < matrix.size() ; i++)
	{
		cout << i << ": ";
		 for (int j = 0; j < matrix.size(); j++)
		 {
 			cout << matrix[i][j] << ' ';
		 }
		 cout << endl;
	}
}

void Graph::print_neighbors()
{
	for(int p = 0; p < matrix.size(); p++)
	{
		auto neighborhood = neighbors(p);
		cout << p << ": ";
		for(auto i: neighborhood)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
}