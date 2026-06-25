class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> pr;
        for (int i=0; i < position.size(); i++) {
            pr.push_back({position[i], speed[i]});
        }

        // sort the position and speed in descending order of position
        sort(pr.rbegin(), pr.rend());

        // compute the time required to reach target
        // use stack to maintain times of fleet
        // if the time remaining required to reach target for car that is behind
        // is smaller than or equal to the front, then it can catch up with 
        // front car and form fleet
        vector<double> stk;
        for (auto& p: pr) {
            stk.push_back((double)(target - p.first) / p.second);
            if (stk.size() >= 2 &&
                stk.back() <= stk[stk.size()-2])
                stk.pop_back();
        }

        return stk.size();

    }
};
