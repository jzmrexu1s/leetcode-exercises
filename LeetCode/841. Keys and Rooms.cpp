class Solution {
private:
    vector<bool> allkeys;
    int keyscount;
public:
    void rec(vector<vector<int>>& rooms, vector<int>& keylist) {
        for (int i = 0; i < keylist.size(); i ++) {
            int thiskey = keylist[i];
            if (allkeys[thiskey] == false) {
                allkeys[thiskey] = true;
                keyscount ++;
                rec(rooms, rooms[thiskey]);
            }

        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); i ++) {
            allkeys.push_back(false);
        }
        allkeys[0] = true;
        keyscount = 1;
        rec(rooms, rooms[0]);
        // cout << keyscount;
        return keyscount == rooms.size();
    }
};