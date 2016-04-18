--- ipc/ipc_message_utils.cc.orig	2016-04-16 22:57:57.641338143 +0200
+++ ipc/ipc_message_utils.cc	2016-04-16 22:58:47.881335781 +0200
@@ -414,7 +414,7 @@
   l->append(base::UintToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::Int64ToString(static_cast<int64_t>(p)));
