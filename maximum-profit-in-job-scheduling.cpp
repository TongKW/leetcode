struct Interval
{
    int start;
    int end;
    int profit;
    Interval(int s, int e, int p) : start(s), end(e), profit(p) {}
};

struct MaxProfit
{
    int end;
    int profit;
    MaxProfit(int e, int p) : end(e), profit(p) {}
};

bool intervals_comp( const Interval& int1, const Interval& int2 ) {
    return int1.end < int2.end;
}

bool max_profits_comp( const MaxProfit& mp1, const MaxProfit& mp2 ) {
    return mp1.end < mp2.end;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for (int i = 0; i < startTime.size(); i++) {
            intervals.push_back(Interval(startTime[i], endTime[i], profit[i]));
        }
        sort(
            intervals.begin(),
            intervals.end(),
            intervals_comp
        );
        maxProfits.push_back(MaxProfit(0, 0));
        int max_profit = 0;
        for (Interval& interval : intervals) {
            auto start_it = upper_bound(
                maxProfits.begin(), 
                maxProfits.end(), 
                MaxProfit(interval.start, 0), 
                max_profits_comp
            );
            int start_pos = start_it - maxProfits.begin();
            int current_max = maxProfits[start_pos - 1].profit + interval.profit;
            MaxProfit last_mp = maxProfits.back();
            if (current_max <= last_mp.profit) continue;
            if (interval.end == last_mp.end) {
                maxProfits.pop_back();
            }
            maxProfits.push_back(MaxProfit(interval.end, current_max));
            max_profit = max(max_profit, current_max);
        }
        return max_profit;
    }
private:
    vector<Interval> intervals;
    vector<MaxProfit> maxProfits;
};
