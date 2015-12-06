--- remoting/remoting_host.gypi.orig	2015-12-04 23:06:13.124292000 +0100
+++ remoting/remoting_host.gypi	2015-12-04 23:08:18.149472000 +0100
@@ -18,7 +18,7 @@
         'remoting_host_win.gypi',
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or os_bsd==1', {
       'includes': [
         'remoting_host_linux.gypi',
       ],
@@ -57,7 +57,7 @@
             '<@(remoting_host_sources)',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or os_bsd==1', {
               'conditions': [
                 ['use_x11==1', {
                   'dependencies': [
@@ -331,7 +331,7 @@
             'host/setup/start_host.cc',
           ],
           'conditions': [
-            ['OS=="linux" and use_allocator!="none"', {
+            ['(OS=="linux" or os_bsd==1) and use_allocator!="none"', {
               'dependencies': [
                 '../base/allocator/allocator.gyp:allocator',
               ],
@@ -671,13 +671,13 @@
                 'host/it2me/it2me_native_messaging_host_main.h',
               ],
               'conditions': [
-                ['OS=="linux" and chromeos==0 and use_ozone==0', {
+                ['(OS=="linux" or os_bsd==1) and chromeos==0 and use_ozone==0', {
                   'dependencies': [
                     # Always use GTK on Linux, even for Aura builds.
                     '../build/linux/system.gyp:gtk2',
                   ],
                 }],
-                ['OS=="linux" and use_allocator!="none"', {
+                ['OS=="linux" or os_bsd==1 and use_allocator!="none"', {
                   'dependencies': [
                     '../base/allocator/allocator.gyp:allocator',
                   ],
