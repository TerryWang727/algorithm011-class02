学习笔记
泛型递归、树的递归
树的面试题解法一般都是递归
原因why？
1.节点的定义
它的节点和树本身数据结构的定义就是用递归的方式进行的
2.重复性(自相似性)
不仅是树本身、二叉树以及二叉搜索树，在定义它的数据结构和算法特性的时候，存在重复性即自相似性 
以二叉搜索树举例，定义左子树都要小于根节点，右子树都要大于根节点，且左右子树具有相似的特征，以此类推，左右子树也满足以上特点
i

递归需要注意的点、代码模板结构
1.递归的终结条件
2.处理当前层逻辑
3.下探到下一层
4.清理当前层关系
递归本身的特点
本质上类似于循环，通过函数体调用本身来进行循环，没有明显的边界
每一层递归相应的时间会变慢
1.向下进入到不同的递归层，向上又回到原来的一层
"不能跳！只能一层层一次递归下去，具有对称性"
2.用参数进行同步
3.函数里的参数与全局变量可以在不同的递归层发生携带与变化，不同的递归层不会相互影响

计算n! python
n! = 1* 2 * 3 * …… * n
def Factorial(n)
  if n <= 1:
    return 1
  return n * Factorial(n-1)

思维要点
1.不要进行人肉递归(最大误区)不要自己画递归状态树
2.找最近最简方法，将其拆解成可重复解决的问题（重复子问题）
3.数学归纳法思维 最开始最简单的条件是成立的 比如n=1或n=2时成立且能证明当n成立的时候可以推出n+1也是成立的

递归泛型代码模板
#python
def recursion(level, param1, param2, …):
    # recursion terminator
    if level > max_level:
      process_result
      return
      
    # process logic in current level
    process(level, data…)

    # drill down
    self.recursion(level+1, param1 ,param2 …)

    # reverse the current level status if needed

相应的递归面试题
爬楼梯 斐波那契数列
括号生成
翻转二叉树
验证二叉搜索树
二叉树最大深度 最小深度
二叉树的序列化和反序列化
二叉树的最近公共祖先

分治代码模板
# Python
def divide_conquer(problem, param1, param2, ...):
  # recursion terminator
  if problem is None:
	print_result
	return
  # prepare data
  data = prepare_data(problem)
  subproblems = split_problem(problem, data)
  # conquer subproblems
  subresult1 = self.divide_conquer(subproblems[0], p1, ...)
  subresult2 = self.divide_conquer(subproblems[1], p1, ...)
  subresult3 = self.divide_conquer(subproblems[2], p1, ...)
  …
  # process and generate the final result
  result = process_result(subresult1, subresult2, subresult3, …)

  # revert the current level states

分治就是递归的组合，拆解成若干个子问题的递归合并(个人理解)
conquer subproblems就是drill down下探到下一层，每层解决自己当前层的问题，不同层互不干扰

复杂的分治要看返回的子问题的值的质量管控

Backtracking 回溯
回溯法采用试错的思想，它尝试分步去解决一个问题。在分步解决问题的过程中，当它通过尝试发现现有分步答案不能得到有效的正确的解答的时候，它将取消上一步甚至上几步的计算，再通过其它的可能分步解答再次尝试寻找问题的答案。

回溯法通常用最简单的递归方法来实现，在反复重复上述步骤后可能出现两种情况：
1.找到一个可能存在的正确的答案；
2.在尝试了所有可能的分布方法后，宣告该问题没有答案。

在最坏的情况下，回溯法导致一次复杂度为指数时间的计算。

