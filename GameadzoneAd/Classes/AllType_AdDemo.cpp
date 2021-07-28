#include "AppDelegate.h"
#include "AllType_AdDemo.hpp"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "GameAdzone.h"
#endif
USING_NS_CC;

Scene* AllType_AdDemo::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = AllType_AdDemo::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AllType_AdDemo::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
        
    Background =Sprite::create("SL_level_screen_bg.png");
    Background->setPosition(Vec2(384,512));
    this->addChild(Background);

#pragma mark - Create Ad Button

    Text_Data[1]="Banner Ad";
    Text_Data[2]="Banner Hide";
    Text_Data[3]="Interstitial";
    Text_Data[4]="More App";
    Text_Data[5]="Reward Video Ad";
    Text_Data[6]="Overlay ads";
    Text_Data[7]="Icon ads";
    Text_Data[8]="Icon Hide";
    Text_Data[9]="Rectangle Ad Show";
    Text_Data[10]="Rectangle Ad Hide";

    Ad_Button_Point[1]=Vec2(185,700);
    Ad_Button_Point[2]=Vec2(185,600);
    Ad_Button_Point[3]=Vec2(185,500);
    Ad_Button_Point[4]=Vec2(185,400);
    Ad_Button_Point[5]=Vec2(185,300);
    Ad_Button_Point[6]=Vec2(583,700);
    Ad_Button_Point[7]=Vec2(583,600);
    Ad_Button_Point[8]=Vec2(583,500);
    Ad_Button_Point[9]=Vec2(583,400);
    Ad_Button_Point[10]=Vec2(583,300);
    
    for(int i=1;i<=10;i++)
    {
        Ad_Button[i]=ui::Button::create("Ad_Button.png");
        Ad_Button[i]->setPosition(Ad_Button_Point[i]);
        Ad_Button[i]->addTouchEventListener(CC_CALLBACK_2(AllType_AdDemo::OnButtonClick,this));
        Ad_Button[i]->setTag(i);
        this->addChild(Ad_Button[i]);

        AD_Text[i]=Label::createWithTTF(Text_Data[i].c_str(), "Arial Rounded Bold.ttf", 27);
        AD_Text[i]->setPosition(Ad_Button[i]->getContentSize()/2);
        AD_Text[i]->setColor(Color3B::BLACK);
        Ad_Button[i]->addChild(AD_Text[i]);
    }
    
# define touchlistener
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(AllType_AdDemo::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(AllType_AdDemo::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(AllType_AdDemo::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    this->scheduleOnce(SEL_SCHEDULE(&AllType_AdDemo::EnabledKeyBack), 1.5);

    p=1;
    
    return true;
}
void AllType_AdDemo::OnButtonClick(Ref * pSender, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
    {
        ui::Button* pMenuItem = (ui::Button *)(pSender);
        tag_value= (int)pMenuItem->getTag();
        CCLOG("tag_value %d",tag_value);
        
        if (Background->getNumberOfRunningActions()!=0)
            return;
        
        Background->runAction(DelayTime::create(0.5));
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        switch (tag_value)
        {
#pragma mark - Banner Ad
            case 1:
                //To Show BannerAD on Top
                GameAdzone::showBannerAdsTop();

                //To Show BannerAD on Bottom
                //GameAdzone::showBannerAdsBottom();

                break;
#pragma mark - Banner Hide
            case 2:
                GameAdzone::hideBannerAds();
                break;
#pragma mark - Interstitial
            case 3:
                GameAdzone::showInterstitialAds();
                break;
#pragma mark - More App
            case 4:
                GameAdzone::showMoreApps();
                break;
#pragma mark - Show Video Ad
            case 5:
                GameAdzone::showRewardAds();
                break;
#pragma mark - Alert ads
            case 6:
                GameAdzone::ShowOverlayAD();
                break;
#pragma mark - Icon ads
            case 7:
                GameAdzone::showIconAd(577,(123- (123*GameAdzone::getBannerHeight()/Device_Resosultion_Height)),100,100);//Always take frame position and add 10 pixels to show icon ad at proper place
                break;
#pragma mark - Icon Hide
            case 8:
                GameAdzone::hideIconAd();
                break;
#pragma mark - Box Portrait Center
            case 9:
                //Portrait Top
                GameAdzone::showRectangleBanner(GameAdzone::rectangleBannerPostion::Portrait_Top);

                //Portrait Center
                //GameAdzone::showRectangleBanner(GameAdzone::rectangleBannerPostion::Portrait_Center);

                //Portrait Bottom
                //GameAdzone::showRectangleBanner(GameAdzone::rectangleBannerPostion::Portrait_Bottom);

                //Landscape Left
                //GameAdzone::showRectangleBanner(GameAdzone::rectangleBannerPostion::Landscape_Left);

                //Landscape Center
//                GameAdzone::showRectangleBanner(GameAdzone::rectangleBannerPostion::Landscape_Center);

                //Landscape Right
//                GameAdzone::showRectangleBanner(GameAdzone::rectangleBannerPostion::Landscape_Right);

                break;
#pragma mark - Box Hide
            case 10:
                GameAdzone::hideRectangleBanner();
                break;
            default:
                break;
        }
#endif
    }
}
bool AllType_AdDemo::onTouchBegan(Touch* touch, Event* event)
{
    Point location = touch->getLocationInView();
    location = Director::getInstance()->convertToGL(location);
    location = this->convertToNodeSpace(location);
    
    return true;
}
void AllType_AdDemo::onTouchMoved(Touch* touch, Event* event)
{
    Point location = touch->getLocationInView();
    location = Director::getInstance()->convertToGL(location);
    location = this->convertToNodeSpace(location);
    //Ad_Button[p]->setPosition(location);
}
void AllType_AdDemo::onTouchEnded(Touch* touch, Event* event)
{
    Point location = touch->getLocationInView();
    location = Director::getInstance()->convertToGL(location);
    location = this->convertToNodeSpace(location);
    CCLOG("Ad_Button_Point[%d]=Vec2(%.2f,%.2f);",p,location.x,location.y);
    p++;
    // CCLOG("Bubbles[%d]->setPosition(Vec2((%f),(%f)));",a,location.x,location.y);
    // a++;
}
void AllType_AdDemo::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void AllType_AdDemo::EnabledKeyBack()
{
    this->setKeypadEnabled(true);
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void AllType_AdDemo::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{
    if(keyCode == EventKeyboard::KeyCode::KEY_BACK)
    {
        this->setKeypadEnabled(false);
        Director::getInstance()->end();
    }
}
#endif
