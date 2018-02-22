// CSE 101 Winter 2016, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __GRID_SUM_CPP__
#define __GRID_SUM_CPP__

#include "TwoD_Array.hpp"
#include "GridSum.hpp"

// Perform the precomputation step here
GridSum::GridSum (TwoD_Array<int>& grid) {
	TwoD_Array<int> * arr = new 
		TwoD_Array<int>(grid.getNumRows(), grid.getNumCols());

	for(int i = 0; i < grid.getNumCols; i++){
		arr.at(0,i) = grid.at(0,i);
	}

	for(int i = 1; i<grid.getNumRows; i++){
		for(int j = 0; j<grid.getNumCols; j++){
			arr.at(i,j) = grid.at(i,j) + arr(i-1, j);
		}
	}

	for(int i = 0; i<grid.getNumRows; i++){
		for(int j = 1; j<grid.getNumCols; j++){
			arr.at(i,j) = arr.at(i,j) + arr(i, j-1);
		}
	}

	grid = arr;
}

// Perform the query step here
int GridSum::query (int x1, int y1, int x2, int y2) {
  return 0;
}

#endif
