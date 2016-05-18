/*
 *  MaplyInteractionLayer_private.h
 *  WhirlyGlobeComponent
 *
 *  Created by Steve Gifford on 7/21/12.
 *  Copyright 2011-2015 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import "MaplyInteractionLayer_private.h"
#import "MaplyScreenMarker.h"
#import "MaplyMarker.h"
#import "MaplyScreenLabel.h"
#import "MaplyLabel.h"
#import "MaplyVectorObject_private.h"
#import "MaplyCoordinate.h"
#import "ImageTexture_private.h"

using namespace Eigen;
using namespace WhirlyKit;
using namespace WhirlyGlobe;

@implementation MaplyInteractionLayer
{
    Maply::MapScene *mapScene;
    MaplyView *mapView;
}

- (id)initWithMapView:(MaplyView *)inMapView
{
    self = [super initWithView:inMapView];
    if (!self)
        return nil;
    mapView = inMapView;
    
    return self;
}

- (void)startWithThread:(WhirlyKitLayerThread *)inLayerThread scene:(WhirlyKit::Scene *)inScene
{
    [super startWithThread:inLayerThread scene:inScene];
    mapScene = (Maply::MapScene *)inScene;
    
    layerThread = inLayerThread;
    scene = (Maply::MapScene *)inScene;
    userObjects = [NSMutableSet set];
}

- (void)dealloc
{    
}

/// Called by the layer thread to shut a layer down.
/// Clean all your stuff out of the scenegraph and so forth.
- (void)shutdown
{
    [super shutdown];
}

// Do the logic for a selection
// Runs in the layer thread
- (void) userDidTapLayerThread:(MaplyTapMessage *)msg
{
    // First, we'll look for labels and markers
    std::vector<SelectionManager::SelectedObject> selObjs;
    SelectionManager *selectionManager = ((SelectionManager *)scene->getManager(kWKSelectionManager));
    selectionManager->pickObjects(Point2f(msg.touchLoc.x,msg.touchLoc.y),10.0,mapView, selObjs);
    
    std::vector<SelectionManager::SelectedObject>::iterator it = selObjs.begin();
    
    NSMutableArray *selObjArray = [NSMutableArray array];
    
    while (it != selObjs.end()) {
        SimpleIdentity selectID = it->selectID;
        SelectObjectSet::iterator seletedIt = selectObjectSet.find(SelectObject(selectID));
        if (seletedIt != selectObjectSet.end())
        {
            [selObjArray addObject:seletedIt->obj];
        }
        it++;
    }
    
    if(selObjArray.count == 0) {
        // Next, try the vectors
        // Note: Ignoring everything but the first return
        NSArray *vecObjs = [self findVectorsInPoint:Point2f(msg.whereGeo.x(),msg.whereGeo.y()) inView:(MaplyBaseViewController*)self.viewController multi:false];
        if ([vecObjs count] > 0) {
            [selObjArray addObjectsFromArray:vecObjs];
        }
    }
    
    // Tell the view controller about it
    dispatch_async(dispatch_get_main_queue(),^
                   {
                       [_viewController handleSelection:msg didSelect:selObjArray];
                   }
                   );
}

// Check for a selection
- (void) userDidTap:(MaplyTapMessage *)msg
{
    // Pass it off to the layer thread
    [self performSelector:@selector(userDidTapLayerThread:) onThread:layerThread withObject:msg waitUntilDone:NO];
}

@end