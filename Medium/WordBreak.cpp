/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>

class WordInfo
{
public:
    WordInfo(std::string word, int s, int e) : word_(word), start_idx_(s), end_idx_(e)
    {

    }

    int start_idx_;
    int end_idx_;
    std::string word_;
};

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        // 단어를 찾을때 O(logn)의 시간복잡도를 갖도록 하기위해 set에 저장
        std::set<std::string> words;
        for (const auto& word : wordDict)
        {
            words.insert(word);
        }

        // match된 단어의 마지막 인덱스를 저장해두는 stack
        std::stack<WordInfo> match_index;

        // 최초 match 단어 찾은 후 stack에 push
        bool is_matched = false;
        std::string assembled = "";
        int start_idx = 0;
        int end_idx = 0;
        for (const auto& character : s)
        {
            assembled += character;
            if (words.find(assembled) != words.end())
            {
                is_matched = true;
                break;
            }
            end_idx++;
        }

        if (!is_matched)
        {
            return false;
        }

        WordInfo info(assembled, start_idx, end_idx);
        match_index.push(info);
        
        int tmp_start_idx = end_idx;
        int tmp_end_idx = end_idx;
        assembled = "";

        // assemble looping
        // - start_idx와 end_idx는 계속 tracking
        // - assembled를 찾은 후 남은 문자열 s에서 wordDict에 매칭되는 단어를 찾았으면 stack에 push
        // - 찾지 못한 경우라면
        //   : end_idx를 증가시켜 매칭할 단어에 문자를 추가
        //   : 만약 end_idx가 입력 문자열의 끝에 다달았을 경우, stack의 top값(WordInfo)에서 start_idx 및 end_idx를 조회하여 이어서 assemble
        // - loop 탈출 조건은 다시 한번 생각해보기
        bool result = true;
        while( match_index.empty() || (match_index.top().end_idx_ != s.size() - 1) )
        {   
            tmp_end_idx++;
            if(tmp_end_idx >= s.size())
            {
                result = false;
                break;
            }

            assembled += s[tmp_end_idx];
            std::cout << "debug >> assemble: \"" << assembled << "\"" << std::endl;
            if (words.find(assembled) != words.end())
            {
                // match!
                WordInfo info(assembled, tmp_start_idx, tmp_end_idx);
                match_index.push(info);
                std::cout << "  debug >> push: \"" << assembled << "\"" << std::endl;
                assembled = "";
                tmp_start_idx = tmp_end_idx;
            }
            else
            {
                // no match!
                if(tmp_end_idx == s.size() - 1)
                {
                    if(match_index.empty())
                    {
                        result = false;
                        break;
                    }

                    // 문자열 s의 끝에 도달한 경우
                    auto popped = match_index.top();
                    match_index.pop();
                    std::cout << "    debug >> pop: \"" << popped.word_ << "\"" << std::endl;

                    assembled = popped.word_;
                    tmp_start_idx = popped.start_idx_;
                    tmp_end_idx = popped.end_idx_;
                }
            }
        }

        return result;
    }
};

int main()
{
    // std::string input = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami";
    // std::vector<std::string> wordDict = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
    
    std::string input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::vector<std::string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    Solution s;
    std::cout << std::boolalpha << s.wordBreak(input, wordDict) << std::endl;
    return 0;
}