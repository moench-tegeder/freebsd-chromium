--- third_party/WebKit/Source/core/core.gyp.orig	2016-04-16 20:26:11.032966598 +0200
+++ third_party/WebKit/Source/core/core.gyp	2016-04-16 20:30:57.962946565 +0200
@@ -367,7 +367,7 @@
             'layout/LayoutThemeMac.mm',
           ],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources!': [
             'layout/LayoutThemeLinux.cpp',
             'layout/LayoutThemeLinux.h',
@@ -644,7 +644,7 @@
                 'layout/LayoutThemeMac.mm',
               ],
             }],
-            ['OS != "linux"', {
+            ['OS != "linux" and os_bsd != 1', {
               'sources!': [
                 'layout/LayoutThemeLinux.cpp',
                 'layout/LayoutThemeLinux.h',
