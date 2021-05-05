/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/
#include <iostream>
#include <vector>

#define MAX_COLUMN_SIZE 1000

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        char **plate = nullptr;
        plate = new char *[numRows];
        for (int i = 0; i < numRows; i++)
        {
            plate[i] = new char[MAX_COLUMN_SIZE];
        }

        // 공백으로 초기화(나중에 공백인 경우에는 결과 값에서 제외하기 위해)
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < MAX_COLUMN_SIZE; j++)
            {
                plate[i][j] = ' ';
            }
        }

        int nLen = s.length();
        int nCnt = 0;
        int nCol = 0;

        while (nCnt <= nLen)
        {
            // phase1
            for (int i = 0; i < numRows; i++)
            {
                plate[i][nCol] = s.at(nCnt);
                //printf("plate[%d][%d] = %c\n", i, nCol, plate[i][nCol]);
                nCnt++;
                if (nCnt >= nLen)
                {
                    return makeResult(plate, numRows);
                }
            }

            if (numRows > 1)
            {
                // phsae2
                for (int i = 0; i < numRows - 2; i++)
                {
                    nCol++;
                    int nRow = numRows - 2 - i;
                    plate[nRow][nCol] = s.at(nCnt);
                    //printf("plate[%d][%d] = %c\n", nRow, nCol, plate[nRow][nCol]);
                    nCnt++;
                    if (nCnt >= nLen)
                    {
                        return makeResult(plate, numRows);
                    }
                }
                nCol++;
            }
            else
            {
                nCol++;
            }
        }

        return makeResult(plate, numRows);
    }

private:
    std::string makeResult(char **plate, int numRows)
    {
        std::string strRet = "";
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < MAX_COLUMN_SIZE; j++)
            {
                if (plate[i][j] != ' ')
                {
                    strRet += plate[i][j];
                }
            }
        }
        return strRet;
    }
};

int main()
{
    std::string input = "PAYPALISHIRING";
    //std::string input = "AB";
    Solution s;
    std::cout << s.convert(input, 1) << std::endl;
    return 0;
}