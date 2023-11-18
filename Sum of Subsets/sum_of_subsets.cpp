#include<bits/stdc++.h>
using namespace std;

void printcombination(vector<int>&combination) {
    cout<<"Following are the indexes of the array whose sum generates the required target : "<<endl;
    for(int i=0; i<combination.size(); i++){
        cout<<combination[i]+1<<" ";
    }
    cout<<endl<<endl;
}

void recurse(int array[], int n, vector<int>&combination, int ind, int target) {
    if(ind == n){
        int sum = 0;
        for(int i=0; i<combination.size(); i++){
            sum += array[combination[i]];
        }
        if(sum == target){
            printcombination(combination);
        }
        return;
    }

    // pick
    combination.push_back(ind);
    recurse(array, n, combination, ind+1, target);
    combination.pop_back();
    // not pick
    recurse(array, n, combination, ind+1, target);
}

int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    int target;
    cin>>target;
    vector<int>combination;
    recurse(array, n, combination, 0, target);
    return 0;
}