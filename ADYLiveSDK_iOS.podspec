#
# Be sure to run `pod lib lint ADYLiveSDK_iOS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ADYLiveSDK_iOS'
  s.version          = '0.1.4'
  s.summary          = 'ADYLiveSDK_iOS. 奥点小助手SDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  It's an SDK for adyun live sdk, which implement by Objective-C.
                       DESC

  s.homepage         = 'https://github.com/HEROhuqinchao/ADYLiveSDK_iOS'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'HEROhuqinchao' => '616592062@qq.com' }
  s.source           = { :git => 'https://github.com/HEROhuqinchao/ADYLiveSDK_iOS.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

   #s.ios.deployment_target = '10.0'
   s.platform     = :ios
   s.platform     = :ios, "9.0"

#  s.source_files = 'ADYLiveSDK_iOS/Classes/**/*.{h,m}'

  s.frameworks = "CoreVideo","OpenGLES","AVFoundation","CoreMedia","VideoToolbox","AudioToolbox"
  s.vendored_frameworks = 'ADYLiveSDK_iOS/Classes/ADYLiveSDK.framework'

  # s.resource_bundles = {
  #   'ADYLiveSDK_iOS' => ['ADYLiveSDK_iOS/Assets/*.png']
  # }
#s.user_target_xcconfig = {'OTHER_LDFLAGS' => ['-lObjC','-all_load']}#build setting的配置
#s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' } #设置不支持bitcode
#s.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' } #设置不支持bitcode


  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
