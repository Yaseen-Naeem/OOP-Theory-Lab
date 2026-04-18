#ifndef IFILTER_H
#define IFILTER_H
#include <string>

class IFilter {
public:
    virtual bool match(std::string b, double maxP) const = 0;
    virtual ~IFilter();
};

#endif