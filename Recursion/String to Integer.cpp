/*Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
*/
#include <iostream>

using namespace std;


int len(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}
int power(int n,int len){
    int mul=1;
    while(len>0){
        mul*=n;
        len--;
    }
    return mul;
}
int stringToNumber(char input[]) {

	if(input[0]=='\0'){
        return 0;
    }

    int num=input[0]-'0';
    int pow=(power(10,len(input)-1));
    return num * pow +stringToNumber(input+1);

}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
