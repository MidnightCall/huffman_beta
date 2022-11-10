//
// Created by praist on 2022/11/9.
//

#include "FileIO.h"

// public function

string FileIO::readFile(string srcFile) {
    string s = ""; // 保存读入的字符串
    string buffer; // 暂存逐行读取的字符串
    ifstream fileIn(srcFile);

    if (!fileIn) {
        fileIn.close();
        throw "file open error";
    }
    else {
        while (getline(fileIn, buffer))
            s = s + buffer + '\n'; // 每读取一行后加'\n'用于还原时换行      
    }

    s.erase(s.size() - 1); // 最后一行末尾的'\n'删除

    fileIn.close();
    return s;
}

void FileIO::writeFile(string destFile, string content) {
    ofstream fileOut(destFile);

    if (!fileOut) {
        fileOut.close();
        throw "file open error";
    }
    else {
        fileOut << content;
    }
    fileOut.close();
}

map<char, int> FileIO::readMap(string srcFile) {
    map<char, int> hashtable;
    ifstream fileIn("map" + srcFile);
    string buffer;
    vector<string> temp;
    if (!fileIn) {
        fileIn.close();
        throw "file open error";
    }
    else {
        while (getline(fileIn, buffer)) {
            if (buffer == "") { // 判断是否读到'\n'和其对应的键值对
                getline(fileIn, buffer);
                stringSplit(buffer, '$', temp);
                hashtable.insert(make_pair('\n', stoi(*(++temp.begin()))));
            }
            else {
                stringSplit(buffer, '$', temp);
                vector<string>::iterator iter = temp.begin();
                string ch_str = *iter;
                char ch = ch_str.at(0);
                iter++;
                string num_str = *iter;
                int num = stoi(num_str);
                hashtable.insert(make_pair(ch, num));
            }
        }
        fileIn.close();
    }
    return hashtable;
}

void FileIO::writeMap(map<char, int> hashmap, string destFile) {
    string buffer = "";
    ofstream fileOut("map" + destFile);
    if (!fileOut) {
        fileOut.close();
        throw "file open error";
    }
    for (map<char, int>::iterator it = hashmap.begin(); it != hashmap.end(); it++) {
        string currStr = "";
        currStr += it->first;
        currStr.append("$");
        currStr.append(to_string(it->second));
        // cout << currStr << endl;
        buffer.append(currStr).append("\n");
    }
    fileOut << buffer;
    fileOut.close();
}

void FileIO::compress(string srcFile, string destFile) {
    Huffman huff;
    string rawString = readFile(srcFile); // 读取原始字符串
    map<char, int> frequency = huff.statistics(rawString); // 构建字符串频率表
    string huffmanCode = huff.encode(rawString, frequency); // 构建哈夫曼编码
    writeFileInBinary(destFile, huffmanCode); // 写入文件
    writeMap(frequency, destFile); // 写入频率表
}

void FileIO::decompress(string srcFile, string destFile) {
    Huffman huff;
    map<char, int> frequency = readMap(srcFile); // 读取频率表
    string huffmanCode = readFileInBinary(srcFile); // 读取哈夫曼编码串
    string message = huff.decode(huffmanCode, frequency); // 解码
    writeFile(destFile, message); // 写文件
}

void FileIO::stringSplit(string str, char delim, vector<string>& s){
    s.clear();
    str += delim;
    string buffer = "";

    for(int i = 0; i < str.size(); i++){
        if (str[i] != delim) {
            buffer += str[i];
        }
        else {
            s.push_back(buffer);
            buffer = "";
        }
    }
}

void FileIO::writeFileInBinary(string destFile, string content) {
    ofstream fileOut(destFile, ios::binary | ios::out);
    unsigned char currentByte;
    string currentBits;

    for (int i = 0; i < content.size(); i += 8) {
        currentBits = content.substr(i, 8);
        currentByte = bitToByte(currentBits);

        fileOut.write((const char*)&currentByte, sizeof(unsigned char));
    }

    fileOut.close();
}

string FileIO::readFileInBinary(string srcFile) {
    ifstream fileIn(srcFile, ios::binary | ios::out);
    string ret = "";
    unsigned char currentByte;

    while (fileIn.read((char*)&currentByte, sizeof(unsigned char))) {
        ret += byteToBit(currentByte);
    }

    return ret;
}

unsigned char FileIO::bitToByte(string bits){
    int length = 8; // 确保换入bits为8
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = bits[i] == '1' ? pow(2, (7 - i)) + sum : sum;
    }
    return sum;
}

string FileIO::byteToBit(unsigned char bytes){
    string str = "";
    int remainder;
    while (bytes > 0) {
        remainder = bytes % 2;
        bytes /= 2;
        str += to_string(remainder);
    }
    reverse(str.begin(), str.end());
    return str;
}
