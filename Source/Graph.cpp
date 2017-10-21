#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

#include "Graph.hpp"

using namespace std;
Graph::Graph(int vert_count)
{
	Graph::vert_count = vert_count;
	matrix = vector<vector<double>>(vert_count, vector<double>(vert_count));
}

Graph::Graph(int vert_count, double density)
{
	Graph::vert_count = vert_count;

	matrix = vector<vector<double>> (vert_count, vector<double>(vert_count));
	
	default_random_engine generator;
	uniform_real_distribution<double> density_distribution(0.0,1.0);
	uniform_real_distribution<double> weight_distribution(1.0,10.0);

	double max_neighbors = (vert_count * density);
	for(int i = 0; i < vert_count; ++i)
	{
		for(int j = 0; j < vert_count; ++j)
		{
			double prob = density_distribution(generator);
			vector<int> neighborhood = neighbors(j);
			if((prob < density) && (i != j) && ( neighborhood.size() <= max_neighbors))
			{
				double new_weight = weight_distribution(generator);
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

inline void Graph::add_edge(int x, int y, double weight)
{
	if (matrix[x][y] == 0 && matrix[y][x] == 0)
	{
		matrix[x][y] = matrix[y][x] = weight;
		edge_count++;
	}
	return;
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

int Graph::number_neighbors()
{
	int num_neighbors = 0;
	for (int p = 0; p < matrix.size(); p++)
	{
		auto neighborhood = neighbors(p);
		for (auto i : neighborhood)
		{
			num_neighbors++;
		}
	}
	return num_neighbors;
}