//
//  FLLogSink.h
//  FishLampFrameworks
//
//  Created by Mike Fullerton on 8/22/12.
//  Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton.. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import <FishLampCore/FishLampCore.h>

@class FLLogEntry;

typedef enum {
    FLLogOutputSimple           = 0,
    FLLogOutputWithLocation     = (1 << 1),
    FLLogOutputWithStackTrace   = (1 << 2)
} FLLogSinkOutputFlags;

@class FLLogger;

@protocol FLLogSink <NSObject>
- (void) logEntry:(FLLogEntry*) entry stopPropagating:(BOOL*) stop;
@end

@interface FLLogSink : NSObject<FLLogSink> {
@private
    FLLogSinkOutputFlags _outputFlags;
}
- (id) initWithOutputFlags:(FLLogSinkOutputFlags) outputFlags;

@property (readwrite, assign) FLLogSinkOutputFlags outputFlags;
@end


