# LeetCodeProblems

LeetCode 1일 1문 실천([내 계정 정보](https://leetcode.com/chelseafandev/))

- [LeetCodeProblems](#leetcodeproblems)
  - [Acceptance를 깎아먹은 문제들은?](#acceptance를-깎아먹은-문제들은)
    - [Easy](#easy)
    - [Medium](#medium)
  - [Easy인데 충분히 생각할 거리가 있었던 문제들은?](#easy인데-충분히-생각할-거리가-있었던-문제들은)

## Acceptance를 깎아먹은 문제들은?
### Easy
- Reverse Integer [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/ReverseInteger.cpp)
  - Runtime Error 3회
  - Wrong Answer 1회

- Palindrome Number [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/PalindromeNumber.cpp)
  - Wrong Answer 1회

- Roman to Integer [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/RomanToInteger.cpp)
  - Wrong Answer 1회

- Valid Parentheses [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/ValidParentheses.cpp)
  - Wrong Answer 1회
  
- Remove Duplicates from Sorted Array [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/RemoveDuplicate.cpp)
  - Runtime Error 1회

- Length of Last Word [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/LengthOfLastWord.cpp)
  - Wrong Answer 1회

- Climbing Stairs [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/ClimbingStairs.cpp)
  - Wrong Answer 1회

- Majority Element [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/MajorityElement.cpp)
  - Wrong Answer 1회

- Linked List Cycle [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/LinkedListCycle.cpp)
  - Wrong Answer 1회

- Sqrt(x) [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/Sqrtx.cpp)
  - Runtime Error 1회

- Best Time to Buy and Sell Stock [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/BestTimeToBuyandSellStock.cpp)
  - Wrong Answer 1회
  - Time Limit Exceeded 2회
  - sell할 수 있는 날들 중 가장 비싼 값을 미리 저장해두자

- (Sloving) Intersection Of Two Linked List [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/IntersectionOfTwoLinkedList.cpp)
  - Wrong Answer 1회
  
- (Reference) Convert Sorted Array to Binary Search Tree [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/ConvertSortedArraytoBST.cpp)
  - 정렬된 vector의 중간 값은 BST의 root다(!)
  - 정렬된 vector라는 것을 활용하여 서브 트리에 포함시킬 sub vector를 구한다(!)

- Balanced Binary Tree [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/BalancedBinaryTree.cpp)
  - recursive를 어떻게 적용할지 고민을 좀 했던 문제

- Intersection Of Two Arrays 2 [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/IntersectionOfTwoArrays2.cpp)
  - 두 배열 간의 Intersection이라는 것이 요소 간의 순서를 고려해야하는지 아닌지가 문제에 명확히 명시되어있지않음😨
  - Wrong Answer 3회

- Excel Sheet Column Number [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/ExcelSheetColumnNumber.cpp)
  - 너무 복잡하게 생각했던 문제. 점화식 풀듯이 풀어나가면 훨씬 간단하게 풀렸을듯함😬
  - Discuss 참조

- Diameter Of Binary Tree [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/DiameterOfBinaryTree.cpp)
  - recursive를 어떻게 적용해야할지 감이 오지 않았던 문제. 서브 트리의 root를 기준으로 diameter를 구해서 큰 값을 찾으면 될거라는 생각은했지만 실제 코드 구현에서 막힘.
  - 솔루션 참조
<br>

### Medium
- Add Two Numbers
AddTwoNumbersv2.cpp [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Medium/AddTwoNumbersv2.cpp)
  - Runtime Error 2회
  - Wrong Answer 3회

- Longest Substring Without Repeating Characters [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Medium/LongestSubstringWRC.cpp)
  - Wrong Answer 4회

- Longest Palindromic Substring [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Medium/LongestPalindromicSubstring.cpp)
  - Time Limit Exceeded 3회

- ZigZag Conversion [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Medium/ZigZagConversion.cpp)
  - Wring Answer 1회

- Container With Most Water [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Medium/ContainerWithMostWater.cpp)
  - 답안 참조. Two Pointer Approach!

- Decode String [소스로 이동](https://github.com/chelseafandev/LeetCodeProblems/blob/main/Medium/DecodeString.cpp)
  - 답안 참조. 중첩된 bracket의 문자열을 어떻게 처리할 것인가?

- Minimum Operations to Reduce X to Zero [소스로 이동](https://github.com/chelseafandev/LeetCodeProblems/blob/main/Medium/MinimumOperationstoReduceXtoZero.cpp)
  - 답안 참조. 슬라이딩 윈도우

<br>

## Easy인데 충분히 생각할 거리가 있었던 문제들은?
- Maximum Depth Of Binary Tree [소스로 이동](https://github.com/junhaeng90/LeetCodeProblems/blob/main/Easy/MaximumDepthOfBinaryTree.cpp)
  - tree와 dfs를 함께 생각해야 했던 문제😃