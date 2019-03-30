import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
        while(true){
            Scanner sc = new Scanner(System.in);
            System.out.println(maxSubStringLength(sc.nextLine()));
        }
	}
	
    /**
     * 计算不重复子串的最大长度
     * 思路：遍历一遍数组，使用一个整形数组ascii记录遍历索引i之前的字符最后出现的位置，
     * 用于对子串的起始位置index进行定位，同时记录子串的最大长度res
     * @param str
     * @return
     */
    private static int maxSubStringLength(String str){
        int res = 0;
        int[] ascii = new int[128];
        int index = 0;
        for(int i=0;i<str.length();i++){
            index = Math.max(ascii[str.charAt(i)-'a'], index);  //指向子串的起始位置
            res = Math.max(res, i-index+1);  //子串的最大长度
            ascii[str.charAt(i)-'a'] = i+1;  //记录i之前的字符最后出现的位置
        }
        return res;
    }

}
