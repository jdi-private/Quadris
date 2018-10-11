#include "textdisplay.h"
#include "info.h"
using namespace std;
TextDisplay::TextDisplay() {
	for (int i = 0; i < 18; i++) {
		vector<char> temp(11,'-');
		theDisplay.emplace_back(temp);
	} 
}

void TextDisplay::notify(Info frominfo) {
	//Info frominfo = whoNotified.getInfo();
    if (frominfo.type == ' ') {
        theDisplay[frominfo.x_cor][frominfo.y_cor] = '-';
    } else {
        theDisplay[frominfo.x_cor][frominfo.y_cor] = frominfo.type;
    }
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (auto c_col : td.theDisplay) {
		for (char c : c_col) {
			out << c;
		}
		out << endl;
	}
	return out;
}
