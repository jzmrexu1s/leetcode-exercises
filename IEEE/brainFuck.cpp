
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool analyze (string & tokens);

int
main (int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "EE: No input file." << endl;
        return -1;
    }

    ifstream file_in (argv[1]);
    string tokens;

    /*
     * 打开参数中的文件名并解释brainfuck 代码
     */
    if (!file_in)
    {
        cerr << "EE: Can not open file: " << argv[1] << endl;
        return -1;
    }

    /*
     * 读入文件
     */
    while (!file_in.eof ())
    {
        string str_tmp;
        file_in >> str_tmp;
        tokens.insert (tokens.length (), str_tmp);
    }
    file_in.close ();

    /*
     * 解释brainfuck 代码
     */
    if (!analyze (tokens))
    {
        return -1;
    }

    return 0;
}

/*
 * 解释brainfuck 代码
 */
bool
analyze (string & tokens) {
    int pointer = 0;    // 指针
    int layer;      // 嵌套'[' 和']' 的层数
    string work;      // 工作数组,存指针指向内存单元的值

    /*
     * 检查'[' 和']' 是否匹配
     * 因为不匹配可能导致其后解释过程死循环
     */
    layer = 0;
    for (uint32_t location = 0; location < tokens.length(); ++location) {
        if ('[' == tokens[location]) {
            ++layer;
        }
        if (']' == tokens[location]) {
            --layer;
        }
    }
    if (layer < 0) {
        cerr << "EE: Expect token '[' but not found." << endl;
        return false;
    }
    if (layer > 0) {
        cerr << "EE: Expect token ']' but not found." << endl;
        return false;
    }

    /*
     * 解释过程开始
     */
    for (uint32_t location = 0; location < tokens.length(); ++location) {
        switch (tokens[location]) {
            // 指针减一
            case '<':
                --pointer;
                if (pointer < 0) {
                    pointer = work.length();
                }
                break;
                // 指针加一
            case '>':
                ++pointer;
                break;
                // 指针指向的字节的值减一
            case '-':
                --work[pointer];
                break;
                // 指针指向的字节的值加一
            case '+':
                ++work[pointer];
                break;
                // 输出指针指向的单元内容（ASCII 码）
            case '.':
                cout << work[pointer];
                break;
                // 输入指针指向的单元内容（ASCII 码）
            case ',':
                cin.get(work[pointer]);  // ">>" 操作符无法正确处理
                // 读入的换行符
                break;
                // 如果指针指向的单元值为零，向后跳转到对应的']'指令的次一指令处
            case '[':
                layer = 1;
                if (work[pointer]) {
                    break;
                }
                while (layer) {
                    ++location;
                    if ('[' == tokens[location]) {
                        ++layer;
                    }
                    if (']' == tokens[location]) {
                        --layer;
                    }
                }
                --location;    // 循环结束后location 位置为']',需自减一次
                break;
                // 如果指针指向的单元值不为零，向前跳转到对应的'['指令的次一指令处
            case ']':
                layer = 1;
                if (!work[pointer]) {
                    break;
                }
                while (layer) {
                    --location;
                    if (']' == tokens[location]) {
                        ++layer;
                    }
                    if ('[' == tokens[location]) {
                        --layer;
                    }
                }
                break;
                // 非法token 打印信息并退出解释过程
            default:
                cerr << endl << "EE: Can not analyze token: "
                     << tokens[location] << endl;
                return false;
        }
    }

    return true;
}