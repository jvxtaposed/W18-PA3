// CSE 101 Winter 2018, PA 3
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"
#include <iostream>

std::string s = "";
std::string backtrack( TwoD_Array<int> * T, std::string s1, std::string s2, int i, int j){
	if(i == 0 || j == 0){
		return s;
	}
	if(s1[i] == s2[j]){
	 	s.push_back(s1[i]);	
	 	
		std::cout<<"s: " << s << std::endl;
		return backtrack(T, s1, s2, i-1, j-1) + s;
	}
	if( T->at(i, j-1) > T->at(i-1, j)){
		return backtrack(T, s1, s2, i, j-1);
	}
	return backtrack(T, s1, s2, i-1, j);
}

std::string lcs(std::string s1, std::string s2) {

	int m = s1.length();
	int n = s2.length();
	std::cout<<"s1 len: " << n << std::endl;
	std::cout<<"s2 len: " << m << std::endl;
	TwoD_Array<int> * T = new TwoD_Array<int>(m,n);
	//initialize left col
	for(int i = 0; i < m; i++){
		T->at(i,0) = 0;
	}
	//initialize top row
	for(int j = 0; j < n; j++){
		T->at(0,j) = 0;
	}
	//iterate thru arr to get the length of the LCS
	for(int i = 1; i < m; i++){
		for( int j = 1; j < n; j++){
		//std::cout<< "s1[i]= "<<s1[i]<<" s2[j]= "<<s2[j] << std::endl;
			if(s1[i] == s2[j]){
				T->at(i,j) = T->at(i-1, j-1) + 1;
			}
			else{
				T->at(i,j) = MAX(T->at(i,j-1), T->at(i-1,j));
			}
		}
	}
	T->printOut();

	//now time to RETURN THE LETTERS!!!!!
	backtrack(T, s1, s2, m, n);

  return s;
}
#endif
