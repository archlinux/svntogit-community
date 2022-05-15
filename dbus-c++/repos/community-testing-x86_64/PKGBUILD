# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Ray Rashif <schiv@archlinux.org>
# Contributor: Xavier D. <magicrhesus@ouranos.be>
# Contributor: Zarra <zarraxx@gmail.com>

pkgname=dbus-c++
_pkgname="lib${pkgname}"
_upstream="dbus-cplusplus"
pkgver=0.9.0
pkgrel=10
pkgdesc="A C++ API for D-BUS"
arch=('x86_64')
url="http://dbus-cplusplus.sourceforge.net/"
license=('LGPL2.1')
depends=('dbus' 'gcc-libs' 'glib2' 'glibc')
provides=('libdbus-c++-1.so' 'libdbus-c++-glib-1.so')
source=("https://sourceforge.net/projects/${_upstream}/files/${pkgname}/${pkgver}/${_pkgname}-${pkgver}.tar.gz"
        'gcc47.patch'
        'disable-threading.patch'
        'fix-writechar.patch'
        'template-operators.patch')
sha512sums=('7acebbb4254b2886cc0f05c5ddeeeac0b5863c5552d32249463b89380b0b95b8225c80bd98b8c7fcaada42ab770b5eff41b15390cd0d78bf1ee322ac6c2de319'
            'd8618e1eafd25be074ffecf958fbc04f1b2a844c865ec2d795565809a5d11e7f60c1a8c3a6d952b1485af6b199753b36c06f1759a5559274eed55cf5e6585e20'
            '94d95089ea84af1438191285955bf0866a7d7cbe535ac7fb8282ef6fb96c4ee052f439fb8c9d0b18b9ebec65d39cc45754bb48192ffb46c3d0c4ed6b1b6693a6'
            'df0a3a80d139877eaea5f352da5dfa2bc0407360ddfb59301707c77bd4329ecd986f366f27bbdd7e4ce385125c6ec46fcf115854aa01d97cf11dff905cd9a385'
            'af8e6281e6eb9c94cae7e8feaf8a8d7b653e4b394f9cc72fa381f647bc9c891906007dd06f55c89449396c5efd84656fe71ff453c7023cabfaad15a23f0b8a86')

prepare() {
  cd "${_pkgname}-${pkgver}"
  patch -Np0 -i "${srcdir}/gcc47.patch"
  patch -Np1 -i "${srcdir}/disable-threading.patch"
  patch -Np1 -i "${srcdir}/fix-writechar.patch"
  patch -Np1 -i "${srcdir}/template-operators.patch"
  autoreconf -vfi
}

build() {
  cd "${_pkgname}-${pkgver}"
  # -lpthread needed
  export LDFLAGS+=" -lpthread"
  ./configure --prefix=/usr \
              --disable-static \
              --disable-ecore \
              --enable-glib
  make
}

package() {
  cd "${_pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
  install -vDm 644 {AUTHORS,ChangeLog,NEWS,README,TODO} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}
# vim:set ts=2 sw=2 et:
