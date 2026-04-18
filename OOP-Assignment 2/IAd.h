#ifndef IAD_H
#define IAD_H

class IAd {
public:
    virtual void addAd(class Vehicle* v) = 0;
    virtual ~IAd();
};

#endif