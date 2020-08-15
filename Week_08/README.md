学习笔记
实战位运算的要点 
判断数的奇偶
x % 2 == 1 ==> (x & 1) == 1
x % 2 == 0 ==> (x & 1) == 0

x >> 1 ==> x / 2
即: x = x / 2; ==> x = x >> 1;
mid = (left + right) / 2; ==> mid = (left + right) >> 1;
X = X & (X - 1) ==> 清零最低位的1
X & -X => 得到最低位的1
X & ~ X ==> 0


//C/C++

class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);

        return this->res;
    }

    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }

        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }


private:
    int res = 0;
};


布隆过滤器
巴顿.布隆于一九七零年提出
一个很长的二进制向量 （位数组）
一系列随机函数 (哈希)
空间效率和查询效率高
有一定的误判率（哈希表是精确匹配）


布隆过滤器添加元素
1.将要添加的元素给k个哈希函数
2.得到对应于位数组上的k个位置
3.将这k个位置设为1

布隆过滤器查询元素
1.将要查询的元素给k个哈希函数
2.得到对应于位数组上的k个位置
3.如果k个位置有一个为0，则肯定不在集合中
4.如果k个位置全部为1，则可能在集合中


布隆过滤器实现
下面给出python的实现，使用murmurhash算法

import mmh3
from bitarray import bitarray


# zhihu_crawler.bloom_filter

# Implement a simple bloom filter with murmurhash algorithm.
# Bloom filter is used to check wether an element exists in a collection, and it has a good performance in big data situation.
# It may has positive rate depend on hash functions and elements count.



BIT_SIZE = 5000000

class BloomFilter:

    def __init__(self):
        # Initialize bloom filter, set size and all bits to 0
        bit_array = bitarray(BIT_SIZE)
        bit_array.setall(0)

        self.bit_array = bit_array

    def add(self, url):
        # Add a url, and set points in bitarray to 1 (Points count is equal to hash funcs count.)
        # Here use 7 hash functions.
        point_list = self.get_postions(url)

        for b in point_list:
            self.bit_array[b] = 1

    def contains(self, url):
        # Check if a url is in a collection
        point_list = self.get_postions(url)

        result = True
        for b in point_list:
            result = result and self.bit_array[b]

        return result

    def get_postions(self, url):
        # Get points positions in bit vector.
        point1 = mmh3.hash(url, 41) % BIT_SIZE
        point2 = mmh3.hash(url, 42) % BIT_SIZE
        point3 = mmh3.hash(url, 43) % BIT_SIZE
        point4 = mmh3.hash(url, 44) % BIT_SIZE
        point5 = mmh3.hash(url, 45) % BIT_SIZE
        point6 = mmh3.hash(url, 46) % BIT_SIZE
        point7 = mmh3.hash(url, 47) % BIT_SIZE


        return [point1, point2, point3, point4, point5, point6, point7]



布隆过滤器和哈希对比
布隆存在误差 只判断这个元素有没有 不需要存起来 所以内存小 
空间效率和查询时间超过一般算法，缺点是有一定的误识别率和删除困难

布隆过滤器查到不一定存在，只是在访问数据库之前进行筛查


LRU Cache
两个要素：大小、替换策略  越新越小越常用就放越前面
Hash Table + Double LinkedList 实现
O(1)查询、修改、更新

替换策略
LFU least ferquently used
LRU least recently used
https://en.wikipedia.org/wiki/Cache_replacement_policies

https://www.cnblogs.com/onepixel/p/7674659.html
初级排序 O(n^2)
1.选择排序(Selection Sort)
每次找最小值，然后放到待排序数组的起始位置。

#include<iostream>  
using namespace std;  
int findSmallest (int[],int);  
int main ()  
{  
    int myarray[10] = {11,5,2,20,42,53,23,34,101,22};  
    int pos,temp,pass=0;  
    cout<<"\n Input list of elements to be Sorted\n";  
    for(int i=0;i<10;i++)  
    {  
        cout<<myarray[i]<<"\t";  
    } 
    for(int i=0;i<10;i++)  
    {  
        pos = findSmallest (myarray,i);  
        temp = myarray[i];  
        myarray[i]=myarray[pos];  
        myarray[pos] = temp; 
        pass++;
    }  
    cout<<"\n Sorted list of elements is\n";  
    for(int i=0;i<10;i++)  
    {  
        cout<<myarray[i]<<"\t";  
    } 
    cout<<"\nNumber of passes required to sort the array: "<<pass;
    return 0;  
}  
int findSmallest(int myarray[],int i)  
{  
    int ele_small,position,j;  
    ele_small = myarray[i];  
    position = i;  
    for(j=i+1;j<10;j++)  
    {  
        if(myarray[j]<ele_small)  
        {  
            ele_small = myarray[j];  
            position=j;  
        }  
    }  
    return position;  
}


2.插入排序(Insertion Sort)
从前到后逐步扫描构建有序序列；对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入
#include <bits/stdc++.h> 
using namespace std; 
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
// A utility function to print an array of size n  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
/* Driver code */
int main()  
{  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return ;  
}  
3.冒泡排序(Bubble Sort)
嵌套循环，每次查看相邻的元素，如果逆序，则交换
// C++ program for implementation of Bubble sort  
#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver code  
int main()  
{  
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  

高级排序 O(N*logN)

快速排序 (Quick Sort)
数组取标杆pivot，将小元素放pivot左边，大元素放在右侧，然后依次对右边和右边的子数组继续快排；以达到整个序列有序
partition要做的就是选到pivot标杆的位置，且把所有小于pivot的元素都挪到左侧，大于pivot的元素都挪到右侧，返回pivot的位置
pivot表示标杆位置，在pivot下标左侧元素都小于pivot，在pivot下标右侧都大于pivot，再对左侧继续调用快排，对右侧同样继续调用Quick Sort
快速排序代码

//C/C++


int random_partition(vector<int>& nums, int l, intr) {
  int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot
  int pivot = nums[random_pivot_index];
  swap(nums[random_pivot_index], nums[r]);
  int i = l - 1;
  for (int j=l; j<r; j++) {
    if (nums[j] < pivot) {
      i++;
      swap(nums[i], nums[j]);
    }
  }
  int pivot_index = i + 1;
  swap(nums[pivot_index], nums[r]);
  return pivot_index;
}
void random_quicksort(vector<int>& nums, int l, int r) {
  if (l < r) {
    int pivot_index = random_partition(nums, l, r);
    random_quicksort(nums, l, pivot_index-1);
    random_quicksort(nums, pivot_index+1, r);
  }
}


归并排序
先排序左右子数组，然后合并两个有序子数组

//C/C++

void mergeSort(vector<int> &nums, int left, int right) {
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid+1, right);

	merge(nums, left, mid, right);
}


void merge(vector<int> &nums, int left, int mid, int right) {
	vector<int> tmp(right-left+1);
	int i = left, j = mid+1, k = 0;

	while (i <= mid && j <= right) {
		tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	}
	while (i <= mid) tmp[k++] = nums[i++];
	while (j <= right) tmp[k++] = nums[j++];

	for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
}

堆排序 (Heap Sort) 堆插入、删除、维护O(logN)，取最大/小值O(1)
1.数组元素依次建立小顶堆
2.依次取堆顶元素，并删除

//C/C++

void heapify(vector<int> &array, int length, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int largest = i;

    if (left < length && array[left] > array[largest]) {
        largest = left;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
        heapify(array, length, largest);
    }


    return ;
}

void heapSort(vector<int> &array) {
    if (array.size() == 0) return ;

    int length = array.size();
    for (int i = length / 2 - 1; i >= 0; i--) 
        heapify(array, length, i);

    for (int i = length - 1; i >= 0; i--) {
        int temp = array[0]; array[0] = array[i]; array[i] = temp;
        heapify(array, i, 0);
    }

    return ;
}


