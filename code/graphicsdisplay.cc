#include "graphicsdisplay.h"
#include <string>
#include <iostream>
using namespace std;

GraphicsDisplay::GraphicsDisplay():xd{Xwindow(1000,1600)} {
         
  xd.fillRectangle(195, 75, 5,1085 , Xwindow::Black);
  xd.fillRectangle(195, 75, 670, 5, Xwindow::Black);
  xd.fillRectangle(195, 1160, 670, 5, Xwindow::Black);
  xd.fillRectangle(860, 75, 5, 1085, Xwindow::Black);

  xd.drawBigString(400, 73, "QUADRIS");
  xd.drawString(10, 75, "Created by:");
  xd.drawString(10, 100, "Owen &");
  xd.drawString(10, 125, "Aaron &");
  xd.drawString(10, 150, "Jimmy");
}

void GraphicsDisplay::drawcell(int x, int y, int colour) {
  if (colour == Xwindow::White) {
   xd.fillRectangle(200 + (60 * y), 80 + (60 * x),60,60, Xwindow::White);
  } else {
    xd.fillRectangle(200 + (60 * y), 80 + (60 * x),60,5, Xwindow::Grey19);
    xd.fillRectangle(200 + (60 * y), 80 + (60 * x),5,60, Xwindow::Grey19);
    xd.fillRectangle(200 + (60 * y), 135 + (60 * x),60,5, Xwindow::Grey19);
    xd.fillRectangle(255 + (60 * y), 80 + (60 * x),5,60, Xwindow::Grey19);

    xd.fillRectangle(205 + (60 * y), 85 + (60 * x),50,50,colour);

  }
}

void GraphicsDisplay::notify(Info frominfo) {
   int x = frominfo.x_cor;
   int y = frominfo.y_cor;
   char type = frominfo.type;
    if (frominfo.type == ' ') {
       drawcell(x,y,Xwindow::White);
   } else if (type == 'I') {
       drawcell(x,y,Xwindow::Red);
   } else if (type == 'J') {
       drawcell(x,y,Xwindow::Green);
   } else if (type == 'Z') {
       drawcell(x,y,Xwindow::Cyan);
   } else if (type == 'O') {
       drawcell(x,y,Xwindow::Yellow);
   } else if (type == 'L') {
       drawcell(x,y,Xwindow::Magenta);
   } else if (frominfo.type == 'S') {
       drawcell(x,y,Xwindow::Orange);
   } else if (type == 'T'){
       drawcell(x,y,Xwindow::Black);
   } else {
       drawcell(x,y,Xwindow::Brown);
   }
}

void GraphicsDisplay::drawGeneralInfo(int level, int score, int hi_score, char next_block)  {
   //clear the board
   xd.fillRectangle(0, 0 ,195 ,1000, Xwindow::White);

   //int x_margin = 10;
   //int y_margin = 75;
   string l = "Level:";
   l = l.append(20 - to_string(level).length(), ' ');
   l = l.append(to_string(level));
   xd.drawString(10,150,l);

   string score_s = "Score:";
   score_s = score_s.append(20 - to_string(score).length(), ' ');
   score_s = score_s.append(to_string(score));
   xd.drawString(10,180,score_s);

   string hi_score_s = "Hi Score:";
   hi_score_s = hi_score_s.append(17 - to_string(hi_score).length(), ' ');
   hi_score_s = hi_score_s.append(to_string(hi_score));
   xd.drawString(10,210,hi_score_s);

   xd.drawString(10,240,"next");

   if (next_block == 'I') {
      xd.fillRectangle(10, 300 ,160 ,40, Xwindow::Red);
   } else if (next_block == 'J') {
      xd.fillRectangle(10, 260 ,40 ,80, Xwindow::Green);
      xd.fillRectangle(50, 300 ,80 ,40, Xwindow::Green);
  } else if (next_block == 'L'){
      xd.fillRectangle(10, 300 ,80 ,40, Xwindow::Magenta);
      xd.fillRectangle(90, 260 ,40 ,80, Xwindow::Magenta);
  } else if (next_block == 'O') {
      xd.fillRectangle(10, 260 ,80 ,80, Xwindow::Yellow);
  } else if (next_block == 'S') {
      xd.fillRectangle(10, 300 ,80 ,40, Xwindow::Orange);
      xd.fillRectangle(50, 260 ,80 ,40, Xwindow::Orange);
  } else if (next_block == 'Z') {
      xd.fillRectangle(50, 300 ,80 ,40, Xwindow::Cyan);
      xd.fillRectangle(10, 260 ,80 ,40, Xwindow::Cyan);
  } else {
      xd.fillRectangle(50, 300 ,40 ,40,Xwindow::Black);
      xd.fillRectangle(10, 260 ,120 ,40, Xwindow::Black);
  }
}

