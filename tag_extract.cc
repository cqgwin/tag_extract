#include "tag_extract.h"
#include "utils.h"

void TagExtractor::get_tags(string filename) {
    tags = utils::get_set(filename);
}

void TagExtractor::get_stopword(string filename) {
    stopword = utils::get_set(filename);
}

void TagExtractor::get_labels(string filename) {
    labels = utils::get_set(filename);
}

void TagExtractor::get_label_pair(string filename) {
    label_pair = utils::get_set2(filename);
}

void TagExtractor::get_idf(string filename) {
    idf = utils::get_map(filename);
}

int main() {
    string stopword_path = "";
    string tags_path = "";
    string label_path = "";
    string label_pair_path = "";
    string idf_path = "";
    
    set<string> stopword = get_set(stopword_path);
    set<string> 
    set< pair<string, string> >
    
    map<string,int> idf = get_map(idf_path);
    
    return 0;
}
