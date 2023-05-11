# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-panel
pkgver=1.26.3
pkgrel=1
pkgdesc="The MATE Panel"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('dbus-glib' 'libwnck3' 'libcanberra' 'libmateweather' 'libsm' 'mate-menus' 'mate-desktop' 'gettext' 'gtk-layer-shell')
makedepends=('itstool' 'gobject-introspection' 'mate-common' 'yelp-tools' 'autoconf-archive')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
groups=('mate')
conflicts=('mate-panel-gtk3')
replaces=('mate-panel-gtk3')
sha256sums=('f33f10d527450ba7e98cc70ab255ac481330aa9e66dbcc7c511b6baa171de029')

build() {
    cd "${pkgname}-${pkgver}" 
    ./configure \
                --prefix=/usr \
                --libexecdir=/usr/lib/${pkgname} \
                --sysconfdir=/etc \
                --localstatedir=/var \
                --enable-introspection

    #https://bugzilla.gnome.org/show_bug.cgi?id=656231
    sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    make
}

package() {
    cd "${pkgname}-${pkgver}"
    make DESTDIR="${pkgdir}" install
}
