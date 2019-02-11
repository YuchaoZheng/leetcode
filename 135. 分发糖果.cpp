//
// Created by 郑宇超 on 2019/2/11.
//

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

 思路：
 记录每个位置左边有多少个数比他小，右边有多少个数比他小
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() == 0)
            return 0;
        vector<int> l(ratings.size());
        vector<int> r(ratings.size());
        l[0] = 0;
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1])
                l[i] = l[i - 1] + 1;
            else
                l[i] = 0;
        r[ratings.size() - 1] = 0;
        int ans = 0;
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                r[i] = r[i + 1] + 1;
            else
                r[i] = 0;
        for (int i = 0; i < ratings.size(); i++)
            ans += max(r[i], l[i]) + 1;
        return ans;
    }
};