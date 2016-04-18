--- chrome/common/chrome_paths.h.orig	2016-04-16 18:42:12.386401317 +0200
+++ chrome/common/chrome_paths.h	2016-04-16 18:45:44.962381649 +0200
@@ -50,7 +50,7 @@
   DIR_USER_APPLICATIONS,        // ~/Applications
   DIR_USER_LIBRARY,             // ~/Library
 #endif
-#if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD)) || \
+#if defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD)) || \
     defined(OS_MACOSX)
   DIR_USER_EXTERNAL_EXTENSIONS,  // Directory for per-user external extensions
                                  // on Chrome Mac and Chromium Linux.
@@ -117,7 +117,7 @@
   DIR_SUPERVISED_USER_INSTALLED_WHITELISTS,  // Directory where sanitized
                                              // supervised user whitelists are
                                              // installed.
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
   DIR_NATIVE_MESSAGING,         // System directory where native messaging host
                                 // manifest files are stored.
   DIR_USER_NATIVE_MESSAGING,    // Directory with Native Messaging Hosts
@@ -132,10 +132,10 @@
   DIR_GEN_TEST_DATA,            // Directory where generated test data resides.
   DIR_TEST_DATA,                // Directory where unit test data resides.
   DIR_TEST_TOOLS,               // Directory where unit test tools reside.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   FILE_COMPONENT_FLASH_HINT,    // A file in a known location that points to
                                 // the component updated flash plugin.
-#endif // defined(OS_LINUX)
+#endif // defined(OS_LINUX) || defined(OS_BSD)
 
   PATH_END
 };
