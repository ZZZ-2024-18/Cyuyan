#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
// 使用宏定义来设定默认的最大值范围，但允许通过函数参数覆盖  
#define DEFAULT_MAX_VAL 101  
  
// 使用结构体来封装数组和它的最大值  
typedef struct {  
    int *arr;  
    size_t size;  
    int maxVal;  
} IntArray;  
  
// 初始化计数数组并返回其指针  
int* createCountArray(int maxVal) {  
    return (int*)calloc(maxVal, sizeof(int));  
}  
  
// 统计元素并填充计数数组  
void countElements(const IntArray *arr, int *count) {  
    for (size_t i = 0; i < arr->size; i++) {  
        if (arr->arr[i] >= 0 && arr->arr[i] < arr->maxVal) {  
            count[arr->arr[i]]++;  
        }  
    }  
}  
  
// 打印计数结果  
void printCounts(const int *count, int maxVal) {  
    for (int i = 0; i < maxVal; i++) {  
        if (count[i] > 0) {  
            printf("%d 出现了 %d 次\n", i, count[i]);  
        }  
    }  
}  
  
// 释放计数数组的内存  
void freeCountArray(int *count) {  
    free(count);  
}  
  
// 创建一个IntArray实例  
IntArray createIntArray(int *elements, size_t size, int maxVal) {  
    IntArray arr = {elements, size, maxVal};  
    return arr;  
}  
  
int main() {  
    int arr[] = {3, 5, 2, 5, 3, 7, 3, 2, 8, 8, 8, 100}; // 示例数组，包含边界值100  
    size_t size = sizeof(arr) / sizeof(arr[0]);  
    IntArray intArray = createIntArray(arr, size, DEFAULT_MAX_VAL); // 假设元素范围在0到100之间  
  
    int *count = createCountArray(intArray.maxVal);  
    countElements(&intArray, count);  
    printCounts(count, intArray.maxVal);  
  
    freeCountArray(count); // 释放计数数组的内存  
  
    return 0;  
}