//
// Created by 郑宇超 on 2019/2/12.
//
/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。


思路：
先计算转化次数，时间复杂度O(可到达的词典数目 * 单词数目)
统计答案
*/
class Solution {
public:
    vector <vector<string>> ans;
    vector <string> singleAns;

    bool diff(string &word1, string &word2) {
        int count = 0;
        for (int i = 0; word1[i] != '\0'; i++)
            if (word1[i] != word2[i]) {
                count++;
                if (count > 1)
                    return false;
            }
        if (count == 0)
            return false;
        return true;
    }

    void getAns(int &id1, int &id2, int &size, vector <string> &wordList, vector<int> &arriveStep, \
                vector <vector<int >> &flag) {
        singleAns.push_back(wordList[id1]);
        if (id1 == id2) {
            ans.push_back(singleAns);
            singleAns.pop_back();
            return;
        }
        if (arriveStep[id1] >= arriveStep[id2]) {
            singleAns.pop_back();
            return;
        }
        for (auto i:flag[id1])
            if (arriveStep[id1] + 1 == arriveStep[i])
                getAns(i, id2, size, wordList, arriveStep, flag);
        singleAns.pop_back();
        return;
    }

    vector <vector<string>> findLadders(string beginWord, string endWord, vector <string> &wordList) {
        singleAns.clear();
        for (int i = 0; i < ans.size(); i++)
            ans.clear();
        int startID = -1, endID = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord)
                startID = i;
            if (wordList[i] == endWord)
                endID = i;
        }
        if (startID == -1) {
            startID = wordList.size();
            wordList.push_back(beginWord);
        }
        if (endID == -1)
            return ans;
        vector <vector<int >> flag(wordList.size() + 1);
        for (int i = 0; i < wordList.size(); i++)
            for (int j = i + 1; j < wordList.size(); j++)
                if (diff(wordList[i], wordList[j]))
                    flag[i].push_back(j), flag[j].push_back(i);

        int size = wordList.size();
        vector<int> arriveStep(wordList.size(), 0);
        queue<int> Q;
        Q.push(startID);
        arriveStep[startID] = 1;
        while (!Q.empty()) {
            int id = Q.front();
            Q.pop();
            if (id == endID) {
                while (!Q.empty())
                    Q.pop();
                break;
            }
            for (auto i:flag[id])
                if (arriveStep[i] == 0) {
                    Q.push(i);
                    arriveStep[i] = arriveStep[id] + 1;
                }
        }
        getAns(startID, endID, size, wordList, arriveStep, flag);
        return ans;
    }
};