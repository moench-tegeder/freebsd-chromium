--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2016-04-16 23:14:47.031269362 +0200
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp	2016-04-16 23:15:26.838266639 +0200
@@ -65,7 +65,7 @@
 const char* kTextEmojiFonts[] = { "Droid Sans Fallback" };
 const char* kSymbolsFonts[] = { "Droid Sans Fallback" };
 const char* kMathFonts[] = { "Droid Sans Fallback" };
-#elif OS(LINUX)
+#elif OS(LINUX) || OS(FREEBSD)
 const char* kColorEmojiFonts[] = { "Noto Color Emoji", "Noto Sans Symbols", "Symbola", "DejaVu Sans" };
 const char* kTextEmojiFonts[] = { "Noto Sans Symbols", "Symbola", "Droid Sans Fallback", "DejaVu Sans" };
 const char* kSymbolsFonts[] = { "FreeSerif", "FreeMono", "Droid Sans Fallback", "DejaVu Sans" };
