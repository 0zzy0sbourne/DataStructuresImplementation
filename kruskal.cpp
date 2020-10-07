#include <bits/stdc++.h> 

using namespace std; 
class Edge{
	public: 
		int src, dest, weight ;
}; 
class Graph
{

	public:
		int V , E ; 
		Edge* edge ; 


};  
Graph* createGraph(int vertex, int edge)
{
	Graph* graph = new Graph(); 
	graph->E=edge; 
	graph->V=vertex;
	graph->edge = new Edge[edge]; 
	return graph ;
}; 

class subset {
	public:
		int rank , parent ; 
}; 

int find(subset subsets[] , int i ) {
// uses path compression 

	if(subsets[i].parent != i)
	{
		subsets[i].parent = find(subsets , subsets[i].parent); 
	}
	return subsets[i].parent; 
}

// a function that unions two sets of x and y ( uses union by rank) 
void Union(subset subsets[], int x ,int y) 
{
	int rootx = find(subsets , x ) ; 
	int rooty = find(subsets , y ) ; 

	// smaller tree get under the bigger tree . 
	if(subsets[rootx].rank < subsets[rooty].rank)
	{
		subsets[rootx].parent = rooty ; 
	}
	else if(subsets[rooty].rank < subsets[rootx].rank) 
	{
		subsets[rooty].parent = rootx ; 
	}
	else { 
		subsets[rooty].parent = rootx ; 
		subsets[rootx].rank++;
		
	}
}


// Compare two edges according to their edges . 

int myComp(const void* a  , const void* b)
{
	Edge* a1 = (Edge*)a ; 
	Edge* b1 = (Edge*)b ; 
	return a1->weight > b1->weight; 
	
}

void Kruskal(Graph* graph)
{
	int vertexNum = graph->V; 
	Edge result[vertexNum]; 
	int i = 0  ;  // an index variable used for sorted  edges .
	int e = 0 ; // an index variable used for result

	// sort all the edges in a non-decreasing order
	
	qsort(graph->edge , graph->E , sizeof(graph->edge[0]) , myComp); 

	subset*  subsets = new subset[(vertexNum * sizeof(subset))];

	for(int m =0;m<vertexNum;m++) 
	{
		subsets[m].parent = m ; 
		subsets[m].rank = 0 ; 
	}
	while(e < vertexNum-1 && i < graph->E ) 
	{
		Edge next_edge = graph->edge[i++];
		int sourceNode = find(subsets  , next_edge.src); 
		int destNode =find(subsets  , next_edge.dest) ; 	

		if(sourceNode != destNode)
		{
			result[e++] = next_edge ; 
			Union(subsets, sourceNode , destNode); 

		}
	}


	// print the result  
	
	cout<<"Following are the edges in the constructed Graph:"<<endl ; 
	for(int k = 0;k<e;k++)
	{
		cout<<result[k].src<<"---"<<result[k].dest<<endl; 
	}

	
}
int main()
{

	int V = 6 ; 
	int E  = 9; 
	Graph* graph  = createGraph(V , E);

	graph->edge[0].src = 0 ; 
	graph->edge[0].dest = 1 ; 
	graph->edge[0].weight = 3 ; 

	graph->edge[1].src= 0 ;
	graph->edge[1].dest = 3 ; 
	graph->edge[1].weight = 2 ; 
	
	graph->edge[2].src = 0 ; 
	graph->edge[2].dest = 4 ; 
	graph->edge[2].weight = 7 ; 
	
	graph->edge[3].src = 0 ; 
	graph->edge[3].dest = 5 ; 
	graph->edge[3].weight = 1 ; 

	graph->edge[4].src = 1 ; 
	graph->edge[4].dest = 4 ; 
	graph->edge[4].weight = 4 ; 
	
	graph->edge[5].src = 1 ; 
	graph->edge[5].dest = 5 ; 
	graph->edge[5].weight = 5 ; 

	graph-> edge[6].src = 1 ; 
	graph->edge[6].dest = 2 ; 
	graph->edge[6].weight = 1 ; 

	graph->edge[7].src = 3 ; 
	graph->edge[7].dest = 2 ; 
	graph->edge[7].weight =6 ; 

	graph->edge[8].src = 4 ; 
	graph->edge[8].dest = 5 ; 
	graph->edge[8].weight = 9 ; 

	Kruskal(graph) ; 


	return 0 ; 
}
