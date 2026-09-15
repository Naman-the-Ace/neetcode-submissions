class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        string res  = "";
        unordered_map<char,vector<char>>adjList;
        unordered_map<char,int>indegree;

        for(string word:words){
            for(char c:word){
                indegree[c]=0;
            }
        }
        for(int i =0;i+1<words.size();i++){
            string w1 = words[i],w2=words[i+1];
            if(w1.length()>w2.length() && w1.substr(0,w2.length())==w2) return "";

            int l1=0,l2=0;
            while(l1<w1.length() && l2<w2.length()  && w1[l1]==w2[l2]){
                l1++;
                l2++;
            }
            if(l1<w1.length() && l2<w2.length()){
                adjList[w1[l1]].push_back(w2[l2]);
                indegree[w2[l2]]++;
            }
        }
        queue<char>q;
        for(auto it:indegree){
            if(it.second==0){
                q.push(it.first);
            }
        }
        while(!q.empty()){
            char front = q.front();
            q.pop();
            res+=front;
            for(char next:adjList[front]){
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }
        }
        return res.length()== indegree.size()?res:"";
    }
};
