--- gpu/config/gpu_util.cc.orig	2016-04-16 20:09:16.821036659 +0200
+++ gpu/config/gpu_util.cc	2016-04-16 20:09:58.125033607 +0200
@@ -56,6 +56,7 @@
 
 void ApplyGpuDriverBugWorkarounds(const GPUInfo& gpu_info,
                                   base::CommandLine* command_line) {
+#if !defined(OS_FREEBSD)
   scoped_ptr<GpuDriverBugList> list(GpuDriverBugList::Create());
   list->LoadList(kGpuDriverBugListJson,
                  GpuControlList::kCurrentOsOnly);
@@ -88,6 +89,7 @@
     command_line->AppendSwitchASCII(switches::kDisableGLExtensions,
                                     base::JoinString(v, " "));
   }
+#endif
 }
 
 void StringToFeatureSet(
