// Villapando, raiden

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPoints(vector<int>& reward1, vector<int>& reward2, int k){
    int n = reward1.size();

    vector<pair<int, int>> diff;
    for(int i = 0; i < n; i++){
        diff.push_back({reward1[i] - reward2[i], i});
    }
    sort(diff.rbegin(), diff.rend());   
    int maxPoints = 0;
    for(int i = 0; i < k; i++){
        maxPoints += reward1[diff[i].second];
    }
    for(int i = k; i < n; i++){
        maxPoints += reward2[diff[i].second];
    } 
    return maxPoints;
}
int main (){
    vector<int> reward1_1 = {1, 1, 3, 4};
    vector<int> reward2_1 = {4, 4, 1, 1};
    vector<int> reward1_2 = {1, 1};
    vector<int> reward2_2 = {1, 1};
    int k1 =2;
    cout << "output 1 : " << maxPoints(reward1_1, reward2_1, k1) << endl;
    int k2 =2;
    cout << "output 2 : " << maxPoints(reward1_2, reward2_2, k2) << endl;

}
