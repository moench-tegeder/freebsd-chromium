--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -38,7 +38,7 @@
 #include "ui/views/window/frame_background.h"
 #include "ui/views/window/window_shape.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -292,7 +292,7 @@ void OpaqueBrowserFrameView::ButtonPress
 void OpaqueBrowserFrameView::OnMenuButtonClicked(views::MenuButton* source,
                                                  const gfx::Point& point,
                                                  const ui::Event* event) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::MenuRunner menu_runner(frame()->GetSystemMenuModel(),
                                 views::MenuRunner::HAS_MNEMONICS);
   ignore_result(menu_runner.RunMenuAt(browser_view()->GetWidget(),
