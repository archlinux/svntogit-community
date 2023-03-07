# Contributor: Jan de Groot <jgc@archlinux.org>

pkgname=libmms
pkgver=0.6.4
pkgrel=4
pkgdesc="MMS stream protocol library"
arch=(x86_64)
url="https://sourceforge.net/projects/libmms/"
license=(LGPL)
depends=('glibc')
source=(https://download.sourceforge.net/libmms/${pkgname}-${pkgver}.tar.gz
        libmms-Remove-requires-glib2.0.patch)
sha256sums=('3c05e05aebcbfcc044d9e8c2d4646cd8359be39a3f0ba8ce4e72a9094bee704f'
            '5c4e8d2e0d8f623d692d855e8de3e88e6da1e3748523fdc661a029ec1aff33a1')

prepare() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  # Remove "Requires: glib-2.0" since libmms no longer depends on GLib.
  patch -Np1 -i ../libmms-Remove-requires-glib2.0.patch
}

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  ./configure --prefix=/usr --disable-static
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
}
