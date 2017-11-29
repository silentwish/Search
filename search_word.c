#include <stdio.h>
#include<string.h>

int searchWord(char S[],char W[]);

int main()
{
	char S[100] = "IIC1 IIC2 IIC3 SPI1 SPI2 SPI3 GPIO1 GPIO2 GPIO3";
	char temp[20];
	
	int i;
	printf("搜索内容为：%s\n请输入搜索内容：",S);
	gets(temp);
	i = searchWord(S,temp);
	
	if(i==-1)
		{
			printf("不存在该内容！\n");
		}
	else
		{
			printf("搜索结果为：%s\n",temp);
		}
		return 0;
}

int searchWord(char S[],char W[])
{
	int i,j;		//循环变量
	int n;			//内容长度+1（‘\0’）
	int k;			//搜索长度
	
	n = strlen(S)+1;		//获取内容长度+1（‘\0’）
	k = strlen(W);			//获取搜索长度
	
	for(i = 0;i < n-k;i++)			//循环到n-k，因为n-k后面，找不到含有k个字符的词了。
	{
		for(j = 0;j < k;j++)			//循环词每个字母  
		{
			if(S[i+j]!=W[j]||W[j]==' ')			//当S[i+j]不与W[j]相等，或者词里出现空格时跳出 
				{
					break;
				}
		}
		if(j==k&&(S[i+j]==' '||S[i+j]=='\0')) 
			
					/*j==k，表示内容里存在与词完全匹配的字母(可能还不是单词)。如String与tri此时匹配能成功。 
            而S[i+j]等于' '或者'\0',表示句子后面分割或者结束。但匹配的段落前面不一定分割。 
            如String与ing匹配能成功，但String与tri匹配就不能成功了。*/
            
			{
			if(i==0||(i > 0&&S[i-1]==' '))		//此处判断是否有前分割,只有句首和存在前分割的段落才是单词
				{
					return i;
				}
			}
	}
	return -1;
}