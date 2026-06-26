class Solution {
public:
    char symbol(int val) {
        if (val == 1) return 'I';
        if (val == 5) return 'V';
        if (val == 10) return 'X';
        if (val == 50) return 'L';
        if (val == 100) return 'C';
        if (val == 500) return 'D';
        if (val == 1000) return 'M';
        return 'Q';    
    }
    pair<int,int> get_last_non_zero_and_place_value(int n) {
        int curr = n%10;
        int curr_place = 1;
        while (n%10 == 0) {
            n = n/10;
            curr = n%10;
            curr_place *= 10;
        }
        return {curr,curr_place};
    }
    string intToRoman(int num) {
        int digits = log10(num) + 1;
        string ans;
        while (num) {
            auto [curr,place] = get_last_non_zero_and_place_value(num);
            if (curr < 4) {
                ans = string(curr,symbol(place)) + ans;
            }
            else if (curr < 9) {
                char temp = symbol(place*5);
                if (curr == 4) {
                    char pre_temp = symbol(place);
                    ans = temp + ans;
                    ans = pre_temp + ans;
                }
                else {
                    string temp2 = string(curr-5,symbol(place));
                    cout << temp2;
                    ans = temp2 + ans;
                    ans = temp + ans;
                }
            }
            else if (curr == 9){
                //ie curr == 9
                char temp = symbol(place*10);
                char pre_temp = symbol(place);
                ans = temp + ans;
                ans = pre_temp + ans;
            }
            num = num/(place*10) * (place*10);
        }
        return ans;
    }
};