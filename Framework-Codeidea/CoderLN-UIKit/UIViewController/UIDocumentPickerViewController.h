/*
 * UIDocumentPickerViewController.h 
 *
 * UIKit (c) 2014-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class UIDocumentPickerViewController, UIDocumentMenuViewController;

__TVOS_PROHIBITED @protocol UIDocumentPickerDelegate <NSObject>

- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentAtURL:(NSURL *)url;

@optional
// called if the user dismisses the document picker without selecting a document (using the Cancel button)
- (void)documentPickerWasCancelled:(UIDocumentPickerViewController *)controller;
@end

typedef NS_ENUM(NSUInteger, UIDocumentPickerMode) {
    UIDocumentPickerModeImport,
    UIDocumentPickerModeOpen,
    UIDocumentPickerModeExportToService,
    UIDocumentPickerModeMoveToService
} NS_ENUM_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UIDocumentPickerViewController : UIViewController

// Initializes the picker instance for selecting a document in a remote location. The valid modes are Import and Open.
- (instancetype)initWithDocumentTypes:(NSArray <NSString *>*)allowedUTIs inMode:(UIDocumentPickerMode)mode NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

// Initializes the picker for exporting a local file to an external location. The valid modes are Export and Move. The new location will be returned using didPickDocumentAtURL:
- (instancetype)initWithURL:(NSURL *)url inMode:(UIDocumentPickerMode)mode NS_DESIGNATED_INITIALIZER;

@property (nullable, nonatomic, weak) id<UIDocumentPickerDelegate> delegate;
@property (nonatomic, assign, readonly) UIDocumentPickerMode documentPickerMode;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
