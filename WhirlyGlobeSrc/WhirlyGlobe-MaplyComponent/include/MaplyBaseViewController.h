/*
 *  MaplyBaseViewController.h
 *  MaplyComponent
 *
 *  Created by Steve Gifford on 12/14/12.
 *  Copyright 2012 mousebird consulting
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

#import <UIKit/UIKit.h>
#import "MaplyCoordinate.h"
#import "MaplyScreenMarker.h"
#import "MaplyVectorObject.h"
#import "MaplyViewTracker.h"
#import "MaplyComponentObject.h"
#import "MaplySharedAttributes.h"
#import "MaplyViewControllerLayer.h"

/** The MaplyBaseViewController is the base class for the Maply and WhirlyGlobe
    view controllers.  Most of its functionality is private, but you can use
    those view controllers instead.
 */
@interface MaplyBaseViewController : UIViewController

/// Set selection support on or off here
@property(nonatomic,assign) bool selection;

/// Set the globe view's background color.
/// Black, by default.
@property (nonatomic,strong) UIColor *clearColor;

/// Add rendering and other general hints for the globe view controller.
- (void)setHints:(NSDictionary *)hintsDict;

/// Add a quad tree paged earth layer with MapBox Tiles on top
- (MaplyViewControllerLayer *)addQuadEarthLayerWithMBTiles:(NSString *)name;

/// Add a quad tree paged earth layer from the remote source with the given attributes
- (MaplyViewControllerLayer *)addQuadEarthLayerWithRemoteSource:(NSString *)baseURL imageExt:(NSString *)ext cache:(NSString *)cachdDir minZoom:(int)minZoom maxZoom:(int)maxZoom;

/// Add a quad tree paged earth layer as defined by a JSON description.  cacheDir is where we'll cache local files.
- (MaplyViewControllerLayer *)addQuadEarthLayerWithRemoteSource:(NSDictionary *)jsonDict cache:(NSString *)cacheDir;

/// Add visual defaults for the screen markers
- (void)setScreenMarkerDesc:(NSDictionary *)desc;

/// Add a group of screen (2D) markers
- (MaplyComponentObject *)addScreenMarkers:(NSArray *)markers;

/// Add visual defaults for the markers
- (void)setMarkerDesc:(NSDictionary *)desc;

/// Add a group of 3D markers
- (MaplyComponentObject *)addMarkers:(NSArray *)markers;

/// Add visual defaults for the screen labels
- (void)setScreenLabelDesc:(NSDictionary *)desc;

/// Add a group of screen (2D) labels
- (MaplyComponentObject *)addScreenLabels:(NSArray *)labels;

/// Add visual defaults for the labels
- (void)setLabelDesc:(NSDictionary *)desc;

/// Add a group of 3D labels
- (MaplyComponentObject *)addLabels:(NSArray *)labels;

/// Add visual defaults for the vectors
- (void)setVectorDesc:(NSDictionary *)desc;

/// Add one or more vectors
- (MaplyComponentObject *)addVectors:(NSArray *)vectors;

/// Add one or more vectors, but only for selection
- (MaplyComponentObject *)addSelectionVectors:(NSArray *)vectors;

/// Change the representation for the given vector object(s).
/// Only a few things are changeable, such as color
- (void)changeVector:(MaplyComponentObject *)compObj desc:(NSDictionary *)desc;

/// Add visual defaults for the shapes
- (void)setShapeDesc:(NSDictionary *)desc;

/// Add one or more shapes
- (MaplyComponentObject *)addShapes:(NSArray *)shapes;

/// Add visual defaults for the stickers
- (void)setStickerDesc:(NSDictionary *)desc;

/// Add one or more stickers
- (MaplyComponentObject *)addStickers:(NSArray *)stickers;

/// Add a view to track to a particular location
- (void)addViewTracker:(MaplyViewTracker *)viewTrack;

/// Remove the view tracker associated with the given UIView
- (void)removeViewTrackForView:(UIView *)view;

/// Remove the data associated with an object the user added earlier
- (void)removeObject:(MaplyComponentObject *)theObj;

/// Remove an array of data objects
- (void)removeObjects:(NSArray *)theObjs;

/// Remove a single layer
- (void)removeLayer:(MaplyViewControllerLayer *)layer;

/// Remove all the base layers (e.g map layers)
- (void)removeAllLayers;

/// This utility routine will convert a lat/lon (in radians) to display coordinates
- (MaplyCoordinate3d)displayPointFromGeo:(MaplyCoordinate)geoCoord;

/// Start animation (only if it's been paused)
- (void)startAnimation;

/// Pause animation (probably because we're going into the background)
- (void)stopAnimation;

/// Turn on/off performance output (goes to the log periodically)
@property (nonatomic,assign) bool performanceOutput;

@end
