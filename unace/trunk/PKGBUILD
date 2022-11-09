# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: lowercase

pkgname=unace
pkgver=2.5
pkgrel=11
pkgdesc="An extraction tool for the proprietary ace archive format"
arch=('x86_64')
url="http://www.winace.com/"
license=('custom')
depends=('ncurses')
makedepends=('patch')
install=$pkgname.install
changelog=$pkgname.changelog
source=(https://ftp.debian.org/debian/pool/non-free/u/unace-nonfree/unace-nonfree_2.5.orig.tar.gz
        https://salsa.debian.org/fabian/unace-nonfree/raw/6f374bfd86ced925409a8bd70b5786e6020b4cbe/debian/patches/20-isatty.diff
        01-makefiles.dpatch 04-64bit.dpatch)
sha512sums=('f7e9f3431f882160693cb55a90449e881aead9dc501bb4bb8303f04530bd3f6e1d84bbc2775d23e7c680e1e2d55a06872658c4b14c7bf51dd2db73fdcdea953b'
            '61ebf66c1edf15693d59d5444fc9de5911f409981bd81afcfb5ac90c2f165319148f3b3e94e86c79075869247850e33797a3e6f50cfe0fc5789d25522b7621ea'
            '65d019999b75e3443bf015fc3c69f6d323c0441a05c9d04b4d52a7c4f85bd2719bb543023266598ebbf16976d650e44dff874cbf22ba4c022920fba8608e371b'
            '1fb9e7ec089fe7eee8983bef54b3b50d8f9feac7e27f07114cb91ce98edd7026edde4920f32d7d06abb4dc236a05a7c6eb0bcfa3eb99872e5c17fce6e61651e8')

prepare() {
  cd "${srcdir}"/$pkgname-$pkgver

  patch -p1 < ../01-makefiles.dpatch
  patch -p1 < ../04-64bit.dpatch
  patch -p1 < ../20-isatty.diff
}


build() {
  cd "${srcdir}"/$pkgname-$pkgver

  make
}

package() {
  cd "${srcdir}"/$pkgname-$pkgver

  install -Dm755 unace "${pkgdir}"/usr/bin/$pkgname
  install -Dm644 licence "${pkgdir}"/usr/share/licenses/$pkgname/license
}
