#include "NLP.h"

#include "gsl/gsl"
#include "StringUtils.h"

#include <cctype>
#include <iostream>

namespace NLP
{

    NLP::NLP(gsl::not_null<Database*> database)
    :pdatabase{database}
    {

    }

    std::tuple<double,double> NLP::analysis(std::string& sentence)
    {
        unsigned int total_positive_length = pdatabase->get_positive_length();

        unsigned int total_negative_length = pdatabase->get_negative_length();

        unsigned int total_length = total_positive_length+total_negative_length;

        double positive_sentence_prob = static_cast<double>(total_positive_length)/total_length;

        double negative_sentence_prob = static_cast<double>(total_negative_length)/total_length;

        auto input_words = std::move(extract_words(sentence));

        double sentiment_positive = positive_sentence_prob;

        double sentiment_negative = negative_sentence_prob;

        for(const auto& word : input_words){

            sentiment_positive *= static_cast<double>(laplace_smoothing(pdatabase->get_positive_count(word)))/total_positive_length;

            sentiment_negative *= static_cast<double>(laplace_smoothing(pdatabase->get_negative_count(word)))/total_negative_length;

        }

        double total_sentiment_value =  sentiment_positive+sentiment_negative;

        double normalization_const = 1/total_sentiment_value;

        double positive_sentiment_percentage = sentiment_positive * normalization_const;

        double negative_sentiment_percentage = sentiment_negative * normalization_const;

        return std::make_tuple(positive_sentiment_percentage,negative_sentiment_percentage);
    }

    int NLP::laplace_smoothing(const int& count) const
    {
        return count+1;
    }
}