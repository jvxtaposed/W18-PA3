// CSE 101 Winter 2018, PA 3
//
//Name: Jennifer Fung
// PID: A12099804
// Sources of Help: textbook, lecture on DP, PA3 slides
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __USB_CPP__
#define __USB_CPP__

//#include <vector>
#include <map>
#include "USB.hpp"
#include "TwoD_Array.hpp"

int MIN(int x, int y) { return (x < y)? x : y; }
int big = 999999;

int find_files_naive(int USBsize, std::vector<int>& files) {
  int min = -1;
  for (auto it = files.begin(); it != files.end(); ++it) {
    if (USBsize == *it) {   // 1 is the minimum number of possible files
      return 1;
    }
    else if (USBsize > *it) {
      // assume per the problem statement that the USB size is always met
      int files_used = find_files_naive(USBsize - *it, files) + 1;
      if (min == -1 || (files_used < min && files_used > 0)) {
        min = files_used;
      }
    }
    // do nothing if file size is larger than the USB size
  }
  return min;
}




std::map<int, int> store;
int find_files_memoized(int USBsize, std::vector<int>& files) {
	//create an aux map to tabulate w/ USB sizes as key
	for(int itp = 1; itp <= USBsize;  itp ++) {
		store.emplace(itp, -1);
	}
	int min1 = 0;
	/*
	for(auto it = store.begin(); it != store.end(); it++){
		std::cout<<"aux("<<it->first<<"): "
			<<it->second<<std::endl;
	}
	*/
	//before going into for loop, chck if it's already in the tabulated aux map
	if(store[USBsize] != -1){
		std::cout<<"aux("<<USBsize<<"): "
			<<store[USBsize]<<" + "<< min1 << std::endl;
		return store[USBsize] + min1;
	}
	
		for (auto it = files.begin(); it != files.end(); ++it) {
	    		if (USBsize == *it) {   // 1 is the minimum number of possible files
	    	 		return 1;
	    		}
	    		else if (USBsize > *it) {
	    			//store it into the auxiliary for later use
	    		
	    			// assume per the problem statement that the USB size is always met
	    			int files_used = find_files_memoized(USBsize - *it, files) + 1;
	    			if (min1 == 0 || (files_used < min1 && files_used > 0)) {
	       				min1 = files_used;
	       				store[USBsize+1] = files_used;
	    			}
	   		}
	    // do nothing if file size is larger than the USB size
		}
	for(auto it = store.begin(); it != store.end(); it++){
		std::cout<<"key: "<<it->first<<" tab: "<<it->second<< std::endl;
	}
  return store[USBsize];
}





int find_files_dp(int USBsize, std::vector<int>& files) {
	TwoD_Array<int> * T = new TwoD_Array<int>(1, USBsize+1);
	TwoD_Array<int> * cost = new TwoD_Array<int>(1, USBsize+1);

	//initialize tabulation array to fucking infinity
	T->at(0,0) = 0;
	for(int i = 1; i <= USBsize; i++){
		T->at(0,i) = big;
	}
	//T->printOut();

	//initialize
	for(int i = 0; i <= USBsize; i++){
		cost->at(0,i) = -1;
	}
	//cost->printOut();

	//currF is the current file size
	for(int currF = 0; currF< files.size(); currF++){
		int maxCost = files[currF];
		std::cout<<"files["<<currF<<"]: "<<files[currF] << std::endl;
		//currCap is the current USB capacity
		for(int currCap = 1; currCap <= USBsize; currCap++){
			std::cout<<currF<<">="<<files[currCap] <<std::endl;
			if( currCap >= files[currF] ){
				int checkCost = 1 + T->at(0, currCap - files[currF]);
				if(T->at(0,currCap) > checkCost) {
		
					T->at(0, currCap) = checkCost;
					cost->at(0, currCap) = currF;
				//	maxCost = MIN(maxCost, checkCost);
				}
			}
		}
		T->printOut();
		//std::cout<<"storing maxCost: "<<maxCost<<" at "<< currF<<std::endl;
//		T->at(0, currCap) = maxCost;
	}
	//T->printOut();
	std::cout<<"last elem in T: "<<T->at(0,USBsize)<<std::endl;
	return T->at(0,USBsize);


}
#endif
