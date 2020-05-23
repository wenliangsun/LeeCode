#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class LeeCode929 {
   public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash;
        for (auto email : emails) {
            int at = email.find('@');
            string name;
            for (auto c : email.substr(0, at)) {
                if (c == '+') break;
                if (c == '.') continue;
                name += c;
            }
            string domain = email.substr(at + 1);
            hash.insert(name + '@' + domain);
        }
        return hash.size();
    }
};