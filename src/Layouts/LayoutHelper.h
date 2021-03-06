//
//  BasicLayout.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/21/15.
//
//

#pragma once
#include "Layouts/Layout.h"
#include "Layoutable.h"
#include "LayoutQuery.h"
#include "hash_container/hmap.h"
#include "ui/CocosGUI.h"

using std::string;

namespace ccHelp {
    class LayoutHelper : public Layout
    {
    public:
        static cocos2d::Node* queryNode(cocos2d::Node *root, string query);
        
        template <typename T>
        static T* query(cocos2d::Node *root, const string &query)
        {
            auto *qNode = LayoutHelper::queryNode(root, query);
            if (qNode)
            {
                return dynamic_cast<T*>(qNode);
            }
            
            return nullptr  ;
        }
        
    private:
        static hmap<std::string, Layout::Parameter> Cache;
        static hmap<std::string, LayoutQuery> Queries;
        
    public:
        static void loadLayoutFile(const std::string &file);
        static void apply(cocos2d::Node *root, const std::string &file);
        static void applyJsonString(cocos2d::Node *root, const std::string jsParam);
        static void applyJson(cocos2d::Node *root, const Layout::Parameter &p);
        static void format(cocos2d::Node *root, const string &key, const Json::Value &p);
        static const Layout::Parameter& getLayout(const std::string &file);
        
        static bool asFloat(const Layout::Parameter &p, float &f);
        static bool asColor3(const Layout::Parameter &p, cocos2d::Color3B &c);
        static bool asColor4(const Layout::Parameter &p, cocos2d::Color4B &c);
        static bool asUIResType(const string &res, cocos2d::ui::TextureResType &t);
        
    public:
        static void initAllLayouts();
        static void initQueries();
        inline static void putQuery(string q, LayoutQuery lq) {Queries[q] = lq;}
    };
}