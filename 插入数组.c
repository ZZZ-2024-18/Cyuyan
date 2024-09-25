#include <stdio.h>  
  
// 函数声明  
void insertIntoArray(int arr[], int *size, int index, int value);  
void printArray(int arr[], int size);  
  
int main() {  
    int count[10] = {0}; // 假设我们知道这个数组有足够的空间  
    int size = 0; // 当前数组中元素的数量  
  
    // 插入一些元素  
    insertIntoArray(count, &size, 0, 5);  
    insertIntoArray(count, &size, 1, 10);  
    insertIntoArray(count, &size, 2, 15);  
  
    // 打印数组  
    printArray(count, size);  
  
    return 0;  
}  
  
// 向数组中指定位置插入新元素  
// 注意：这个实现没有检查数组越界  
void insertIntoArray(int arr[], int *size, int index, int value) {  
    // 确保有足够的空间（在实际应用中，你可能需要动态分配内存）  
    // 并且index在有效范围内（这里我们假设它总是有效的）  
  
    // 从数组的末尾开始，将元素向后移动一位，为新元素腾出空间  
    for (int i = *size; i > index; i--) {  
        arr[i] = arr[i - 1];  
    }  
  
    // 插入新元素  
    arr[index] = value;  
  
    // 更新数组的大小  
    (*size)++;  
}  
  
// 打印数组的内容  
void printArray(int arr[], int size) {  
    for (int i = 0; i < size; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}