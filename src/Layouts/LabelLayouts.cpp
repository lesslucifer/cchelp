//
//  LabelLayouts.cpp
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 4/22/15.
//
//

#include "LayoutRegistration.h"

namespace ccHelp {
    void regisLabelLayouts()
    {
        // system font
        auto *lblSystemFont = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string font;
            if (!p.get(font))
                return;
            
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            lbl->setSystemFontName(font);
        });
        GroupLayout::registerLayout("label-system-font", lblSystemFont);
        
        // system font size
        auto *lblSystemFontSize = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            float fontSize;
            if (!LayoutHelper::asFloat(p, fontSize))
                return;
            
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            lbl->setSystemFontSize(fontSize);
        });
        GroupLayout::registerLayout("label-system-font-size", lblSystemFontSize);
        
        // system text
        auto *lblText = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string text;
            if (!p.get(text))
                return;
            
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            lbl->setString(text);
        });
        GroupLayout::registerLayout("label-text", lblText);
        
        // system text color
        auto *lblTextColor = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Color3B c;
            if (!LayoutHelper::asColor3(p, c))
                return;
            
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            lbl->setTextColor((Color4B) c);
        });
        GroupLayout::registerLayout("label-text-color", lblTextColor);
        
        
        // system text h alignment
        auto *lblTextHAlign = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string align;
            if (!p.get(align))
                return;
            
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            for (auto &c : align) {c = tolower(c);}
            
            if (align == "left")
            {
                lbl->setAlignment(TextHAlignment::LEFT);
            }
            else if (align == "right")
            {
                lbl->setAlignment(TextHAlignment::RIGHT);
            }
            else if (align == "center")
            {
                lbl->setAlignment(TextHAlignment::CENTER);
            }
        });
        GroupLayout::registerLayout("label-text-h-align", lblTextHAlign);
        
        // system text h alignment
        auto *lblTextVAlign = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            string align;
            if (!p.get(align))
                return;
            
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            for (auto &c : align) {c = tolower(c);}
            
            if (align == "top")
            {
                lbl->setAlignment(lbl->getHorizontalAlignment(), TextVAlignment::TOP);
            }
            else if (align == "bottom")
            {
                lbl->setAlignment(lbl->getHorizontalAlignment(), TextVAlignment::BOTTOM);
            }
            else if (align == "center")
            {
                lbl->setAlignment(lbl->getHorizontalAlignment(), TextVAlignment::CENTER);
            }
        });
        GroupLayout::registerLayout("label-text-v-align", lblTextVAlign);
        
        auto *lblDimension = new FunctionLayout([](Node *n, const Layout::Parameter &p) {
            Label *lbl = dynamic_cast<Label*>(n);
            if (!lbl)
                return;
            
            string matchContent;
            if (p.get(matchContent) && matchContent == "match_content")
            {
                lbl->setDimensions(lbl->getContentSize().width, lbl->getContentSize().height);
                return;
            }
            
            float size = 0.f;
            if (p.get(size, 1, "width", "w", nullptr))
            {
                lbl->setDimensions(size, lbl->getDimensions().height);
            }
            if (p.get(size, 2, "height", "h", nullptr))
            {
                lbl->setDimensions(lbl->getDimensions().width, size);
            }
        });
        GroupLayout::registerLayout("label-dimension", lblDimension);
        
    }
}
