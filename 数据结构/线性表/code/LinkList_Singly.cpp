/**
 * @file LinkList_Singly.cpp
 * @brief 带头节点单链表完整实现
 */

#include <iostream>
using namespace std;

// 数据类型定义
typedef int ElemType;

// 节点结构
struct LNode {
    ElemType data;
    struct LNode* next;
};
typedef LNode* LinkList;

// 链表初始化
bool InitList(LinkList& L) {
    L = new LNode;
    if (L == nullptr) return false;
    L->next = nullptr;
    return true;
}

// 尾插法建立链表
LinkList List_TailInsert(LinkList& L) {
    int x;
    LNode* s, * r = L;

    cout << "请输入整数建立链表 (输入 9999 结束): ";
    cin >> x;
    while (x != 9999) {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = nullptr;
    return L;
}

// 按位插入
bool ListInsert(LinkList L, int i, ElemType e) {
    if (i < 1) return false;

    LNode* p = L;
    int j = 0;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == nullptr) return false;

    LNode* s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

// 按位删除
bool ListDelete(LinkList L, int i, ElemType& e) {
    if (i < 1) return false;

    LNode* p = L;
    int j = 0;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == nullptr || p->next == nullptr) return false;

    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;

    return true;
}

// 按位查找
LNode* GetElem(LinkList L, int i) {
    if (i < 0) return nullptr;
    LNode* p = L;
    int j = 0;
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
    }
    return p;
}

// 求表长
int Length(LinkList L) {
    int len = 0;
    LNode* p = L;
    while (p->next != nullptr) {
        p = p->next;
        len++;
    }
    return len;
}

// 打印链表
void PrintList(LinkList L) {
    LNode* p = L->next;
    cout << "当前链表: Head -> ";
    while (p != nullptr) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// 销毁链表
void DestroyList(LinkList& L) {
    LNode* p = L;
    LNode* q;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    L = nullptr;
}

// 主函数测试
int test_link_list() {
    LinkList L;

    // 初始化
    InitList(L);

    // 尾插法建表
    List_TailInsert(L);
    PrintList(L);
    cout << "当前表长: " << Length(L) << endl;

    // 插入测试
    cout << "\n--- 测试：在第 2 个位置插入 99 ---" << endl;
    ListInsert(L, 2, 99);
    PrintList(L);

    // 删除测试
    cout << "\n--- 测试：删除第 3 个位置的元素 ---" << endl;
    int delVal;
    if (ListDelete(L, 3, delVal)) {
        cout << "删除成功，删除的值为: " << delVal << endl;
    }
    else {
        cout << "删除失败" << endl;
    }
    PrintList(L);

    // 查找测试
    cout << "\n--- 测试：查找 ---" << endl;
    LNode* p = GetElem(L, 2);
    if (p) cout << "第 2 个位置的值是: " << p->data << endl;

    LNode* q = LocateElem(L, 10);
    if (q) cout << "找到了值 10，地址为: " << q << endl;
    else cout << "未找到值 10" << endl;

    // 销毁链表
    cout << "\n--- 销毁链表 ---" << endl;
    DestroyList(L);
    cout << "链表已销毁，程序结束。" << endl;

    return 0;
}