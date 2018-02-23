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

int MAX(int x, int y) { return (x > y)? x : y; }

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
	for(int itp = 0; itp < USBsize;  itp ++){
		store.emplace(itp, -1);
	}
	for(auto it = store.begin(); it != store.end(); it++){
		std::cout<<"aux("<<store.find(*it)->first<<"): "
			<<store.find(*it)->second<<std::endl;
	}

	//before going into for loop, chck if it's already in the tabulated aux map
	if(store.find(USBsize)->first != -1){
		return store.find(USBsize)->second + min;
	}
	else{
		for (auto it = files.begin(); it != files.end(); ++it) {
	    	if (USBsize == *it) {   // 1 is the minimum number of possible files
	     		return 1;
	    	}
	    	else if (USBsize > *it) {
	    		//store it into the auxiliary for later use
	    		store[USBsize] = *it;
	    		// assume per the problem statement that the USB size is always met
	    		int files_used = find_files_naive(USBsize - *it, files) + 1;
	    		if (min == -1 || (files_used < min && files_used > 0)) {
	       			min = files_used;
	    		}
	   		}
	    // do nothing if file size is larger than the USB size
		}
	}
  return min;
}





int find_files_dp(int USBsize, std::vector<int>& files) {
	TwoD_Array<int> * arr = new TwoD_Array<int>()
  return 0;
}
#endif
