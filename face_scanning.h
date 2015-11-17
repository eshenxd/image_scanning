/*
    * 代码名称： 图像扫描画面实现
	* 代码功能： opencv实现图像扫描动态画面功能
	* 代码作者： Ethan
	* 代码版本： 
	* V1.0(2015-11-16) 实现了上述主体功能，暂未发现问题
    * V2.0(2015-11-17) 更改了扫描不能随着位置的变化而变化的bug,增加了与facedetector类的接口
	*
*/
#pragma once
#ifndef _FACE_SCANNING_H_
#define _FACE_SCANNING_H_

#include "header.h"

static int drawHere_index;
static int flag = 0;

namespace ImgScan{
	
	/* 标示需要扫描的矩形块位置*/
	struct _Rect_
	{
		int top;
		int left;
		int bottom;
		int right;

		_Rect_(int* pos):top(pos[1]),left(pos[0]),bottom(pos[3]),right(pos[2]){}
	};
	/* 扫描器*/
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