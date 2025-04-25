
#include "Button.h"

Button::Button(int x, int y, int width, int height,  string label, RGB& fill, RGB& border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill = fill;
    this->border = border;
}

Button::Button(int x, int y, int width, int height, string label, CuColour fill, CuColour border){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->label = label;
    this->fill.setColour(fill);
    this->border.setColour(border);
}

Button::Button(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    label = "";
    fill = RGB(0, 0, 0);
    border = RGB(255, 255, 255);
}

bool Button::overlaps(Button& button){
    if (x < button.x + button.width && x + width > button.x && y < button.y + button.height && y + height > button.y){
        return true;
    }
    if (button.x < x + width && button.x + button.width > x && button.y < y + height && button.y + button.height > y){
        return true;
    }
    return false;
}

//setters

void Button::setPosition(int x, int y){
    this->x = x;
    this->y = y;
}

void Button::setX(int x){
    this->x = x;
}

void Button::setY(int y){
    this->y = y;
}

void Button::setSize(int width, int height){
    this->width = width;
    this->height = height;
}

void Button::setWidth(int width){
    this->width = width;
}

void Button::setHeight(int height){
    this->height = height;
}

//getters

int Button::getX(){
    return x;
}

int Button::getY(){
    return y;
}

int Button::getWidth(){
    return width;
}

int Button::getHeight(){
    return height;
}

string Button::getLabel(){
    return label;
}



void Button::draw(Display *display, Window& win, GC& gc, int parentX, int parentY){
    int x = this->x + parentX;
    int y = this->y + parentY;
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, width, height);
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, width, height);
    // const char *str = "Butt\non";
    // get the font structure
    // XFontStruct *font = XLoadQueryFont(display, "fixed");
    // int textWidth = XTextWidth(font, label.c_str(), label.length());
    const char* font_name = "fixed"; // You can specify a different font
    XID font = XLoadFont(display, font_name);
    XFontStruct* font_info = XQueryFont(display, font);
    if (!font_info) {
        XCloseDisplay(display);
        return; // Failed to query font
    }
    XSetFont(display, gc, font);

    int text_width = XTextWidth(font_info, label.c_str(), label.length());
    int length = label.length();

    //make sure it fits in the button
    while (text_width > width - 10){
        length--;
        text_width = XTextWidth(font_info, label.c_str(), length);
    }

    int offsetX = (width - text_width)/2;

    int text_height = font_info->ascent + font_info->descent;

    int offsetY = (height - text_height)/2 + font_info->ascent;

    // Cleanup
    XFreeFontInfo(NULL, font_info, 1);
    // cout<<"Text width: "<<textWidth<<endl;
    cout<<"Button width: "<<width<<endl;
    // XDrawString(display, win, gc, x + 10, y + 20, label.c_str(), label.length());
    XDrawImageString(display, win, gc, x+offsetX, y + offsetY, label.c_str(), length);
    // XDrawString(display, win, gc, x + 10, y + 20, str, 7);
    cout<<"Called draw on Button"<<endl;
}


void Button::print(){
    cout<<"Button:   "<<label<<endl;
    cout<<"Position: "<<x<<", "<<y<<endl;
    cout<<"Size:     "<<width<<", "<<height<<endl;
}