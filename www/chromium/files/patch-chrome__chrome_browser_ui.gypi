--- chrome/chrome_browser_ui.gypi.orig	2016-04-16 16:09:41.888027333 +0200
+++ chrome/chrome_browser_ui.gypi	2016-04-16 16:12:39.890015467 +0200
@@ -3069,7 +3069,7 @@
             }],
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or os_bsd==1)', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -3077,7 +3077,7 @@
             '../build/linux/system.gyp:gio',
           ],
         }],
-        ['OS=="win" or OS=="mac" or desktop_linux==1', {
+        ['OS=="win" or OS=="mac" or desktop_linux==1 or os_bsd==1', {
           'sources': [ '<@(chrome_browser_ui_desktop_sources)' ],
         }],
         ['use_aura==1', {
@@ -3244,14 +3244,14 @@
             }],
           ],
         }],
-        ['desktop_linux==1', {
+        ['desktop_linux==1 or os_bsd==1', {
           'dependencies': [
             '../ui/base/ime/ui_base_ime.gyp:ui_base_ime',
             '../ui/events/events.gyp:dom_keycode_converter',
           ],
           'sources': [ '<@(chrome_browser_ui_desktop_linux_sources)' ],
         }],
-        ['OS=="linux"', {  # Both desktop Linux and ChromeOS.
+        ['OS=="linux" or OS=="freebsd"', {  # Both desktop Linux and ChromeOS.
           'sources': [ '<@(chrome_browser_ui_linux_sources)' ],
           'conditions': [
             ['use_aura==1', {
