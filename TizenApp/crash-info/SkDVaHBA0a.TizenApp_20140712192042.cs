S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131118.1124
Build-Date: 2013.11.18 11:24:59

Crash Information
Process Name: TizenApp
PID: 1710
Date: 2014-07-12 19:20:42(GMT+0900)
Executable File Path: /opt/apps/SkDVaHBA0a/bin/TizenApp
This process is multi-thread process
pid=1710 tid=1710
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 1710, uid 5000)

Register Information
r0   = 0xfffffffc, r1   = 0xffffffff
r2   = 0x00000000, r3   = 0xb6ebe650
r4   = 0x0002ad04, r5   = 0xfffffffc
r6   = 0xffff0fc0, r7   = 0xffffffff
r8   = 0x000af5a8, r9   = 0xb2644f4c
r10  = 0x00000000, fp   = 0xbe8ffff8
ip   = 0xb2663ee4, sp   = 0xbe8fffb8
lr   = 0xb4c23c71, pc   = 0xb4c3e222
cpsr = 0x20000030

Memory Information
MemTotal:   797320 KB
MemFree:     26200 KB
Buffers:     35620 KB
Cached:     430652 KB
VmPeak:      89200 KB
VmSize:      81064 KB
VmLck:           0 KB
VmHWM:       24524 KB
VmRSS:       18004 KB
VmData:       8024 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       43928 KB
VmPTE:          68 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 00214000 rw-p [heap]
b23c1000 b23c6000 r-xp /usr/lib/libhaptic-module.so
b244b000 b244e000 r-xp /usr/lib/bufmgr/libtbm_exynos4412.so.0.0.0
b2456000 b2457000 r-xp /usr/lib/libdrm_slp.so.1.0.0
b2471000 b2485000 r-xp /usr/lib/libnetwork.so.0.0.0
b248e000 b2496000 r-xp /usr/lib/libcapi-network-wifi.so.0.1.2_24
b249e000 b24b2000 r-xp /usr/lib/libwifi-direct.so.0.0
b24ba000 b24c2000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b24c3000 b24cc000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b24d4000 b2547000 r-xp /usr/lib/osp/libosp-wifi.so.1.2.2.0
b2553000 b2618000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b2638000 b265b000 r-xp /opt/usr/apps/SkDVaHBA0a/bin/TizenApp.exe
b2667000 b26d9000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b26e1000 b271b000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b2724000 b2728000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2730000 b2761000 r-xp /usr/lib/libpulse.so.0.12.4
b2769000 b27cc000 r-xp /usr/lib/libasound.so.2.0.0
b27d6000 b27d9000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b27e1000 b27e5000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b27ee000 b280b000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2813000 b2821000 r-xp /usr/lib/libmmfsound.so.0.1.0
b2829000 b28c5000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b28d1000 b2912000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b291b000 b2924000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b292c000 b2939000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2942000 b2948000 r-xp /usr/lib/libUMP.so
b2950000 b2953000 r-xp /usr/lib/libmm_ta.so.0.0.0
b295b000 b296a000 r-xp /usr/lib/libICE.so.6.3.0
b2974000 b2979000 r-xp /usr/lib/libSM.so.6.0.1
b2981000 b2982000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b298a000 b2992000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b299a000 b29a2000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b29ad000 b29b0000 r-xp /usr/lib/libmmfsession.so.0.0.0
b29b8000 b29fc000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a05000 b2a18000 r-xp /usr/lib/libEGL_platform.so
b2a21000 b2af8000 r-xp /usr/lib/libMali.so
b2b03000 b2b09000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b11000 b2b12000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b1b000 b2b59000 r-xp /usr/lib/libGLESv2.so.2.0
b2b61000 b2bac000 r-xp /usr/lib/libtiff.so.5.1.0
b2bb7000 b2be0000 r-xp /usr/lib/libturbojpeg.so
b2bf9000 b2bff000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c07000 b2c0d000 r-xp /usr/lib/libgif.so.4.1.6
b2c15000 b2c37000 r-xp /usr/lib/libavutil.so.51.73.101
b2c46000 b2c74000 r-xp /usr/lib/libswscale.so.2.1.101
b2c7d000 b2f74000 r-xp /usr/lib/libavcodec.so.54.59.100
b329b000 b32b4000 r-xp /usr/lib/libpng12.so.0.50.0
b32bd000 b32c3000 r-xp /usr/lib/libfeedback.so.0.1.4
b32cb000 b32d7000 r-xp /usr/lib/libtts.so
b32df000 b32f6000 r-xp /usr/lib/libEGL.so.1.4
b32ff000 b33b6000 r-xp /usr/lib/libcairo.so.2.11200.12
b33c0000 b33da000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b33e3000 b3cde000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3d51000 b3d56000 r-xp /usr/lib/libslp_devman_plugin.so
b3d5f000 b3d62000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3d6a000 b3d6e000 r-xp /usr/lib/libsysman.so.0.2.0
b3d76000 b3d87000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3d90000 b3d92000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3d9a000 b3d9c000 r-xp /usr/lib/libdeviced.so.0.1.0
b3da4000 b3dba000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3dc2000 b3dc4000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3dcc000 b3dcf000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3dd7000 b3dda000 r-xp /usr/lib/libdevice-node.so.0.1
b3de2000 b3de6000 r-xp /usr/lib/libheynoti.so.0.0.2
b3dee000 b3e33000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e3c000 b3e51000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3e5a000 b3e5e000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3e66000 b3e6b000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3e73000 b3e74000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3e7d000 b3e80000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3e88000 b3e8b000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3e94000 b3e97000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3e9f000 b3ea0000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3ea8000 b3eb6000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3ebf000 b3ee1000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3ee9000 b3eec000 r-xp /usr/lib/libuuid.so.1.3.0
b3ef5000 b3f13000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f1b000 b3f32000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f3b000 b3f3c000 r-xp /usr/lib/libpmapi.so.1.2
b3f44000 b3f4c000 r-xp /usr/lib/libminizip.so.1.0.0
b3f54000 b3f5f000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3f67000 b403f000 r-xp /usr/lib/libxml2.so.2.7.8
b404c000 b406a000 r-xp /usr/lib/libpcre.so.0.0.1
b4072000 b4075000 r-xp /usr/lib/libiniparser.so.0
b407e000 b4082000 r-xp /usr/lib/libhaptic.so.0.1
b408a000 b4095000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40a2000 b40a7000 r-xp /usr/lib/libdevman.so.0.1
b40b0000 b40b4000 r-xp /usr/lib/libchromium.so.1.0
b40bc000 b40c2000 r-xp /usr/lib/libappsvc.so.0.1.0
b40ca000 b40cb000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b40db000 b40dd000 r-xp /opt/usr/apps/SkDVaHBA0a/bin/TizenApp
b40e5000 b40eb000 r-xp /usr/lib/libalarm.so.0.0.0
b40f4000 b4106000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b410e000 b440d000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4434000 b443e000 r-xp /lib/libnss_files-2.13.so
b4447000 b4450000 r-xp /lib/libnss_nis-2.13.so
b4459000 b446a000 r-xp /lib/libnsl-2.13.so
b4475000 b447b000 r-xp /lib/libnss_compat-2.13.so
b4484000 b448d000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b47b5000 b47c6000 r-xp /usr/lib/libcom-core.so.0.0.1
b47ce000 b47d0000 r-xp /usr/lib/libdri2.so.0.0.0
b47d8000 b47e0000 r-xp /usr/lib/libdrm.so.2.4.0
b47e8000 b47ec000 r-xp /usr/lib/libtbm.so.1.0.0
b47f4000 b47f7000 r-xp /usr/lib/libXv.so.1.0.0
b47ff000 b48ca000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b48e0000 b48f0000 r-xp /usr/lib/libnotification.so.0.1.0
b48f8000 b491c000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4925000 b4935000 r-xp /lib/libresolv-2.13.so
b4939000 b493b000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4943000 b4a96000 r-xp /usr/lib/libcrypto.so.1.0.0
b4ab4000 b4b00000 r-xp /usr/lib/libssl.so.1.0.0
b4b0c000 b4b38000 r-xp /usr/lib/libidn.so.11.5.44
b4b41000 b4b4b000 r-xp /usr/lib/libcares.so.2.0.0
b4b53000 b4b6a000 r-xp /lib/libexpat.so.1.5.2
b4b74000 b4b98000 r-xp /usr/lib/libicule.so.48.1
b4ba1000 b4ba9000 r-xp /usr/lib/libsf_common.so
b4bb1000 b4c4c000 r-xp /usr/lib/libstdc++.so.6.0.14
b4c5f000 b4d3c000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d47000 b4d6c000 r-xp /usr/lib/libexif.so.12.3.3
b4d80000 b4d8a000 r-xp /usr/lib/libethumb.so.1.7.99
b4d92000 b4dd6000 r-xp /usr/lib/libsndfile.so.1.0.25
b4de4000 b4de6000 r-xp /usr/lib/libctxdata.so.0.0.0
b4dee000 b4dfc000 r-xp /usr/lib/libremix.so.0.0.0
b4e04000 b4e05000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e0d000 b4e26000 r-xp /usr/lib/liblua-5.1.so
b4e2f000 b4e36000 r-xp /usr/lib/libembryo.so.1.7.99
b4e3f000 b4e42000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e4a000 b4e87000 r-xp /usr/lib/libcurl.so.4.3.0
b4e91000 b4e95000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4e9e000 b4f08000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f15000 b4f39000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f42000 b4f9e000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b4fb0000 b4fc4000 r-xp /usr/lib/libfribidi.so.0.3.1
b4fcc000 b5021000 r-xp /usr/lib/libfreetype.so.6.8.1
b502c000 b5050000 r-xp /usr/lib/libjpeg.so.8.0.2
b5068000 b507f000 r-xp /lib/libz.so.1.2.5
b5087000 b5094000 r-xp /usr/lib/libsensor.so.1.1.0
b509f000 b50a1000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50a9000 b50af000 r-xp /usr/lib/libxdgmime.so.1.1.0
b61c6000 b62ae000 r-xp /usr/lib/libicuuc.so.48.1
b62bb000 b63db000 r-xp /usr/lib/libicui18n.so.48.1
b63e9000 b63ec000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b63f4000 b63fd000 r-xp /usr/lib/libvconf.so.0.2.45
b6405000 b6413000 r-xp /usr/lib/libail.so.0.1.0
b641b000 b6433000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6434000 b6439000 r-xp /usr/lib/libffi.so.5.0.10
b6441000 b6442000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b644a000 b6454000 r-xp /usr/lib/libXext.so.6.4.0
b645d000 b6460000 r-xp /usr/lib/libXtst.so.6.1.0
b6468000 b646e000 r-xp /usr/lib/libXrender.so.1.3.0
b6476000 b647c000 r-xp /usr/lib/libXrandr.so.2.2.0
b6484000 b6485000 r-xp /usr/lib/libXinerama.so.1.0.0
b648e000 b6497000 r-xp /usr/lib/libXi.so.6.1.0
b649f000 b64a2000 r-xp /usr/lib/libXfixes.so.3.1.0
b64aa000 b64ac000 r-xp /usr/lib/libXgesture.so.7.0.0
b64b4000 b64b6000 r-xp /usr/lib/libXcomposite.so.1.0.0
b64be000 b64bf000 r-xp /usr/lib/libXdamage.so.1.1.0
b64c8000 b64cf000 r-xp /usr/lib/libXcursor.so.1.0.2
b64d7000 b64df000 r-xp /usr/lib/libemotion.so.1.7.99
b64e7000 b6502000 r-xp /usr/lib/libecore_con.so.1.7.99
b650b000 b6510000 r-xp /usr/lib/libecore_imf.so.1.7.99
b6519000 b6521000 r-xp /usr/lib/libethumb_client.so.1.7.99
b6529000 b652b000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6533000 b6537000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6540000 b6556000 r-xp /usr/lib/libefreet.so.1.7.99
b6560000 b6569000 r-xp /usr/lib/libedbus.so.1.7.99
b6571000 b6576000 r-xp /usr/lib/libecore_fb.so.1.7.99
b657f000 b65db000 r-xp /usr/lib/libedje.so.1.7.99
b65e5000 b65fc000 r-xp /usr/lib/libecore_input.so.1.7.99
b6617000 b661c000 r-xp /usr/lib/libecore_file.so.1.7.99
b6624000 b6641000 r-xp /usr/lib/libecore_evas.so.1.7.99
b664a000 b6689000 r-xp /usr/lib/libeina.so.1.7.99
b6692000 b6741000 r-xp /usr/lib/libevas.so.1.7.99
b6763000 b6776000 r-xp /usr/lib/libeet.so.1.7.99
b677f000 b67e9000 r-xp /lib/libm-2.13.so
b67f5000 b67fc000 r-xp /usr/lib/libutilX.so.1.1.0
b6804000 b6809000 r-xp /usr/lib/libappcore-common.so.1.1
b6811000 b681c000 r-xp /usr/lib/libaul.so.0.1.0
b6825000 b6859000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b6862000 b6892000 r-xp /usr/lib/libecore_x.so.1.7.99
b689b000 b68b0000 r-xp /usr/lib/libecore.so.1.7.99
b68c7000 b69e7000 r-xp /usr/lib/libelementary.so.1.7.99
b69fa000 b69fd000 r-xp /lib/libattr.so.1.1.0
b6a05000 b6a07000 r-xp /usr/lib/libXau.so.6.0.0
b6a0f000 b6a15000 r-xp /lib/librt-2.13.so
b6a1e000 b6a26000 r-xp /lib/libcrypt-2.13.so
b6a56000 b6a59000 r-xp /lib/libcap.so.2.21
b6a61000 b6a63000 r-xp /usr/lib/libiri.so
b6a6b000 b6a80000 r-xp /usr/lib/libxcb.so.1.1.0
b6a88000 b6a93000 r-xp /lib/libunwind.so.8.0.1
b6ac1000 b6bde000 r-xp /lib/libc-2.13.so
b6bec000 b6bf5000 r-xp /lib/libgcc_s-4.5.3.so.1
b6bfd000 b6c00000 r-xp /usr/lib/libsmack.so.1.0.0
b6c08000 b6c34000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c3d000 b6c41000 r-xp /usr/lib/libbundle.so.0.1.22
b6c49000 b6c4b000 r-xp /lib/libdl-2.13.so
b6c54000 b6d2e000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d37000 b6da1000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6dab000 b6db8000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6dc1000 b6ea7000 r-xp /usr/lib/libX11.so.6.3.0
b6eb2000 b6ec6000 r-xp /lib/libpthread-2.13.so
b6ed6000 b6eda000 r-xp /usr/lib/libappcore-efl.so.1.1
b6ee3000 b6ee4000 r-xp /usr/lib/libdlog.so.0.0.0
b6eec000 b6ef0000 r-xp /usr/lib/libsys-assert.so
b6ef8000 b6f15000 r-xp /lib/ld-2.13.so
be8e1000 be902000 rwxp [stack]
End of Maps Information

Callstack Information (PID:1710)
Call Stack Count: 1
 0: __sync_fetch_and_add_4 + 0xd (0xb4c3e222) [/usr/lib/libstdc++.so.6] + 0x8d222
End of Call Stack

Package Information
Package Name: SkDVaHBA0a.TizenApp
Package ID : SkDVaHBA0a
Version: 1.0.0
Package Type: tpk
App Name: TizenApp
App ID: SkDVaHBA0a.TizenApp
Type: Application
Categories: (NULL)
