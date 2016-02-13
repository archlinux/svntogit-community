gcc -o core/libmincrypt/dsa_sig.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/dsa_sig.c
gcc -o core/libmincrypt/p256_ec.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/p256_ec.c
gcc -o core/libmincrypt/rsa.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/rsa.c
gcc -o core/libmincrypt/sha.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/sha.c
gcc -o core/libmincrypt/p256.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/p256.c
gcc -o core/libmincrypt/p256_ecdsa.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/p256_ecdsa.c
gcc -o core/libmincrypt/sha256.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/libmincrypt/sha256.c
gcc -o core/mkbootimg/mkbootimg.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/include -c core/mkbootimg/mkbootimg.c
g++ -o mkbootimg  $LDFLAGS core/libmincrypt/dsa_sig.c.o core/libmincrypt/p256_ec.c.o core/libmincrypt/rsa.c.o core/libmincrypt/sha.c.o core/libmincrypt/p256.c.o core/libmincrypt/p256_ecdsa.c.o core/libmincrypt/sha256.c.o core/mkbootimg/mkbootimg.c.o
g++ -o core/adb/adb.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb.cpp
g++ -o core/adb/adb_auth.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_auth.cpp
g++ -o core/adb/adb_io.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_io.cpp
g++ -o core/adb/adb_listeners.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_listeners.cpp
g++ -o core/adb/adb_utils.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_utils.cpp
g++ -o core/adb/sockets.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/sockets.cpp
g++ -o core/adb/transport.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/transport.cpp
g++ -o core/adb/transport_local.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/transport_local.cpp
g++ -o core/adb/transport_usb.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/transport_usb.cpp
g++ -o core/adb/fdevent.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/fdevent.cpp
g++ -o core/adb/get_my_path_linux.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/get_my_path_linux.cpp
g++ -o core/adb/usb_linux.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/usb_linux.cpp
g++ -o core/adb/adb_auth_host.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_auth_host.cpp
g++ -o core/adb/adb_main.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_REVISION=\"$PKGVER\" -D_GNU_SOURCE -DADB_HOST=1 -DWORKAROUND_BUG6558362 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_main.cpp
g++ -o core/adb/console.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_REVISION=\"$PKGVER\" -D_GNU_SOURCE -DADB_HOST=1 -DWORKAROUND_BUG6558362 -fpermissive -Icore/include -Icore/base/include -c core/adb/console.cpp
g++ -o core/adb/commandline.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_REVISION=\"$PKGVER\" -D_GNU_SOURCE -DADB_HOST=1 -DWORKAROUND_BUG6558362 -fpermissive -Icore/include -Icore/base/include -c core/adb/commandline.cpp
g++ -o core/adb/adb_client.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_REVISION=\"$PKGVER\" -D_GNU_SOURCE -DADB_HOST=1 -DWORKAROUND_BUG6558362 -fpermissive -Icore/include -Icore/base/include -c core/adb/adb_client.cpp
g++ -o core/adb/services.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_REVISION=\"$PKGVER\" -D_GNU_SOURCE -DADB_HOST=1 -DWORKAROUND_BUG6558362 -fpermissive -Icore/include -Icore/base/include -c core/adb/services.cpp
g++ -o core/adb/file_sync_client.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_REVISION=\"$PKGVER\" -D_GNU_SOURCE -DADB_HOST=1 -DWORKAROUND_BUG6558362 -fpermissive -Icore/include -Icore/base/include -c core/adb/file_sync_client.cpp
g++ -o core/base/file.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -Icore/base/include -Icore/include -c core/base/file.cpp
g++ -o core/base/stringprintf.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -Icore/base/include -Icore/include -c core/base/stringprintf.cpp
g++ -o core/base/strings.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DADB_HOST=1 -Icore/base/include -Icore/include -c core/base/strings.cpp
gcc -o core/liblog/logd_write.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DLIBLOG_LOG_TAG=1005 -DFAKE_LOG_DEVICE=1 -D_GNU_SOURCE -Icore/log/include -Icore/include -c core/liblog/logd_write.c
gcc -o core/liblog/log_event_write.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DLIBLOG_LOG_TAG=1005 -DFAKE_LOG_DEVICE=1 -D_GNU_SOURCE -Icore/log/include -Icore/include -c core/liblog/log_event_write.c
gcc -o core/liblog/fake_log_device.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DLIBLOG_LOG_TAG=1005 -DFAKE_LOG_DEVICE=1 -D_GNU_SOURCE -Icore/log/include -Icore/include -c core/liblog/fake_log_device.c
gcc -o core/libcutils/load_file.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/load_file.c
gcc -o core/libcutils/socket_inaddr_any_server.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/socket_inaddr_any_server.c
gcc -o core/libcutils/socket_local_client.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/socket_local_client.c
gcc -o core/libcutils/socket_local_server.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/socket_local_server.c
gcc -o core/libcutils/socket_loopback_client.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/socket_loopback_client.c
gcc -o core/libcutils/socket_loopback_server.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/socket_loopback_server.c
gcc -o core/libcutils/socket_network_client.c.o -std=gnu11 $CFLAGS $CPPFLAGS -D_GNU_SOURCE -Icore/include -c core/libcutils/socket_network_client.c
g++ -o adb -lrt -ldl -lpthread -lcrypto $LDFLAGS core/base/file.cpp.o core/base/stringprintf.cpp.o core/base/strings.cpp.o core/liblog/logd_write.c.o core/liblog/log_event_write.c.o core/liblog/fake_log_device.c.o core/libcutils/load_file.c.o core/libcutils/socket_inaddr_any_server.c.o core/libcutils/socket_local_client.c.o core/libcutils/socket_local_server.c.o core/libcutils/socket_loopback_client.c.o core/libcutils/socket_loopback_server.c.o core/libcutils/socket_network_client.c.o core/adb/adb.cpp.o core/adb/adb_auth.cpp.o core/adb/adb_io.cpp.o core/adb/adb_listeners.cpp.o core/adb/adb_utils.cpp.o core/adb/sockets.cpp.o core/adb/transport.cpp.o core/adb/transport_local.cpp.o core/adb/transport_usb.cpp.o core/adb/fdevent.cpp.o core/adb/get_my_path_linux.cpp.o core/adb/usb_linux.cpp.o core/adb/adb_auth_host.cpp.o core/adb/adb_main.cpp.o core/adb/console.cpp.o core/adb/commandline.cpp.o core/adb/adb_client.cpp.o core/adb/services.cpp.o core/adb/file_sync_client.cpp.o
gcc -o core/fastboot/protocol.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/protocol.c
gcc -o core/fastboot/engine.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/engine.c
g++ -o core/fastboot/bootimg_utils.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/bootimg_utils.cpp
g++ -o core/fastboot/fastboot.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/fastboot.cpp
gcc -o core/fastboot/util.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/util.c
gcc -o core/fastboot/fs.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/fs.c
gcc -o core/fastboot/usb_linux.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/usb_linux.c
gcc -o core/fastboot/util_linux.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DFASTBOOT_REVISION=\"$PKGVER\" -D_GNU_SOURCE -Icore/include -Icore/libsparse/include -Icore/mkbootimg -Iextras/ext4_utils -Iextras/f2fs_utils -c core/fastboot/util_linux.c
gcc -o core/libsparse/backed_block.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -c core/libsparse/backed_block.c
gcc -o core/libsparse/output_file.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -c core/libsparse/output_file.c
gcc -o core/libsparse/sparse.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -c core/libsparse/sparse.c
gcc -o core/libsparse/sparse_crc32.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -c core/libsparse/sparse_crc32.c
gcc -o core/libsparse/sparse_err.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -c core/libsparse/sparse_err.c
gcc -o core/libsparse/sparse_read.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -c core/libsparse/sparse_read.c
g++ -o core/libziparchive/zip_archive.cc.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -Icore/base/include -Icore/include -c core/libziparchive/zip_archive.cc
g++ -o core/libutils/FileMap.cpp.o -std=gnu++11 $CXXFLAGS $CPPFLAGS -Icore/include -c core/libutils/FileMap.cpp
gcc -o extras/ext4_utils/make_ext4fs.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/make_ext4fs.c
gcc -o extras/ext4_utils/ext4fixup.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/ext4fixup.c
gcc -o extras/ext4_utils/ext4_utils.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/ext4_utils.c
gcc -o extras/ext4_utils/allocate.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/allocate.c
gcc -o extras/ext4_utils/contents.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/contents.c
gcc -o extras/ext4_utils/extent.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/extent.c
gcc -o extras/ext4_utils/indirect.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/indirect.c
gcc -o extras/ext4_utils/sha1.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/sha1.c
gcc -o extras/ext4_utils/wipe.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/wipe.c
gcc -o extras/ext4_utils/crc16.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/crc16.c
gcc -o extras/ext4_utils/ext4_sb.c.o -std=gnu11 $CFLAGS $CPPFLAGS -Icore/libsparse/include -Icore/include -Ilibselinux/include -c extras/ext4_utils/ext4_sb.c
gcc -o libselinux/src/callbacks.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/callbacks.c
gcc -o libselinux/src/check_context.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/check_context.c
gcc -o libselinux/src/freecon.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/freecon.c
gcc -o libselinux/src/init.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/init.c
gcc -o libselinux/src/label.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/label.c
gcc -o libselinux/src/label_file.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/label_file.c
gcc -o libselinux/src/label_android_property.c.o -std=gnu11 $CFLAGS $CPPFLAGS -DAUDITD_LOG_TAG=1003 -D_GNU_SOURCE -DHOST -Ilibselinux/include -c libselinux/src/label_android_property.c
g++ -o fastboot -lz -lpcre $LDFLAGS core/libsparse/backed_block.c.o core/libsparse/output_file.c.o core/libsparse/sparse.c.o core/libsparse/sparse_crc32.c.o core/libsparse/sparse_err.c.o core/libsparse/sparse_read.c.o core/libziparchive/zip_archive.cc.o core/liblog/logd_write.c.o core/liblog/log_event_write.c.o core/liblog/fake_log_device.c.o core/libutils/FileMap.cpp.o core/base/file.cpp.o core/base/stringprintf.cpp.o core/base/strings.cpp.o extras/ext4_utils/make_ext4fs.c.o extras/ext4_utils/ext4fixup.c.o extras/ext4_utils/ext4_utils.c.o extras/ext4_utils/allocate.c.o extras/ext4_utils/contents.c.o extras/ext4_utils/extent.c.o extras/ext4_utils/indirect.c.o extras/ext4_utils/sha1.c.o extras/ext4_utils/wipe.c.o extras/ext4_utils/crc16.c.o extras/ext4_utils/ext4_sb.c.o libselinux/src/callbacks.c.o libselinux/src/check_context.c.o libselinux/src/freecon.c.o libselinux/src/init.c.o libselinux/src/label.c.o libselinux/src/label_file.c.o libselinux/src/label_android_property.c.o core/fastboot/protocol.c.o core/fastboot/engine.c.o core/fastboot/bootimg_utils.cpp.o core/fastboot/fastboot.cpp.o core/fastboot/util.c.o core/fastboot/fs.c.o core/fastboot/usb_linux.c.o core/fastboot/util_linux.c.o
