/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <Foundation/NSJSONSerialization.h>
#import <Cordova/CDVAvailability.h>
#import <Cordova/CDVInvokedUrlCommand.h>
#import <Cordova/CDVCommandDelegate.h>
#import <Cordova/CDVCommandQueue.h>
#import <Cordova/CDVSettingsDictionary.h>
#import <Cordova/CDVScreenOrientationDelegate.h>
#import <Cordova/CDVWebViewEngineProtocol.h>

@class CDVPlugin;

NS_ASSUME_NONNULL_BEGIN

@interface CDVViewController : UIViewController

@property (nonatomic, nullable, readonly, strong) NSXMLParser *configParser CDV_DEPRECATED(8, "Unused");
@property (nonatomic, nullable, readonly, copy) NSString *appURLScheme CDV_DEPRECATED(8, "Unused");

@property (nonatomic, readonly, nullable, weak) IBOutlet UIView *webView;

@property (nonatomic, readonly, strong) NSDictionary<NSString *, CDVPlugin *> *pluginObjects;
@property (nullable, nonatomic, readonly, strong) NSDictionary<NSString *, NSString *> *pluginsMap CDV_DEPRECATED(8, "Internal implementation detail, should not be used");

@property (nonatomic, readwrite, copy) NSString *appScheme;

@property (nonatomic, readonly, strong) CDVCommandQueue *commandQueue;
@property (nonatomic, readonly, strong) id <CDVCommandDelegate> commandDelegate;
@property (nonatomic, readonly, strong) id <CDVWebViewEngineProtocol> webViewEngine;

/**
 The Cordova preferences for this view.

 This is a dictionary populated from the preference key/value pairs in the
 Cordova XML configuration file.
 */
@property (nonatomic, readonly, strong) CDVSettingsDictionary *settings;

@property (nonatomic, readwrite, copy) IBInspectable NSString *configFile;

/**
 The filepath to the Cordova XML configuration file.
 */
@property (nonatomic, nullable, readonly, copy) NSURL *configFilePath;

/**
 The filepath to the HTML error fallback page, if one has been provided.
 */
@property (nonatomic, nullable, readonly, copy) NSURL *errorURL;

/**
 The folder path containing the web content to be displayed.
 The default value is `"www"`.
 This can be set in the storyboard file as a view controller attribute.
  */
@property (nonatomic, readwrite, copy) IBInspectable NSString *webContentFolderName;

@property (nonatomic, readwrite, copy) NSString *wwwFolderName CDV_DEPRECATED_WITH_REPLACEMENT(8, "Use webContentFolderName instead", "webContentFolderName");

@property (nonatomic, nullable, readwrite, copy) IBInspectable NSString *startPage;

/**
 A boolean value indicating whether to show the splash screen while the webview
 is initially loading.

 The default value is `YES`.

 This can be set in the storyboard file as a view controller attribute.
 */
@property (nonatomic) IBInspectable BOOL showInitialSplashScreen;

/**
 The color drawn behind the web content.

 This is used as the background color for the web view behind any HTML content
 and during loading before web content has been rendered. The default value is
 the system background color.

 This can be set in the storyboard file as a view controller attribute.
 */
@property (nonatomic, null_resettable, copy) IBInspectable UIColor *backgroundColor;

/**
 The color drawn behind the splash screen content.

 This is used as the background color for the splash screen while the web
 content is loading. If a page background color has been specified, that will
 be used as the default value, otherwise the system background color is used.

 This can be set in the storyboard file as a view controller attribute.
 */
@property (nonatomic, null_resettable, copy) IBInspectable UIColor *splashBackgroundColor;

- (UIView*)newCordovaViewWithFrame:(CGRect)bounds;

- (nullable CDVPlugin *)getCommandInstance:(NSString *)pluginName;
- (void)registerPlugin:(CDVPlugin*)plugin withClassName:(NSString*)className;
- (void)registerPlugin:(CDVPlugin*)plugin withPluginName:(NSString*)pluginName;

/**
 Toggles the display of the splash screen overtop of the web view.

 - Parameters:
   - visible: Whether to make the splash screen visible or not.
 */
- (void)showLaunchScreen:(BOOL)visible;

- (void)parseSettingsWithParser:(NSObject <NSXMLParserDelegate>*)delegate;

@end

NS_ASSUME_NONNULL_END
