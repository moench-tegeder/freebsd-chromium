--- components/autofill/core/browser/form_structure.cc.orig	2016-04-16 19:05:41.214298612 +0200
+++ components/autofill/core/browser/form_structure.cc	2016-04-16 19:06:09.062296628 +0200
@@ -34,7 +34,11 @@
 #include "components/autofill/core/common/form_field_data_predictions.h"
 #include "components/rappor/rappor_service.h"
 #include "components/rappor/rappor_utils.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace autofill {
 namespace {
