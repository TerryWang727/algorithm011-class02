学习笔记

深度优先搜索、广度优先搜索的实现和特性

搜索-遍历
每个节点都要访问一次
每个节点仅仅只访问一次
对于节点访问的顺序不同分为 1.深度优先: depth first search
                           2.广度优先: breadth first search
                           3.优先级优先-启发式搜索
			   4. ...
                           

深度优先搜索
DFS 递归写法

# Python

visited = set()

def dfs(node, visited):
    if node in visited: # terminator
    	# already visited
    	return
    
    visited.add(node)
    
    # process current node here.
    ...
    for next_node in node.children():
        if next_node not in visited:
	    dfs(next_node, visited)


DFS 非递归写法
# Python
def DFS(self, tree):

    if tree.root is None:
        return []

    visited, stack = [], [tree.root]
    
    while stack:
        node = stack.pop()
	visited.add(node)
	
	process (node)
	nodes = generate_related_nodes(node)
	stack.push(nodes)
    # other processing work
    ...

BFS 代码模板
# Python
def BFS(graph, start, end):
    visited = set()
    queue = []
    queue.append([start])
    while queue:
	node = queue.pop()
	visited.add(node)

        process(node)
	nodes = generate_related_nodes(node)
	queue.push(nodes)
    # other processing work
    ...

deque来表示，一开始队列为空，把开始节点加入到队列里面去，然后维护visited节点（visited记录节点是否被访问过）当队列不为空的时候把节点往队列里面加，process这个节点，同时从这个节点扩散出周围节点，并依次加入到队列里面。从而对于这个队列的节点，一个一个依次访问，同时队列具有先入先出的特性，所以就会按照层的节点的顺序，一个一个依次从队列里面取

贪心算法 Greedy
贪心算法是一种在每一步选择中，都采取在当前状态下最好或最优(即最有利)的选择，从而希望导致结果是全局最好或最优的解法。
！！！注意局限性
	
贪心算法与动态规划的不同在于贪心算法对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，可以回退。

贪心：当下做局部最优判断
回溯：能够回退
动态规划：最有判断+回退


贪心可以解决一些最优化问题，如：求图中的最小生成树、求哈夫曼编码等。然而对于工程和生活中的问题，贪心法一般不能得到我们呢所要求的答案。
一旦一个问题可以通过贪心算法来解决，那么贪心算法一般是解决这个问题的最好办法。由于贪心算法的高效性以及其所求得的答案比较接近最优结果，贪心算法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。

二分查找
前提 1.目标函数单调性（单调递增或递减）
     2.存在上下界(bounded)
     3.能够通过索引访问(index accessible)

left + (right - left)/2 求中间值，它的优势在于不会超出当前数组最大值的范围，防止越界，而(right + left)/2 取到数组后两位时可能会出现越界的情况。

二分查找代码模板
# Python
left, right = 0, len(array) - 1
while left <= right:
      mid = (left + right) / 2
      if array[mid] == target:
            # find the target!!
	    break or return result
      elif array[mid] < target:
	    left = mid + 1
      else:
	    right = mid - 1

牛顿迭代法
1.确定迭代变量，存在一个可直接或间接地不断由旧值递推出新值的变量，这个变量就是迭代变量
2.建立迭代关系式
3.对迭代过程进行控制，也就是算法实现


使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
思路 二分查找 时间复杂度O(logn) 
数组局部是有序的，从mid开始分开两部分[4,5,6]和[7,0,1,2]
通过比较左右边界查看哪个数组有序，确定target在那边找
while left <= right:
      mid = (left + right) / 2
      if array[mid] == target:
            # find the target!!
            break or return result
      elif array[mid] < target:
            left = mid + 1
      else:
            right = mid - 1

牛顿迭代法
1.确定迭代变量，存在一个可直接或间接地不断由旧值递推出新值的变量，这个变量就是迭
代变量
2.建立迭代关系式
3.对迭代过程进行控制，也就是算法实现


使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
思路 二分查找 时间复杂度O(logn)
数组局部是有序的，从mid开始分开两部分[4,5,6]和[7,0,1,2]
通过比较左右边界查看哪个数组有序，确定target在那边找

所以分类讨论
1.从左边界到mid
如果[l, mid-1]是有序数组，且target的大小满足在[nums[left],nums[mid])，则我们应该将搜索范围缩小至[left, mid-1]，否则在 [mid+1, right]中寻找。
2.从mid到右边界
如果[mid, r]是有序数组，且target的大小满足(nums[mid+1],nums[r]]，则我们应该将搜索范围缩小至[mid+1, r]，否则在[l, mid-1]中寻找。

cpp代码
int searchTarget(vector<int>& nums, int target) {
    int lo = 0, hi = int(nums.size()) - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo == hi && nums[lo] == target ? lo : -1;
}
