--- extensions/browser/api/serial/serial_api.cc.orig	2016-04-16 20:05:23.492052481 +0200
+++ extensions/browser/api/serial/serial_api.cc	2016-04-16 20:06:45.477048899 +0200
@@ -86,11 +86,14 @@
 void SerialGetDevicesFunction::Work() {
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
 
+#if !defined(OS_FREEBSD)
+// XXX rene's quick hack on FreeBSD - still needed? (cmt)
   scoped_ptr<device::SerialDeviceEnumerator> enumerator =
       device::SerialDeviceEnumerator::Create();
   mojo::Array<device::serial::DeviceInfoPtr> devices = enumerator->GetDevices();
   results_ = serial::GetDevices::Results::Create(
       devices.To<std::vector<linked_ptr<serial::DeviceInfo> > >());
+#endif
 }
 
 SerialConnectFunction::SerialConnectFunction() {
