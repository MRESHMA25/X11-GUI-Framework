#include <iostream>
#include <random>
#include <sstream>
#include "Tester.h"
#include "CuWindow.h"
#include <unistd.h>



using namespace std;

// unit tests for Buttons and Panels
int testPrintButtons();
int testPrintPanels();
int testButtonsinPanel();

// Integration tests for CuWindow
int mwTestPanels();
int mwTestButtons();

void testRenderWindow();

void studentTests();

int main(){
    
    int choice = -1;
    while(choice != 0 && cin.good()){
        std::cout<<endl;
        std::cout<<" 0. Exit"<<endl;
        
        std::cout<<" 1. [3 marks] Test Buttons"<<endl;

        std::cout<<" 2. [3 marks] Test Panels"<<endl;
        std::cout<<" 3. [5 marks] Test add, remove, and print Buttons in Panel"<<endl;
        std::cout<<endl<<" CuWindow tests:"<<endl;
        std::cout<<" 4. [5 marks] Test add, remove, and print Panels in CuWindow"<<endl;
        std::cout<<" 5. [2 marks] Test add, remove, and print Buttons and Panels in CuWindow"<<endl<<endl; 
        std::cout<<" 6. [28 marks] Test all and get mark"<<endl<<endl;
        std::cout<<" 7. [6 marks, manual inspection] Test render window"<<endl;

        std::cout<<" 8. [4 marks, manual inspection] Student test code"<<endl<<endl;
        cin >> choice;
        std::cout<<endl;

        // clear the buffer since buffers are a pain in the butt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice)
        {
            case 1: testPrintButtons(); break;  
            case 2: testPrintPanels(); break;  
            case 3: testButtonsinPanel(); break;
            case 4: mwTestPanels(); break;
            case 5: mwTestButtons(); break;
            case 6: 
                {int score = 0;
                score += testPrintButtons();
                score += testPrintPanels();
                score += testButtonsinPanel();
                score += mwTestPanels();
                score += mwTestButtons();
                std::cout << "Your autograded score is "<<score<<" out of 18\n\nPlease add manual marks for rendering (out of 6) and tests (out of 4) for a total out of 28" << endl << endl;}
                // testRenderWindow();
                break;
            case 7: testRenderWindow(); break;
            case 8:
                studentTests();
                break;
        }
    }
    std::cout<<"Bye!"<<endl;
    return 0;  
}


Tester tester;

void studentTests(){
    // Make a window, try stuff out
    // RGB colour(0, 255, 0);  // change this to your favourite colour
    // CuWindow window("Test", 600, 600, colour);

    // make and add panels, add buttons to panels, etc
    // You should test, at least, different Button colours, different Window colours, 
    // and different placements of Panels and Buttons. There should be at least 
    // 4 different configurations of Panels and Buttons in your test. Each configuration must have
    // at least 2 Panels and 2 Buttons.

    // You can use tester.pressEnterToContinue() to pause the program between configurations
}


int testPrintButtons(){
    string labels[5] = {"Button 1", "Button 2", "Button 3", "Button 4", "Button 5"};
    Button buttons[5];
    string ycoords[5] = {"10", "70", "130", "190", "250"};
    string widths[5] = {"20", "31", "42", "53", "64"};
    for (int i = 0; i < 5; i++){
        buttons[i] = Button(10 + 10*i, 10 + 60*i, 20+11*i, 50, labels[i], CuBlack, CuWhite);
    }

    cout<<"Button print test"<<endl<<endl;

    tester.initCapture();
    for (int i = 0; i < 5; i++){
        buttons[i].print();
    }
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.findInOrder({0,1,2,3,4}, labels, error);

    if (error == 0){
        cout<<"Label printing test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Label printing test failed"<<endl;
    }

    error = 0;
    tester.findInOrder({0,1,2,3,4}, ycoords, error);

    if (error == 0){
        cout<<"Y coordinate printing test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Y coordinate printing test failed"<<endl;
    }

    error = 0;

    tester.findInOrder({0,1,2,3,4}, widths, error);

    if (error == 0){
        cout<<"Width printing test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Width printing test failed"<<endl;
    }

    cout<<"Button print test score: "<<score<<"/3"<<endl<<endl;

    return score;
}

int testPrintPanels(){
    string ids[5] = {"Panel 1", "Panel 2", "Panel 3", "Panel 4", "Panel 5"};
    Panel panels[5];
    string ycoords[5] = {"10", "70", "130", "190", "250"};
    string widths[5] = {"20", "31", "42", "53", "64"};
    for (int i = 0; i < 5; i++){
        panels[i] = Panel(10 + 10*i, 10 + 60*i, 20+11*i, 50, ids[i]);
    }

    cout<<"Panel print test"<<endl<<endl;

    tester.initCapture();
    for (int i = 0; i < 5; i++){
        panels[i].print();
    }
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.findInOrder({0,1,2,3,4}, ids, error);

    if (error == 0){
        cout<<"ID printing test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"ID printing test failed"<<endl;
    }

    error = 0;
    tester.findInOrder({0,1,2,3,4}, ycoords, error);

    if (error == 0){
        cout<<"Y coordinate printing test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Y coordinate printing test failed"<<endl;
    }

    error = 0;

    tester.findInOrder({0,1,2,3,4}, widths, error);

    if (error == 0){
        cout<<"Width printing test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Width printing test failed"<<endl;
    }

    cout<<"Panel print test score: "<<score<<"/3"<<endl<<endl;

    return score;
}

int testButtonsinPanel(){
    Panel panel(10, 10, 200, 200, "Panel 1");
    Button button1(10, 10, 80, 50, "Button 1", CuBlack, CuWhite);
    Button button2(10, 50, 80, 50, "Button 2", CuBlack, CuWhite);
    Button button3(10, 130, 80, 50, "Button 3", CuBlack, CuWhite);
    Button button4(80, 130, 80, 50, "Button 4", CuBlack, CuWhite);
    Button button5(100, 130, 80, 50, "Button 5", CuBlack, CuWhite);
    Button button6(100, 180, 80, 50, "Button 6", CuBlack, CuWhite);
    panel.addButton(button1);
    panel.addButton(button2);
    panel.addButton(button3);
    panel.addButton(button4);
    panel.addButton(button5);
    panel.addButton(button6);

    cout<<"Panel buttons test"<<endl<<endl;

    tester.initCapture();
    panel.printButtons();
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({"Button 1", "Button 3", "Button 5"}, error);

    if (error == 0){
        cout<<"Correct buttons found, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Not all Buttons found, test failed"<<endl;
    }

    error = 0;
    tester.confirmAbsent({"Button 2", "Button 4", "Button 6"}, error);

    if (error == 0){
        cout<<"Button 2, 4 and 6 not found, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Button 2 or 4 or 6 was added but should not be, test failed"<<endl;
    }

    panel.removeButton("Button 3");

    error = 0;
    tester.initCapture();
    panel.printButtons();
    tester.endCapture();

    error = 0;

    tester.find({"Button 1", "Button 5"}, error);

    if (error == 0){
        cout<<"Correct buttons found after removal, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Not all Buttons found after removal, test failed"<<endl;
    }

    error = 0;
    tester.confirmAbsent({"Button 3"}, error);

    if (error == 0){
        cout<<"Button 3 not found after removal, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Button 3 was not removed, test failed"<<endl;
    }

    panel.removeButton("Button 1");
    panel.removeButton("Button 5");

    error = 0;
    tester.initCapture();
    panel.printButtons();
    tester.endCapture();

    error = 0;

    tester.confirmAbsent({"Button 1", "Button 5"}, error);

    if (error == 0){
        cout<<"Button 1 and 5 not found after removal, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Button 1 or 5 was not removed, test failed"<<endl;
    }

    cout<<"Panel buttons test score: "<<score<<"/5"<<endl<<endl;

    return score;
}


int mwTestPanels(){
    RGB colour(0, 255, 0);
    CuWindow window("Test", 600, 600, colour);
    Panel panel1(10, 10, 80, 50, "Panel 1");
    Panel panel2(10, 50, 80, 50, "Panel 2");
    Panel panel3(10, 60, 80, 50, "Panel 3");
    Panel panel4(80, 60, 80, 50, "Panel 4");
    Panel panel5(100, 60, 80, 50, "Panel 5");
    Panel panel6(100, 180, 550, 50, "Panel 6");

    Button button1(10, 10, 80, 50, "Button 1", CuBlack, CuWhite);
    Button button2(10, 50, 80, 50, "Button 2", CuBlack, CuWhite);

    panel1.addButton(button1);
    panel3.addButton(button2);

    window.addPanel(panel1);
    window.addPanel(panel2);
    window.addPanel(panel3);
    window.addPanel(panel4);
    window.addPanel(panel5);
    window.addPanel(panel6);

    cout<<"CuWindow panels test"<<endl<<endl;

    tester.initCapture();
    window.printPanels();
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({"Panel 1", "Panel 3",  "Panel 5"}, error);

    if (error == 0){
        cout<<"Correct panels found, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Not all Panels found, test failed"<<endl;
    }

    error = 0;

    tester.confirmAbsent({"Panel 2", "Panel 4", "Panel 6"}, error);

    if (error == 0){
        cout<<"Panel 2, 4 and 6 not found, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Panel 2 or 4 or 6 was added but should not be, test failed"<<endl;
    }

    window.removePanel("Panel 3");

    error = 0;
    tester.initCapture();
    window.printPanels();
    tester.endCapture();

    error = 0;

    tester.find({"Panel 1", "Panel 5"}, error);

    if (error == 0){
        cout<<"Correct panels found after removal, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Not all Panels found after removal, test failed"<<endl;
    }

    error = 0;
    tester.confirmAbsent({"Panel 3"}, error);

    if (error == 0){
        cout<<"Panel 3 not found after removal, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Panel 3 was not removed, test failed"<<endl;
    }

    window.removePanel("Panel 1");
    window.removePanel("Panel 5");

    error = 0;

    tester.initCapture();
    window.printPanels();
    tester.endCapture();

    error = 0;

    tester.confirmAbsent( {"Panel 1", "Panel 5"}, error);

    if (error == 0){
        cout<<"Panel 1 and 5 not found after removal, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Panel 1 or 5 was not removed, test failed"<<endl;
    }

    cout<<"CuWindow panels test score: "<<score<<"/5"<<endl<<endl;

    return score;
}

int mwTestButtons(){

    RGB red(255, 0, 0);
    CuWindow window("Test", 600, 600, red);
    Panel panel1(0, 0, 600, 300, "Panel 1");
    Panel panel2(0, 300, 600, 300, "Panel 2");

    Button button1(10, 10, 80, 50, "Button 1", CuBlack, CuWhite);
    Button button2(10, 70, 80, 50, "Button 2", CuBlack, CuWhite);
    Button button3(10, 130, 80, 50, "Button 3", CuBlack, CuWhite);
    Button button4(80, 130, 80, 50, "Button 4", CuBlack, CuWhite);

    panel1.addButton(button1);
    panel1.addButton(button2);
    panel1.addButton(button3);
    // panel1.addButton(button4);

    panel2.addButton(button1);
    panel2.addButton(button2);
    // panel2.addButton(button3);
    panel2.addButton(button4);

    window.addPanel(panel1);
    window.addPanel(panel2);

    cout<<"CuWindow buttons test"<<endl<<endl;

    tester.initCapture();
    window.printPanelButtons();
    tester.endCapture();

    int error = 0;
    
    int score = 0;

    tester.findInOrder({"Button 1", "Button 2", "Button 3", "Button 1", "Button 2", "Button 4"}, error);

    if (error == 0){
        cout<<"Correct buttons found in correct order, test passed, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Not all Buttons found or found out of order, test failed"<<endl;
    }

    panel1.removeButton("Button 3");
    panel2.removeButton("Button 4");

    tester.initCapture();
    window.printPanelButtons();
    tester.endCapture();

    error = 0;
    tester.findInOrder({"Button 1", "Button 2", "Button 3", "Button 1", "Button 2", "Button 4"}, error);

    if (error == 0){
        cout<<"Copy of Panels were made correctly, 1 mark"<<endl;
        score += 1;
    } else {
        cout<<"Panels not copied into CuWindow correctly, test failed"<<endl;
    }

    cout<<"CuWindow buttons test score: "<<score<<"/2"<<endl<<endl;

    return score;
}

void testRenderWindow(){

    RGB colour(0, 255, 0);

    cout<<"The background colour in hex is: "<<hex<<colour.getColour()<<endl;
    cout<<"The rgb values are: "<<dec<<colour.getR()<<" "<<colour.getG()<<" "<<colour.getB()<<endl;
    CuWindow window("Test", 600, 600, colour);
    Panel panel1(0, 0, 600, 300, "Panel 1");
    Panel panel2(0, 300, 600, 300, "Panel 2");

    Button button1(10, 10, 80, 50, "Button 1", CuBlack, CuWhite);
    Button button2(10, 70, 80, 50, "Button 2", CuBlack, CuWhite);
    Button button3(10, 130, 80, 50, "Button 3", CuBlack, CuWhite);
    Button button4(80, 130, 80, 50, "Button 4", CuBlack, CuWhite);

    panel1.addButton(button1);
    panel1.addButton(button2);
    panel1.addButton(button3);
    // panel1.addButton(button4);

    panel2.addButton(button1);
    panel2.addButton(button2);
    // panel2.addButton(button3);
    panel2.addButton(button4);

    window.addPanel(panel1);
    window.addPanel(panel2);

    cout<<"CuWindow render test"<<endl<<endl;

    
    window.draw();

    cout<<"Window rendered, please check if it looks correct (see specification for details)"<<endl;
    tester.pressEnterToContinue();

    cout<<"Removing panel 1"<<endl;
    window.removePanel("Panel 1");

    window.draw();

    cout<<"Window rendered, please check if it looks correct (see specification for details)"<<endl;
    tester.pressEnterToContinue();
    
}

