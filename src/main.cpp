#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

char* img;
int iX = 1196;
int iY = 1200;


class t : public olc::PixelGameEngine {
 public:
	t() {
		sAppName = "lol";
	}

	bool OnUserCreate() override {
		return true;
	}

	bool OnUserUpdate(float tme) override {
		int s = 0;
		for (int y = 0; y != iY; y++) {
			for (int x = 0; x != iX; x++) {
				Draw(x, y, olc::Pixel(img[s+1], img[s+2], img[s+3], img[s]));
				s+=4;
			}
		}
		return true;
	}
};

int main() {;
	std::ifstream fl;
	fl.open("tst/mirror 1196x1200"); // file location
	img = new char [4*iX*iY];
	fl.seekg(fl.end);
	int sz = fl.tellg();
	fl.seekg(fl.beg);

	fl.read(img, iX*iY*4);
	
		
	t t;
	if (t.Construct(1900, 1200, 1900/iX, 1200/iY)) {
		t.Start();
	}
	
}
