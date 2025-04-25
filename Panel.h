#ifndef PANEL_H
#define PANEL_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>

#include "defs.h"
#include "Button.h"

using namespace std;

class Panel {
		
	public:
		//constructor
		Panel(int x, int y, int width, int height, string id);
		Panel();

		bool addButton(Button& button);
		bool removeButton(string id);

		// setters
		void setId(string id);
		void setPosition(int x, int y);
		void setX(int x);
		void setY(int y);
		
		void setSize(int width, int height);
		void setWidth(int width);
		void setHeight(int height);

		// getters
		string getId();
		int getX();
		int getY();
		int getWidth();
		int getHeight();

		void draw(Display *display, Window& win, GC& gc);

		bool overlaps(Panel& panel);
		
		void print();
		void printButtons();
	
	private:
		int x;
		int y;
		int width;
		int height;
		string id;

		Button buttons[MAX_COMPONENTS];
		int buttonCount;


	
};
#endif