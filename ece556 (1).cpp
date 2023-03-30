#include "ece556.h"
#include <new>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

#define LINE_SIZE 256
int readBenchmark(const char *fileName, routingInst *rst)
{
	/*********** TO BE FILLED BY YOU **********/

	int blockages = 0;
	FILE *fp;
	char *line;
	char *field;

	line = new char[LINE_SIZE]();
	fp = fopen(fileName, "r");
	fgets(line, LINE_SIZE, fp);

	fgets(line, LINE_SIZE, fp);
	field = strtok(line, " \n\t");
	field = strtok(NULL, " \n\t");
	rst->gx = atoi(field); // Converting the field to an integer and store in the
						   // x dimension of the routing instance
	field = strtok(NULL, " \n\t");
	rst->gy = atoi(field);

	fgets(line, LINE_SIZE, fp);
	field = strtok(line, " \n\t");
	field = strtok(NULL, " \n\t");
	// the capacity of each edge
	rst->cap = atoi(field);

	fgets(line, LINE_SIZE, fp);
	field = strtok(line, " \n\t");
	field = strtok(NULL, "  \n\t");
	field = strtok(NULL, "  \n\t");
	// store as the number of nets
	rst->numNets = atoi(field);
	// Allocating the memory to store the nets in the routing instance
	rst->nets = new net[rst->numNets]();
	int net_count = 0;
	int pin_count = 0;
	for (net_count = 0; net_count < rst->numNets; net_count++)
	{
		fgets(line, LINE_SIZE, fp);
		field = strtok(line, "n \n\t");
		rst->nets[net_count].id = atoi(field);
		field = strtok(NULL, " \n\t");
		rst->nets[net_count].numPins = atoi(field);
		// Allocating the memory to store the pins in the net
		rst->nets[net_count].pins = new point[rst->nets[net_count].numPins]();

		for (pin_count = 0; pin_count < rst->nets[net_count].numPins; pin_count++)
		{
			fgets(line, LINE_SIZE, fp);
			field = strtok(line, " \n\t");
			rst->nets[net_count].pins[pin_count].x = atoi(field);
			;
			field = strtok(NULL, " \n\t");
			rst->nets[net_count].pins[pin_count].y = atoi(field);
		}
	}

	fgets(line, LINE_SIZE, fp);
	field = strtok(line, "\n");
	blockages = atoi(field);

	int *bx = new int[blockages * 2]();
	int *by = new int[blockages * 2]();
	int *bc = new int[blockages]();

	int loop1;

	for (loop1 = 0; loop1 < blockages; loop1++)
	{
		fgets(line, LINE_SIZE, fp);
		field = strtok(line, " \n\t");

		*(bx + loop1 * 2) = atoi(field);

		field = strtok(NULL, " \n\t");
		*(by + loop1 * 2) = atoi(field);

		field = strtok(NULL, " \n\t");
		*(bx + loop1 * 2 + 1) = atoi(field);

		field = strtok(NULL, " \n\t");
		*(by + loop1 * 2 + 1) = atoi(field);

		field = strtok(NULL, " \n\t");
		*(bc + loop1) = atoi(field);
	}

	// To Calculate the no. of edges
	rst->numEdges = rst->gy * (rst->gx - 1) + rst->gx * (rst->gy - 1);

	// Edge Utilization
	rst->edgeUtils = new int[rst->numEdges];

	// populating the capacities of the edges
	rst->edgeCaps = new int[rst->numEdges];

	for (loop1 = 0; loop1 < rst->numEdges; loop1++)
	{
		*(rst->edgeCaps + loop1) = 1;
	}

	// replacing blockages with new values
	for (loop1 = 0; loop1 < blockages; loop1++)
	{
		if ((*(bx + loop1 * 2) == *(bx + loop1 * 2 + 1)) && (*(by + loop1 * 2) != *(by + loop1 * 2 + 1)))
		{

			if (*(by + loop1 * 2) < *(by + loop1 * 2 + 1))
			{

				rst->edgeCaps[(rst->gy * (rst->gx - 1)) + (*(bx + loop1 * 2)) + (rst->gx * (*(by + loop1 * 2)))] = *(bc + loop1);
			}
			else
			{

				rst->edgeCaps[(rst->gy * (rst->gx - 1)) + (*(bx + loop1 * 2 + 1)) + (rst->gx * (*(by + loop1 * 2 + 1)))] = *(bc + loop1);
			}
		}

		else
		{

			if (*(bx + loop1 * 2) < *(bx + loop1 * 2 + 1))
			{

				rst->edgeCaps[((*(by + loop1 * 2)) * (rst->gx - 1)) + (*(bx + loop1 * 2))] = *(bc + loop1);
			}
			else
			{

				rst->edgeCaps[((*(by + loop1 * 2 + 1)) * (rst->gx - 1)) + (*(bx + loop1 * 2 + 1))] = *(bc + loop1);
			}
		}
	}

	return 1;
}

int solveRouting(routingInst *rst)
{
	/*********** TO BE FILLED BY YOU **********/
	int net_count;
	point P1, P2;
	int seg_count;
	int pin_count;

	for (net_count = 0; net_count < rst->numNets; net_count++)
	{
		rst->nets[net_count].nroute.numSegs = rst->nets[net_count].numPins - 1; // considering two pins of the net for a segment. So, segments=pins-1

		rst->nets[net_count].nroute.segments = new segment[rst->nets[net_count].nroute.numSegs]();
		pin_count = 0;
		for (seg_count = 0; seg_count < rst->nets[net_count].nroute.numSegs; seg_count++)
		{

			P1.x = rst->nets[net_count].pins[pin_count].x;
			P1.y = rst->nets[net_count].pins[pin_count].y;
			pin_count++;
			P2.x = rst->nets[net_count].pins[pin_count].x;
			P2.y = rst->nets[net_count].pins[pin_count].y;

			rst->nets[net_count].nroute.segments[seg_count].p1 = P1;
			rst->nets[net_count].nroute.segments[seg_count].p2 = P2;
			rst->nets[net_count].nroute.segments[seg_count].numEdges = abs(P1.x - P2.x) + abs(P1.y - P2.y);
			rst->nets[net_count].nroute.segments[seg_count].edges = new int[abs(P1.x - P2.x) + abs(P1.y - P2.y)];

			if (P1.x > P2.x)
			{
				// make sure P1.x<P2.x, because we traverse from P1 --> p2
				int temp;
				temp = P1.x;
				P1.x = P2.x;
				P2.x = temp;
			}

			if (P1.y > P2.y)
			{ // make sure P1.y<P2.y, because we traverse from P1 --> p2
				int temp;
				temp = P1.y;
				P1.y = P2.y;
				P2.y = temp;
			}

			int edge_count = 0;
			int xval;
			int yval;

			for (xval = P1.x; xval < P2.x; xval++)
			{
				*(rst->nets[net_count].nroute.segments[seg_count].edges + edge_count) =

					P1.y * (rst->gx - 1) + xval;

				edge_count++;
			}

			for (yval = P1.y; yval < P2.y; yval++)
			{
				*(rst->nets[net_count].nroute.segments[seg_count].edges + edge_count) =

					(rst->gx - 1) * (rst->gx - 1) + yval * (rst->gy - 1) + P2.x;

				edge_count++;
			}
		}
	}

	return 1;
}

int writeOutput(const char *outRouteFile, routingInst *rst)
{
	/*********** TO BE FILLED BY YOU **********/
	int i, j;
	ofstream out_stream(outRouteFile);
	if (!out_stream)
	{
		cout << "Unable to open the file" << endl;
		out_stream.close();
		return 0;
	}
	for (i = 0; i < rst->numNets; i++)
	{
		out_stream << "n" << rst->nets[i].id << endl;

		for (j = 0; j < rst->nets[i].nroute.numSegs; j++)
		{
			segment seg = rst->nets[i].nroute.segments[j];

			if (seg.p1.x == seg.p2.x || seg.p1.y == seg.p2.y)
			{
				out_stream << "(" << seg.p1.x << "," << seg.p1.y << ")-";
				out_stream << "(" << seg.p2.x << "," << seg.p2.y << ")" << endl;
			}

			else
			{
				out_stream << "(" << seg.p1.x << "," << seg.p1.y << ")-";
				out_stream << "(" << seg.p2.x << "," << seg.p1.y << ")" << endl;
				out_stream << "(" << seg.p2.x << "," << seg.p1.y << ")-";
				out_stream << "(" << seg.p2.x << "," << seg.p2.y << ")" << endl;
			}
		}
		out_stream << "!" << endl;
	}

	out_stream.close();

	return 1;
}

int release(routingInst *rst)
{
	/*********** TO BE FILLED BY YOU **********/
	// Initializing the values
	rst->cap = 0;
	rst->numEdges = 0;
	rst->gx = 0;
	rst->gy = 0;

	delete[] rst->edgeCaps;
	rst->edgeCaps = NULL;

	delete[] rst->edgeUtils;
	rst->edgeUtils = NULL;

	for (int i = 0; i < rst->numNets; i++)
	{
		delete[] rst->nets[i].pins;
	}
	rst->numNets = 0;
	rst->nets = NULL;
	return 1;
}