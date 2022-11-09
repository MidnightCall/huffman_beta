//
// Created by praist on 2022/11/7.
//

#include "Huffman.h"

map<char, int> Huffman::statistics(string str) {
    map<char, int> hashmap;
    int i = 0;
    vector<char> array;
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        array.push_back(*it);
    }

    for(vector<char>::iterator it = array.begin(); it != array.end(); it++){
        char ch = *it;
        
        map<char, int>::iterator mapIt = hashmap.find(ch);
        if(mapIt != hashmap.end()){
            hashmap[ch] = mapIt->second + 1;
        }else{
            hashmap.insert(make_pair(ch, 1));
        }
        
    }
    return hashmap;
}

string Huffman::encode(string originalStr, map<char, int> statistics) {
    if(originalStr.empty() ){ // 判空
        throw "empty string";
    }

    int char_size = originalStr.size();
    int i = 0;
    char* charArray = (char*)malloc(char_size);
    for(string::iterator it = originalStr.begin(); it != originalStr.end(); it++){
        charArray[i++] = *it;
    }
    vector<Node*> leafNodes;
    buildTree(statistics, leafNodes); // 构建树并连接节点
    map<char, string> encodeInfo = buildEncodingInfo(leafNodes); // 获取子节点的哈夫曼编码

    string buffer;
    for(int i = 0; i < char_size; i++){
        char character = charArray[i];
        buffer += encodeInfo.find(character)->second;
    }

    return buffer;
}

string Huffman::decode(string binaryStr, map<char, int> statistics) {
    if(binaryStr.empty()){
        return "";
    }

    // 将给定的哈夫曼编码转换为字符数组
    int size = binaryStr.size();
    char* binaryCharArray = (char*)malloc(size);
    int n = 0;
    for(string::iterator it = binaryStr.begin(); it != binaryStr.end(); it++){
        binaryCharArray[n++] = *it;
    }

    vector<char> binaryList; // 存储string二进制码
    for(int i = 0; i < size; i++){
        binaryList.push_back(binaryCharArray[i]);
    }

    vector<Node*> leafNodes; // 保存叶子节点
    Tree* tree = buildTree(statistics, leafNodes); // 构建哈夫曼树

    string buffer; // 存储返回字符串的变量
    vector<char>::iterator it = binaryList.begin();
    while(it != binaryList.end()){
        Node* node = tree->root;

        do{
            char ch = *it;
            if(ch == '0'){
                node = node->leftChild;
                it++;
            }else if(ch == '1'){
                node = node->rightChild;
                it++;
            }else{
                throw "Error in huffman code";
            }
        }while(!node->isLeaf());

        buffer += node->ch;
    }

    return buffer;

}

void Huffman::testBuildTree() {
    vector<Node*> leafs;
    string rawString = "abbcccdddd";
    map<char, int> stat = statistics(rawString);
    Tree* tree = buildTree(stat, leafs);
    tree->inorderTraverse(tree->root);
    for (vector<Node*>::iterator iter = leafs.begin(); iter != leafs.end(); iter++) {
        cout << (*iter)->ch << ":" << (*iter)->frequency << endl;
    }
}

Tree* Huffman::buildTree(map<char, int> statistics, vector<Node *>& leafs) {
    // 获取map中的键，构建数组
    int keys_size = statistics.size();
    char* keys = (char*)malloc(keys_size);
    int i = 0;
    for (map<char, int>::iterator it = statistics.begin(); it != statistics.end(); it++) {
        keys[i++] = it->first;
    }

    // 建立叶节点的优先队列
    priority_queue<Node*, vector<Node*>, comparator> priorityQueue;
    for (int i = 0; i < keys_size; i++) { // 遍历map中的键
        char character = keys[i];
        Node* node = new Node();
        node->ch = character; // 将键读入Node
        node->frequency = statistics.find(character)->second; // 读入权重
        priorityQueue.push(node); // 将构造好的Node压入优先队列
        leafs.push_back(node);  // 将节点压入叶节点队列
    }

    // 哈夫曼树的构建
    int size = priorityQueue.size();
    for (int i = 1; i <= size - 1; i++) {
        // 从队列中取出权值最小的两个节点
        Node* node1 = priorityQueue.top();
        priorityQueue.pop();
        Node* node2 = priorityQueue.top();
        priorityQueue.pop();

        // 将两节点权值相加，构建新的节点
        Node* sumNode = new Node;
        //sumNode->ch = node1->ch + node2->ch;
        sumNode->frequency = node1->frequency + node2->frequency;

        // 将新节点左右子节点置为构造新节点的两个节点
        sumNode->leftChild = node1;
        sumNode->rightChild = node2;

        node1->parent = sumNode;
        node2->parent = sumNode;

        priorityQueue.push(sumNode);
    }

    Tree* tree = new Tree;
    Node* root = priorityQueue.top();
    priorityQueue.pop();
    tree->root = root;
    return tree;
}

void Huffman::testBuildEncodingInfo() {
    vector<Node*> leafs;
    string rawString = "abbcccdddd";
    map<char, int> stat = statistics(rawString);
    Tree* tree = buildTree(stat, leafs);
    map<char, string> codeMap = buildEncodingInfo(leafs);
    for (map<char, string>::iterator it = codeMap.begin(); it != codeMap.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

map<char, string> Huffman::buildEncodingInfo(vector<Node *> leafNodes) {
    map<char, string> codewords;
    for(vector<Node*>::iterator it = leafNodes.begin(); it != leafNodes.end(); it++){
        Node* currentNode = *it; // 获取当前节点
        char character = currentNode->ch; // 获取键
        string codeword = "";

        do{ // 从叶节点遍历到根节点，构建当前节点的huffman编码
            if(currentNode->isLeftChild()){ // 若为左孩子，则哈夫曼编码前加0
                codeword = "0" + codeword;
            }else{ // 若为右孩子，则哈夫曼编码前加1
                codeword = "1" + codeword;
            }

            currentNode = currentNode->parent;
        }while(currentNode->parent != NULL);

        codewords.insert(make_pair(character, codeword));
    }
    return codewords;
}
