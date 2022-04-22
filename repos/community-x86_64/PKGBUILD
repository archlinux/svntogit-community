# Maintainer: Alexander F Rødseth <xyproto@archlinux.org>
# Contributor: graysky <graysky@archlinux.us>
# Contributor: <kastor@fobos.org.ar>

pkgname=lrzip
pkgver=0.641
pkgrel=2
pkgdesc='Multi-threaded compression with rzip/lzma, lzo, and zpaq'
url='https://github.com/ckolivas/lrzip'
license=('GPL')
arch=('x86_64')
depends=('lzo')
makedepends=('git')
source=("git+https://github.com/ckolivas/lrzip#tag=v$pkgver")
sha256sums=('SKIP')

build() {
  cd "$pkgname"

  CFLAGS="$CFLAGS -fomit-frame-pointer"
  CXXFLAGS="$CXXFLAGS -fomit-frame-pointer"

  ./autogen.sh --prefix=/usr "$flags"
  make
}

check() {
  make -C "$pkgname" -k check
}

package() {
  make -C "$pkgname" DESTDIR="$pkgdir" install-strip
}

# vim: ts=2 sw=2 et:
# getver: -u 3 github.com/ckolivas/lrzip/blob/master/ChangeLog
