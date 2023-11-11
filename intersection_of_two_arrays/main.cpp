#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> setWithNumbers;
        for (int num : nums1)
        {
            setWithNumbers.insert(num);
        }

        vector<int> toReturn;

        for (int num : nums2)
        {
            if (setWithNumbers.find(num) != setWithNumbers.end())
            {
                toReturn.push_back(num);
                setWithNumbers.erase(num);
            }
        }

        return toReturn;
    }
};

int main()
{
    vector<int> One = {1, 2, 2, 1};
    vector<int> Two = {2, 2};

    Solution s;
    vector<int> afterInter = s.intersection(One, Two);

    for (int &num : afterInter)
    {
        cout << num << " ";
    }

    return 0;
}