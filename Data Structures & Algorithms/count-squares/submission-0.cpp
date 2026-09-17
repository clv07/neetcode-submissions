class CountSquares {
    unordered_map<int, unordered_map<int, int>> cnt; // x -> y -> multiplicity
public:
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1], total = 0;
        for (auto& [x, col]: cnt) {
            if (x == px) continue; // skip zero-width squares
            int d = abs(x - px);
            for (int y: {py - d, py + d}) { // the only two valid diagonals in this column
                auto it = col.find(y);
                if (it == col.end()) continue;
                total += it->second  // (x, y) diagonal
                        * cnt[x][py] // (x, py) same column as diagonal
                        * cnt[px][y];  // (px, y) same column as query
            }
        }

        return total;
    }
};
