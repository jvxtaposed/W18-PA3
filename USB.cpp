// CSE 101 Winter 2018, PA 3
//
//Name: Jennifer Fung
// PID: A12099804
// Sources of Help: textbook, lecture on DP, PA3 slides
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __USB_CPP__
#define __USB_CPP__

#include <vector>
#include <map>
#include "USB.hpp"
#include "TwoD_Array.hpp"

int MIN(int x, int y) { return (x > y)? x : y; }

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
	int min = -1;
	//create an aux map to tabulate w/ USB sizes as key
	for(int itp = 1; itp <= USBsize;  itp ++) {
		store.emplace(itp, 0);
	}
	/*
	for(auto it = store.begin(); it != store.end(); it++){
		std::cout<<"aux("<<it->first<<"): "
			<<it->second<<std::endl;
	}
	*/
	//before going into for loop, chck if it's already in the tabulated aux map
	if(store[USBsize] != 0){
	/*
		std::cout<<"aux("<<USBsize<<"): "
			<<store[USBsize]<<std::endl;
	*/
		return store[USBsize] + min;
	}
	
		for (auto it = files.begin(); it != files.end(); ++it) {
	    	if (USBsize == *it) {   // 1 is the minimum number of possible files
	     		return 1;
	    	}
	    	else if (USBsize > *it) {
	    		//store it into the auxiliary for later use
	    		
	    		// assume per the problem statement that the USB size is always met
	    		int files_used = find_files_memoized(USBsize - *it, files) + 1;
	    		if (min == -1 || (files_used < min && files_used > 0)) {
	       			min = files_used;
	       			store[USBsize] = files_used;
	    		}
	   		}
	    // do nothing if file size is larger than the USB size
		}
  return min;
}





int find_files_dp(int USBsize, std::vector<int>& files) {
	vector<int> val;
	int i, j;
	int minSize = -1;

	//initialized 
	TwoD_Array<int> * arr = new TwoD_Array<int>(files.size()+1 , USBsize+1);
	for(int c = 0; c < USBsize; c++){
		//initializating 0th row as INF
		arr->at(0,c) = -1;
		//push back values into val
		val[i] = files[i];
	}
	arr->printOut();

	//initializing col
	for( int f = 1; f <= files.size(); f++){
		arr->at(f,0)=0;
	}

	for(i = 0;  i< files.size(); i++){
		for(j= 0; j< USBsize ; j++){
			/*
			if( i==0 || j==0){
				arr->at(i,j)=0;
			}
			*/
				//std::cout<<"files["<<files[i]<<"] < "<<USBsize<<std::endl;
		//if 
			if(files[i] <= USBsize){
				std::cout<<"files["<<files[i]<<"] < "<<USBsize<<std::endl;
				int checkCost = val[i-1] + arr->at(i-1, j-files[i]);
				arr->at(i,j) = MIN(arr->at(i-1,j), checkCost);

			}
			else{
				arr->at(i,j) = arr->at(i-1,j);
			}
		}
	}


  return arr->at(files.size(), USBsize);
}
#endif
