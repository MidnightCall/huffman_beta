#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

// ---------- INCLUDES ---------------------------------------------------------------
#include <iostream>
#include <string>
using namespace  std;

/**
 * @ClassName Node
 * @brief 组建哈夫曼树的节点类
 *              由于不了解C++的instance of关键字如何实现
 *              从而将内部节点于叶子节点合并为一个类
 *              并在类的内部添加判断方法来达到同等效果
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/9 9:58
 * @brief Version: beta-1.0
 */
class Node {

public:
// ---------- FIELDS --------------------------------------------------------
    char ch = NULL; // 节点保存的字符
    int frequency = 0; // 权重
    Node* parent = NULL; // 父节点
    Node* leftChild = NULL; // 左孩子
    Node* rightChild = NULL; // 右孩子


// ---------- PUBLIC FUNCTION --------------------------------------------------------

    /**
     * @brief 判断是否为叶节点
     * @return 若为叶节点，返回true；否则返回false
     */
    bool isLeaf();

    /**
     * @brief 判断是否为根节点
     * @return 若为根节点，返回true；否则返回false
     */
    bool isRoot();

    /**
     * @brief 判断是否为某一个节点的左孩子
     * @return 若为某一个节点的左孩子，返回true；否则返回false
     */
    bool isLeftChild();
};


#endif //HUFFMAN_NODE_H
