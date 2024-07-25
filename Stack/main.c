#include"expression.h"
int main(){
    char str1[MaxSize],str2[MaxSize];
    scanf("%s",str1);
    Transmit(str1, str2);
    printf("%s\n",str1);
    printf("%s\n",str2);
    int ans;
    Calculate(str2, &ans);
    printf("%d", ans);
}