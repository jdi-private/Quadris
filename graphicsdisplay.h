#ifndef _GRAPHICSDISPLAY_H_
#define _GRAPHICSDISPLAY_H_
#include "cell.h"
#include "observer.h"
#include "window.h"

class Xwindow;
class GraphicsDisplay:public Observer {
   Xwindow xd;
   void drawcell(int x, int y, int colour);
public:
   GraphicsDisplay();
   void notify(Info frominfo) override;
   void drawGeneralInfo(int level, int socre, int hi_score, char next_block);
   ~GraphicsDisplay() = default;

};
#endif

