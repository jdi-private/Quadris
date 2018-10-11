#ifndef _INFO_H
#define _INFO_H
struct Info {
	
	int x_cor;
	int y_cor;
	char type;

	Info(int x, int y, char c): x_cor{x}, y_cor{y}, type{c} { }
};

#endif
