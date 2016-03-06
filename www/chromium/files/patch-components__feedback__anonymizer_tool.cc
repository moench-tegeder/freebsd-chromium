--- components/feedback/anonymizer_tool.cc.orig	2016-03-05 21:12:40.810576880 +0100
+++ components/feedback/anonymizer_tool.cc	2016-03-05 21:12:56.522575394 +0100
@@ -9,7 +9,11 @@
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_util.h"
 #include "base/strings/stringprintf.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using re2::RE2;
 
