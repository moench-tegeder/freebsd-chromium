--- ui/base/ime/ime_engine_handler_interface.h.orig	2016-04-17 19:25:01.146316434 +0200
+++ ui/base/ime/ime_engine_handler_interface.h	2016-04-17 19:25:14.666315458 +0200
@@ -138,7 +138,7 @@
   // Hides the input view window (from API call).
   virtual void HideInputView() = 0;
 
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
 
   // Get the id of the IME extension.
   virtual std::string GetExtensionId() const = 0;
