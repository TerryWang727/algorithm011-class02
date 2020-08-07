学习笔记
字典树 Trie 
数据结构 
字典树，即Trie树，又称单词查找树或键树，是一种树形结构。典型应用是用于统计和排序大量的字符串(但不仅限于字符串)，所以经常被搜索引擎用于文本词频的统计。
Trie树的优点是；
最大限度的减少无谓的字符串比较，查询效率比哈希表高。
结点存储额外信息 相应的字符来指向下一个节点 
核心思想
Trie树的核心思想是空间换时间
利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的
基本性质

单词搜索2用Tire树实现的时间复杂度O(m * (4 * 3^(n-1)) )
m为网格数,n为单词最大length

// C/C++
class Trie {
    struct TrieNode {
        map<char, TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->child_table.count(word[i]) == 0)
                curr->child_table[word[i]] = new TrieNode();

            curr = curr->child_table[word[i]];
        }
        curr->end = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
private:
    TrieNode* root;
    bool find(string s, int exact_match) {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->child_table.count(s[i]) == 0)
                return false;
            else
                curr = curr->child_table[s[i]];
        }

        if (exact_match)
            return (curr->end) ? true : false;
        else
            return true;
    }
};

并查集 UnionSet
判断这两个个体是否在一个集合当中
适用场景
组团、配对问题
Group or not？基本操作
makeSet(s):建立一个新的并查集，其中包含s个单元素集合。
unionSet(x, y):如果元素x和元素y所在的集合合并，要求x和y所在的集合不相交，如果相交则不合并。
find(x):找到元素x所在的集合的代表，该操作也可以用于判断两个元素是否位于同一个集合，只要将他们各自的代表比较一下就可以了。

代码模板

// C/C++
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

//递归
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }


    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }


    int getCount() const {
        return count;
    }


private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

初级搜索
1.朴素搜索
2.优化方式:不重复(Fibonacci)、剪枝(生成括号问题)
3.搜索方向
DFS Depth First Search 深度优先搜索
BFS Breadth First Srearch 广度优先搜索
双向搜索、启发式搜索A*优先级搜索

剪枝的实现和特性
1.尽量让它去重复 尽早地剪枝
2.在搜索的方向上，进行加强


双向BFS的实现、特性
Two-ended
思路:两端往中间BFS

总结双向BFS代码模板
1.定义 begin()、end() fornt back
2.BFS开始 front and back
3.遍历front change之后in back return back
4.然后回复当前层状态

启发式搜索的实现、特性 Heuristic Search 曼哈顿 汉明
1.通过优先级来选择 优先级高的来

核心估价函数

启发式函数:h(n),它用来评价哪些结点最有希望的是我们要找的结点,h(n)会返回一个非负实数，也可以认为是从结点n的目标结点路径的聚集成本。
启发式函数是一种告知搜索方向的方法。它提供了一种明智的方法来猜测哪个邻居结点会导向的一个目标。

A*代码模板
// C/C++
class Node {
public:
    int x;
    int y;
    bool operator< (const Node &A) {
        // 
    }
};

void generate_related_nodes(Node &node) {
    // 
}

void process(Node &node) {
    // 
}

void AstarSearch(vector<vector<int>>& graph, Node& start, Node& end) {
    vector<vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
    priority_queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        visited[cur.x][cur.y] = true;


        process(node);
        vector<Node> nodes = generate_related_nodes(node) 
        for (auto node : nodes) {
            if (!visited[node.x][node.y]) q.push(node);
        }
    }

    return ;
}


红黑树和AVL树
保证性能的关键
1.保证二位维度！—> 左右子树结点平衡
2.Balanced
3.https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree

AVL树
平衡因子 Balance Factor
它的左子树的高度减去它的右子树的高度(有时相反)。
balance fector = {-1, 0, 1}
通过旋转操作来进行平衡
左旋 右旋 左右旋 右左旋
不足：结点需要存储额外信息、且调整次数频繁

红黑树 Red-black Tree 
红黑树是一种近似平衡的二叉搜索树，它能够确保任何一个节点的左右子树的高度差小于两倍。具体来说，红黑树是满足如下条件的二叉搜索树:
每个结点要么是红色，要么是黑色
根结点是黑色
每个叶结点(NIL结点， 空结点)是黑色的。
不能有相邻接的两个红色结点
从任一结点到其每个叶子的所有路径都包含相同数目的黑色结点

