/************************************************************
* ��֯���ƣ�
* �ļ�����: BUTTON.c
* ����:  �ܳ���
* �汾 : v1.0
* ����:
* ����: ������ʼ������غ���
* ��Ҫ�������书�� : 

* ��ʷ�޸ļ�¼: // ��ʷ�޸ļ�¼
* <����> <ʱ��> <�汾 > <����>
* �ܳ���
***********************************************************/
#include "BUTTON.h"
#include "../../BSP/delay.h"

#define BUTTON
#ifdef BUTTON
//extern  struct PID pid;
/*************************************************
* ��������: void Button_config()
* ����: Ƭ�ϰ���io��ʼ������
* ����˵��: ��ʼ�� P23,24,25,26Ϊ����
*************************************************/
void Button_config(void)
{
    GPIO_InitTypeDef    GPIO_InitStructure;     //�ṹ����
    GPIO_InitStructure.Pin  = BUTTON1_GPIO_PIN | BUTTON2_GPIO_PIN | BUTTON3_GPIO_PIN|BUTTON4_GPIO_PIN;      //ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
    GPIO_InitStructure.Mode = GPIO_PullUp;       //ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);  //��ʼ��
    P23=1;
    P24=1;
    P25=1;
    P26=1;
}
/*************************************************
* ��������:static bit digitalRead(pin)//��ȡ����״̬����,���°�������1��û���·���0
* ����: �����������ŵ�ƽ��ȡ����
* ����: ��Ҫ��ȡ��pin* ���:
* ����ֵ: ���ŵ�ƽ�����·���1��δ���·���0
* ����˵��: �ڲ��������ⲿ�������
*************************************************/
static bit digitalRead(pin)//��ȡ����״̬����,���°�������1��û���·���0
{
    if(!pin)
    {
        return !pin;
    }
}
static bit BUTTON1_bit=0;
static bit BUTTON2_bit=0;
static bit BUTTON3_bit=0;
static bit BUTTON4_bit=0;
/*************************************************
* ��������: bit getButtonState(u8 BUTTON_data)
* ����: ����״̬��ȡ
* ����: �������ź�
* ����ֵ: ����״̬�����·���1��δ���·���0
* ����˵��: �˺���Ϊ���ӿں���
*************************************************/
bit getButtonState(u8 BUTTON_data)
{
    switch(BUTTON_data)
    {
    case BUTTON1_GPIO_PIN:
        return   BUTTON1_bit;
        break;
    case BUTTON2_GPIO_PIN:
        return   BUTTON2_bit;
        break;
    case BUTTON3_GPIO_PIN:
        return   BUTTON3_bit;
        break;
    case BUTTON4_GPIO_PIN:
        return   BUTTON4_bit;
        break;
    }
}
/*************************************************
* ��������: void  buttonScan(void )//����ɨ�躯��
* ����: ����������
* ����: ��
* ���: ��
* ����ֵ: ��
* ����˵��: �˰���������û��ʹ�õ���ʱ����
*           ���ں����Ĺ����иĽ��˺���
*************************************************/
void  buttonScan(void )//����ɨ�躯��
{
    if(digitalRead(BUTTON1))
    {
        if(digitalRead(BUTTON1))
        {
#ifdef BUTTON_DEBUG
            PrintString1("BUTTON1 is on\n");
#endif
            BUTTON1_bit=1;
        }
    }
    else
    {
        BUTTON1_bit=0;
    }
    if(digitalRead(BUTTON2))
    {
        if(!BUTTON2_bit)
        {
#ifdef BUTTON_DEBUG
            PrintString1("BUTTON2 is on\n");
#endif
            BUTTON2_bit=1;
        }
    }
    else
    {
        BUTTON2_bit=0;
    }
    if(digitalRead(BUTTON3))
    {
        if(!BUTTON3_bit)
        {
#ifdef BUTTON_DEBUG
            PrintString1("BUTTON3 is on\n");
#endif
            BUTTON3_bit=1;
           
        }
    }
    else
    {
        BUTTON3_bit=0;
    }
    if(digitalRead(BUTTON4))
    {
        if(!BUTTON4_bit)
        {
#ifdef BUTTON_DEBUG
            PrintString1("BUTTON4 is on\n");
#endif
            BUTTON4_bit=1;
           
        }
    }
    else
    {
        BUTTON4_bit=0;
    }
}
#endif