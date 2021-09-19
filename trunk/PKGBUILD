# Maintainer: Sébastien Luttringer
# Contributer: Nicolas Martyanoff <khaelin@gmail.com>

pkgname=lksctp-tools
pkgver=1.0.19
pkgrel=1
pkgdesc='An implementation of the SCTP protocol'
arch=('x86_64')
url='https://github.com/sctp/lksctp-tools'
license=('GPL2' 'LGPL2.1')
makedepends=('git')
depends=('bash')
source=("git+https://github.com/sctp/lksctp-tools.git#tag=v$pkgver")
sha256sums=('SKIP')

build() {
  cd $pkgname
  ./bootstrap
  ./configure --prefix=/usr
  make
}

check() {
  cd $pkgname/src/func_tests
  make v4test
  make v6test
}

package() {
  cd $pkgname
  make DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
