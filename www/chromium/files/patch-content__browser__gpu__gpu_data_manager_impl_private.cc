--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2016-04-16 19:38:59.574161086 +0200
+++ content/browser/gpu/gpu_data_manager_impl_private.cc	2016-04-16 19:42:40.111146294 +0200
@@ -486,8 +486,10 @@
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_FREEBSD)
   gpu::IdentifyActiveGPU(&gpu_info);
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -529,6 +531,7 @@
     // Also declare the driver_vendor to be osmesa to be able to specify
     // exceptions based on driver_vendor==osmesa for some blacklist rules.
     gpu_info.driver_vendor = gfx::kGLImplementationOSMesaName;
+#if !defined(OS_FREEBSD)
   } else {
     TRACE_EVENT0("startup",
       "GpuDataManagerImpl::Initialize:CollectBasicGraphicsInfo");
@@ -545,6 +548,7 @@
       gpu_info.gpu.active = true;
       gpu_info.secondary_gpus.clear();
     }
+#endif
   }
 #if defined(ARCH_CPU_X86_FAMILY)
   if (!gpu_info.gpu.vendor_id || !gpu_info.gpu.device_id) {
@@ -631,7 +635,9 @@
     return;
 
   bool was_info_available = IsCompleteGpuInfoAvailable();
+#if !defined(OS_FREEBSD)
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   if (IsCompleteGpuInfoAvailable()) {
     complete_gpu_info_already_requested_ = true;
   } else if (was_info_available) {
