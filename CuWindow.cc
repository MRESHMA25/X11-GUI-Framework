
#include "CuWindow.h"
#include <iostream>
#include <unistd.h>


CuWindow::CuWindow(string name, int width, int height, RGB& color){
    panelCount = 0;
    this->width = width;
    this->height = height;
    display = XOpenDisplay(NULL);
    if (display == NULL){
        cerr<<"Cannot open display"<<endl;
        exit(1);
    }
    this->name = name;
    background = color;

    // cout<<"Background colour: "<<hex<<background.getColour()<<endl;
    // cout<<"CuWindow constructor: The rgb values are: "<<background.getR()<<" "<<background.getG()<<" "<<background.getB()<<endl;
    // // Create a simple window, set the title and get the graphics context then
    // make is visible and get ready to draw
    
    // win = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0,
                    // width, height, 0, 0x000000, 0xFFFFFF);
    win = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0,
                    width, height, 0, 0x000000, background.getColour());
    XStoreName(display, win, name.c_str());
    gc = XCreateGC(display, win, 0, NULL);
    XMapWindow(display, win);
    XFlush(display);
    usleep(20000); 
}

CuWindow::CuWindow(string name, int width, int height, CuColour color){
    panelCount = 0;
    this->width = width;
    this->height = height;
    display = XOpenDisplay(NULL);
    if (display == NULL){
        cerr<<"Cannot open display"<<endl;
        exit(1);
    }
    this->name = name;
    background.setColour(color);
    // Create a simple window, set the title and get the graphics context then
    // make is visible and get ready to draw
    
    // win = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0,
                    // width, height, 0, 0x000000, 0xFFFFFF);
    win = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0,
                    width, height, 0, 0x000000, background.getColour());
    XStoreName(display, win, name.c_str());
    gc = XCreateGC(display, win, 0, NULL);
    XMapWindow(display, win);
    XFlush(display);
    usleep(20000); 
}

CuWindow::~CuWindow(){
    XFreeGC(display, gc);
    XDestroyWindow(display, win);
    XCloseDisplay(display);
}


bool CuWindow::addPanel(Panel& panel){
    
    if (panelCount >= MAX_COMPONENTS)return false;

    if (panel.getX() + panel.getWidth() > width || panel.getY() + panel.getHeight() > height){
        return false;
    }

    for (int i = 0; i < panelCount; i++){
        if (panels[i].overlaps(panel)){
            return false;
        }
    }

    panels[panelCount] = panel;
    panelCount++;
    return true;
}

bool CuWindow::removePanel(string id){
    for (int i = 0; i < panelCount; i++){
        if (panels[i].getId() == id){
            for (int j = i; j < panelCount - 1; j++){
                panels[j] = panels[j+1];
            }
            panelCount--;
            return true;
        }
    }
    return false;
}

Panel* CuWindow::getPanel(string id){
    for (int i = 0; i < panelCount; i++){
        if (panels[i].getId() == id){
            return &panels[i];
        }
    } 
    return nullptr;
}

void CuWindow::draw(){
    // draw the window
    usleep(100000);
    XSetForeground(display, gc, background.getColour());
    XFillRectangle(display, win, gc, 0, 0, 600, 600);

    for (int i = 0; i < panelCount; i++){
        panels[i].draw(display, win, gc);
    }

    XFlush(display);

}


void CuWindow::print(){
    cout<<"Window: "<<name<<endl;
    cout<<"Panels: "<<panelCount<<endl;
    
}

void CuWindow::printPanels(){
    for (int i = 0; i < panelCount; i++){
        panels[i].print();
    }
}

void CuWindow::printPanelButtons(){
    for (int i = 0; i < panelCount; i++){
        panels[i].printButtons();
    }
}