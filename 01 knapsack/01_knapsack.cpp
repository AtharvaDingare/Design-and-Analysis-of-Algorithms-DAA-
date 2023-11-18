#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; // number of items
    cin>>n;
    int weights[n]; // weight of each item
    int profit[n]; // profits associated
    int bagw; // bag weight = total weight u can afford to take
    cin>>bagw;
    // input the weights
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }

    // input the profits
    for(int i=0; i<n; i++){
        cin>>profit[i];
    }

    int matrix[n][bagw+1]; // this will store profit associated with ith index and jth weight
    /*
        QUESTION TO ASK : 
        IF MY CURRENT BAG WEIGHT IS 'J' AND I HAVE ACCESS TO THE FIRST 'I' ELEMENTS , THEN WHAT IS MY ANSWER ?
        ANSWER = MAXIMUM PROFIT GIVEN ABOVE CONDITIONS
    */

    /*
        // ANSWER TO QUESTION : 

        IF YOU HAVE ACCESS TO "ONLY" 0TH INDEX , THEN ONCE YOUR BAG CAPACITY IS GREATER THAN WEIGHT OF THAT INDEX YOU WILL ALWAYS PICK
        TO GET THE PROFIT ASSOCIATED WITH IT

        IF YOU HAVE ACCESS TO MORE THAN 0TH INDEX , THEN LETS ASSUME YOU ARE ON Ith INDEX , YOU HAVE 2 OPTIONS 
        1. PICK --> IN THIS CASE YOU PICK THE ELEMENT (ONLY IF CURRENT CAPACITY IS GREATER OR EQUAL TO ITS WEIGHT) AND GET ITS PROFIT
        2. NOT PICK --> IN THIS CASE YOU DONT PICK AND HENCE DONT GET THE PROFIT ASSOCIATED

        RESULTS OF THE 2 CASES : 
        1. IF YOU DO PICK , THEN YOUR CAPACITY WILL DECREASE THIS WAY : CAPACITY = CAPACITY - WEIGHT[I] AND PROFIT = PROFIT + PROFIT[I]
           NOW , YOU HAVE TO DEAL WITH ELEMENTS FROM (I-1) TO (0) WITH THE CAPACITY LEFT

        2. IF YOU DO NOT PICK THEN YOUR CAPACITY DOES NOT INCREASE AND YOU HAVE TO DEAL WITH (I-1) TO (0) WITH WHATEVER CAPACITY YOU HAVE
    */
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=bagw; j++){
            if(i == 0){
                if(j >= weights[i]){
                    matrix[i][j] = profit[i];
                }
                else{
                    matrix[i][j] = 0;
                }
                continue;
            }
            int pick = -1 * 1e9;
            if(j >= weights[i]){
                pick = profit[i] + matrix[i-1][j - weights[i]];
            }
            int notpick = matrix[i-1][j];
            int finaloutcome = max(pick , notpick);
            matrix[i][j] = finaloutcome;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=bagw; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"final answer is : "<<matrix[n-1][bagw]<<endl;
    return 0;
}