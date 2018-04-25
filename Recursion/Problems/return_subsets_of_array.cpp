//Given an integer array (of length n), find and return all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.
// Input format :
// Line 1 : Size of array
// Line 2 : Array elements (separated by space)

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/


#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    if(n == 0){
      output[0][0] = 0;
      // output[0][1] = "";
      return 1;
    }
  
  	int smallOutput = subset(input+1, n-1, output);
	
  	for(int i=0; i<smallOutput; i++){
      	output[i+smallOutput][0] = 1 + output[i][0];
      	output[i+smallOutput][1] = input[0];
      
      	for(int j=1; j<= output[i][0] ; j++){
          	output[i+smallOutput][j+1] = output[i][j];          	
        }
    }
  
  	return 2*smallOutput;
}

int main(){
	int size;
	cin >> size;

	int * input = new int[size];
	for(int i=0; i<size; i++){
		cin >>input[i];
	}
	
	//declare ouput array
	subset(input, size, output);

}