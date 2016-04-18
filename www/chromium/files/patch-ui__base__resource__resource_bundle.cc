--- ui/base/resource/resource_bundle.cc.orig	2016-04-16 20:33:42.482935511 +0200
+++ ui/base/resource/resource_bundle.cc	2016-04-16 20:34:50.667930349 +0200
@@ -674,7 +674,7 @@
 #elif defined(OS_MACOSX)
   if (base::mac::IsOSLionOrLater())
     supported_scale_factors.push_back(SCALE_FACTOR_200P);
-#elif defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
   ui::SetSupportedScaleFactors(supported_scale_factors);
