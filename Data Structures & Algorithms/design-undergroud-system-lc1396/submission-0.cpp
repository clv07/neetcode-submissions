// goal: return average time taken from startStation to endStation
// Data Structure:
// 1. Hash table: to track average time taken from startStation to endStation
// (a) key: (startStation, endStation)
// (b) value: (total time of all records, number of records)

// 2. Hash table: to track the status of customer check in and check out from different station
// - when a customer checked in, add an entry to hash table
// - when a customer checked out, delete the entry from table
// (a) key: customer
// (b) value: (startStation, time)

class UndergroundSystem {
private:
    unordered_map<string, pair<double, int>> avgTime;
    unordered_map<int, pair<string, double>> travel;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        travel[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = travel[id];
        travel.erase(id);
        string key = startStation + "," + stationName;
        
        auto it = avgTime.find(key); // if the station pair exist in the table
        if (it == avgTime.end()) avgTime[key] = {0.0, 0}; // initialize entry if not exist

        auto &[totalTime, numRecord] = avgTime[key]; 
        totalTime += t * 1.0 - startTime * 1.0; // convert to double before adding up
        ++numRecord;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        auto &[totalTime, numRecord] = avgTime[key];
        return totalTime / numRecord;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */