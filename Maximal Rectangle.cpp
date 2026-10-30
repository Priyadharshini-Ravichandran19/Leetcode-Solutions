/* 85. Maximal Rectangle
(Hard)

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1
*/

'''Solution'''
  class Solution {
public:
    int largestRectangleArea(vector<int>& h)
    {
        int ml=h.size();
        int uu=0;
        stack<int>st;
        for(int i=0;i<=ml;i++)
        {
            int hh=(i==ml)?0:h[i];
            while(!st.empty() && h[st.top()]>hh)
            {
                int y=h[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
            
            uu=max(uu,y*width);
            }
                st.push(i);
        }
        return uu;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=0;
        vector<int>h(n,0);
        for(int i=0;i<m;i++)
        {
            //heights updated for each row
            for(int j=0;j<n;j++){

            if(matrix[i][j]=='1')
            {
                h[j]+=1;
            }
            else{
                h[j]=0;
            }
        }
            maxi=max(maxi,largestRectangleArea(h));
        }
        return maxi;
    }
};
