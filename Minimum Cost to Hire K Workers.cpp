class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        double result = DBL_MAX; //std::numeric_limits<double>::max()
        //maximum representable finite floating-point (double) number

        for(int manager = 0; manager < n; manager++) {
            
            double managerRatio = (double)min_wage[manager]/quality[manager];

            vector<double> group;
            for(int worker = 0; worker < n; worker++) {
                double worker_wage = quality[worker] * managerRatio;
                if(worker_wage >= min_wage[worker]) {
                    group.push_back(worker_wage);
                }
            }

            if(group.size() < k)
                continue;
            
            priority_queue<double, vector<double>> pq;
            double sum = 0;

            for(double &wage : group) {
                sum += wage;
                pq.push(wage);

                if(pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }

            result = min(result, sum);

        }

        return result;
    }
};
