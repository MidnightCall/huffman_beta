#ifndef UI_HPP_
#define UI_HPP_

// ---------- INCLUDES ---------------------------------------------------------------
#include<iostream>
using namespace std;

/**
 * @ClassName FileIO
 * @brief 用于管理用户界面相关操作的类
 * @brief Author: kojikoji 1310402980@qq.com
 * @brief Date: 2022/11/9 9:58
 * @brief Version: beta-1.0
 */
class UI{


// ---------- PUBLIC FUNCTION --------------------------------------------------------
public:

    /**
     * @brief 用户界面打印
     */
	void printMenu() {
		cout << "1.Huffman compress" << endl;
		cout << "2.Huffman decompress" << endl;
		cout << "3.Exit" << endl;
		cout << "Please select:";
	}

    /**
     * @brief 获取用户的菜单选择结果，当用户的选择
     *              不在菜单内时，会重新显示菜单并提示重新输入
     * @attention 叶子节点中的每个符号值必须小于给定的上限
     * @return 返回用户选择的结果，为一个1-3的整数
     */
	int getchoice() {
		int choice;
		cin >> choice;
		while (choice > 3 || choice < 1) {
			cout << "Invalid input, please input again:";
			cin >> choice;
		}
		return choice;
	}

    /**
     * @brief 程序运行的入口
     */
    void run() {
        Huffman huffman;
        FileIO fileIO;
        Tree tree;
        UI ui;
        string srcFile;
        string destFile;

        // 菜单打印与用户输入读取
        int choice;
        do
        {
            ui.printMenu();
            choice = ui.getchoice();
            switch (choice) {
            case 1:
                cout << "Please input source file name(size less than 4GB):";
                cin >> srcFile;
                cout << "Please input code file name:";
                cin >> destFile;
                fileIO.compress(srcFile, destFile);
                cout << "Processing..." << endl;
                cout << "Process end" << endl;
                break;
            case 2:
                cout << "Please input code file name:" << endl;
                cin >> srcFile;
                cout << "Please input target file name:" << endl;
                cin >> destFile;
                fileIO.decompress(srcFile, destFile);
                cout << "Processing..." << endl;
                cout << "Process end" << endl;
                break;
            }
            if (choice != 3) {
                system("pause");
            }
            system("cls");
        } while (choice != 3);

        cout << "Thanks for using" << endl;
    }
};

#endif // !1