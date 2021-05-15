# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: durbatuluk <dvdscripter@gmail.org>
# Contributor: Steve Ponsford <sp4d@lavabit.com>

pkgname=blackbox
pkgver=0.77
pkgrel=1
pkgdesc="A window manager for X11"
url="https://github.com/bbidulock/blackboxwm"
arch=('x86_64')
depends=('gcc-libs' 'libxft' 'libxext' 'libx11' 'libxt')
license=('MIT')
source=($pkgname-$pkgver.tar.gz::"https://github.com/bbidulock/blackboxwm/archive/$pkgver.tar.gz")
sha256sums=('c614adae1a96edab02f2b0d00cd6b33080c5b9b11569fc254a069e1a9fcb8275')

prepare() {
  cd blackboxwm-$pkgver
  sed -e '/AC_DISABLE_SHARED/d' -i configure.ac # Build shared library
  ./autogen.sh
}

build() {
  cd blackboxwm-$pkgver
  ./configure --prefix=/usr --mandir=/usr/share/man
  make
}

package() {
  cd blackboxwm-$pkgver
  make DESTDIR="$pkgdir" install
  install -D -m644 COPYING "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
