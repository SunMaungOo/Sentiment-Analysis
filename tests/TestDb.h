#ifndef TEST_DB_H

#define TEST_DB_H

#include "Database.h"
#include "unordered_map"

class TestDb final : public NLP::Database{

    public:

    unsigned int get_positive_length() override
    {
        return 3;
    }

    unsigned int get_negative_length() override
    {
        return 5;
    }

    unsigned int get_positive_count(const std::string& word) override
    {
        std::unordered_map<std::string,int> map;
        map.insert(std::make_pair("it",2));
        map.insert(std::make_pair("was",2));
        map.insert(std::make_pair("great",3));

        return map[word];
    }

    unsigned int get_negative_count(const std::string& word) override
    {
        std::unordered_map<std::string,int> map;
        map.insert(std::make_pair("it",1));
        map.insert(std::make_pair("is",2));
        map.insert(std::make_pair("bad",3));

        return map[word];
    }

};

#endif