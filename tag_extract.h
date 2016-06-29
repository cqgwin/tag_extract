

#ifndef TAG_EXTRACT_H
#define TAG_EXTRACT_H


#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<vector>

using namespace std;

class TagExtractor{
 public:
     void get_tags(string filename);
     void get_stopword(string filename);
     void get_labels(string filename);
     void get_label_pair(string filename);
     void get_idf(string filename);
     void 
 private:
     set<string> tags;
     set<string> stopword;
     set<string> labels;
     map<string, float> idf;
     set< pair<string, string> >label_pair;
};


#endif /* TAG_EXTRACT_H */

