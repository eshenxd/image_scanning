/*
    * �������ƣ� ͼ��ɨ�軭��ʵ��
	* ���빦�ܣ� opencvʵ��ͼ��ɨ�趯̬���湦��
	* �������ߣ� Ethan
	* ����汾�� 
	* V1.0(2015-11-16) ʵ�����������幦�ܣ���δ��������
    * V2.0(2015-11-17) ������ɨ�費������λ�õı仯���仯��bug,��������facedetector��Ľӿ�
	*
*/
#pragma once
#ifndef _FACE_SCANNING_H_
#define _FACE_SCANNING_H_

#include "header.h"

static int drawHere_index;
static int flag = 0;

namespace ImgScan{
	
	/* ��ʾ��Ҫɨ��ľ��ο�λ��*/
	struct _Rect_
	{
		int top;
		int left;
		int bottom;
		int right;

		_Rect_(int* pos):top(pos[1]),left(pos[0]),bottom(pos[3]),right(pos[2]){}
	};
	/* ɨ����*/
	class Scanner
	{
	public:
		Scanner(_Rect_ );
		~Scanner();

		inline void loadScanImage(IplImage* image){ img = image;}
		void runScan();

	
	private:
		IplImage* img ;
		CvPoint p1,p2;
		CvPoint top_left,top_right,bottom_left,bottom_right;
		int left_x,left_y,right_x,right_y;
		int dis_long_x,dis_long_y;

		int gap;
		int drawBegin;
	};

}

#endif