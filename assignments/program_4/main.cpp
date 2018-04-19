
///////////////////////////////////////////////////////////////////////////////
//             
// Title:            Spanning Tree 
// Files:            csv.h, distance.h, edge_heap.h, main.cpp, filtered_cities.csv
// Semester:         Spring 2018
//
// Author:           Ashma Henry
// Email:            geneve.ash@gmail.com
// Description:
//       This program creates a graph structure with cities as Vertices and no Edges initially. 
//       It then connects the cities by adding edges between cities that are close 
//       together. It also ensures that city is reachable by ensuring that each vertex 
//       has a max degree of 3, where each edge represents one of three closest cities to that vertex.
/////////////////////////////////////////////////////////////////////////////////

#include "graph.h"
#include <fstream>

using namespace std;

/**
* loadGraphCSV - loads a graph with the given csv
* Params:
*     string filename  - filename to open
* Returns
*     graph
*/
graph loadGraphCSV(string filename, int max = 0)
{
	// declaration of variables
	int zip;
	double lat;
	double lon;
	string city;
	string state;
	string county;


	strMapInt cityCheck;

	int i = 0;

	graph G;

	ifstream file(filename);

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		zip = stoi((*loop)[0]);
		if ((*loop)[1].length() > 0)
		{
			lat = stod((*loop)[1]);
		}
		else
		{
			lat = 0.0;
		}

		if ((*loop)[2].length() > 0)
		{
			lon = stod((*loop)[2]);
		}
		else
		{
			lon = 0.0;
		}

		city = (*loop)[3];
		state = (*loop)[4];
		county = (*loop)[5];


		if (cityCheck.find(city) == cityCheck.end())
		{
			// Add the city as a key to the map.
			cityCheck[city] = 0;

			// If statement use to get specific state
			if (state == "PR") {
				G.addVertex(city, state, lat, lon);
				i++;
			}
		}

		if (i > max && max != 0) {
			return G;
		}

	}

	return G;
}

/**
* filterDups - filters out duplicate cities and creates new output file
* Params:
*     string filename  - filename to open
*     string outfile   - filename to write to
* Returns
*     graph
*/
void filterDups(string filename, string outfile)
{
	// declaration of variables
	int zip;
	double lat;
	double lon;
	string city;
	string state;
	string county;

	strMapInt cityCheck;

	int i = 0;


	ifstream file(filename);
	ofstream out(outfile);

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		zip = stoi((*loop)[0]);
		if ((*loop)[1].length() > 0)
		{
			lat = stod((*loop)[1]);
		}
		else
		{
			lat = 0.0;
		}

		if ((*loop)[2].length() > 0)
		{
			lon = stod((*loop)[2]);
		}
		else
		{
			lon = 0.0;
		}

		city = (*loop)[3];
		state = (*loop)[4];
		county = (*loop)[5];


		if (cityCheck.find(city) == cityCheck.end())
		{
			// Add the city as a key to the map.
			cityCheck[city] = 0;
			out << zip << "," << lat << "," << lon << "," << city << "," << state << "," << county << "\n";

		}


	}

}

// Test Driver
int main(int argc, char **argv)
{
	//declaration of variables
	ofstream outfile;
	outfile.open("out.txt", ofstream::app);
	srand(984325);
	int max_vertices =18952;
	int max_edges = 300;
	int degree;
	cout << "What is your max degree? " << endl;
	cin >> degree;


	// loads graph into vertices
	graph G = loadGraphCSV("filtered_cities.csv", max_vertices);



	//G.printGraph();
	//cout << G.searchGraph("truro") << endl;

	// Prints out number of edges and miles from each state
	G.createSpanningTree("KS", degree);
	outfile << "Lebanon, Kansas" << endl;
	outfile << " " << G.createSpanningTree("KS", degree) << " miles ";
	outfile << G.num_edges << " edges" << endl << endl;

	G.createSpanningTree("FL", degree);
	outfile << "Miami, Florida" << endl;
	outfile << " " << G.createSpanningTree("FL", degree) << " miles ";
	outfile << G.num_edges << " edges" << endl << endl;

	G.createSpanningTree("TX", degree);
	outfile << "Dallas, Texas" << endl;
	outfile << " " << G.createSpanningTree("TX", degree) << " miles ";
	outfile << G.num_edges << " edges" << endl << endl;

	G.createSpanningTree("MA", degree);
	outfile << "Boston, Massachusetts" << endl;
	outfile << " " << G.createSpanningTree("MA", degree) << " miles ";
	outfile << G.num_edges << " edges" << endl << endl;


	G.createSpanningTree("PR", degree);
	outfile << "San Juan, Puerto Rico" << endl;
	outfile << " " << G.createSpanningTree("PR", degree) << " miles ";
	outfile << G.num_edges << " edges" << endl << endl;



	cout<<G.graphViz(true);

	//G.printVids();

	int *size = G.graphSize();

	cout<<"V= "<<size[0]<<" E= "<<size[1]<<endl;

	 for(int i=0;i<G.vertexList.size();i++)
	 {
	     cout<<(*G.vertexList[i])<<endl;
	 }

	 outfile.close();
	 system("pause");

	return 0;
}
