--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2016-04-16 16:02:10.774058550 +0200
+++ chrome/browser/ui/views/chrome_views_delegate.h	2016-04-16 16:03:56.974051907 +0200
@@ -35,7 +35,7 @@
 #if defined(OS_WIN)
   HICON GetDefaultWindowIcon() const override;
   HICON GetSmallWindowIcon() const override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
 
@@ -48,7 +48,7 @@
   void OnBeforeWidgetInit(
       views::Widget::InitParams* params,
       views::internal::NativeWidgetDelegate* delegate) override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
   ui::ContextFactory* GetContextFactory() override;
