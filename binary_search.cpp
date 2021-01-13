/*By Eric 13/01/2021 -Binary search algorithm- */
#include <iostream>

using namespace std;

/* funtion prototypes
----------------------------------------------------------------------*/
int binarySearch(int array[], int left, int right, int objective);

/* main function
----------------------------------------------------------------------*/
int main(){
	int array[] = {10, 23, 34, 41, 50, 100};
	
	int objective = 100;
	int size = 6;
	
	int result = binarySearch(array, 0, size -1, objective);
	
	if (result == -1) {
		cout<< " objective: "<< objective<< " not found"<< endl;
	} else {
		cout<< " objective: "<< objective<< " found"<< " at the position "<< result<<endl;
	}
	
	return 0;
}

int binarySearch(int array[], int left, int right, int objective)
{
	if (right >= left){
		int mid = left + (right - left) / 2;	// segment the main array in half
		
		if(array[mid] == objective){
			return mid;							// position found
		}
		
		if(array[mid] > objective){				// discard the right side, keep searching from the left to the middle -1
			return binarySearch(array, left, mid - 1, objective);
		} else {								// discard the left side, keep searching from the middle + 1 to the end
			return binarySearch(array, mid + 1, right, objective);	
		}
	}
	
	return -1;									// right == left ---> number no found
}
