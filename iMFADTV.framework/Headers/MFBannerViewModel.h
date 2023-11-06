//
//  MFBannerViewModel.h
//  iMFADTV
//
//  Created by CF-NB on 2023/10/08.
//

#import <Foundation/Foundation.h>
#import "MFBannerView.h"
#import "MFBannerModel.h"

typedef NS_OPTIONS(NSInteger, Alignment) {
    Alignment_Center = 3,
    Alignment_Left = 1,
    Alignment_Right = 2
};


@class MFBannerViewModel;
@protocol MFBannerViewModelDelegate <NSObject>

@optional

- (void)requestAdSuccess;
- (void)requestAdFail;
- (void)onClickAd;

@end

@interface MFBannerViewModel : NSObject

@property(nonatomic, assign)id<MFBannerViewModelDelegate> delegate;
@property(nonatomic, strong)MFBannerView *bannerView;

- (id)initWithBannerID:(NSString *)bannerId AdSize:(MFAdSize)size origin:(CGPoint)origin;

- (void)setDebugInfo:(BOOL)isDebug;
- (void)setAdAutoRefresh:(BOOL)isAutoRefresh;
- (void)setBannerBackgroudColor:(UIColor *)color;
- (void)setBannerAlignment:(Alignment)alignment;

- (void)startRequestAd;
- (void)showAd;
- (void)closeAd;
@end

