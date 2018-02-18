#ifndef SPOONIE_OVERSAMPLE_WHEEL_HPP_INCLUDED
#define SPOONIE_OVERSAMPLE_WHEEL_HPP_INCLUDED

#include "NanoWheel.hpp"

START_NAMESPACE_DISTRHO

class OversampleWheel : public NanoWheel
{
public:
    using NanoWheel::NanoWheel;

protected:
    void draw() override;
    
private:
    DISTRHO_LEAK_DETECTOR(OversampleWheel)
};

END_NAMESPACE_DISTRHO

#endif