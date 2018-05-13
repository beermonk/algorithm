#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

// unordered_map操作
int test_unordered_map()
{
    std::unordered_map<int, int> my_map;
    std::vector<int> num {3, 2, 1, 4, 8, 9, 6};
    for (int i = 0; i < num.size(); i++) 
    {
        my_map[num[i]] = i;
    }
    for (auto i : my_map) {
        std::cout << i.first << "\t" << i.second << std::endl;
    }

    return 0;

}

int test_unordered_set()
{    
    std::unordered_set<int> example = {1, 2, 3, 4};

    auto search = example.find(2);
    if(search != example.end()) {
        std::cout << "Found " << (*search) << '\n';
    }
    else {
        std::cout << "Not found\n";
    }

    return 0;

}
int main()
{  
    test_unordered_map();
}
