// https://leetcode.com/problems/word-ladder-ii/

/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.


*/


class Solution {
public:
bool able(string s,string t){
    int c=0;
    for(int i=0;i<s.length();i++)
        c+=(s[i]!=t[i]);
    return c==1;
}
void bfs(vector<vector<int>> &g,vector<int> parent[],int n,int start,int end){
    vector <int> dist(n,1005);
    queue <int> q;
    q.push(start);
    parent[start]={-1};
    dist[start]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int u:g[x]){
            if(dist[u]>dist[x]+1){
                dist[u]=dist[x]+1;
                q.push(u);
                parent[u].clear();
                parent[u].push_back(x);
            }
            else if(dist[u]==dist[x]+1)
                parent[u].push_back(x);
        }
    }
}
void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[],int node){
    if(node==-1){
        // as parent of start was -1, we've completed the backtrack
        Paths.push_back(path);
        return ;
    }
    for(auto u:parent[node]){
        path.push_back(u);
        shortestPaths(Paths,path,parent,u);
        path.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // start and end are indices of beginWord and endWord
    int n=wordList.size(),start=-1,end=-1;
    vector<vector<string>> ANS;
    for(int i=0;i<n;i++){
        if(wordList[i]==beginWord)
            start=i;
        if(wordList[i]==endWord)
            end=i;
    }
    
    // if endWord doesn't exist, return empty list
    if(end==-1)
        return ANS;
    
    // if beginWord doesn't exist, add it in start of WordList
    if(start==-1){
        wordList.emplace(wordList.begin(),beginWord);
        start=0;
        end++;
        n++;
    }
    // for each word, we're making adjency list of neighbour words (words that can be made with one letter change)
    // Paths will store all the shortest paths (formed later by backtracking)
    vector<vector<int>> g(n,vector<int>()),Paths;
    
    // storing possible parents for each word (to backtrack later), path is the current sequence (while backtracking)
    vector<int> parent[n],path;
    
    // creating adjency list for each pair of words in the wordList (including beginword)
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(able(wordList[i],wordList[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
    
    bfs(g,parent,n,start,end); 
    
    // backtracking to make shortestpaths
    shortestPaths(Paths,path,parent,end);
    for(auto u:Paths){
        vector <string> now;
        for(int i=0;i<u.size()-1;i++)
            now.push_back(wordList[u[i]]);
        reverse(now.begin(),now.end());
        now.push_back(wordList[end]);
        ANS.push_back(now);
    }
    return ANS;
}
}; 
