//
//  MaplyLongPressDelegate.m
//  WhirlyGlobeLib
//
//  Created by Sunhy on 16/8/17.
//
//

#import "MaplyLongPressDelegate.h"

#import "EAGLView.h"
#import "SceneRendererES.h"
#import "MaplyView.h"
#import "GlobeMath.h"

using namespace WhirlyKit;

@implementation MaplyLongPressDelegate
{
    MaplyView *mapView;
}

- (id)initWithMapView:(MaplyView *)inView
{
    self = [super init];
    if (self)
    {
        mapView = inView;
    }
    
    return self;
}

+ (MaplyLongPressDelegate *)longPressDelegateForView:(UIView *)view mapView:(MaplyView *)mapView
{
    MaplyLongPressDelegate *longPressDelegate = [[MaplyLongPressDelegate alloc] initWithMapView:mapView];
    UILongPressGestureRecognizer *gestureRecognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:longPressDelegate action:@selector(longPressAction:)];
    gestureRecognizer.minimumPressDuration = 0.2;
    longPressDelegate.gestureRecognizer = gestureRecognizer;
    [view addGestureRecognizer:gestureRecognizer];
    return longPressDelegate;
}

// We'll let other gestures run
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer
{
    return YES;
}

// Called for a longPress
- (void)longPressAction:(id)sender
{
    UILongPressGestureRecognizer *longPress = sender;
    CGPoint touchLoc = [longPress locationInView:longPress.view];
    WhirlyKitEAGLView  *glView = (WhirlyKitEAGLView  *)longPress.view;
    WhirlyKitSceneRendererES *sceneRender = glView.renderer;
    CoordSystemDisplayAdapter *coordAdapter = mapView.coordAdapter;
    //    WhirlyKit::Scene *scene = sceneRender.scene;
    
    // Just figure out where we tapped
    Point3d hit;
    Eigen::Matrix4d theTransform = [mapView calcFullMatrix];
    if ([mapView pointOnPlaneFromScreen:touchLoc transform:&theTransform frameSize:Point2f(sceneRender.framebufferWidth/glView.contentScaleFactor,sceneRender.framebufferHeight/glView.contentScaleFactor) hit:&hit clip:true])
    {
        MaplyTapMessage *msg = [[MaplyTapMessage alloc] init];
        [msg setTouchLoc:touchLoc];
        [msg setView:longPress.view];
        [msg setWorldLoc:Point3f(hit.x(),hit.y(),hit.z())];
        Point3d localPt = coordAdapter->displayToLocal(hit);
        [msg setWhereGeo:coordAdapter->getCoordSystem()->localToGeographic(localPt)];
        msg.heightAboveSurface = hit.z();
        msg.isLongPressed = YES;
        msg.state = longPress.state;
        [[NSNotificationCenter defaultCenter] postNotification:[NSNotification notificationWithName:MaplyTapMsg object:msg]];
    } else {
        // Not expecting this case
        NSLog(@"NOEXPECT");
    }
}

@end
