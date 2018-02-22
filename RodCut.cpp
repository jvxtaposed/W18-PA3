// CSE 101 Winter 2018, PA 3
//
// Name: Jennifer Fung
// PID: A12099804
// Sources of Help: Berkeley EECS Dynamic programming lecture chapter 6, textbook, lecture DP
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __RODCUT_CPP__
#define __RODCUT_CPP__

#include "TwoD_Array.hpp"
#include "RodCut.hpp"
#include <iostream>

/*
if length == 0, then $ = 0
if length > 0 {
	max val = max(max_val, price[j])
}

*/

int rodcut(std::map<int, int> prices, int length) {
	//create a map to store precalculated values
	std::map<int, int> store;

	for(auto itp = prices.begin(); itp != prices.end(); itp ++){
		store.emplace(itp->first, 0);
	}
	//length of zero will return a cost of 0
	//store.emplace(0,0);
	int in, check;

	for(in = 1; in<= length; in++){
		int maxCost = prices.find(in)->second;
		for(check = 0; check < in; check++){
			std::cout<<"in: " << in <<" j: "<< check 
				<<" prices[j]: " << prices.find(check)->second
				<<" store[i-j-1]: " << store.find(in - check - 1)->second << std::endl;
			int checkCost = prices.find(check)->second 
				+ store.find(in - check)->second;
			maxCost = MAX(maxCost, checkCost);
		}
	std::cout<<"inserting maxCost: "<< maxCost <<std::endl;
		store[in] = maxCost;
	std::cout<<"store[i]: " << store.find(in)->second<<std::endl;

	}
for(auto it= store.begin(); it != store.end(); it++){
	std::cout << "len: " << it->first <<" value: " << it->second << std::endl;
}
return store.find(length)->second;

/*

	if(length == 1){
			total = prices.find(length);
			return total;
	}
	else(length > 0){

	}
	*/
}
#endif
