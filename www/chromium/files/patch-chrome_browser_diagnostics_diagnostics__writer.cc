--- chrome/browser/diagnostics/diagnostics_writer.cc.orig	2017-03-09 20:04:28 UTC
+++ chrome/browser/diagnostics/diagnostics_writer.cc
@@ -263,7 +263,7 @@ bool DiagnosticsWriter::WriteResult(bool
       console_->SetColor(color);
       console_->Write(base::ASCIIToUTF16(result));
     }
-    if (format_ == MACHINE) {
+    if (format_ == THEMACHINE) {
       return WriteInfoLine(base::StringPrintf(
           "%03d %s (%s)", outcome_code, id.c_str(), extra.c_str()));
     } else {
