// CSE 101 Winter 2018, PA 3
//
//Name: Jennifer Fung
// PID: A12099804
// Sources of Help: textbook, lecture on DP, PA3 slides
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"
#include <iostream>

std::string s = "";
std::string backtrack( TwoD_Array<int> * T, std::string s1, std::string s2, int i, int j){
	if(i == -1 || j == -1){
		return s;
	}
	if(s1[i] == s2[j]){
	// 	s.push_back(s1[i]);	
	 s = s1[i] + s;	
		return backtrack(T, s1, s2, i-1, j-1) + s;
	}
	if( T->at(i+1, j) > T->at(i, j+1)){
		return backtrack(T, s1, s2, i, j-1);
	}
	return backtrack(T, s1, s2, i-1, j);
}

std::string lcs(std::string s1, std::string s2) {

	int m = s1.length();
	int n = s2.length();
	TwoD_Array<int> * T = new TwoD_Array<int>(m+1,n+1);
	//initialize left col
	for(int i = 0; i <= m; i++){
		T->at(i,0) = 0;
	}
	//initialize top row
	for(int j = 0; j <= n; j++){
		T->at(0,j) = 0;
	}
	//iterate thru arr to get the length of the LCS
	for(int i = 0; i < m; i++){
		for( int j = 0; j < n; j++){
	
			if(s1[i] == s2[j]){	
				T->at(i+1,j+1) = T->at(i, j) + 1;
			}
			else{
				T->at(i+1,j+1) = MAX(T->at(i+1,j), T->at(i,j+1));
			}
		}
	}
	//T->printOut();

	//now time to RETURN THE LETTERS!!!!!
	backtrack(T, s1, s2, m, n);

  return s;
}
#endif
