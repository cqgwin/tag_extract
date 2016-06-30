

#include"utils.h"


std::set<std::string>  utils::get_set(std::string filename) {
    std::set<std::string> word;
    std::ifstream ifile;
    ifile.open(filename);
    while(ifile.good()) {
        std::string line;
        getline(ifile, line);
        word.insert(line);
    }
    return word;
}

std::map< std::pair<std::string, std::string>, float>  utils::get_map2(std::string filename) {
    std::map< std::pair<std::string, std::string>, float> word_pair;
    std::ifstream ifile;
    ifile.open(filename);
    while(ifile.good()) {
        std::string line;
        getline(ifile, line);
        std::vector<std::string> items = split(line, "\t");
        word_pair[make_pair(items[0], items[1])] = atof(items[2].c_str());
    }
    return word_pair;
}

std::map<std::string,float> utils::get_map(std::string filename) {
    std::map<std::string, float> word_map;
    std::ifstream ifile;
    ifile.open(filename);
    while(ifile.good()) {
        std::string line;
        getline(ifile, line);
        std::vector<std::string> items = split(line, "\t");
        float t_float = atof(items[1].c_str());
        word_map.insert(std::make_pair(items[0], t_float));
    }
    return word_map;
}

std::vector<std::string> utils::split(const std::string &s, const std::string & seperator) {
    std::vector<std::string> v;
    std::string::size_type pos1, pos2;
    pos2 = s.find(seperator);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + seperator.size();
        pos2 = s.find(seperator, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    return v;
}

