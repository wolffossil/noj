#include <stdio.h>
#include <windows.h>

int determinant(int matrix[20][20],int order);
int laplace_expansion(int matrix[20][20],int r,int c,int order);

int main()
{
    int order,matrix[20][20],result = 0,i,j;
    
    printf("行列式计算器可以计算20阶以下的行列式。你可以先输入阶数，然后形如\n");
    Sleep(800);
    printf("1 2 3\n4 5 6\n7 8 9\n");
    Sleep(800);
    printf("这样来输入你需要计算的行列式。\n\n");
    Sleep(600);
    printf("请输入阶数:");
    scanf("%d",&order);
    if(order <= 0)
        printf("请输入大于0的整数！");
    else
    {
        printf("请输入一个%d阶行列式:\n",order);
        for(i = 0;i < order;i ++)
            for(j = 0;j < order;j ++)
                scanf("%d",&matrix[i][j]);
        result = determinant(matrix,order);
        printf("行列式的值为: %d",result);
    }
    
    return 0;
}

int determinant(int matrix[20][20],int order)
{
    int result = 0,sign = 1,cofactor,i;
    
    if(order == 1)
        result = matrix[0][0];
    else
    	for(i = 0;i < order;i ++)
        {
            cofactor = laplace_expansion(matrix,i,0,order);
            result += sign * matrix[i][0] * cofactor;
            sign *= -1;
        }
    
    return result;
}

int laplace_expansion(int matrix[20][20],int r,int c,int order)
{
    int result = 0,cofactor[20][20],original_i,original_j,i,j;
    
    for(i = 0;i < order;i ++)
        for(j = 0;j < order;j ++)
        {
            original_i = i;
            original_j = j;
            if(i == r || j == c);
            else
            {
                if(i > r)
                    i --;
                if(j > c)
                    j --;
                cofactor[i][j] = matrix[original_i][original_j];
                i = original_i;
                j = original_j;
            }
        }
    if(order >= 2)
        result = determinant(cofactor,order - 1);
    
    return result;
}