--- content/browser/child_process_launcher.cc.orig	2016-04-16 19:08:34.807286846 +0200
+++ content/browser/child_process_launcher.cc	2016-04-16 19:21:27.041234413 +0200
@@ -149,7 +149,7 @@
 #endif
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   std::map<int, base::MemoryMappedFile::Region> regions;
   GetContentClient()->browser()->GetAdditionalMappedFilesForChildProcess(
       *cmd_line, child_process_id, files_to_register.get()
@@ -209,7 +209,7 @@
     }
   }
 #endif  // defined(V8_USE_EXTERNAL_STARTUP_DATA)
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_ANDROID)
   files_to_register->Share(
@@ -251,7 +251,7 @@
         files_to_register->GetMappingWithIDAdjustment(
             base::GlobalDescriptors::kBaseDescriptor);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (process_type == switches::kRendererProcess) {
       const int sandbox_fd =
           RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -259,7 +259,7 @@
           sandbox_fd,
           GetSandboxFD()));
     }
-#endif  // defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
 
     // Actually launch the app.
     base::LaunchOptions options;
@@ -333,13 +333,13 @@
   process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     zygote->EnsureProcessTerminated(process.Handle());
   } else
-#endif  // !OS_MACOSX
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
     base::EnsureProcessTerminated(std::move(process));
 #endif  // OS_POSIX
 #endif  // defined(OS_ANDROID)
@@ -435,7 +435,7 @@
 
 void ChildProcessLauncher::UpdateTerminationStatus(bool known_dead) {
   DCHECK(CalledOnValidThread());
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = zygote_->GetTerminationStatus(
         process_.Handle(), known_dead, &exit_code_);
@@ -443,7 +443,7 @@
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
   } else {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   if (known_dead) {
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
@@ -505,7 +505,7 @@
   starting_ = false;
   process_ = std::move(process);
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (process_.IsValid()) {
