--- third_party/cacheinvalidation/src/google/cacheinvalidation/include/types.h.orig	2016-04-16 23:03:07.539317718 +0200
+++ third_party/cacheinvalidation/src/google/cacheinvalidation/include/types.h	2016-04-16 23:04:24.619312236 +0200
@@ -337,6 +337,8 @@
 
   /* Creates a new Status object given the code and message. */
   Status(Code code, const string& message) : code_(code), message_(message) {}
+  /* this is a hack to cope with the std::pair constructor -cmt */
+  Status() : code_(SUCCESS), message_(nullptr) {}
 
   bool IsSuccess() const {
     return code_ == SUCCESS;
