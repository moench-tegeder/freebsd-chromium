--- device/usb/usb_device_handle_impl.cc.orig	2016-04-16 19:48:24.680121823 +0200
+++ device/usb/usb_device_handle_impl.cc	2016-04-16 19:49:24.184119479 +0200
@@ -24,7 +24,12 @@
 #include "device/usb/usb_error.h"
 #include "device/usb/usb_service.h"
 #include "net/base/io_buffer.h"
+#if defined(OS_FREEBSD)
+#include "libusb.h"
+#define LIBUSB_CALL
+#else
 #include "third_party/libusb/src/libusb/libusb.h"
+#endif
 
 namespace device {
 
