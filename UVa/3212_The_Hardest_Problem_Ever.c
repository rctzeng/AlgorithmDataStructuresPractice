#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[201];
    int i,l,t;
    while(gets(str)){
        if(strcmp(str,"ENDOFINPUT")==0) break;
        if(strcmp(str,"START")==0){
            gets(str);l=strlen(str);
            for(i=0;i<l;i++){
                t=str[i]-'A';
                if(t<26 && t>=0)
                    printf("%c",'A'+(t+21)%26);
                else    printf("%c",str[i]);
            }
            printf("\n");
            gets(str);
        }
    }

    return 0;
}
