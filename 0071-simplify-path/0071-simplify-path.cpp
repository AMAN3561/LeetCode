class Solution {
public:
    void buildAns(stack<string>& st, string &ans){
        if(st.empty()){
            return;
        } 
        string minpath = st.top();
        st.pop();
        buildAns(st, ans);
        ans += minpath;
    }
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while(i < path.length()){
            int start = i;
            int end = i + 1;
            while(end < path.length() && path[end] != '/'){
                end++;
            }
            string minpath = path.substr(start, end - start);
            i = end;
            if(minpath == "/" || minpath == "/."){
                continue;
            }
            if(minpath != "/.."){
                st.push(minpath);
            }
            else if(!st.empty()){
                st.pop();
            }
        }  
        string ans = st.empty() ? "/" : "";
        buildAns(st, ans);
        return ans;
    }
};