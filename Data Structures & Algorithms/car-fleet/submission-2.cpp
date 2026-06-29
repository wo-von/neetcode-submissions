class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> cars;            // still O(n): needed to sort
        for (size_t i = 0; i < position.size(); i++)
            cars.push_back({(double)position[i], (double)speed[i]});
        sort(cars.rbegin(), cars.rend());            // by position, descending

        int fleets = 0;
        double curTime = 0;                          // arrival time of current leader
        for (const auto& car : cars) {
            double t = ((double)target - car.first) / car.second;
            if (t > curTime) {                       // can't catch fleet ahead → new fleet
                fleets++;
                curTime = t;
            }
        }
        return fleets;
    }
};