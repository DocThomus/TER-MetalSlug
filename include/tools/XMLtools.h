#ifndef XMLTOOLS_H
#define XMLTOOLS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "tools.h"

using namespace std;
using namespace rapidxml;

// class Int2 {
// 	public :
// 		unsigned int x;
// 		unsigned int y;
// 		inline Int2() {x=0;y=0;};
// 		inline Int2(int i,int j) {x=i;y=j;};
// };

bool buildSpriteMap(string filename,vector<Int2>animations, vector<Int2> positions, vector<Int2> tailles);
bool loadSpriteMap(string filename,vector<Int2>*animations, vector<Int2>* positions, vector<Int2>* tailles);

#endif