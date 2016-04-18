--- base/trace_event/process_memory_dump.cc.orig	2016-04-16 15:06:15.413290661 +0200
+++ base/trace_event/process_memory_dump.cc	2016-04-16 15:06:43.036287472 +0200
@@ -96,7 +96,7 @@
     // HANDLE_EINTR tries for 100 times. So following the same pattern.
     do {
       result =
-          mincore(reinterpret_cast<void*>(chunk_start), chunk_size, vec.get());
+          mincore(reinterpret_cast<void*>(chunk_start), chunk_size, (char *) vec.get());
     } while (result == -1 && errno == EAGAIN && error_counter++ < 100);
     failure = !!result;
 
