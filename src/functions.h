#pragma once
#include<iostream>
#include<ctime>
#include<vector>
#include<windows.h>
using namespace std;

vector<vector<char> > initArr(int, int);
void drawArr(vector<vector<char> >&);
void frameArr(vector<vector<char> >&);
int numOfNeighbours(vector<vector<char> >, int, int);
void willLive(vector<vector<char> >, vector<vector<char> >&, int, int);
void nextGen(vector<vector<char> >&, vector<vector<char> >&);
void clearArr(vector<vector<char> >&);
void printStartBanner();
void printEndBanner();
void printArr(vector<vector<char> >);
void chooseOption(int&, int&, int&, int&);
void waitAndClear();
void lifeCycle(int , vector<vector<char> >&, vector<vector<char> >&);
