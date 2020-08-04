#ifndef FILE_DB_H

#define FILE_DB_H

#include "Database.h"
#include "StringUtils.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>


class FileDb : public NLP::Database{

    public:

    FileDb(std::vector<std::string>& pos_sentences,
    std::vector<std::string>& neg_sentences)
    :ppos_length{pos_sentences.size()},
    pneg_length{neg_sentences.size()},
    ppos_map{to_count_map(pos_sentences)},
    pneg_map{to_count_map(neg_sentences)}{

    }

    unsigned int get_positive_length() override
    {
        return ppos_length;
    }

    unsigned int get_negative_length() override
    {
        return pneg_length;
    }

    unsigned int get_positive_count(const std::string& word) override
    {
        return ppos_map[word];
    }

    unsigned int get_negative_count(const std::string& word) override
    {
        return pneg_map[word];
    }

    private:

    std::unordered_map<std::string,unsigned int> to_count_map(std::vector<std::string>& sentences) const{

        std::unordered_map<std::string,unsigned int> count_map{};

        for(auto& sentence:sentences){
            auto word_set = std::move(NLP::extract_words(sentence));

            for(const auto& word:word_set){
                count_map[word]+=1;
            }
        }
       
        return count_map;
    }

    private:

    std::size_t ppos_length;

    std::size_t pneg_length;

    std::unordered_map<std::string,unsigned int> ppos_map;

    std::unordered_map<std::string,unsigned int> pneg_map;

};

#endif
