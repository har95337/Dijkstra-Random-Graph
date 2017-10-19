#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;
class Graph
{
	public:
		vector<vector<int>> matrix;
		
		Graph(int vert_count, double density);

		vector<int> neighbors(int x);

		inline void add_edge(int x, int y, int weight);

		inline bool adjacent(int x, int y);

		inline void delete_edge(int x, int y);

		inline int edge_weight(int x, int y) { return matrix[x][y]; };

		void print_Graph();
		
		void print_neighbors();
			
		int V() {return vert_count;};
			
		int E() {return edge_count;};
		
	private:
		const int max_weight = 10;
		
		int vert_count;
		
		int edge_count;
};

#endif