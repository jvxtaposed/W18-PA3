// CSE 101 Winter 2018, PA 3
//
//Name: Jennifer Fung
// PID: A12099804
// Sources of Help: textbook, lecture on DP, PA3 slides
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __USB_CPP__
#define __USB_CPP__

#include <map>
#include "USB.hpp"
#include "TwoD_Array.hpp"

int MIN(int x, int y) { return (x < y)? x : y; }

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
	for(int itp = 1; itp <= USBsize;  itp ++){
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
	int i, j;
	int minSize = -1;

	//initialized 
	TwoD_Array<int> * arr = new TwoD_Array<int>(1,USBsize);
	for(int c = 1; c <= USBsize; c++){
		arr->at(0,c) = 0;
	}
	arr->printOut();

	for(i = 0;  i< files.size(); i++){
		for(j= 0; j< i; j++){
			/*
			if( i==0 || j==0){
				arr->at(i,j)=0;
			}
			*/
			else if(files[i] <= j){
				std::cout<<"files["<<i<<"] < "<<j<<std::endl;
				//int checkSize = files[j] + arr->at(i-1, USBsize - files-i];
				arr->at(i,j) = MIN(arr->at(i-1,j), 
					1 + arr[i-1,j-files[i]])

			}
			else{

			}
		}
	}


  return 0;
}
#endif
