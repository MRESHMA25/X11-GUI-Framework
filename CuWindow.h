#ifndef CuWindow_H
#define CuWindow_H

#include <iostream>
#include <string>
#include <X11/Xlib.h>
#include "defs.h"
#include "Panel.h"
#include "RGB.h"


using namespace std;

class CuWindow {
		
	public:
		//constructor
		CuWindow(string name, int width, int height, RGB& color);
		CuWindow(string name, int width, int height, CuColour color);
		~CuWindow();

		// bool addPanel(int x, int y, int width, int height);
		bool addPanel(Panel& panel);
		bool removePanel(string id);
		Panel* getPanel(string id);

		void draw();
		
		void print();
		void printPanels();
		void printPanelButtons();
	
	private:
		Display *display;
		Window   win;
		GC       gc;

		int width;
		int height;
		RGB background;

		string name; 

		Panel panels[MAX_COMPONENTS];
		int panelCount;
	
};
#endif