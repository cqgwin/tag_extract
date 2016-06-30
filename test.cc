#include "tag_extract.h"
#include "utils.h"

bool is_not_necessary(char c)
{
    switch(c)
    {
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            return true;
    default:
        return false;
    }
}


int main() {
    std::string stopword_path = "D:/datasets/tags/stopword.txt";
    std::string tags_path = "D:/datasets/tags/newtags.dict";
    std::string label_path = "D:/datasets/tags/label43.dict";
    std::string label_pair_path = "D:/datasets/tags/pair_vote.txt";
    std::string idf_path = "D:/datasets/tags/word_idf.txt";
    
    TagExtractor extractor(tags_path, stopword_path, label_path, idf_path, label_pair_path);
    
    std::cout<<"initial over"<<std::endl;
    std::string data_path = "D:/datasets/tags/toutiao_sample30.download";
    
    std::ifstream ifile;
    ifile.open(data_path);
    while(ifile.good()) {
        std::string line;
        getline(ifile, line);
        std::vector<std::string> items = utils::split(line, ",");
        std::vector<std::string> words = utils::split(items[2] + items[3], " ");
        std::vector<std::string> words_cleaned;
        for(unsigned int i = 0; i < words.size(); i++) {
            words[i].erase(std::remove_if(words[i].begin(), words[i].end(), &is_not_necessary), words[i].end());
            if(words[i] == " " || words[i] == "\t" || words[i] == "\n")
                continue;
            words_cleaned.push_back(words[i]);
        }
        std::vector< std::pair<std::string, float> > tags_socre = extractor.extract(words);
        for(unsigned int i = 0; i < tags_socre.size(); i++) {
            std::cout<<tags_socre[i].first<<" "<<tags_socre[i].second<<std::endl;
        }
        std::cout<<"predict over"<<std::endl;
    }
    return 0;
}