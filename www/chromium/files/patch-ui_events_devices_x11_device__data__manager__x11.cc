--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2017-03-09 20:04:49 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -834,6 +834,8 @@ void DeviceDataManagerX11::SetDisabledKe
 }
 
 void DeviceDataManagerX11::DisableDevice(int deviceid) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   blocked_devices_.set(deviceid, true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
@@ -845,6 +847,7 @@ void DeviceDataManagerX11::DisableDevice
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(int deviceid) {
