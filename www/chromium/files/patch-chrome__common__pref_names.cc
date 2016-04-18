--- chrome/common/pref_names.cc.orig	2016-04-16 18:57:05.708334475 +0200
+++ chrome/common/pref_names.cc	2016-04-16 18:58:03.797330758 +0200
@@ -885,7 +885,7 @@
 // supervised users.
 const char kRecordHistory[] = "settings.history_recorded";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1348,7 +1348,7 @@
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
