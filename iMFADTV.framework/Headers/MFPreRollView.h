//
//  MFPreRollView.m
//  iMFADTV
//
//  2023/10/08.
//

#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>

@protocol MFPreRollDelegate <NSObject>

@optional
//Pre-roll Vast影片播完處理
- (void)readyPlayVideo;

//Pre-roll Vast影片錯誤處理
- (void)onFailedToVast;

@end
@interface MFPreRollView : UIView

@property (nonatomic, strong) UIButton *playButton;


@property(nonatomic,weak)id<MFPreRollDelegate>delegate;
#pragma mark - Pre-roll set init frame;
- (id)initWithFrame:(CGRect) frame;

#pragma mark - Pre-roll set init frame with user player view;
-(id)initWithView:(UIView *) playerView;

#pragma mark - set Frame with mid roll
-(id)initWithMidRollFrame:(AVPlayerViewController *)userPlayercontroller;

#pragma mark - Pre-roll get ViewController
-(void)getView:(UIViewController *)view;

#pragma mark - 設定版位
-(void)setZoneID:(NSString *)zoneID;

#pragma mark - 開啟廣告
- (void)setPlayer;

#pragma mark - 關閉Pre-roll 影片
-(void)closePrerollVideo;

#pragma mark - 繼續播放Pre-roll 影片
-(void)resumePrerollVideo;

#pragma mark - Multiple Settings
-(void)setZoneID:(NSString *)zoneID getViewController:(UIViewController *)view;

#pragma mark - 取得版本
+(NSString *)version;
@end
