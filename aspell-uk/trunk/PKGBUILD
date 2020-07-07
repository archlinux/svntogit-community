# Maintainer: Jaroslav Lichtblau <dragonlord@aur.archlinux.org>
# Contributor: Roman Kyrylych <roman@archlinux.org>

pkgname=aspell-uk
pkgver=1.8.0
_ftpver=1.4.0
pkgrel=3
pkgdesc="Ukrainian dictionary for aspell"
arch=('x86_64')
url="http://ispell-uk.sourceforge.net/"
license=('GPL' 'LGPL' 'MPL')
depends=('aspell')
source=(ftp://ftp.gnu.org/gnu/aspell/dict/uk/aspell6-uk-${_ftpver}-0.tar.bz2
        https://downloads.sourceforge.net/project/ispell-uk/spell-uk/$pkgver/spell-uk-$pkgver.tgz
        aspell-uk-perl-5.26.patch)
sha256sums=('35f9a7e840c1272706bc6dd172bc9625cbd843d021094da8598a6abba525f18c'
            '111e5b945254df4e140922d10daa3da2beffe05d389c1cb2e1e436298f23f2b5'
            '736c05603a361cd31ff045f2669e8fd8cdaa7ec6222bc328d1ad9310d422e609')

prepare() {
  cd spell-uk-$pkgver
  patch -p1 -i ../aspell-uk-perl-5.26.patch # Fix build with perl 5.26
}

build() {
  # needed when using a source package from ispell-uk project
  cd ${srcdir}/spell-uk-$pkgver
  make

  cd ${srcdir}/aspell6-uk-${_ftpver}-0
  ./configure
  make

  # needed when using a source package from ispell-uk project
  #mv ${srcdir}/spell-uk-$pkgver/dist/aspell-uk-$pkgver/* \
  #  ${srcdir}/aspell6-uk-${_ftpver}-0
}

package() {
  cd ${srcdir}/aspell6-uk-${_ftpver}-0

  make DESTDIR="$pkgdir" install
}
