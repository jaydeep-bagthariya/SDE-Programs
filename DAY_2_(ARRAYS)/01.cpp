//      *******73. SET MATRIX ZEROES******
// (LEET CODE)
// Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?
 

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]


// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


// Brute force approach
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     for(int k=0;k<m;k++)
//                     {
//                         if(matrix[i][k]!=0)
//                             matrix[i][k]=INT_MAX;
//                     }
//                     for(int l=0;l<n;l++)
//                     {
//                         if(matrix[l][j]!=0)
//                             matrix[l][j]=INT_MAX;
//                     }
//                 }
//             }
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==INT_MAX)
//                     matrix[i][j]=0;
//             }
//         }
        
//     }
// };



// BETTER APPROACH

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         set<int> t1,t2;  you can take vector also 
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     t1.insert(i);
//                     t2.insert(j);
//                 }
//             }
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(t1.find(i)!=t1.end() || t2.find(j)!=t2.end())
//                     matrix[i][j]=0;
//             }
//         }
        
//     }
// };



// ANOTHER OPTIOMAL SOLUTION WITH NO EXTRA SPACE 


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         int col0 = 1;
        
//         for(int i=0;i<n;i++)
//         {
//             if(matrix[i][0]==0) col0 = 0;      
//             for(int j=1;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     matrix[i][0]=0;
//                     matrix[0][j]=0;
//                 }
//             }
//         }
        
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=m-1;j>=1;j--)
//             {
//                 if(matrix[i][0]==0 || matrix[0][j]==0)
//                     matrix[i][j]=0;
//             }
//              if(col0 == 0) matrix[i][0]=0;
//         }    
        
//     }
// };