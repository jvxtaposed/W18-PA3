// CSE 101 Winter 2018, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"


std::string backtrack( TwoD_Array<int> * T, std::string s1, std::string s2, int i, int j){
	std::string s;
	if(i == 0 || j == 0){
		return "";
	}
	if(s1.at(i) == s2.at(j)){
	 	s.push_back(s1.at(i));	
		return backtrack(T, s1, s2, i-1, j-1) + s;
	}
	if( T->at(i, j-1) > T->at(i-1, j)){
		return backtrack(T, s1, s2, i, j-1);
	}
	return backtrack(T, s1, s2, i-1, j);
}

std::string lcs(std::string s1, std::string s2) {

	int n = s1.length();
	int m = s2.length();

	TwoD_Array<int> * T = new TwoD_Array<int>(m+1,n+1);
	//initialize left col
	for(int i = 0; i < m; i++){
		T->at(i,0) = 0;
	}
	//initialize top row
	for(int c = 0; c < n; c++){
		T->at(0,c) = 0;
	}
	//iterate thru arr to get the length of the LCS
	for(int i = 1; i < n; i++){
		for( int j = 1; j < m; j++){
			if(s1.at(i) == s2.at(i)){
				T->at(i,j) = T->at(i-1, j-1) + 1;
			}
			else{
				T->at(i,j) = MAX(T->at(i,j-1), T->at(i-1,j));
			}
		}
	}

	//now time to 
	backtrack(T, s1, s2, m, n);

  return "";
}
#endif
