// CSE 101 Winter 2018, PA 3
//
// Name: Jennifer Fung
// PID: A12099804
// Sources of Help: UTdallas powerpoint slide, textbook, lecture on DP, PA3 slides
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __RODCUT_CPP__
#define __RODCUT_CPP__

#include "TwoD_Array.hpp"
#include "RodCut.hpp"
#include <iostream>

/*
//algorithm derived from a university of texas dallas powerpoint slide 
//and made relevant to the problem
        stored: array(1..n) //precalculated values are stored in there
        for in= 1 to n
            maxCost := 0
            for check= 1 to in  //Find the max cut position for the length check
                maxCost := MAX(maxCost, price[i] + stored[j-i]
            
            stored(in) := maxCost

        return stored(n) //bc the maximum cost value will already be stored there

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
				<<" store[i-j]: " << store.find(in - check - 1)->second << std::endl;
			int checkCost = prices.find(check)->second 
				+ store.find(in - check)->second;
		std::cout <<"checkCost: "<< checkCost << std::endl;
			maxCost = MAX(maxCost, checkCost);

		std::cout<<"maxCost: "<< maxCost << std::endl;
		}
		std::cout<<"inserting maxCost: "<< maxCost <<std::endl;	
		store[in] = maxCost;
	    std::cout<<"store[i]: " << store.find(in)->second<<std::endl;
	}
for(auto it= store.begin(); it != store.end(); it++){
	std::cout << "len: " << it->first <<" value: " << it->second << std::endl;
}
return store.find(length)->second;

}
#endif
