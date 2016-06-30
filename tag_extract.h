

#ifndef TAG_EXTRACT_H
#define TAG_EXTRACT_H


#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include <algorithm>


class TagExtractor{
 public:
     TagExtractor(std::string tags_path, std::string stopword_path, std::string labels_path, std::string idf_path, std::string label_pair_path);
     ~TagExtractor();
     std::vector< std::pair<std::string, float> > extract(std::vector<std::string> words);
 private:
     std::set<std::string> all_tags;
     std::set<std::string> stopword;
     std::set<std::string> labels;
     std::map<std::string, float> idf;
     std::map< std::pair<std::string, std::string>,float >label_pair;
};


#endif /* TAG_EXTRACT_H */

