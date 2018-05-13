#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> removeElements(std::vector<int>& num, int target)
        {
            int index = 0;
            for (int i = 0; i < num.size(); i++) {
                if (num[i] != target) {
                    num[index++] = num[i];
                }
            }
            return num;
        }

};

int main()
{
    std::vector<int> num {1, 3, 2, 1, 7, 9, 8, 4, 5, 3};
    Solution slu;
    std::vector<int> res = slu.removeElements(num, 1);
    for (auto i : res) {
        std::cout << i << "\t";
    }
    std::cout << "\n";
    return 0;
}
