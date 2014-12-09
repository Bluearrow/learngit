/* 8.cpp
 * @题目：
 * 把一个数组前面的若干个元素放到数组末尾，称之为数组的旋转。
 * 输入一个递增排序数组的一个旋转，输出该数组的最小值。
 * @分析：
 * 简单例子，数组{3,4,5,1,2}是数组{1,2,3,4,5}的一个旋转，该数组
 * 最小值是1。最直观的办法就是遍历数组，找到数组中第一次出现元素
 * 值变小的位置。显然，这种查找方法的时间复杂度不是最优的。利用
 * 折半查找的思路，比较首尾元素和中间元素的值，缩小查找范围。
 */

int Hi(int* array, int length)
{
    if(array == NULL || length <= 0 )
        throw new std::exception("Invalid parameters.");

    int start = 0;
    int end = length - 1;
    //确保有0个元素被放到末尾时，输出第一
    int mid = start;
    while(array[start] >= array[end])
    {
        if(end - start == 1)
        {
            mid = end;
            break;
        }
        mid = (start + end)/2;
        if(array[start] < array[mid])
            start = mid;
        else
            end = mid;
    }
    return array[mid];
}
