#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_L 16

//new_node生成一个Node结构体,同时生成包含n个Node *元素的数组
#define new_node(n) ((Node*)malloc(sizeof(Node)+n*sizeof(Node*)))
typedef int keyType;
typedef int valueType;

//每个节点的数据结构
typedef struct node
{
    keyType key;// key值
    valueType value;// value值
    struct node *next[1];// 后继指针数组，柔性数组 可实现结构体的变长
} Node;
//跳表结构
typedef struct skip_list
{
    int level;// 最大层数
    Node *head;//指向头结点
} skip_list;

// 创建节点
Node *create_node(int level, keyType key, valueType val);
//创建跳跃表
skip_list *create_sl();
//插入元素的时候元素所占有的层数完全是随机算法
int randomLevel();
// 插入节点
bool insert(skip_list *sl, keyType key, valueType val);
bool erase(skip_list *sl, keyType key);
// 查找节点
valueType *search(skip_list *sl, keyType key);
//从最高层开始逐层打印
void print_sl(skip_list *sl);
// 释放跳跃表
void sl_free(skip_list *sl);

#endif
