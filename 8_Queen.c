
#include <stdio.h>
#include <stdlib.h>

#define N 15

int n; //�ʺ����
int sum = 0; //���н����
int x[N]; //�ʺ���õ�����

/*
 *�жϺ������жϵ�k���ʺ��Ƿ���Է���ĳһ��λ��
 *�����֮ǰ�Ļʺ������ͬһ�л�ͬһ�Խ��������ʧ�ܣ�����0�����򷵻�1
*/
int place(int k)
{
    int i;
    for(i=1;i<k;i++)
      if(abs(k-i)==abs(x[k]-x[i]) || x[k] == x[i])
        return 0;
    return 1;
}

/*
 *�����н⺯��������t���ʺ���Է�����t�е�ĳһλ��ʱ������������һ�ʺ�ֱ��
 *���лʺ���ý��������ĳһ�ʺ��ܷ��ã���������һ�з��ã������һ�ж����ܷ�
 *�û����лʺ���ý�����������һ�ʺ����·��ã����շ������п��н������
*/
int queen(int t)
{
    int i;
	if(t>n && n>0) //�����õĻʺ󳬹�nʱ�����н������1����ʱn�������0
      sum++;
    else
    {
		for(i=1;i<=n;i++)
		{
          x[t] = i; //������t���ʺ���ڵ�i��
          if(place(t)) //������Է���ĳһλ�ã����������һ�ʺ�
            queen(t+1); 
		}
	}
    return sum;
}

int main()
{
    int t;
    scanf("%d",&n);
    
    if(n == 0) //���n=0������н����Ϊ0���������һ����Ҫ����
      t = 0;
	else
		t = queen(1);
    printf("%d\n",t);
    return 0;
}
