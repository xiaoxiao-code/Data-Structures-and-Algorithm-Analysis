/**
 * 顺序表（动态分配）完整实现与测试
 * 功能：初始化、插入、删除、查找、打印、销毁
 */

#include <iostream>
#include <cstdlib>

using namespace std;

// 1. 定义顺序表结构与常量
#define InitSize 10   // 默认初始容量
typedef int ElemType; // 数据元素类型

struct SeqList {
    ElemType* data;   // 动态数组首指针
    int MaxSize;      // 当前最大容量
    int length;       // 当前元素个数
};

// 2. 函数声明
void InitList(SeqList& L);
void DestroyList(SeqList& L);
void PrintList(const SeqList& L);
bool ListInsert(SeqList& L, int i, ElemType e);
bool ListDelete(SeqList& L, int i, ElemType& e);
bool GetElem(const SeqList& L, int i, ElemType& e);
int LocateElem(const SeqList& L, ElemType e);

// 3. 函数实现
// 初始化顺序表
void InitList(SeqList& L) {
    L.data = new ElemType[InitSize];
    if (L.data == nullptr) {
        cerr << "内存分配失败！" << endl;
        exit(0);
    }
    L.length = 0;
    L.MaxSize = InitSize;
}

// 销毁顺序表
void DestroyList(SeqList& L) {
    if (L.data != nullptr) {
        delete[] L.data;
        L.data = nullptr;
    }
    L.length = 0;
    L.MaxSize = 0;
}

// 打印顺序表
void PrintList(const SeqList& L) {
    if (L.length == 0) {
        cout << "顺序表为空" << endl;
        return;
    }
    cout << "顺序表内容（长度" << L.length << "）：[ ";
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << "]" << endl;
}

// 插入元素
bool ListInsert(SeqList& L, int i, ElemType e) {
    if (i < 0 || i > L.length) return false;
    if (L.length >= L.MaxSize) return false;

    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i] = e;
    L.length++;
    return true;
}

// 删除元素
bool ListDelete(SeqList& L, int i, ElemType& e) {
    if (i < 0 || i >= L.length) return false;

    e = L.data[i];
    for (int j = i; j < L.length - 1; j++) {
        L.data[j] = L.data[j + 1];
    }

    L.length--;
    return true;
}

// 按位查找
bool GetElem(const SeqList& L, int i, ElemType& e) {
    if (i < 0 || i >= L.length) return false;
    e = L.data[i];
    return true;
}

// 按值查找
int LocateElem(const SeqList& L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i;
    }
    return -1;
}

// 4. 主函数测试
int test_seq_list() {
    SeqList L;
    ElemType val;
    int index;

    cout << "=== 顺序表测试 ===" << endl;

    // 初始化测试
    cout << "\n1. 初始化顺序表：" << endl;
    InitList(L);
    PrintList(L);

    // 插入测试
    cout << "\n2. 插入元素测试：" << endl;
    ListInsert(L, 0, 10);
    ListInsert(L, 1, 20);
    ListInsert(L, 2, 30);
    ListInsert(L, 1, 99);
    PrintList(L);

    // 按位查找测试
    cout << "\n3. 按位查找测试：" << endl;
    if (GetElem(L, 2, val)) {
        cout << "第2个元素是：" << val << endl;
    }

    // 按值查找测试
    cout << "\n4. 按值查找测试：" << endl;
    index = LocateElem(L, 20);
    if (index != -1) {
        cout << "元素20的位置是：" << index << endl;
    }

    // 删除测试
    cout << "\n5. 删除元素测试：" << endl;
    if (ListDelete(L, 1, val)) {
        cout << "删除的元素值是：" << val << endl;
    }
    PrintList(L);

    // 销毁测试
    cout << "\n6. 销毁顺序表：" << endl;
    DestroyList(L);
    cout << "顺序表已销毁" << endl;

    return 0;
}