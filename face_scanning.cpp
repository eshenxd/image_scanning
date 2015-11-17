#include "face_scanning.h"


namespace ImgScan{

	Scanner::Scanner(_Rect_ rect){
		top_left = cvPoint(rect.left,rect.top);
		top_right = cvPoint(rect.right,rect.top);
		bottom_left = cvPoint(rect.left,rect.bottom);
		bottom_right = cvPoint(rect.right,rect.bottom);

		dis_long_y = (rect.bottom - rect.top)/10;
		dis_long_x = (rect.right - rect.left)/10;
		gap = (rect.bottom - rect.top)/20 ;
		
		drawBegin = top_left.y;
	}

	Scanner::~Scanner(){}

	/* ÔËÐÐÉ¨ÃèÆ÷*/
	void Scanner::runScan(){

		int draw_y;

		if(flag == 0){
			draw_y =drawBegin + gap*drawHere_index;
			p1 = cvPoint(top_left.x,draw_y);
			p2 = cvPoint(top_right.x,draw_y);
			cvLine(img,p1,p2,cvScalar(255,255,0),1,8,0);
			drawHere_index++;
			if(draw_y > (bottom_left.y-dis_long_y))flag = 1;	
		}
		if(flag == 1){
			draw_y = drawBegin + gap*drawHere_index;;
			p1 = cvPoint(top_left.x,draw_y);
			p2 = cvPoint(top_right.x,draw_y);
			cvLine(img,p1,p2,cvScalar(255,255,0),1,8,0);
			drawHere_index--;
			if(draw_y < (top_left.y+dis_long_y))flag = 0;

		}
		img = NULL;
	}

}