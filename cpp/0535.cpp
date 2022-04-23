#include <string>
#include <random>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {
        for (int i = 0; i < 26; i++) {
            charset += 'a' + i;
            charset += 'A' + i;
        }
        for (int i = 0; i < 10; i++) {
            charset += '0' + i;
        }
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url2code.count(longUrl)) {
            return url2code[longUrl];
        }
        string code = "";
        for (int i = 0; i < N_CODES; i++) {
            code += charset[rd() % charset.size()];
        }
        url2code[longUrl] = code;
        code2url[code] = longUrl;
        return TINY_URL + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(TINY_URL.size(), N_CODES);
        return code2url[code];
    }

private:
    random_device rd;
    unordered_map<string, string> url2code, code2url;
    string charset = "";
    const string TINY_URL = "http://tinyurl.com/";
    const int N_CODES = 6;
};

int main() {
    Solution sol;
    cout << sol.decode(sol.encode("asdfadfadfadfasdf")) << endl;
    return 0;
}
