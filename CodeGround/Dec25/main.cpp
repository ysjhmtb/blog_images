/*
5 5
0 1 1 0 1
0 1 1 0 1
0 0 0 0 0
0 1 1 0 1
0 0 1 1 1

4

a function to judge whether all elements of array have 1. this function's parameters are i, j, length to search.

*/

#include <iostream>
#include <vector>

class Solution {
private:
    unsigned int row;
    unsigned int col;
    std::vector<std::vector<int> > m_field;

public:
    Solution(const unsigned int &row, const unsigned int &col, const std::vector<std::vector<int> > field) {
        this->row = row;
        this->col = col;

        for (unsigned int i = 0; i < row; i++) {
            for (unsigned int j = 0; j < col; j++) {
                std::cout << field[i][j] << std::endl;
                // 빌드하면 Process finished with exit code 11
                // 이 부분에서 문제가 발생하는 것 같은데, 무엇이 문제일까?
                this->m_field[i][j] = field[i][j];
            }
        }
    }

    bool hasAllOne(unsigned int i, unsigned int j, unsigned int len) {
        bool flag = true;

        if (i + len > row)
            return false;

        for (unsigned int k = i; k <= i + len; k++) {
            for (unsigned int l = j; l <= j + len; j++) {
                if (m_field[k][l] != 1) {
                    flag = false;
                    return flag;
                }
            }
        }

        return flag;
    }
};

int main() {
    // std::cout << "Hello world" << std::endl;

    int row = 5;
    int col = 5;
    std::vector<std::vector<int> > field;

    std::vector<int> temp1{0, 1, 1, 0, 1};
    std::vector<int> temp2{0, 1, 1, 0, 1};
    std::vector<int> temp3{0, 0, 0, 0, 0};
    std::vector<int> temp4{0, 1, 1, 0, 1};
    std::vector<int> temp5{0, 0, 1, 1, 1};

    field.push_back(temp1);
    field.push_back(temp2);
    field.push_back(temp3);
    field.push_back(temp4);
    field.push_back(temp5);

    Solution ref(row, col, field);

    std::cout << std::boolalpha;

    std::cout << ref.hasAllOne(0, 0, 1) << std::endl;

    std::cout << "EOF" << std::endl;

    return 0;
}
