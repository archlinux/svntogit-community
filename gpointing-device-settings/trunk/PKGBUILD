# Contributor: Thomas Mudrunka <harvie@@email..cz>
# You can also contact me on http://blog.harvie.cz/

pkgname=gpointing-device-settings
pkgver=1.5.1
pkgrel=3
pkgdesc="GUI tool for setting pointing device such as TrackPoint or Touchpad. Each UI can be written as dynamic loadable module, so a third party can add its own UI. This 
will replace GSynaptics."
arch=('i686' 'x86_64')
license=('GPL')
url="http://live.gnome.org/GPointingDeviceSettings"
depends=(
	'gtk2' 'gconf' 'gnome-settings-daemon' 'xorg-xinput'
)
makedepends=(
	'intltool' 'pkgconfig'
)
optdepends=(
	'xf86-input-synaptics: Synaptics touchpads'
	'libsynaptics: Synaptics touchpads'
)

source=("http://keihanna.dl.sourceforge.jp/gsynaptics/45812/${pkgname}-${pkgver}.tar.gz")
md5sums=('1d1491473df8eabca3c15c997a975d7f')

build() {
	cd "${srcdir}/${pkgname}-${pkgver}"

	#WORKAROUND!!! WE SHOULD GET RID OF THIS:###########
	echo 'diff --git a/configure.ac b/configure.ac
index 29215e8..728d4c0 100644
--- a/configure.ac
+++ b/configure.ac
@@ -146,9 +146,9 @@ GENHTML_OPTIONS="--title 'GPointingDeviceSettings Code Coverage'"
 
 GPDS_CFLAGS="$XINPUT_CFLAGS $GTK_CFLAGS"
 GPDS_CFLAGS="$GPDS_CFLAGS $GCONF2_CFLAGS"
-GPDS_CFLAGS="$GPDS_CFLAGS -DGTK_DISABLE_DEPRECATED"
-GPDS_CFLAGS="$GPDS_CFLAGS -DGDK_DISABLE_DEPRECATED"
-GPDS_CFLAGS="$GPDS_CFLAGS -DG_DISABLE_DEPRECATED"
+#GPDS_CFLAGS="$GPDS_CFLAGS -DGTK_DISABLE_DEPRECATED"
+#GPDS_CFLAGS="$GPDS_CFLAGS -DGDK_DISABLE_DEPRECATED"
+#GPDS_CFLAGS="$GPDS_CFLAGS -DG_DISABLE_DEPRECATED"
 GPDS_CFLAGS="$GPDS_CFLAGS -DGPDS_MODULEDIR=\\\"\"\$(gpds_moduledir)\"\\\""
 GPDS_CFLAGS="$GPDS_CFLAGS -DGPDS_DATADIR=\\\"\"\$(gpds_datadir)\"\\\""
 GPDS_CFLAGS="$GPDS_CFLAGS -DGPDS_UIDIR=\\\"\"\$(gpds_uidir)\"\\\""
' | patch -p1

#Magic patch contributed by mattis:
	echo '--- a/modules/gnome-settings-daemon-plugins/gsd-pointing-device-plugin.c
+++ b/modules/gnome-settings-daemon-plugins/gsd-pointing-device-plugin.c
@@ -158,6 +158,9 @@
     plugin_class->activate = activate;
     plugin_class->deactivate = deactivate;
 }
+
+static void
+gsd_mouse_extension_plugin_class_finalize(GsdMouseExtensionPluginClass *klass);
' | patch -p1
	####################################################

	./configure  --prefix=/usr --sysconfdir=/etc  || return 1
	#./configure || return 1
	make || return 1
	make DESTDIR=${pkgdir} install || return 1

	mkdir -p ${pkgdir}/usr/bin
	cd ${pkgdir}/usr/bin

	mkdir -p ${pkgdir}/usr/share/applications

#	echo '[Desktop Entry]
#Encoding=UTF-8
#Name=gpointing-device-settings
#Comment=Set your pointing device (such as TrackPoint or Touchpad) preferences
#Exec=gpointing-device-settings
##Icon=input-mouse
#Icon=input_devices_settings
#Terminal=false
#Type=Application
#StartupNotify=true
#Categories=GNOME;GTK;Settings;HardwareSettings;Application;
#' > ${pkgdir}/usr/share/applications/gnome-gpointing-device-settings.desktop

}
