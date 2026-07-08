class Solution {
public:
    int countSetMSBs(int byte) {
        int c = 0;
        int mask = 128;
        while (byte & mask) {
            mask = mask >> 1;
            c++;
        }
        return c;
    }
    bool validUtf8(vector<int>& data) {
        int i = 0;
        int n = data.size();
        while (i < n) {
            int c = countSetMSBs(data[i]);
            cout << c;
            if (c == 0) { 
                i++;
            }

            else if (c== 1 || c > 4 || i + c > n) {
                return false;
            }

            else {
                i++;
                while (--c) {
                    if (data[i] < 128 || data[i] > 191) {
                        return false;
                    }
                    else i++;
                } 
            }
            
        }
        return true;
    }
};