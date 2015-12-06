--- components/metrics/system_memory_stats_recorder_linux.cc.orig	2015-12-04 22:02:44.070348000 +0100
+++ components/metrics/system_memory_stats_recorder_linux.cc	2015-12-04 22:03:45.958077000 +0100
@@ -29,6 +29,7 @@
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_FREEBSD)
   base::SystemMemoryInfoKB memory;
   if (!base::GetSystemMemoryInfo(&memory))
     return;
@@ -92,6 +93,7 @@
       break;
     }
   }
+#endif // !defined(OS_FREEBSD)
 }
 
 }  // namespace metrics
