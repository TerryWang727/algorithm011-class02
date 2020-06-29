学习笔记
hash table 哈希表
映射函数叫散列函数，存储数组叫哈希表
工程实践：
电话号码簿、用户信息表、LRU Cache缓存、Redis 键值对存储
查询、添加、删除O(1)   worst O(n)  哈希函数选择不好或者size过小
哈希碰撞：同一下标累加了多个Element


map key—value对，key不重复
Set 不重复的元素集合
HashSet O(1) 
TreeSet O(log n)



Linked list 是特殊化的 Tree
Tree 是特殊化的 Graph
树节点定义 

二叉树的遍历 O(n)
1.前序 Pre-order：根-左-右
2.中序 In-order: 左-根-右
3.后序 Post-order; 左-右-根

二叉搜索树 
“左子树所有节点均小于它的根节点的值”
“右子树所有节点均大于它的根节点的值”
！！以此类推：左、右子树也分别为二叉搜索树（重复性！！!）

中序遍历：升序排列



常见 二叉搜索树操作
查询  O(log n)
插入新节点(创建) O(log n)
删除 O(log n)

堆Heap
迅速找到一堆数中最大值或最小值的数据结构


假设大顶堆
find-max：O（1）
delete-max： O（log n）
insert（create）： O（log n）or 斐波那契堆可达到 O（1）


二叉堆
通过数组实现
索引为i的左孩子的索引是(2*i+1);
索引为i的右孩子的索引是(2*i+2);
索引为i的父节点的索引是floor"取整"((i-1)/2);
插入 
一律先插入到堆的尾部，依次向上调整整个堆的结构（一直到根）HeapifyUp

Delete Max 删除堆顶操作

将堆尾元素替换到顶部（即对顶被替代删除掉），依次从根部向下调整整个堆的结构（一直到堆尾）HeapifyDown

图 Gpraph
Graph (V,E)
Vertex：点
度-入度和出度 边是无向的话入度等于出度
点与点之间：连通与否
Edge：边
有向和无向（单行线）
权重（边长）

无向无权图


基于图的常见算法
DFS-递归
！！！“visited=set()”//和树DFS最大的区别

BFS
！！！“visited=set()”//和树BFS最大的区别
