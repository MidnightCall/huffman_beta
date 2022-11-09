#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H


// ---------- INCLUDES ---------------------------------------------------------------
#include <vector>
#include <queue>
#include <string>
#include <map>
#include "Tree.h"
using namespace std;

// 重写仿函数，用于比较Node*
struct comparator {
    bool operator() (Node* node1, Node* node2) {
        return node1->frequency > node2->frequency;
    }
};


/**
 * @ClassName HUFFMAN
 * @brief 哈夫曼编码相关操作的类
 *              用于记载符号和对应的二进制编码字符串；
 *              主要用途：
 *              (1) 解码：读取根节点字段并且遍历树来抽取出所需要的信息
 *              (2) 译码：调用getCode()函数来提取指定符号的二进制编码
 *              从根节电到指定叶节点的路径决定了叶节点记录的符号的二进制编码，
 *              往左走表示0，往右走表示1.
 *              (3) 构建哈夫曼树(私有方法，仅供内部方法调用)
 *              (4) 构建密码表(私有方法，仅供内部方法调用)
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/9 9:58
 * @brief Version: beta-1.0
 * @attention 构建的哈夫曼树要求
 *            (1) 根节点必须为内部节点(InternalNode)，编码树必须为有限树
 *            (2) 每个符号只能存在于一个叶子节点中
 */
class Huffman {


// ---------- PUBLIC FUNCTION --------------------------------------------------------
public:

    /**
     * @brief 由给定的字符串构建频率表
     * @return 返回构建的字符串频率表，其中，
     *         表的键为字符，值为对应字符在
     *         字符串中出现的频率
     */
    map<char, int> statistics(string str);

    /**
     * @brief 对由给定的字符串和频率表编码
     * @param originalStr 原始字符串
     * @param statistics 解码用频率表
     * @return 返回编码后的字符串
     */
    string encode(string originalStr, map<char, int> statistics);

    /**
     * @brief 对由给定的字符串和频率表解码
     * @param originalStr 原始字符串
     * @param statistics 解码用频率表
     * @return 返回解码后的字符串
     */
    string decode(string binaryStr, map<char, int> statistics);


    // 测试私有方法的方法, 已废弃
    // @Deprecated
    void testBuildTree();
    // @Deprecated
    void testBuildEncodingInfo();


// ---------- PRIVATE FUNCTION --------------------------------------------------------
private:
    /**
     * @brief 由给定频率表构建哈夫曼树，同时收集叶节点
     * @param statistics 给定的频率表
     * @param leafs 用于构建叶节点的表
     * @return 返回构建出的哈夫曼树的指针
     */
    Tree* buildTree(map<char, int> statistics, vector<Node*>& leafs); // 构建哈夫曼树

    /**
     * @brief 由叶节点的集合构建译码表
     * @param leafNodes 叶节点集合
     * @return 返回构建的译码表，
     *         表的键为字符，值为对应的哈夫曼码
     */
    map<char, string> buildEncodingInfo(vector<Node*> leafNodes);

};


#endif //HUFFMAN_HUFFMAN_H
