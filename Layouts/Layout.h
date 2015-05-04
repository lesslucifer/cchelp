//
//  Layout.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#pragma once
#include "Def.h"
#include "jsoncpp/json2/json.h"
#include "cocos2d.h"

namespace ccHelp {
    
    class Layout
    {
    public:
        typedef Json::Value Parameter;
        
        virtual void doLayout(cocos2d::Node *node, const Parameter &par) const = 0;
    };
}