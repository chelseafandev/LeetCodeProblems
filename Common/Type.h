struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct SpecialNode
{
    int val;
    SpecialNode* left;
    SpecialNode* right;
    SpecialNode* next;

    SpecialNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    SpecialNode(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    SpecialNode(int _val, SpecialNode* _left, SpecialNode* _right, SpecialNode* _next) : val(_val), left(_left), right(_right), next(_next) {}
};