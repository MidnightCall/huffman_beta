// ---------- INCLUDES ---------------------------------------------------------------
#ifndef HUFFMAN_FILEIO_H
#define HUFFMAN_FILEIO_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <filesystem>
using namespace std;
#include "Huffman.h"

/**
 * @ClassName FileIO
 * @brief 用于处理文件相关操作的类
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/9 9:58
 * @brief Version: beta-1.0
 * @attention 在文件不存在或打开失败时，会抛出异常
 *            会在后续版本完善
 */
class FileIO {

// ---------- PUBLIC FUNCTION --------------------------------------------------------
public:

    /**
     * @brief 将指定的文件压缩为目标文件
     * @param srcFile 待压缩的文件
     * @param destFile 压缩后文件的名称
     * @attention 待压缩的文件必须存在，否则抛出异常
     */
    void compress(string srcFile, string destFile); // 压缩操作

    /**
     * @brief 解压指定的文件
     * @param srcFile 待解压的文件
     * @param destFile 解压后文件的名称
     * @attention 待解压的文件必须存在，否则抛出异常
     */
    void decompress(string srcFile, string destFile); // 解压操作

// ---------- PRIVATE FUNCTION --------------------------------------------------------
private:

    /**
     * @brief 从文件中读取字符串的函数
     * @param srcFile 待读取的文件名
     * @attention 待读取的文件必须存在，否则抛出异常
     * @return 返回从文件中读取的字符串，每一行的结尾追加'\n'，以便后续还原
     */
    string readFile(string srcFile); 

    /**
     * @brief 将指定的字符串写入文件
     * @param destFile 写入的目标文件名
     * @param content 写入的内容
     * @Deprecated
     */
    void writeFile(string destFile, string content); 

    /**
     * @brief 从指定文件中读取字符频率表
     * @param srcFile 指定的文件名
     * @attention 指定的文件必须存在，否则抛出异常
     * @return 返回从文件中读取到的频率表
     */
    map<char, int> readMap(string srcFile);

    /**
     * @brief 将频率表写入指定的文件中
     * @param srcFile 写入的文件名
     * @param hashmap 待写入的频率表
     */
    void writeMap(map<char, int> hashmap, string destFile);

    /**
     * @brief 用指定的字符将字符串分割，辅助readMap和writeMap的执行
     * @param str 待分割的字符串
     * @param delim 用于分割的字符
     * @param s 分割后的子字符串存储到的容器
     */
    void stringSplit(string str, char delim, vector<string>& s); 

    /**
     * @brief 将一个8位的比特流转化为一个字节
     * @param bits 待转化的比特流i
     * @return 返回转化后的字节
     */
    unsigned char bitToByte(string bits);

    /**
     * @brief 将单个字节流转化为比特流，8位的字符串保存
     * @param byte 带转换的字节
     * @return 返回转化后的比特流，以8位字符串的形式保存
     */
    string byteToBit(unsigned char byte);

    /**
     * @brief 以二进制方式从指定的文件中读取内容，并转化为对应的哈夫曼码
     * @param srcFile 待读取的文件名
     * @return 返回读取到的哈夫曼码
     */
    string readFileInBinary(string srcFile);

    /**
     * @brief 将指定的哈夫曼码转化为字节流，并以二进制方式向指定的文件写入
     * @param fileName 待写入的文件名
     * @param content 待写入的哈夫曼码
     */
    void writeFileInBinary(string destFile, string content);

    int getFileSize(string filename);
};


#endif //HUFFMAN_FILEIO_H
