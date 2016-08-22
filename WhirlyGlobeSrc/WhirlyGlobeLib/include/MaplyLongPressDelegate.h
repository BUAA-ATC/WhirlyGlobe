//
//  MaplyLongPressDelegate.h
//  WhirlyGlobeLib
//
//  Created by Sunhy on 16/8/17.
//
//

#import <UIKit/UIKit.h>
#import "WhirlyVector.h"
#import "MaplyView.h"
#import "MaplyTapMessage.h"

@interface MaplyLongPressDelegate : NSObject <UIGestureRecognizerDelegate>

/// Create a longPress gesture recognizer and a delegate, then wire them up to the given UIView
+ (MaplyLongPressDelegate *)longPressDelegateForView:(UIView *)view mapView:(MaplyView *)mapView;

/// Gesture recognizer created for the delegate
@property (nonatomic,weak) UILongPressGestureRecognizer *gestureRecognizer;

@end

