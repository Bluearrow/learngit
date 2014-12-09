#include  <iostream>
using namespace std;
/* 3.cpp
 * 题目：
 * 在一个二位数组中，每一行都按从左到右递增的顺序排序，每一列都
 * 按从上到下递增的顺序排序。给定一个数，判断该数是否在此二位数组中。
 * 分析：
 * 先从最大行逐一排除不可能的行，再从最小列逐一排除不可能的列。
 * 时间复杂度O(rows+columns)。
 */

/* array：用一位数组来表示此二维数组
 * rows, columns：二维数组的行数和列数
 * number：被查找的数
 */
bool Hi(int* array, int rows, int columns, int number)
{
    bool result = false;
    if(array != NULL && rows > 0 && columns > 0)
    {
        int row = rows - 1;
        int column = 0;
        while(row >=0 && column < columns)
        {
            if(array[row * columns + column] == number)
                result = true;
            else if(array[row * columns + column] > number)
                row--;
            else
                column++;
        }
    }
    return result;
}
