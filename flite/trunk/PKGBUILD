# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Steven Honeyman <stevenhoneyman at gmail com>

pkgname=flite
pkgver=2.2
pkgrel=1
pkgdesc="A lightweight speech synthesis engine"
arch=(x86_64)
url="http://www.festvox.org/flite/"
license=(custom)
depends=(alsa-lib)
makedepends=(chrpath)
source=(https://github.com/festvox/flite/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('ab1555fe5adc3f99f1d4a1a0eb1596d329fd6d74f1464a0097c81f53c0cf9e5c')

prepare() {
  cd $pkgname-$pkgver
  sed '/^#VOXES.*$/d; s/+//g; s/cmu_indic_lex/&\nVOXES = cmu_us_kal16 cmu_us_slt/' config/android.lv >config/archlinux.lv
  sed -i '/$(INSTALL) -m 755 $(BINDIR)\/flite_time $(DESTDIR)$(INSTALLBINDIR)/d' main/Makefile
}

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --enable-shared \
			    --with-audio=alsa \
			    --with-vox=cmu_us_kal16 \
			    --with-langvox=archlinux
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
  install -D -m644 COPYING "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

# Fix rpath
  chrpath -d "$pkgdir"/usr/bin/*
}
