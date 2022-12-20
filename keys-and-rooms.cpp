class Solution {
public:
    int total;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        total = 0;
        bool visited[rooms.size()];
        for (int i = 0; i < rooms.size(); i++) {
            visited[i] = false;
        }

        queue<int> room_q;
        room_q.push(0);
        while (!room_q.empty()) {
            int temp = room_q.front();
            room_q.pop();
            if (!visited[temp]) {
                total += 1;
                visited[temp] = true;
            }

            for (int j : rooms[temp]) {
                if (!visited[j]) {
                    room_q.push(j);
                    visited[j] = true;
                    total += 1;
                }
            }
        }
        return total == rooms.size();
    }
    
};
