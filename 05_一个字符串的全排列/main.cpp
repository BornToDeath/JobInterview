#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::vector;
using std::string;

/*
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所
 * 有字符串abc,acb,bac,bca,cab和cba。
 *
 * 输入描述：
 * 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
 */

class Solution{
    public:
        vector<string> Permutation(string str){
            vector<string> res;
            QuanPaiLie(str, 0, res);
            return res;
        }
    private:
        void QuanPaiLie(string str, int step, vector<string> &v){
            if(step == str.length()){
                v.push_back(str);
                return;
            }
            for(int i=step;i<str.length();i++){
                char c = str[i];
                str[i] = str[step];
                str[step] = c;
                QuanPaiLie(str, step+1, v);
            }
        }
};

int main(){

    std::cout<<"Input a string with length no more than 9:";
    string str;
    std::cin>>str;

    Solution s;
    vector<string> v = s.Permutation(str);
    for(int i=0;i<v.size();i++){
        std::cout<<i+1<<":"<<v[i]<<std::endl;
    }

    return 0;
}
