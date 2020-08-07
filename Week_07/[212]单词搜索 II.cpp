//给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
// 
//
// 示例: 
//
// 输入: 
//words = ["oath","pea","eat","rain"] and board =
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]
//
//输出: ["eat","oath"] 
//
// 说明: 
//你可以假设所有输入都由小写字母 a-z 组成。 
//
// 提示: 
//
// 
// 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？ 
// 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何
//实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。 
// 
// Related Topics 字典树 回溯算法 
// 👍 208 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//
//    }
//};

//class Solution {
//public:
//    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//        unordered_map<char, unordered_set<string>> wordMap; // {first letter, whole word}
//        unordered_set<string> found;
//        // Inserts each word into map with last letter
//        for (string word : words) {
//            if (wordMap.count(word.back())) {
//                wordMap[word.back()].insert(word);
//            }
//            else {
//                wordMap.insert({ word.back(), {word} });
//            }
//        }
//        vector<string> result;
//        int M = board.size(); // Rows
//        int N = board[0].size(); // Columns
//        for (int i = 0; i < M; i++) {
//            for (int j = 0; j < N; j++) {
//                char currentLetter = board[i][j];
//                if (wordMap.count(currentLetter) == 1) {
//                    for (string currentPossibleWord : wordMap[currentLetter]) {
//                        int letterIndex = currentPossibleWord.size() - 1;
//                        if (!found.count(currentPossibleWord) && dfs(board, currentPossibleWord, letterIndex,i, j) && currentPossibleWord != "") {
//                            result.push_back(currentPossibleWord);
//                            found.insert(currentPossibleWord);
//                        }
//                    }
//                }
//            }
//        }
//        return result;
//    }
//
//    bool dfs(vector<vector<char>> &board, string &word, int letterIndex, int i, int j) {
//        // If we've found the whole word in the board
//        if (letterIndex == -1) {
//            return true;
//        }
//        if (!inside(board, word, letterIndex, i, j)) {
//            return false;
//        }
//        // Save original letter for next searches
//        char previousLetter = board[i][j];
//        // Mark letter as visited on board
//        board[i][j] = '*';
//        // Decrease the last letter index
//        letterIndex--;
//        // Keep searching
//        // Backtracking (Revert back previous letter)
//        bool result = dfs(board, word, letterIndex, i + 1, j)
//                      || dfs(board, word, letterIndex, i - 1, j)
//                      || dfs(board, word, letterIndex, i, j + 1)
//                      || dfs(board, word, letterIndex, i, j - 1);
//        board[i][j] = previousLetter;
//        return result;
//    }
//
//    // Checks borders if we are inside of the grid and check letter if valid
//    bool inside(vector<vector<char>> &board, string &word, int letterIndex, int &i, int &j) {
//        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || word[letterIndex] != board[i][j]) {
//            return false;
//        }
//        return true;
//    }
//};

struct node{
    node* child[26]={0};
    int isleaf=-1;
};

class trie{
public:
    node* root;
    trie() {
        root = new node;
    }
    void insert(string&word,int k){
        int i, j;
        node* p;
        for(i = 0,p = root;i < word.size(); i++){
            j = word[i] - 'a';
            if(!p->child[j]) p->child[j] = new node;
            p = p->child[j];
        }
        p->isleaf = k;
    }
};

class Solution {
    int m, n;
    bitset<1<<15>inside;
    int used[10][10]={0};
public:
    void dfs(node*root,int i,int j,vector<vector<char>>&board){
        used[i][j] = 1;
        if(root->isleaf >= 0){
            inside.set(root->isleaf);
        }
        if(i) {
            node* p = root->child[board[i-1][j]-'a'];
            if(p && !used[i-1][j]) dfs(p, i - 1, j, board);
        }
        if(i + 1 < m) {
            node* p = root->child[board[i+1][j]-'a'];
            if(p && !used[i+1][j]) dfs(p, i + 1, j, board);
        }
        if(j){
            node* p = root->child[board[i][j-1]-'a'];
            if(p && !used[i][j-1]) dfs(p, i, j - 1, board);
        }
        if(j + 1 < n){
            node* p = root->child[board[i][j+1]-'a'];
            if(p && !used[i][j+1]) dfs(p, i, j + 1, board);
        }
        used[i][j] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie t;
        m = board.size();
        n = board[0].size();
        for(int i = 0;i < words.size(); i++) t.insert(words[i], i);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                node* p = t.root->child[board[i][j] - 'a'];
                if(p) dfs(p, i, j, board);
            }
        }
        vector<string> ans;
        for (int i = 0; i < words.size(); i++){
            if(inside[i]) ans.emplace_back(words[i]);
        }
        return ans;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
