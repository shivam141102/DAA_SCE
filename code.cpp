//APPROACH 1: GREEDY
//TIME COMPLEXITY : O(n)
//SPACE COMPLEXITY : O(n)

#include<bits/stdc++.h>
using namespace std;

    int candy(vector<int>& ratings, vector<int>& ans) {
        int n = ratings.size();
        vector<int>left(n, 1), right(n, 1);
        
        //traverse left to right and compare curr value with left side value
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1]+1;
              
         //traverse right to left and compare curr value with right side value
        for(int i = n-2; i >= 0; i--)
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1]+1;
        
        int res = 0;
        for(int i = 0; i < n; i++){
            res += max(left[i], right[i]);
            ans.push_back(max(left[i], right[i]));
        }
        return res;            
    }

    int main(){
        //TAKING INPUTS FROM USER
        int n; 
        cin>>n;
        int a;
        vector<int> ratings, ans;
        for(int i=0 ; i<n ; i++){
            cin>>a;
            ratings.push_back(a);
        }
        
        //PRINTING OUTPUT
        cout<<"Minimum number of candies reena should buy is"<<candy(ratings, ans)<<" "<<endl;
        for(auto it: ans){
            cout<<it<<" ";
        }
        return 0;
    }




//APPROACH 2: SLOPE METHOD
//TIME COMPLEXITY : O(n)
//SPACE COMPLEXITY : O(1)

#include<bits/stdc++.h>
using namespace std;

    //RETURNS SUM
    int sum(int n) {
        return (n * (n + 1)) / 2;
    }
    
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1) return ratings.size();
        
        //INITIALISING VARIABLES
        int candies = 0;
        int up = 0, down = 0;
        int prevSlope = 0;
        
        for(int i = 1; i < ratings.size(); i++) {
            
            //If increasing then 1; if decreasing then -1; if equal then 0.
            int currSlope = (ratings[i] > ratings[i-1]) ? 1 
                : (ratings[i] < ratings[i-1] ? -1 : 0);
                
            //                                       _
            //If mountain slope is changing. \_ || \/ ||  /
            if((prevSlope < 0 && currSlope >= 0) || (prevSlope > 0 && currSlope == 0)) {  
                candies = candies + sum(up) + sum(down) + max(up, down);
                // cout<<up<<" "<<down<<" "<<candies<<endl;
                up = 0; 
                down = 0;
            }
            
            //Add in up/down if slope is increasing or decreasing respectively. 
            //If it is a plain, add a candy as it is the base case.
            if(currSlope > 0) {
                up++;
            }
            else if(currSlope < 0) {
                down++;
            }
            else {
                candies++;
            }
            
            prevSlope = currSlope;
        } 
        // cout<<up<<" "<<down<<" "<<candies<<endl;
        candies = candies + sum(up) + sum(down) + (max(up, down) + 1);
        return candies;
    }
    
    int main(){
        //TAKING INPUTS FROM USER
        int n; 
        cin>>n;
        int a;
        vector<int> ratings;
        for(int i=0 ; i<n ; i++){
            cin>>a;
            ratings.push_back(a);
        }
        
        //PRINTING OUTPUT
        cout<<"Minimum number of candies reena should buy is "<<candy(ratings)<<" "<<endl;
        return 0;
    }