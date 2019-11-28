class Solution {
public:
    string simplifyPath(string path) {
        if (path == "") return "";
        vector<string> a;
        string name = "";
        path += '/';
        for(char c: path) {
            if (c == '/') {
                if (name != "") 
                    a.push_back(name);
                name = "";
            } else name += c;
        }
        stack<string> s;
        for(string name: a) {
            if (name == "..") {
                if (!s.empty()) s.pop();
            } else if (name != ".") s.push(name);
        }
        
        string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        if (res == "") res = "/";
        return res;
    }
};