/*
    * 代码名称： 图像扫描画面实现
	* 代码功能： opencv实现图像扫描动态画面功能
	* 代码作者： Ethan
	* 代码版本： 
	* V1.0(2015-11-16) 实现了上述主体功能，暂未发现问题
 */
#pragma once
#ifndef _FACE_SCANNING_H_
#define _FACE_SCANNING_H_

#include "header.h"

static int drawHere_y1;

struct _Rect_
{
	int top;
	int left;
	int bottom;
	int right;

	_Rect_(int x,int y,int m,int n):top(x),left(y),bottom(m),right(n){}
};

class Scanner
{
public:
	Scanner(_Rect_ rect){
		top_left = cvPoint(rect.left,rect.top);
		top_right = cvPoint(rect.right,rect.top);
		bottom_left = cvPoint(rect.left,rect.bottom);
		bottom_right = cvPoint(rect.right,rect.bottom);

		dis_long = (rect.bottom - rect.top)/10;
		gap = (rect.bottom - rect.top)/80 ;
		flag = 0;

		drawHere_y1 = top_left.y;
	}
	void loadScanImage(IplImage* image)
	{
	img = image;

	}
	
	void runScan(){

		drawRect();
	
		if(flag == 0){

			drawHere_y1 = drawHere_y1 + gap;
			p1 = cvPoint(top_left.x,drawHere_y1);
			p2 = cvPoint(top_right.x,drawHere_y1);
			cvLine(img,p1,p2,cvScalar(255,255,0),1,8,0);
			if(drawHere_y1 > (bottom_left.y-dis_long))flag = 1;	
		}
		if(flag == 1){
			drawHere_y1 = drawHere_y1 - gap;
			p1 = cvPoint(top_left.x,drawHere_y1);
			p2 = cvPoint(top_right.x,drawHere_y1);
			cvLine(img,p1,p2,cvScalar(255,255,0),1,8,0);
			if(drawHere_y1 < (top_left.y+dis_long))flag = 0;
			
			}
		img = NULL;
		}

private:
	IplImage* img ;
	CvPoint p1,p2;
	CvPoint top_left,top_right,bottom_left,bottom_right;
	int left_x,left_y,right_x,right_y;
	int dis_long;
	int flag;
	int gap;
	void drawRect(){

		cvLine(img,top_left,top_right,cvScalar(255,255,0),1,8,0);
		cvLine(img,top_left,cvPoint(top_left.x,top_left.y+dis_long),cvScalar(255,255,0),1,8,0);
		cvLine(img,top_right,cvPoint(top_right.x,top_right.y+dis_long),cvScalar(255,255,0),1,8,0);

		cvLine(img,bottom_left,bottom_right,cvScalar(255,255,0),1,8,0);
		cvLine(img,bottom_left,cvPoint(bottom_left.x,bottom_left.y-dis_long),cvScalar(255,255,0),1,8,0);
		cvLine(img,bottom_right,cvPoint(bottom_right.x,bottom_right.y-dis_long),cvScalar(255,255,0),1,8,0);

	}

};

#endif