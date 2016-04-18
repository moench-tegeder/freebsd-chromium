--- media/media.gyp.orig	2016-04-16 20:12:11.982023874 +0200
+++ media/media.gyp	2016-04-16 20:17:25.704002497 +0200
@@ -745,7 +745,7 @@
             ['exclude', '_alsa\\.(h|cc)$'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_x11==1', {
               'dependencies': [
@@ -1095,7 +1095,7 @@
             'base/simd/filter_yuv_sse2.cc',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and os_bsd!=1', {
           'sources!': [
             'base/keyboard_event_counter.cc',
             'base/keyboard_event_counter.h',
