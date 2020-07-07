# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: James Rayner <james@archlinux.org>
# Contributor: Ben <ben@benmazer.net>

pkgname=dosbox
pkgver=0.74.3
pkgrel=2
pkgdesc='Emulator with builtin DOS for running DOS Games'
arch=('x86_64')
url='http://dosbox.sourceforge.net/'
license=('GPL')
depends=('sdl_net' 'zlib' 'sdl_sound' 'libgl' 'libpng' 'alsa-lib' 'gcc-libs' 'glu')
makedepends=('mesa-libgl' 'gendesk' 'patch')
source=(https://downloads.sourceforge.net/$pkgname/$pkgname-0.74-3.tar.gz
        dosbox.png)
sha256sums=('c0d13dd7ed2ed363b68de615475781e891cd582e8162b5c3669137502222260a'
            '491c42d16fc5ef7ee2eca1b736f7801249d4ca8c0b236a001aec0d3e24504f3b')

prepare() {
  cd "${srcdir}"
  gendesk --pkgname "$pkgname" --pkgdesc "$pkgdesc"
}

build() {
  cd "${srcdir}/$pkgname-0.74-3"

  ./configure --prefix=/usr --sysconfdir=/etc/dosbox
  make
}

package() {
  cd "${srcdir}/$pkgname-0.74-3"

  make DESTDIR="${pkgdir}" install

# install docs, make does not install them
  install -Dm644 README "${pkgdir}"/usr/share/doc/$pkgname/README
  install -Dm644 docs/README.video "${pkgdir}"/usr/share/doc/$pkgname/README.video

  install -Dm644 "${srcdir}/$pkgname.png" \
    "${pkgdir}/usr/share/pixmaps/$pkgname.png"
  install -Dm644 "${srcdir}/$pkgname.desktop" \
    "${pkgdir}/usr/share/applications/$pkgname.desktop"
}

# vim:set ts=2 sw=2 et:
