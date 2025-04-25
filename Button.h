#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "RGB.h"

using namespace std;

class Button {
		
	public:
		//constructor
		Button(int x, int y, int width, int height, string label, RGB& fill, RGB& border);
		Button(int x, int y, int width, int height, string label, CuColour fill, CuColour border);
		Button();
		

		void draw(Display *display, Window& win, GC& gc, int parentX, int parentY);	
		bool overlaps(Button& button);

		//setters
		void setPosition(int x, int y);
		void setX(int x);
		void setY(int y);
		void setSize(int width, int height);
		void setWidth(int width);
		void setHeight(int height);

		//getters
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		string getLabel();
	
		void print();
	
	private:
		int x;
		int y;
		int width;
		int height;
		string label;
		RGB fill;
		RGB border;
	
};
#endif