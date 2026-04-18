#ifndef IDISPLAY_H
#define IDISPLAY_H

class IDisplay {
public:
    virtual void display() const = 0;
    virtual ~IDisplay(); 
};

#endif