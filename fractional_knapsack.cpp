#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; // number of items
    cin>>n;
    float weights[n]; // weight of each item
    float profit[n]; // profits associated
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

    pair<float,int> fractionalvalue[n]; // this is going to store profit per unit weight = profit[i] / weight[i] and then i as second element
    for(int i=0; i<n; i++){
        fractionalvalue[i] = {profit[i]/weights[i] , i};
    }

    // we need to sort fractional value array and start picking based on larger values of profit per unit weight
    sort(fractionalvalue, fractionalvalue+n);

    // now start picking from end of array (because we have sorted it) till your bag is full

    int current = bagw; // weight that is left empty in the bag (currently its all empty)
    int accumulatedProfit = 0; // profit accumulated till now

    cout<<"PICKING : ";
    for(int i=(n-1); i>=0; i--){
        int ind = fractionalvalue[i].second; // this is the index of the element (in the unsorted array) that we are about to pick.
        if(current >= weights[ind]){
            current -= weights[ind]; // we just filled weights[ind]
            accumulatedProfit += profit[ind]; // we got profit associated with 'ind'th element
            cout<<ind+1<<" "; // just printing the indexes that are being picked for formality
        }
    }
    cout<<endl;
    // entire process is done
    cout<<accumulatedProfit<<endl;
    return 0;
}