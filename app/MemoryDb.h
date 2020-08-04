#ifndef MEMORY_DB_H

#define MEMORY_DB_H

#include "Database.h"
#include "unordered_map"

class MemoryDb : public NLP::Database{

    public:

    unsigned int get_positive_length() override
    {
        return 6;
    }

    unsigned int get_negative_length() override
    {
        return 7;
    }

    unsigned int get_positive_count(const std::string& word) override
    {
        std::unordered_map<std::string,int> map;
        map.insert(std::make_pair("was",1));
        map.insert(std::make_pair("great",3));
        map.insert(std::make_pair("it",2));
        map.insert(std::make_pair("much",1));
        map.insert(std::make_pair("so",1));
        map.insert(std::make_pair("fun",1));
        map.insert(std::make_pair("would",1));
        map.insert(std::make_pair("recommend",1));
        map.insert(std::make_pair("product",1));
        map.insert(std::make_pair("my",2));
        map.insert(std::make_pair("loved",1));
        map.insert(std::make_pair("grandson",1));
        map.insert(std::make_pair("mother",1));
        map.insert(std::make_pair("enjoyed",1));
        map.insert(std::make_pair("really",1));
        map.insert(std::make_pair("the",1));
        map.insert(std::make_pair("gift",1));
        map.insert(std::make_pair("purchase",1));

        return map[word];
    }

    unsigned int get_negative_count(const std::string& word) override
    {
        std::unordered_map<std::string,int> map;
        map.insert(std::make_pair("worth",1));
        map.insert(std::make_pair("it",1));
        map.insert(std::make_pair("not",2));
        map.insert(std::make_pair("cheap",1));
        map.insert(std::make_pair("of",1));
        map.insert(std::make_pair("kind",1));
        map.insert(std::make_pair("bad",2));
        map.insert(std::make_pair("really",1));
        map.insert(std::make_pair("way",1));
        map.insert(std::make_pair("n't",1));
        map.insert(std::make_pair("we",1));
        map.insert(std::make_pair("the",1));
        map.insert(std::make_pair("expected",1));
        map.insert(std::make_pair("did",1));
        map.insert(std::make_pair("for",1));
        map.insert(std::make_pair("you",1));
        map.insert(std::make_pair("overpriced",1));
        map.insert(std::make_pair("what",1));
        map.insert(std::make_pair("get",1));
        map.insert(std::make_pair("have",1));
        map.insert(std::make_pair("been",1));
        map.insert(std::make_pair("much",1));
        map.insert(std::make_pair("better",1));
        map.insert(std::make_pair("could",1));
        map.insert(std::make_pair("with",1));
        map.insert(std::make_pair("experience",1));
        map.insert(std::make_pair("would",1));
        map.insert(std::make_pair("buy",1));
        map.insert(std::make_pair("this",1));

        return map[word];
    }

};

#endif
