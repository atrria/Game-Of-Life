#include "functions.h"

const char circle='O'; // character used for live cells

vector<vector<char> > initArr(int rowSize, int collSize) //creating vector of vectors initialized with spaces - dead cells
{
	vector <vector <char> > v;
	v.resize(rowSize, vector<char>(collSize, ' '));
	return v;
}
void drawArr(vector<vector<char> > &v) //cell randomization
{
	for(int i=1; i<(int)v.size()-1; i++)
    {
    	for(int j=1; j<(int)v[i].size()-1; j++)
		{
            if(rand()%2&&rand()%2)
				v[i][j]=circle;
		}
    }
}
void frameArr(vector<vector<char> > &v) //fixing frames
{
	const int rows=v.size();
	const int colls=v[v.size()-1].size();

	v[0][0]=v[rows-2][colls-2]; //corners
	v[0][colls-1]=v[rows-2][1];
	v[rows-1][0]=v[1][colls-2];
	v[rows-1][colls-1]=v[1][1];

	for(int i=1; i<rows-1; i++) //vertical borders
	{
		v[i][0]=v[i][colls-2];
		v[i][colls-1]=v[i][1];
	}
	for(int j=1; j<colls-1; j++) //horizontal borders
	{
		v[0][j]=v[rows-2][j];
		v[rows-1][j]=v[1][j];
	}
}
int numOfNeighbours(vector<vector<char> > v, int i, int j) //number of neighbours for a given cell
{
	int nCount=0;
	if(v[i-1][j-1]==circle)
		nCount++;
	if(v[i-1][j]==circle)
		nCount++;
	if(v[i-1][j+1]==circle)
		nCount++;
	if(v[i][j-1]==circle)
		nCount++;
	if(v[i][j+1]==circle)
		nCount++;
	if(v[i+1][j-1]==circle)
		nCount++;
	if(v[i+1][j]==circle)
		nCount++;
	if(v[i+1][j+1]==circle)
		nCount++;
	return nCount;
}
void willLive(vector<vector<char> > v, vector<vector<char> > &vNew, int i, int j)  //checking surviving conditions for a given cell
{
	int neighbours=numOfNeighbours(v,i,j);
	if(v[i][j]==circle)
	{
		if(neighbours==2 || neighbours==3)
			vNew[i][j]=circle;
		else
			vNew[i][j]=' ';
	}
	else
	{
		if(neighbours==3)
			vNew[i][j]=circle;
		else
			vNew[i][j]=' ';
	}
}
void nextGen(vector<vector<char> > &v, vector<vector<char> > &vNew) //creating new generation
{
	for(int i=1; i<(int)v.size()-1; i++)
    {
    	for(int j=1; j<(int)v[i].size()-1; j++)
		{
			willLive(v,vNew,i,j);
		}
    }
}
void clearArr(vector<vector<char> > &v)
{
	for(int i=0; i<(int)v.size(); i++)
    {
    	for(int j=0; j<(int)v[i].size(); j++)
		{
			v[i][j]=' ';
		}
    }
}
void printStartBanner()
{
	cout<<"=================This is Conway's Game Of Life Simulation=================\n";
	cout<<"\tSpecify reasonable array dimensions and number of generations\n";
	cout<<"\tTo run with default (25x50, 100 generations) press 1\n";
}
void printEndBanner()
{
	cout<<"End of simulation...\n";
}
void printArr(vector<vector<char> > v)
{
    for(int i=1; i<(int)v.size()-1; i++)
    {
    	for(int j=1; j<(int)v[i].size()-1; j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
    }
}
void chooseOption(int &option, int &rowSize, int &collSize, int &gen)
{
	cin>>option;
	if(option!=1)
	{
		rowSize=option+2;
		cin>>collSize;
		collSize+=2;
		cin>>gen;
	}
}
void waitAndClear()
{
	Sleep(30);
	system("cls");
}
void lifeCycle(int gen, vector<vector<char> > &v, vector<vector<char> > &vNew)
{
	for(int i=0; i<gen; i++)
	{
		waitAndClear();
		frameArr(v);
		nextGen(v, vNew);
		printArr(vNew);
		v=vNew;
		clearArr(vNew);
	}
}
