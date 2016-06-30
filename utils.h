

#ifndef UTILS_H
#define UTILS_H

#include<string>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include <stdlib.h>
#include<fstream>

class utils{
public:
    static std::vector<std::string> split(const std::string &s, const std::string & seperator);
    static std::set<std::string>  get_set(std::string filename);
    static std::map< std::pair<std::string, std::string>, float>  get_map2(std::string filename);
    static std::map<std::string,float> get_map(std::string filename);
};

#endif 
