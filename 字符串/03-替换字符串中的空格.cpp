#include <iostream>

using namespace std;

class Solution {
public:
    /*
	void replaceSpace(char *str,int length) {
        char *arr = new char[3*length];
        for (int i = 0, j = 0; i < length; i++){
            if (str[i] == ' ') {
                arr[j++] = '%';
                arr[j++] = '2';
                arr[j++] = '0';
                continue;
            }
            arr[j++] = str[i];
        }
	}
    */
    void replaceSpace(char *str, int length)
    {
        int spaceLength = 0;
        int oldLength = 0;
        int newLength = 0;

        while (*str++ != '\0') {
            if (*str == ' ') {
                spaceLength++;
            }
            oldLength++;
        }
        newLength = 3*spaceLength + oldLength;

        if (length < newLength) {
            return;
        }
        
        // 将空格替换成%20

    }
};

int main()
{
    Solution test;
    char str[20] = "hello world";
    int length = 20;

    test.replaceSpace(str, length);
}
