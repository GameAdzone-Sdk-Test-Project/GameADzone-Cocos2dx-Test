//
// Created by Nikunj on 04/03/21.
//

#include "GameAdzone.h"
#include "platform/android/jni/JniHelper.h"
#include <iostream>
#include <string>
#include <ui/UIHelper.h>
#include <cocos2d.h>
#define app_class_path "com/sdk/gameadzone/GameAdzoneCocos2dx"

using namespace cocos2d;



GameADzoneRewardListener *gameADzoneRewardListener;



jboolean GameAdzone::isIconADLoaded()
{
    JniMethodInfo methodInfo;
    if(JniHelper::getStaticMethodInfo(methodInfo,
                                      app_class_path,
                                      "isIconLoaded",
                                      "()Ljava/lang/String;"))
    {
        jstring isLoaded = (jstring) methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
        std::string isLoadedStr  = JniHelper::jstring2string(isLoaded);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        if(isLoadedStr == "YES")
        {
            return true;
        }
        return false;
    }
}

void GameAdzone::ShowOverlayAD()
{
    CCLOG("ShowIconAD");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "ShowAlertAD",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
jboolean  GameAdzone::isOverlayADLoaded()
{
    JniMethodInfo methodInfo;
    if(JniHelper::getStaticMethodInfo(methodInfo,
                                      app_class_path,
                                      "isAlertLoaded",
                                      "()Ljava/lang/String;"))
    {
        jstring isLoaded = (jstring) methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
        std::string isLoadedStr  = JniHelper::jstring2string(isLoaded);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        if(isLoadedStr == "YES")
        {
            return true;
        }
        return false;
    }
}
void GameAdzone::showMoreApps()
{
    CCLOG("showMoreApps");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "moreApps",
                                      "()V"))
    {


        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void GameAdzone::showRewardAds()
{
    CCLOG("RewardAds");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "RewardVideoAD",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void  GameAdzone::showBannerAdsTop()
{
    CCLOG("showInterstitialAds");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "bannerAdTop",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
int GameAdzone::getBannerHeight()
{
    JniMethodInfo methodInfo;
    if(JniHelper::getStaticMethodInfo(methodInfo,
                                      app_class_path,
                                      "bannerHeight",
                                      "()Ljava/lang/String;"))
    {
        jstring str = (jstring) methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
        std::string guid  = JniHelper::jstring2string(str);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);

        int int_hight;
        std::istringstream(guid) >> int_hight;
        CCLOG("Height",int_hight);
        return int_hight;
    }
}
void  GameAdzone::showBannerAdsBottom()
{
    CCLOG("showInterstitialAds");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "bannerAdBottom",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void  GameAdzone::hideBannerAds()
{
    CCLOG("showInterstitialAds");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "hideBanner",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void GameAdzone::showInterstitialAds()
{
    CCLOG("InterstitialAds");

    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "interstitialAd",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void  GameAdzone::showRectangleBanner(rectangleBannerPostion postion)
{
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "showRectangleBanner",
                                      "(I)V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,postion);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void  GameAdzone::hideRectangleBanner()
{
    CCLOG("hideRectangleBanner");
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "rectangleBannerHide",
                                      "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void GameAdzone::hideIconAd()
{
    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "showIconAd",
                                      "(IIII)V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,0,0,0,0);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}
void  GameAdzone::showIconAd(float postionX , float postionY , float width,float hight)
{
    auto IconLayout = Layout::create();
    IconLayout->setPosition(Vec2(postionX,postionY));
    IconLayout->setContentSize(Size(width,hight));
    IconLayout->setTouchEnabled(true);
    IconLayout->setSwallowTouches(true);

    auto uiRect = cocos2d::ui::Helper::convertBoundingBoxToScreen(IconLayout);

    JniMethodInfo minfo;
    if(JniHelper::getStaticMethodInfo(minfo,
                                      app_class_path,
                                      "showIconAd",
                                      "(IIII)V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,(int)uiRect.origin.x,(int)uiRect.origin.y,(int)uiRect.size.width,(int)uiRect.size.height);
        minfo.env->DeleteLocalRef(minfo.classID);
    }
}

void GameAdzone::setGameADzoneRewardListener(GameADzoneRewardListener *RewardListener)
{
    if (gameADzoneRewardListener !=  NULL)
    {
        gameADzoneRewardListener = NULL;
    }
    gameADzoneRewardListener = RewardListener;

}

void GameAdzone::removeGameADzoneRewardListener()
{
    if (gameADzoneRewardListener !=  NULL)
    {
        gameADzoneRewardListener = NULL;
    }
}


extern "C" {

void Java_com_sdk_gameadzone_GameADzoneRewardedAdmob_GameADzoneOnRewardADLoaded(JNIEnv *env, jobject thiz, jstring myStringParam)
{
    CCLOG("Cocos2dx OnRewardADLoaded");

    if (gameADzoneRewardListener !=  NULL)
    {
        gameADzoneRewardListener->onRewardAdLoaded();
    }

}

void Java_com_sdk_gameadzone_GameADzoneRewardedAdmob_GameADzoneOnRewardAdFailedToLoad(JNIEnv *env, jobject thiz, jstring myStringParam)
{
    CCLOG("Cocos2dx OnRewardAdFailedToLoad");
    if (gameADzoneRewardListener !=  NULL)
    {
        gameADzoneRewardListener->onRewardAdFailedToLoad();
    }


}
void Java_com_sdk_gameadzone_GameADzoneRewardedAdmob_GameADzoneOnUserEarnedReward(JNIEnv *env, jobject thiz, jstring myStringParam)
{
    CCLOG("Cocos2dx OnUserEarnedReward");

    if (gameADzoneRewardListener !=  NULL)
    {
        gameADzoneRewardListener->onUserEarnedReward();
    }

}
}