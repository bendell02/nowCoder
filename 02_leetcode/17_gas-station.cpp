class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int length = gas.size();
        vector<int> max_initial_gas(length, 0);
        vector<int> diff(length, 0);
        vector<bool> flags(length, true);
 
        // calc the diff
        for (int i = 0; i < length; i++) {
            diff[i] = gas[i] - cost[i];
        }
 
        // calc the max_initial_gas
        int index = 0, temp = 0;
        for (int i = 0; i < length; i++) {
            max_initial_gas[i] = diff[i];
            if (max_initial_gas[i] < 0) {
                flags[i] = false;
                continue;
            }
 
            temp = max_initial_gas[i];
            for (int j = 1; j <= length; j++) {
                index = (i + j)%length;
                temp = temp + diff[index];
                if (temp < 0) {
                    flags[i] = false;
                    break;
                }
                max_initial_gas[i] = std::max(max_initial_gas[i], temp);
            }
        }
 
        // get the max value of max_initial_gas
        std::vector<int>::iterator biggest = std::max_element(std::begin(max_initial_gas), std::end(max_initial_gas));
        index = std::distance(std::begin(max_initial_gas), biggest);
        if (flags[index]) {
            return index;
        }
        else {
            return -1;
        }
    }
};
