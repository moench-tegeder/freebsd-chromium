--- chrome/common/pref_names.h.orig	2016-04-16 18:59:58.557322476 +0200
+++ chrome/common/pref_names.h	2016-04-16 19:00:58.053318136 +0200
@@ -295,7 +295,7 @@
 extern const char kRecordHistory[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -464,7 +464,7 @@
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 
