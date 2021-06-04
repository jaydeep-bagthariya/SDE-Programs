//  ****** 74. Search a 2D Matrix ******

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 
// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], 
//target = 3
// Output: true

// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]],
// target = 13
// Output: false


//SOLUTION
//Treat matrix as a sorted array

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row_num,col_num;
    cin>>row_num>>col_num;

    vector<vector<int> > matrix(row_num,vector<int>(col_num));

    for(int i=0;i<row_num;i++)
        for(int j=0;j<col_num;j++)
            cin>>matrix[i][j];
    
    int target;
    cin>>target;

    // int i = 0, j = col_num-1;      //Anothor Solution

    // while(i<row_num && j>=0)
    // {
    //     if(matrix[i][j] == target)
    //     {
    //         cout << "True";
    //         return 1;
    //     }

    //     if(matrix[i][j]>target)
    //         j--;
    //     else
    //         i++;
    // }
	
	int begin = 0, end = row_num * col_num - 1;
	
	while(begin <= end){
		int mid = (begin + end) / 2;
		int mid_value = matrix[mid/col_num][mid%col_num];
		
		if( mid_value == target){
			cout << "True";
            return 0;
        }
		
		else if(mid_value < target)
			//Should move a bit further, otherwise dead loop.
			begin = mid+1;
		else
			end = mid-1;
    }
        
        cout << "False";

}