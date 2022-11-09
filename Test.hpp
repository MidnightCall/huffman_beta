/**
 * @ClassName Test
 * @Description 对Huffman类和FileIO类的方法进行单元测试的类
 * @Author kojikoji 1310402980@qq.com
 * @Date 2022/11/9 9:00
 * @Version beta-1.0
 */

// 全部测试通过 -- 2022/11/9

// 由于黑盒测试已验收，此类废弃

/*
// ---------- INCLUDES ---------------------------------------------------------------
#include <iostream>
using namespace std;
#include "FileIO.h"
#include "Huffman.h"
#include "Tree.h"
#include "UI.hpp"

// ---------- TEST CLASS -------------------------------------------------------------
class Test{

// ---------- PUBLIC FUNCTION --------------------------------------------------------
public:
    void testStatistics() { // pass
        Huffman huff;
        string str = "1122334912dqdqdf[[]afad";
        map<char, int> frequency = huff.statistics(str);

        for (map<char, int>::iterator iter = frequency.begin(); iter != frequency.end(); iter++) {
            cout << iter->first << ": " << iter->second << endl;
        }
    }

    void testBuildTree() { // pass
        Huffman huff;
        huff.testBuildTree();
    }

    void testBuildEncodeInfo() { // pass
        Huffman huff;
        huff.testBuildEncodingInfo();
    }

    void testWriteMap() { // pass
        FileIO io;
        map<char, int> hashmap;

        hashmap.insert(make_pair('a', 1));
        hashmap.insert(make_pair('b', 2));
        hashmap.insert(make_pair('c', 3));
        hashmap.insert(make_pair('d', 4));

        io.writeMap(hashmap, "maptest.txt");

    }

    void testReaderMap() { // pass
        FileIO io;
        map<char, int> outmap = io.readMap("READMEZIP");
        // expected output: a$1\nb&2\nc$3\nd&4
        for (map<char, int>::iterator iter = outmap.begin(); iter != outmap.end(); iter++) {
            cout << iter->first << ": " << iter->second << endl;
        }
    }

    void testDecode() { // pass
        Huffman huff;
        FileIO io;

        map<char, int> frequency = io.readMap("READMEZIP");
        string str = io.readFile("READMEZIP");
        string ret = huff.decode(str, frequency);
        // should be "abbcccdddd"
        cout << retw << endl;
    }

    void testCompress() { // pass
        Huffman huff;
        FileIO io;
        io.compress("README", "READMEZIP");
        string rawString = io.readFile("README");
        string expected = huff.encode(rawString, huff.statistics(rawString));

        string result = io.readFile("READMEZIP");

        int i;
        int length = result.size();
        for (i = 0; i < result.size(); i++) {
            char ch1 = expected[i];
            char ch2 = result[i];

            if (ch1 != ch2) {
                cout << "测试未通过" << endl;
                break;
            }
        }
        if (i == result.size()) {
            cout << "测试通过" << endl;
        }
    }

    void testDecompress() { // pass
        Huffman huff;
        FileIO io;

        io.decompress("READMEZIP", "README_DE");
        string expected = io.readFile("README");
        string result = io.readFile("README_DE");

        int i;
        int length = result.size();
        for (i = 0; i < result.size(); i++) {
            char ch1 = expected[i];
            char ch2 = result[i];

            if (ch1 != ch2) {
                cout << "测试未通过" << endl;
                break;
            }
        }
        if (i == result.size()) {
            cout << "测试通过" << endl;
        }
    }

    void test() { // all pass
    // Test test;

    // test.testStatistics();

    // test.testBuildTree();

    // test.testBuildEncodeInfo();

    // test.testWriteMap();

    // test.testReaderMap();

    // test.testCompress();

    // test.testDecode();

    // test.testDecompress();
}
};
*/