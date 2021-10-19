/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16

Example 4:
Input: height = [1,2,1]
Output: 2
 

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/

/*
해설 설명
(아래 설명에서 언급되는 포인터는 C/C++에서 말하는 포인터가 아닌 단순히 무언가를 가리키는 것을 의미함😃)

수직선 사이에 형성되는 면적인 항상 더 짧은 수직선의 높이에 의해 제한된다.
> the area formed between the lines will always be limited by the height of the shorter line.

우리는 2가지 포인터를 사용할텐데 하나는 수직선의 길이를 담고 있는 배열의 맨 앞이고 다른 하나는 그 배열의 맨 끝이다.
> We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines.

그리고, 우리는 지금 까지 얻어진 면적 중의 최대값을 저장하고 있는 "maxarea" 라는 변수를 유지합니다.
> Futher, we maintain a variable "maxarea" to store the maximum area obtained till now

매 스텝 마다, 우리는 두 수직선 사이에 형성되는 면적을 알아내고 "maxarea" 변수를 업데이트하며 두 포인터 중 더 짧은 수직선을 가리키는 포인터 값을 
또 다른 포인터 방향으로 이동시킵니다.
> At every step, we find out the area formed between them, update "maxarea" and move the pointer pointing to the shorter line 
towards the other end by one step.
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1;
        
        int w = 0;
        int h = 0;
        while(left < right)
        {
            h = height[left] > height[right] ? height[right] : height[left];
            w = right - left;
            max_area = max_area > (h*w) ? max_area : (h*w);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};

int main()
{
    std::vector<int> input = {1,8,6,2,5,4,8,3,7};
    Solution s;
    std::cout << s.maxArea(input) << std::endl;
    return 0;
}