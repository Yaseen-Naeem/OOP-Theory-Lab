#ifndef IMESSAGE_H
#define IMESSAGE_H
#include <string>

class IMessage {
public:
    virtual void receive(std::string msg) = 0;
    virtual ~IMessage();
};

#endif