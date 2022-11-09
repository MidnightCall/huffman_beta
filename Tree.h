// ---------- INCLUDES ---------------------------------------------------------------
#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "Node.h"


/**
 * @ClassName Tree
 * @brief 构建哈夫曼树的类，通过遍历来进行哈夫曼编码
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/9 9:58
 * @brief Version: beta-1.0
 */
class Tree {
public:
// ---------- FIELDS --------------------------------------------------------
    Node* root; // 根节点
    Node* getRoot();
    void setRoot(Node* root);

    // 测试用函数,已废弃
    // @Deprecated
    void inorderTraverse(Node* root);
};


#endif //HUFFMAN_TREE_H
