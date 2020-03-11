#pragma once

#include "./PropertyDescription.h"
#include "../../../json/Value.h"


class CanClimbDescription : PropertyDescription {

public:
    virtual void getJsonName()const;
    virtual ~CanClimbDescription();
    virtual void deserializeData(Json::Value &);
    virtual void serializeData(Json::Value &)const;

    CanClimbDescription();
};
