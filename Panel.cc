
#include "Panel.h"

Panel::Panel(int x, int y, int width, int height, string id){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    buttonCount = 0;
    this->id = id;
}

Panel::Panel(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    buttonCount = 0;
}

void Panel::setId(string id){
    this->id = id;
}

void Panel::setSize(int width, int height){
    this->width = width;
    this->height = height;
}

void Panel::setWidth(int width){
    this->width = width;
}

void Panel::setHeight(int height){
    this->height = height;
}

void Panel::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

void Panel::setX(int x){
    this->x = x;
}

void Panel::setY(int y){
    this->y = y;
}

//getters

string Panel::getId(){
    return id;
}

int Panel::getX(){
    return x;
}

int Panel::getY(){
    return y;
}

int Panel::getWidth(){
    return width;
}

int Panel::getHeight(){
    return height;
}


bool Panel::addButton(Button& button){
    if (buttonCount >= MAX_COMPONENTS) return false;

    if (button.getX() + button.getWidth() > width || button.getY() + button.getHeight() > height){
        return false;
    }
    
    for (int i = 0; i < buttonCount; i++){
        if (buttons[i].overlaps(button)){
            return false;
        }
    }
    
    buttons[buttonCount] = button;
    buttonCount++;
    return true;
}

bool Panel::removeButton(string label){
    for (int i = 0; i < buttonCount; i++){
        if (buttons[i].getLabel() == label){
            for (int j = i; j < buttonCount - 1; j++){
                buttons[j] = buttons[j+1];
            }
            buttonCount--;
            return true;
        }
    }
    return false;
}

void Panel::draw(Display* display, Window& win, GC& gc){
    // XSetForeground(display, gc, 0x000000);
    // XFillRectangle(display, win, gc, x, y, width, height);
    XSetForeground(display, gc, 0xFFFFFF);
    XDrawRectangle(display, win, gc, x, y, width, height);
    for (int i = 0; i < buttonCount; i++){
        buttons[i].draw(display, win, gc, x, y);
    }
}

bool Panel::overlaps(Panel& panel){
    if (x < panel.x + panel.width && x + width > panel.x && y < panel.y + panel.height && y + height > panel.y){
        return true;
    }
    if (panel.x < x + width && panel.x + panel.width > x && panel.y < y + height && panel.y + panel.height > y){
        return true;
    }
    return false;
}

void Panel::print(){
    cout<<"Panel:    "<<id<<endl;
    cout<<"Position: "<<x<<", "<<y<<endl;
    cout<<"Size:     "<<width<<", "<<height<<endl;
    cout<<"Buttons:  "<<buttonCount<<endl;
}

void Panel::printButtons(){
    for (int i = 0; i < buttonCount; i++){
        buttons[i].print();
        cout<<endl;
    }
}