#include <stdio.h>  
  
// 假设数组已经有序，向其中插入新元素并保持有序  
// 注意：这个函数假设arr有足够的空间来存储新元素  
void insertIntoOrderedArray(int arr[], int *size, int newValue) {  
    if (*size >= sizeof(arr) / sizeof(arr[0])) {  
        printf("Array is full, cannot insert new element.\n");  
        return;  
    }  
  
    int i;  
    for (i = *size - 1; (i >= 0 && arr[i] > newValue); i--) {  
        arr[i + 1] = arr[i]; // 将比newValue大的元素向后移动  
    }  
    arr[i + 1] = newValue; // 插入newValue  
    (*size)++; // 更新数组大小  
}  
  
// 打印数组  
void printArray(int arr[], int size) {  
    for (int i = 0; i < size; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  
  
int main() {  
    // 注意：这里的数组大小是固定的，但为了示例，我们假设它足够大  
    int arr[10] = {1, 3, 5, 7, 9}; // 假设用户已经以有序方式输入了这些元素  
    int size = sizeof(arr) / sizeof(arr[0]); // 实际上，这里size会是数组的总容量，而非已填充的元素数量  
    // 但为了示例，我们手动设置为已填充的元素数量  
    size = 5;  
  
    // 插入新元素  
    insertIntoOrderedArray(arr, &size, 4);  
    insertIntoOrderedArray(arr, &size, 8);  
  
    // 打印数组  
    printArray(arr, size);  
  
    return 0;  
}