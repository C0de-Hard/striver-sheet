class Solution {
public:
    string mul(int digit, string& num) {
        if (digit == 0) return "0";
        int n = num.size();

        string ans = "";
        int carry = 0;
        for (int i = n-1; i >= 0; i--) {
            int curr = (num[i]-'0')*digit;
            if (carry > 0) {
                curr += carry;
                carry = 0;
            }
            if (curr >= 10) {
                carry = curr/10;
                curr = curr%10;
            }
            ans =  to_string(curr) + ans;
        }
        if (carry > 0) ans = to_string(carry) + ans;
        return ans;
    }
    string add(string& a, string& b) {
        int n1 = a.size(), n2 = b.size();
        if (n1 < n2) return add(b,a);
        // if (b == "0") return a;

        int i = n1-1, j = n2-1;
        bool carry = false;
        while (i >= 0 && j >= 0) {
            int sum = (a[i]-'0') + (b[j]-'0');
            if (carry) {
                carry = false;
                sum++;
            }
            if (sum >= 10) {
                carry = true;
                sum = sum%10;
            }
            a[i] = sum+'0';
            i--,j--;
        }
        while (carry) {
            if (i < 0) {
                a = '1' + a;
                carry = false;
            }
            else {
                int sum = (a[i]-'0') + carry;
                carry = false;
                if (sum >= 10) {
                    carry = true;
                    sum = sum%10;
                }
                a[i--] = sum+'0';
            }
        }
        return a;
    }
    string multiply(string num1, string num2) {
        string ans;
        int zeroes_req = num1.size()-1;
        for (char ch : num1) {
            string tmp = mul(ch-'0',num2);
            if (tmp != "0" && zeroes_req > 0) {
                for (int z = 1; z <= zeroes_req; z++) {
                    tmp += '0';
                }
            }
            zeroes_req--;
            ans = add(ans,tmp);
        }
        return ans;
    }
};