--- device/usb/usb_context_unittest.cc.orig	2017-03-09 20:04:33 UTC
+++ device/usb/usb_context_unittest.cc
@@ -7,7 +7,11 @@
 #include "build/build_config.h"
 #include "device/usb/usb_context.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
