#include <stdio.h>
#include <string.h>



char str[1000]="0";
int len=0;

int judge(int i){
    if(str[i]=='1'&&str[len-i-1]=='1'){
        return 1;
    }
    else if(str[i]=='9'&&str[len-i-1]=='6'){
        return 1;
    }
    else if(str[i]=='6'&&str[len-i-1]=='9'){
        return 1;
    }
    else if(str[i]=='0'&&str[len-i-1]=='0'){
        return 1;
    }
    else if(str[i]=='8'&&str[len-i-1]=='8'){
        return 1;
    }
    return 0;
}


int main(){
    

    scanf("%s",str);
    len =strlen(str);
    int flag=1;


    if(len==1){
        if(str[0]=='1')
        flag=1;
    }
    else{
        for(int j=0;j<len;j++){
            //printf("%d\n",judge(j));
            if(judge(j)==0){
                //printf("%d\n",judge(j));
                flag=0;
                break;
            }
        
        }
    }

    if(flag==0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }

    return 0;
   
    

}