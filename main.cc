//#include "GeneralInfo.h"
#include "block.h"
#include "grid.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <memory>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "GeneralInfo.h"
#include "graphicsdisplay.h"
#include <cctype>
//#include
using namespace std;

// 85 86 69
int main(int argc, const char* argv[]) {
	multimap<string, string> command_List={
		{"left", "left"},
		{"lef", "left"},
		{"right", "right"},
		{"righ", "right"},
		{"rig", "right"},
		{"ri", "right"},
		{"down", "down"},
		{"dow", "down"},
		{"do", "down"},
		{"drop", "drop"},
		{"dro", "drop"},
		{"dr", "drop"},
		{"restart", "restart"},
		{"restar", "restart"},
		{"resta", "restart"},
		{"rest", "restart"},
		{"res", "restart"},
		{"re", "restart"},
		{"levelu", "levelup"},
		{"levelup", "levelup"},
		{"leveldown", "leveldown"},
		{"leveldow", "leveldown"},
		{"leveldo", "leveldown"},
		{"leveld", "leveldown"},
		{"random", "random"},
		{"rando", "random"},
		{"rand", "random"},
		{"ran", "random"},
		{"ra", "random"},
		{"norandom", "norandom"},
		{"norando", "norandom"},
		{"norand", "norandom"},
		{"noran", "norandom"},
		{"nora", "norandom"},
		{"nor", "norandom"},
		{"sequence", "sequence"},
		{"sequenc", "sequence"},
		{"sequen", "sequence"},
		{"seque", "sequence"},
		{"sequ", "sequence"},
		{"seq", "sequence"},
		{"se", "sequence"},
		{"s", "sequence"},
		{"rename", "rename"},
	};
	//	typedef multimap<string, string>::iterator cmdIt;

	// owen add here
	//int blockdropcount = 0;
	ifstream ifn;
	//

	string input;
	string cmd;
	string fname = "sequence.txt";
	int lvl = 0;
	int seed = time(NULL);
	bool text = true;
	int score = 0;
	int highScore = 0;
	int cleared = 0;
	int uselessMoves = 0;
	stringstream ss;
	bool heavy = 0;
	bool c_req = 0;
	//bool repeat = 0;
	//int repeat_num = 0;
	string rpdCmd;
	for (int i = 0; i < argc; i++){
		cmd = argv[i]; 
		if (cmd=="-seed"){
			string s = argv[i+1];
			ss>>seed;
		} else if (cmd=="-scriptfile")
			fname = argv[i+1];	
		  else if (cmd=="-startlevel"){
			string s = argv[i+1];
			ss >> lvl;
		}  else if (cmd=="-text")
			text = false;
	}
	Grid g;
	g.init();
	//cout<<g<<endl;
	
	cout<< "Command Lists:"<<endl;
	cout<< "left: Moves block to the left."<<endl;
	cout<< "right: Moves block to the right."<<endl;
	cout<< "down: Moves one row down."<<endl;
	cout<< "clockwise: Rotates block 90 degrees clockwise."<<endl;
	cout<< "counterclockwise: Rotates block 90 degrees counter-clockwise."<<endl;

	Level* currLvl;
	if (lvl == 0) 
		currLvl = new Level0{fname};
	else if (lvl == 1) 
		currLvl = new Level1{};
	else if (lvl == 2)
		currLvl = new Level2{};
	else if (lvl == 3){
		currLvl = new Level3{};
		heavy = 1;
	} else{
		currLvl = new Level4{};
		heavy = 1;
		c_req = 1;
	}
	Block* currBlock = currLvl->generateBlock();
    currBlock->init(g);
    cout<<g<<endl; //lololo
	Block* nextBlock = currLvl->generateBlock();
	cout << nextBlock->getletter()<<endl;
	cout<<"Level:      "<<lvl<<endl;
	cout<<"Score:      "<<score<<endl;
	cout<<"High Score: "<<highScore<<endl;
	cout<<"+++++++++++"<<endl;
	cout<<g;
	cout<<"+++++++++++"<<endl;
	cout<<"Next:       "<<endl;
	//add code here
	if (g.ob == nullptr) {
		cout << " no observer. must debug";
	} else {
		g.ob->drawGeneralInfo(lvl,score,highScore,nextBlock->getletter());
	}
	//codes end here
	if (nextBlock->getletter() == 'S') {
		cout<<"   "<<" SS"<<endl;
		cout<<"   "<<"SS"<<endl;
	} else if (nextBlock->getletter() == 'Z') {
		cout<<"   "<<"ZZ"<<endl;
		cout<<"   "<<" ZZ"<<endl;
	} else if (nextBlock->getletter() == 'I') {
		cout<<"   "<<"IIII"<<endl<<endl;
	} else if (nextBlock->getletter() == 'O') {
		cout<<"   "<<"OO"<<endl;
		cout<<"   "<<"OO"<<endl;
	}else if(nextBlock->getletter() == 'L') {
		cout<<"   "<<"  L"<<endl;
		cout<<"   "<<"LLL"<<endl;
	} else if(nextBlock->getletter() == 'J') {
		cout<<"   "<<"J  "<<endl;
		cout<<"   "<<"JJJ"<<endl;
	} else if(nextBlock->getletter() == 'T') {
		cout<<"   "<<" T "<<endl;
		cout<<"   "<<"TTT"<<endl;
	}
	g.setNext(nextBlock);
	while (true) {
		if (ifn.is_open() && (!ifn.eof())) {
			ifn >> input;
			cout << input <<endl;
			if (ifn.eof()) {
				ifn.close();
			}
		} else {
			cin >> input;
		}
		auto result = command_List.equal_range(input);
		cmd = input;
		for (auto i = result.first; i!= result.second; ++i)
			cmd = i->second;
		if (cmd == "left"){
			try{
				currBlock->left(g);
				if (heavy)
					currBlock->down(g);
			}catch(...){}
			
				//function calli
		} else if (cmd == "right"){
			try{
				currBlock->right(g);
				if (heavy)
					currBlock->down(g);
			}catch(...){}
				//function call
		} else if (cmd == "down"){
			try {
				currBlock->down(g);
			}catch(...){}
				//function call

		} else if (cmd == "clockwise"){
			try {
				currBlock->clockWise(g);
			}catch(...){}
				//function call
		} else if (cmd == "counterclockwise"){
			try {
				currBlock->counterClockWise(g);
			}catch(...){}		//function call
		} else if (cmd == "drop"){
			try {
				currBlock->drop(g);
				cleared = g.checkRows();
				if (cleared == 0) 
					uselessMoves++;
				else
					uselessMoves=0;
				//cout << uselessMoves << endl;
				if(lvl==4 && (uselessMoves % 5 == 0)) {
					Block *nb = currLvl->getnullblock();
					cout << "hello" << endl;
					nb->init(g);
					cout << "hello 1" << endl;
					nb->drop(g);
					cout << "hello 2" << endl;
					delete nb;
					cout << "hello 3" << endl;
					cleared = g.checkRows(); 
					cout << "hello 4" << endl;
				}
				if (cleared != 0){
					score+= ((cleared+lvl)*(cleared+lvl));
					cleared = 0;
				}
				if (!g.endGame()) {
				//	v.emplace_back({currBlock, currBlock->getletter(), lvl});
					delete currBlock;
					currBlock = nextBlock;
                   	currBlock->init(g);
                   	// if (ifn.is_open() && (! ifn.eof())) {
                   	// 	if (! ifn.eof()) {
                   	// 		char c;
                   	// 		ifn >> c;
                   	// 		cout << c << endl;
                   	// 		if (c == 'I') {
                   	// 			nextBlock = new IBlock{};
                   	// 		} else if (c =='J') {
                   	// 			nextBlock = new JBlock{};
                   	// 		} else if (c =='L') {
                   	// 			nextBlock = new LBlock{};
                   	// 		} else if (c =='O') {
                   	// 			nextBlock = new OBlock{};
                   	// 		} else if (c =='S') {
                   	// 			nextBlock = new SBlock{};
                   	// 		} else if (c =='Z') {
                   	// 			nextBlock = new ZBlock{};
                   	// 		} else {
                   	// 			nextBlock = new TBlock{};
                   	// 		} 
                   	// 	} else {
                   	// 		ifn.close();
                   	// 	}
                   	// } else {
					nextBlock = currLvl->generateBlock();
					g.setNext(nextBlock);
				} else {
                   			cout<<"Game Over" << endl;
                   			 return 0;
				}
				// owen add code here 
			}catch(...){}
				//function call
		} else if (cmd == "levelup"){
			if (lvl !=4){
				lvl++;		
				delete currLvl;	
			}
			if (lvl==4){
				c_req = 1;
				currLvl = new Level4{};
			}
			if (lvl==3){ 
				heavy=1;
				currLvl = new Level3{};
			} 
			if (lvl == 2)
				currLvl = new Level2{};
			if(lvl == 1)
				currLvl = new Level1{}; 
			
		} else if (cmd == "leveldown"){
			if (lvl!=0){
				lvl--;
				delete currLvl;
			}
                 
                        if (lvl==3){
                                c_req = 0;;
                                currLvl = new Level3{};
                        }
                        if (lvl==2){
                                heavy=0;
                                currLvl = new Level2{};
                        }
                        if (lvl == 1)
                                currLvl = new Level1{};
                        if(lvl == 0)
                                currLvl = new Level0(fname);
				//function call
			
		} else if (cmd == "norandom") {
			cin>>fname;
			delete currLvl;	
			currLvl = new Level0{fname};
				
				//function call
		}else if (cmd == "random"){
			if (lvl == 3) {
				delete currLvl;	
				currLvl = new Level3{};
			} else if (lvl == 4) {
				delete currLvl;	
				currLvl = new Level4{};	
			}
		} else if (cmd == "sequence"){
			string commands;
			cin>>commands;
			ifn.open(commands);
		} else if (cmd == "I"){
			currBlock->unset(g);
			currBlock= new IBlock;
			currBlock->init(g);
				//function call
		} else if (cmd == "J"){

                        currBlock->unset(g);
                        currBlock= new JBlock;
                        currBlock->init(g);

				//function call
		} else if (cmd == "L"){

                        currBlock->unset(g);
                        currBlock= new LBlock;
                        currBlock->init(g);

			//function call
		} else if (cmd == "O"){
			
                        currBlock->unset(g);
                        currBlock= new OBlock;
                        currBlock->init(g);

				//function call
		} else if (cmd == "S"){

                        currBlock->unset(g);
                        currBlock= new SBlock;
                        currBlock->init(g);

				//function call
		} else if (cmd == "Z"){
			
                        currBlock->unset(g);
                        currBlock= new ZBlock;
                        currBlock->init(g);

				//function call
		} else if (cmd == "T"){

                        currBlock->unset(g);
                        currBlock= new TBlock;
                        currBlock->init(g);

				//function call
		} else if (cmd == "restart"){
			if (score>highScore){
				highScore = score;
			}
			score = 0;
			g.init();
      	      		currBlock = currLvl->generateBlock();
        		nextBlock = currLvl->generateBlock();
			currBlock->init(g);
			//function call
		}else if(cmd== "rename") {
				string instruction;
				string shortCut;
				cin>>instruction;
				cin>>shortCut;
				command_List.insert(pair<string, string>(shortCut, instruction));
		} else if (isdigit(cmd[0])) {
			int num = cmd[0] - '0';
			input = cmd.substr(1,cmd.size() - 1);
			result = command_List.equal_range(input);
			cmd = input;
			for (auto i = result.first; i!= result.second; ++i) {
				cmd = i->second;
			}
			while(num > 0) {
				if (cmd == "left"){
				try{
					currBlock->left(g);
				if (heavy)
					currBlock->down(g);
				}catch(...){}
			
				//function calli
				} else if (cmd == "right"){
				try{
					currBlock->right(g);
				if (heavy)
					currBlock->down(g);
				}catch(...){}
				//function call
				} else if (cmd == "down"){
					try {
					currBlock->down(g);
				}catch(...){}
				//function call
				} else if (cmd == "clockwise"){
					try {
					currBlock->clockWise(g);
				}catch(...){}
				//function call
				} else if (cmd == "counterclockwise"){
					try {
					currBlock->counterClockWise(g);
				}catch(...){}
			}
				num --;
			}
		}  else {
			cin.clear();
			cin.ignore();
			continue;
		}
		if (score >= highScore) 
			highScore = score;
			//if (game)
        		
        	cout<<"Level:      "<<lvl<<endl;
        	cout<<"Score:      "<<score<<endl;
        	cout<<"High Score: "<<highScore<<endl;
        	cout<<"+++++++++++"<<endl;
        	cout<<g;
        	cout<<"+++++++++++"<<endl;
        	cout<<"Next:       "<<endl;
        	if (nextBlock->getletter() == 'S') {
                	cout<<"   "<<" SS"<<endl;
                	cout<<"   "<<"SS"<<endl;
        	} else if (nextBlock->getletter() == 'Z') {
                	cout<<"   "<<"ZZ"<<endl;
   	             cout<<"   "<<" ZZ"<<endl;
		} else if (nextBlock->getletter() == 'I') {
        	        cout<<"   "<<"IIII"<<endl<<endl;
		} else if (nextBlock->getletter() == 'O') {
       		        cout<<"   "<<"OO"<<endl;
        	        cout<<"   "<<"OO"<<endl;
        	}else if(nextBlock->getletter() == 'L') {
                	cout<<"   "<<"  L"<<endl;
	                cout<<"   "<<"LLL"<<endl;
        	} else if(nextBlock->getletter() == 'J') {
 	               cout<<"   "<<"J  "<<endl;
        	        cout<<"   "<<"JJJ"<<endl;
      		  } else if(nextBlock->getletter() == 'T') {
        	        cout<<"   "<<" T "<<endl;
               		 cout<<"   "<<"TTT"<<endl;
        	}
        	// Owen adds codes here
        	g.ob->drawGeneralInfo(lvl,score,highScore,nextBlock->getletter());
        	//end adding code.
	}
}
