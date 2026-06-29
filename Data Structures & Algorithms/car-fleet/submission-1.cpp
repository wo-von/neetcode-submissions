class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<float, float>> cars; // <position, speed> of each car
        for (int i = 0; i < position.size(); i++){
            cars.push_back({(float)position[i], (float)speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        vector<pair<float, float>> fleet;

        fleet.push_back(cars.front());
        for (int i = 1; i < cars.size(); i++){
            float t1, t2;
            t1 = ((float)target - cars[i].first)/cars[i].second;
            t2 = ((float)target - fleet.back().first)/fleet.back().second;
            if (t1 <= t2)
                continue;
            else fleet.push_back(cars[i]);
        }
        return fleet.size();
    }
};
