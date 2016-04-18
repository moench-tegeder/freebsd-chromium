--- chrome/browser/ui/input_method/input_method_engine_base.cc.orig	2016-04-17 19:17:13.193349775 +0200
+++ chrome/browser/ui/input_method/input_method_engine_base.cc	2016-04-17 19:17:38.936347160 +0200
@@ -35,7 +35,7 @@
 #elif defined(OS_WIN)
 #include "ui/events/keycodes/dom/keycode_converter.h"
 #include "ui/events/keycodes/keyboard_codes_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/events/keycodes/dom/keycode_converter.h"
 #include "ui/events/keycodes/keyboard_codes_posix.h"
 #endif
