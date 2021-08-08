# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-settings-daemon
pkgver=1.26.0
pkgrel=1
pkgdesc="The MATE Settings daemon"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('dbus-glib' 'libcanberra' 'libmatekbd' 'libmatemixer' 'libnotify'
         'mate-desktop' 'nss' 'polkit' 'gettext')
makedepends=('python')
optdepends=('libcanberra-pulse: PulseAudio support'
            'pulseaudio-alsa: PulseAudio support')
groups=('mate')
conflicts=('mate-settings-daemon-gtk3')
replaces=('mate-settings-daemon-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('b77aa017ff811a6fcae40bd45f18d8606eec87be21e3e6fa6d35c0fe14e66d41')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${pkgname} \
        	--sysconfdir=/etc \
        	--enable-polkit \
        	--enable-pulse

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
