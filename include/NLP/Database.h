#ifndef DATABASE_H

#define DATABASE_H

#include <string>

namespace NLP
{
    class Database
    {
        public:

        /**
         * Return:
         * Positive sentence length
         */
        virtual unsigned int get_positive_length() = 0;

        /**
         * Return:
         * Negative sentence length
         */
        virtual unsigned int get_negative_length() = 0;

        /**
         * Return:
         * How many time the word occur in positive sentence
         */
        virtual unsigned int get_positive_count(const std::string& word)  = 0;

        /**
         * Return:
         * How many time the word occur in negative sentence
         */
        virtual unsigned int get_negative_count(const std::string& word)  = 0;
    };
}

#endif