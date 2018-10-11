#ifndef _General_Info_H
#define _General_Info_H


class GeneralInfo {
	private:
		int score;
		int level;
		int hi_score;
		char nextBlockLetter;
	public:
		GeneralInfo(char nextBlockLetter, int score = 0, int level = 0, int hi_score = 0);
		friend int getScore(GeneralInfo);
		friend int getLevel(GeneralInfo);
		friend int get_hi_score(GeneralInfo);
		friend char getNextBlockLetter(GeneralInfo);
		bool is_valid_score(int s);
		bool is_valid_block(char c);
		bool is_valid_level(int l);
		void setScore(int s);
		void setLevel(int l);
		void set_hi_score(int h);
		void setNextBlockLetter(char c);
};

#endif
