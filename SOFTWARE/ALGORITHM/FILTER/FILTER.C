#include "FILTER.H"
u16 filter(u16 *ary,u8 num,u16 MaxValue,u16 MinValue)
{
	int angleDataloopTemp2;
	u16 finalData=0;
	int maxValue = MinValue;
	int minValue = MaxValue;
	for (angleDataloopTemp2 = 0; angleDataloopTemp2 < num; angleDataloopTemp2++) //�ҳ����ֵ����Сֵ
	{
		if (ary[angleDataloopTemp2] > maxValue) //ȥ�����ֵ��Сֵ
		{
			maxValue = ary[angleDataloopTemp2];
		}
		if (ary[angleDataloopTemp2] < minValue) //ȥ�����ֵ��Сֵ
		{
			minValue = ary[angleDataloopTemp2];
		}
		finalData += ary[angleDataloopTemp2];
	}
	finalData -= (maxValue + minValue);  //ȥ�����ֵ��Сֵ
	finalData /= (num-2);	 //ȡƽ��ֵ
	return finalData;
}