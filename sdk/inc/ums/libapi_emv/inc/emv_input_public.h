#pragma once

//��ȷ�ϼ�����(��Щ����ֱ�ӷ��������ֵ)
#define INPUT_INPUT_RET_OK			0
//��ȡ��������
#define INPUT_INPUT_RET_QUIT		-1
//��ʱ�˳�����
#define INPUT_INPUT_RET_TIMEOVER	-2


void input_PaintTitle(char* title);
void input_PaintHeader(char* header);
void input_PaintInput(char* inputContent);
void input_PaintFooter(char* footer);