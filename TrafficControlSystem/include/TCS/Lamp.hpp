/* Generated by Together */

#ifndef INCLUDE_TCS_LAMP_H
#define INCLUDE_TCS_LAMP_H

/**
 * @interface
 */
class Lamp {
public:

    virtual void off() =0;

    virtual void on() =0;

    virtual bool isOn() =0;

    virtual ~Lamp() = 0;
};
inline
Lamp::~Lamp(){}
#endif //INCLUDE_TCS_LAMP_H
