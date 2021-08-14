# Maintainer: Johannes Löthberg <johannes@kyriasis.com>

pkgname=pacutils
pkgver=0.11.1
pkgrel=1

pkgdesc='Helper tools for libalpm'
url='https://github.com/andrewgregory/pacutils'
arch=('x86_64')
license=('MIT')

depends=('pacman')
makedepends=('git')

source=("git+https://github.com/andrewgregory/pacutils.git#commit=aa4ba003cb446907a71be4aa976546d113ecc688")
sha1sums=('SKIP')

build() {
  cd pacutils
  make CFLAGS="$CFLAGS $LDFLAGS" SYSCONFDIR=/etc LOCALSTATEDIR=/var
}

check() {
  cd pacutils
  make check
}

package() {
  cd pacutils
  make DESTDIR="$pkgdir" PREFIX=/usr install
  install -Dm644 COPYING "$pkgdir"/usr/share/licenses/"$pkgname"/COPYING
}

# vim: set ft=PKGBUILD et sw=2:
