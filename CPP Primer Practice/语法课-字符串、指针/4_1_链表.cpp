#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e4;

struct Node
{
    int val;
    Node* next;

    Node(int _val) : val(_val), next(NULL) {};
};

int main()
{
    Node* p = new Node(1);
    Node* q = new Node(2);
    Node* o = new Node(3);

    p->next = q;
    q->next = o;

    Node* head = p;

    // 在头节点前面添加节点 (4) 1 2 3
    Node* u = new Node(4);
    u->next = head;
    head = u;

    // 删除节点 head指向节点2，跳过节点1
    head->next = head->next->next;


    //链表的遍历方式
    for (Node* i = head; i; i = i->next) // i是指针，运行条件是 i != NULL;
        cout << i->val << endl;
    
    return 0;
}