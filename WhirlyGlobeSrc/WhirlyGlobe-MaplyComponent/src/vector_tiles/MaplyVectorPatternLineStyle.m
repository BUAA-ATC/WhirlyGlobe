//
//  MaplyVectorTileStylePatternLine.m
//  WhirlyGlobe-MaplyComponent
//
//  Created by ZkTsin on 15/10/30.
//
//

#import "MaplyVectorPatternLineStyle.h"

@implementation MaplyVectorTileStylePatternLine
{
    NSMutableArray *subStyles;
}

- (id)initWithStyleEntry:(NSDictionary *)style settings:(MaplyVectorTileStyleSettings *)settings viewC:(MaplyBaseViewController *)viewC
{
    self = [super initWithStyleEntry:style viewC:viewC];
    
    subStyles = [NSMutableArray array];
    NSArray *subStylesArray = style[@"substyles"];
    for (NSMutableDictionary *styleEntry in subStylesArray)
    {        
        int drawPriority = 0;
        if (styleEntry[@"drawpriority"])
        {
            drawPriority = (int)[styleEntry[@"drawpriority"] integerValue];
        }
        NSMutableDictionary *desc = [NSMutableDictionary dictionary];
        //Edited by Qin
        if (styleEntry[@"file"])
        {
            UIImage *patternImage = nil;
            NSString *path = styleEntry[@"file"];
            NSString *fullName = nil;
            if (path)
            {
                NSString *fileName = [path lastPathComponent];
                patternImage = [UIImage imageNamed:fileName];
                if (!patternImage)
                {
                    fullName = [NSString stringWithFormat:@"%@-24@2x.png",path];
                    patternImage = [UIImage imageNamed:fullName];
                    if (!patternImage)
                    {
                        // Try without the extension
                        NSString *shortName = [path stringByDeletingPathExtension];
                        if (shortName)
                        {
                            fullName = [NSString stringWithFormat:@"%@@2x.png",shortName];
                            patternImage = [UIImage imageNamed:fullName];
                        }
                    }
                }
            }
            UIColor *strokeColor = nil;
            CGImageRef image = patternImage.CGImage;
            CGDataProviderRef provider = CGImageGetDataProvider(image);
            NSData* data = CFBridgingRelease(CGDataProviderCopyData(provider));
            const uint8_t *pixels = [data bytes];
            for (int i = 0; i < [data length]; i += 4) {
                uint8_t r = pixels[i];
                uint8_t g = pixels[i + 1];
                uint8_t b = pixels[i + 2];
                uint8_t a = pixels[i + 3];
                if (a) {
                    strokeColor = [UIColor colorWithRed:r / 255.0 green:g / 255.0 blue:b / 255.0 alpha:a];
                    break;
                }
            }
            
            MaplyTexture *patternTexture = [viewC addTexture:patternImage
                                                 imageFormat:MaplyImageIntRGBA
                                                   wrapFlags:MaplyImageWrapY
                                                        mode:MaplyThreadCurrent];
            int height = patternImage.size.height;
            if (height & (height - 1)) {
                NSLog(@"The height of texture image is not power of 2");
            }
            
            
            desc[kMaplyVecWidth] = @(patternImage.size.width);
            desc[kMaplyColor] = strokeColor;
            desc[kMaplyDrawPriority] = @(drawPriority+kMaplyVectorDrawPriorityDefault);
            desc[kMaplyEnable] = @NO;
            desc[kMaplyFade] = @0.0;
            desc[kMaplyVecCentered] = @YES;
            desc[kMaplySelectable] = @(self.selectable);
            desc[kMaplyVecTexture] = patternTexture;
            desc[kMaplyWideVecCoordType] = kMaplyWideVecCoordTypeScreen;
            desc[kMaplyWideVecTexRepeatLen] = @(patternImage.size.height);
            desc[kMaplyVecWidth] = @(patternImage.size.width);
        }
        
        [self resolveVisibility:styleEntry settings:settings desc:desc];
        
        [subStyles addObject:desc];
    }
    
    return self;
}

- (NSArray *)buildObjects:(NSArray *)vecObjs viewC:(MaplyBaseViewController *)viewC;
{
    MaplyComponentObject *baseWideObj = nil;
    NSMutableArray *compObjs = [NSMutableArray array];
    for (NSDictionary *desc in subStyles)
    {
        MaplyComponentObject *compObj = nil;
        if (!baseWideObj)
            baseWideObj = compObj = [viewC addWideVectors:vecObjs desc:desc mode:MaplyThreadCurrent];
        else
            compObj = [viewC instanceVectors:baseWideObj desc:desc mode:MaplyThreadCurrent];

        if (compObj)
            [compObjs addObject:compObj];
    }
    
    return compObjs;
}


@end
