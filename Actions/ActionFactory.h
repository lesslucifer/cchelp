//
//  ActionFactory.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/15/15.
//
//

#pragma once
#include "Def.h"
#include "jsoncpp/json2/json.h"
#include "cocos2d.h"

using cocos2d::Action;
using std::string;

namespace ccHelp {
    class ActionFactoryContext
    {
        
    };
    
    class ActionFactory
    {
    public:
        typedef Json::Value Parameter;
        
        virtual Action* createAction(const Parameter &p, const ActionFactoryContext &ctx) const = 0;
    };
}