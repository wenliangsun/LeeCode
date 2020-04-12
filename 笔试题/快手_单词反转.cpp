#include <iostream>
#include <string>

using namespace std;

/**
 * 单词反转
 *
 */

class ReverseWord {
   public:
    string reverse(string s) {
        if (s.empty()) {
            return s;
        }
        if (s[s.size() - 1] != '.') {
            return "";
        }
        int start = 0;
        int end = 0;
        string str = "";
        while (start < s.size() - 1) {
            if (s[start] == ' ') {
                start++;
                end++;
            } else if (end == s.size() - 1 || s[end] == ' ') {
                str +=
                    reverse(s.substr(start, end - start), 0, end - start - 1);
                str += ' ';
                start = ++end;
            } else {
                end++;
            }
        }
        str += '.';
        str = reverse(str, 0, str.size() - 2);
        return str.substr(1, str.size() - 1);
    }

   private:
    string reverse(string s, int start, int end) {
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};

int main() {
    string s;
    getline(cin, s);
    ReverseWord r = ReverseWord();
    string res = r.reverse(s);
    cout << res << endl;
}