//T09_G01
// Created by juan on 20/04/21.
//
#define FENCE '*'
#define NONELECPOST '+'
#define EXITDOOR 'O'
#define DEADROBOT 'r'
#define LIVEROBOT 'R'
#define DEADHUMAN 'h'
#define LIVEHUMAN 'H'
#define DASHLINE '-'
#define SPACEBAR ' '
#define LIMIT 20
#define NAMESIZE 16
#define NEWLINE '\n'
#define ONE 1
#define TWO 2
#define ZERO 0

#define NO_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define WARNING "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[35m"
#define PINK "\033[1;31m"
#define ORANGE "\033[33m"

#define BG_BLACK "\033[47;30m"
#define BG_GREEN "\033[47;32m"
#define BG_BLUE "\033[47;1;34m"
#define BG_PURPLE "\033[47;35m"
#define BG_PINK "\033[47;1;31m"
/**
void setTextColor(const std::string &color)
{
	std::cout << color;
}


void writeColoredText(const std::string &color, const std::string &text) {
	setTextColor(color);
	if (WARNING == color) {
		std::cerr << text;
	}
	else {
		std::cout << text;
	}
	setTextColor(NO_COLOR);
}
**/