#ifndef NLP_H

#define NLP_H

#include "Database.h"
#include "gsl/gsl"

#include <string>
#include <tuple>
#include <unordered_set>

namespace NLP
{
    class NLP final
    {
        public:

        NLP(gsl::not_null<Database*> database);
 
        /**
         * Analysis the sentiment of the sentence
         * Return:
         * First element = Positive probabilities
         * Second element = Negative probabilities 
         */
        std::tuple<double,double> analysis(std::string& sentence);

        private:

        int laplace_smoothing(const int& count) const;

        private:

        Database* pdatabase;
    
    };
}

#endif