# Maintainer: Alexander F Rødseth <xyproto@archlinux.org>
# Contributor: graysky <graysky@archlinux.us>
# Contributor: <kastor@fobos.org.ar>

pkgname=lrzip
pkgver=0.651
pkgrel=2
pkgdesc='Multi-threaded compression with rzip/lzma, lzo, and zpaq'
url='https://github.com/ckolivas/lrzip'
license=('GPL')
arch=('x86_64')
depends=('lzo')
makedepends=('git')
source=("git+https://github.com/ckolivas/lrzip#tag=v${pkgver}"
        "${pkgname}-${pkgver}-CVE-2018-5786.patch::https://github.com/ckolivas/lrzip/commit/3495188cd8f2215a9feea201f3e05c1341ed95fb.patch")
sha256sums=('SKIP'
            '8573ff8dd049c91cd0e6d754683e889ae439119cb9e738241dedd369c280a6fc')

prepare() {
  cd "${pkgname}"
  patch -Np1 < "../${pkgname}-${pkgver}-CVE-2018-5786.patch"
}

build() {
  cd "${pkgname}"

  CFLAGS="$CFLAGS -fomit-frame-pointer"
  CXXFLAGS="$CXXFLAGS -fomit-frame-pointer"

  ./autogen.sh --prefix=/usr "$flags"
  make
}

check() {
  make -C "${pkgname}" -k check
}

package() {
  make -C "${pkgname}" DESTDIR="${pkgdir}" install-strip
}

# vim: ts=2 sw=2 et:
# getver: -u 3 github.com/ckolivas/lrzip/blob/master/ChangeLog
