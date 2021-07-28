//
// Created by Nikunj on 04/03/21.
//

#ifndef PROJ_ANDROID_GAMEADZONE_H
#define PROJ_ANDROID_GAMEADZONE_H


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "network/HttpClient.h"
#include <ui/UIWebView.h>
#include "cocos2d.h"
using namespace cocos2d;
using namespace network;




class GameADzoneRewardListener
{
public:
    virtual void onRewardAdLoaded(){};
    virtual void onRewardAdFailedToLoad(){};
    virtual void onUserEarnedReward(){};
};


class GameAdzone {


public:
    enum rectangleBannerPostion{
        Portrait_Top=1,
        Portrait_Center=2,
        Portrait_Bottom=3,
        Landscape_Left=4,
        Landscape_Center=5,
        Landscape_Right=6
    };

    static void setGameADzoneRewardListener(GameADzoneRewardListener *listenerclass);
    static void removeGameADzoneRewardListener();

    static void showMoreApps();
    static void showInterstitialAds();
    static void showRewardAds();

    static void showBannerAdsTop();
    static void showBannerAdsBottom();
    static void hideBannerAds();

    static void hideRectangleBanner();
    static void showRectangleBanner(rectangleBannerPostion postion);

    static int getBannerHeight();

    static void showIconAd(float postionX , float postionY , float width,float hight);
    static void hideIconAd();
    static jboolean isIconADLoaded();
    static void ShowIconAD();
    static jboolean isOverlayADLoaded();
    static void ShowOverlayAD();

};


#endif //PROJ_ANDROID_GAMEADZONE_H
