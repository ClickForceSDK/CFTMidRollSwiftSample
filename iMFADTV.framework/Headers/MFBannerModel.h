//
//  MFBannerModel.h
//  iMFADTV
//
//  Created by CF-NB on 2023/10/08.
//

#import <Foundation/Foundation.h>

typedef struct  MFAdSize {
    CGSize size;
    NSUInteger type;
} MFAdSize;

typedef enum {
    MF_BANNER,
    MF_FULLSCREEN
} SizeType;

extern MFAdSize const MFAdSize320X50;
extern MFAdSize const MFAdSize336X280;
extern MFAdSize const MFAdSize300X600;
extern MFAdSize const MFAdSize160X600;
extern MFAdSize const MFAdSize970X250;
extern MFAdSize const MFAdSize970X90;
extern MFAdSize const MFAdSize728X90;
extern MFAdSize const MFAdSize320X100;
extern MFAdSize const MFAdSize300X100;
extern MFAdSize const MFAdSize300X250;
extern MFAdSize const MFAdSize1200X400;
extern MFAdSize const MFSmartSize;

@interface MFBannerModel : NSObject

@end
