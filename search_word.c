#include <stdio.h>
#include<string.h>

int searchWord(char S[],char W[]);

int main()
{
	char S[100] = "IIC1 IIC2 IIC3 SPI1 SPI2 SPI3 GPIO1 GPIO2 GPIO3";
	char temp[20];
	
	int i;
	printf("��������Ϊ��%s\n�������������ݣ�",S);
	gets(temp);
	i = searchWord(S,temp);
	
	if(i==-1)
		{
			printf("�����ڸ����ݣ�\n");
		}
	else
		{
			printf("�������Ϊ��%s\n",temp);
		}
		return 0;
}

int searchWord(char S[],char W[])
{
	int i,j;		//ѭ������
	int n;			//���ݳ���+1����\0����
	int k;			//��������
	
	n = strlen(S)+1;		//��ȡ���ݳ���+1����\0����
	k = strlen(W);			//��ȡ��������
	
	for(i = 0;i < n-k;i++)			//ѭ����n-k����Ϊn-k���棬�Ҳ�������k���ַ��Ĵ��ˡ�
	{
		for(j = 0;j < k;j++)			//ѭ����ÿ����ĸ  
		{
			if(S[i+j]!=W[j]||W[j]==' ')			//��S[i+j]����W[j]��ȣ����ߴ�����ֿո�ʱ���� 
				{
					break;
				}
		}
		if(j==k&&(S[i+j]==' '||S[i+j]=='\0')) 
			
					/*j==k����ʾ��������������ȫƥ�����ĸ(���ܻ����ǵ���)����String��tri��ʱƥ���ܳɹ��� 
            ��S[i+j]����' '����'\0',��ʾ���Ӻ���ָ���߽�������ƥ��Ķ���ǰ�治һ���ָ 
            ��String��ingƥ���ܳɹ�����String��triƥ��Ͳ��ܳɹ��ˡ�*/
            
			{
			if(i==0||(i > 0&&S[i-1]==' '))		//�˴��ж��Ƿ���ǰ�ָ�,ֻ�о��׺ʹ���ǰ�ָ�Ķ�����ǵ���
				{
					return i;
				}
			}
	}
	return -1;
}