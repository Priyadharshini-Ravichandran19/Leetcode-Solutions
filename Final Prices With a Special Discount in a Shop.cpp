
1475. Final Prices With a Special Discount in a Shop

Difficulty: Easy
Topics: Array, Stack, Monotonic Stack

Problem Description

You are given an integer array prices where prices[i] represents the price of the \(i^{th}\) item in a shop.
There is a special discount for items in the shop. If you buy the \(i^{th}\)
item, you will receive a discount equivalent to prices[j], where j is the minimum index such that j > i
and prices[j] <= prices[i]. In other words, the discount is the price of the first item to the right that costs less than 
or equal to the current item.
If no such item exists, you will not receive any discount for the \(i^{th}\) item.
Return an integer array answer where answer[i] is the final price you will pay
for the \(i^{th}\) item of the shop, considering the special discount.

Example 1

Input:
prices = [8, 4, 6, 2, 3]

Output:
[4, 2, 4, 2, 3]


'''Solution'''
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>res(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                res[i]=prices[i]-st.top();
            }else{
                res[i]=prices[i];
            }
            st.push(prices[i]);
        }
        return res;
    }
};
