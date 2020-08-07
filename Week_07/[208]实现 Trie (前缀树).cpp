//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。 
//
// 示例: 
//
// Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");   
//trie.search("app");     // 返回 true 
//
// 说明: 
//
// 
// 你可以假设所有的输入都是由小写字母 a-z 构成的。 
// 保证所有输入均为非空字符串。 
// 
// Related Topics 设计 字典树 
// 👍 362 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Trie {
//private:
//    bool isEnd;
//    Trie* next[26];
//public:
//    /** Initialize your data structure here. */
//    Trie() {
//        isEnd = false;
//        memset(next, 0, sizeof(next));
//    }
//
//    /** Inserts a word into the trie. */
//    void insert(string word) {
//        Trie* node = this;
//        for (char c : word) {
//            if (node->next[c - 'a'] == NULL) {
//                node->next[c - 'a'] = new Trie();
//            }
//            node = node->next[c - 'a'];
//        }
//        node->isEnd = true;
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) {
//        Trie* node = this;
//        for (char c : word) {
//            node = node->next[c - 'a'];
//            if (node == NULL) {
//                return false;
//            }
//        }
//        return node->isEnd;
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix) {
//        Trie* node = this;
//        for (char c : prefix) {
//            node = node->next[c - 'a'];
//            if (node == NULL) {
//                return false;
//            }
//        }
//        return true;
//    }
//};


class Trie {
private:
    Trie* child[26];
    bool isword;
public:
    /** Initialize your data structure here. */
    Trie() {
        isword=false;
        for(int i=0;i<26;i++)
            child[i]=nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* trie=this;
        for(char& c:word){
            int id=c-'a';
            if(!trie->child[id]) trie->child[id]=new Trie();
            trie=trie->child[id];
        }

        trie->isword=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* trie=this;
        for(auto& c:word){
            int id=c-'a';
            if(!trie->child[id]) return false;
            trie=trie->child[id];
        }

        return trie->isword;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* trie=this;
        for(auto& c:prefix){
            int id=c-'a';
            if(!trie->child[id]) return false;
            trie=trie->child[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



//leetcode submit region end(Prohibit modification and deletion)
