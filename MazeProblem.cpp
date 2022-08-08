#include <stdio.h>
#include <iostream>
using namespace std;
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}
bool isSafe(int maze[N][N], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 &&
	y < N && maze[x][y] != 0)
		return true;

	return false;
}
bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };

	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		 cout<<"Solution doesn't exist";
		return false;
	}

	printSolution(sol);
	return true;
}
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	if (x == N - 1 && y == N - 1) {
		sol[x][y] = 1;
		return true;
	}
	if (isSafe(maze, x, y) == true) {
		sol[x][y] = 1;
		for (int i = 1; i <= maze[x][y] && i < N; i++) {
			if (solveMazeUtil(maze, x + i, y, sol) == true)
				return true;
			if (solveMazeUtil(maze, x, y + i, sol) == true)
				return true;
		}
		sol[x][y] = 0;
		return false;
	}

	return false;
}
int main()
{
	cout<<"Enter the values of 4X4 matrix:";
	int maze[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>maze[i][j];
		}
	}
	solveMaze(maze);
	return 0;
}
