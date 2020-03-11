#pragma once

#include "../../../json/Value.h"
#include "./ComponentDescription.h"


class RailActivatorDescription : ComponentDescription {

public:
    virtual void getJsonName()const;
    virtual ~RailActivatorDescription();
    virtual void deserializeData(Json::Value &);
    virtual void serializeData(Json::Value &)const;

    RailActivatorDescription();
};
