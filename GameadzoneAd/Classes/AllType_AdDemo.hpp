#ifndef AllType_AdDemo_hpp
#define AllType_AdDemo_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"

using namespace cocos2d;
class AllType_AdDemo: public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void OnButtonClick(Ref * pSender, cocos2d::ui::Widget::TouchEventType type);

    Sprite * Background;
    
    ui::Button * Ad_Button[30];
    Point Ad_Button_Point[30];
    Label * AD_Text[30];
    std::string Text_Data[30];
    
    int tag_value;
    int p;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
        
    void EnabledKeyBack();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pEvent);
#endif
    
    bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    
    // implement the "static create()" method manually
    CREATE_FUNC(AllType_AdDemo);
};
#endif /* AllType_AdDemo_hpp */
