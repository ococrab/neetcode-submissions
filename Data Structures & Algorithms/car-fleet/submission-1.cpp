#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n==0) return 0;
        vector<pair<int, double>> cars(n);
        for(int i = 0; i<n; i++){
            cars[i]={position[i], (double)speed[i]};
        }

        sort(cars.begin(), cars.end(),
        [](const pair<int, double>& a, const pair<int, double>& b){
            return a.first>b.first;
        });
        int fleets = 0;
        double curTime = 0;
        for(int i = 0; i<n; i++){
            double time = (target-cars[i].first)/cars[i].second;
            if(time>curTime){
                fleets++;
                curTime = time;
            }
        }
        return fleets;
    }
};
