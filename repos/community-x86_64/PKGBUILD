# Maintainer:  Christian Himpel <chressie at gmail dot com>
# Contributor: Johannes Hanika <hanatos at gmail dot com>

pkgname=darktable
pkgver=0.5
pkgrel=1
pkgdesc="Utility to organize and develop raw images"
arch=(i686 x86_64)
url=http://darktable.sf.net/
license=(GPL3)
depends=('exiv2>=0.18' 'gconf>=2.26' 'intltool>=0.40' 'lcms' 'lensfun>=0.2.3' 'libglade')
makedepends=('intltool>=0.40')
install=darktable.install
options=(!libtool)
source=(http://downloads.sourceforge.net/$pkgname/$pkgname-$pkgver.tar.bz2)
md5sums=('7e441a94e6c44e8b212439f7ac5cf3a6')

build() {
  # Linking fails with --as-needed linker option
  unset LDFLAGS

  cd $srcdir/$pkgname-$pkgver
  autoreconf
  ./configure --prefix=/usr --disable-schemas-install --with-gconf-schema-file-dir=/usr/share/gconf/schemas || return 1
  make || return 1
  make DESTDIR=$pkgdir install || return 1
  mkdir -p $pkgdir/usr/share/doc/$pkgname-$pkgver
  install -m644 AUTHORS LICENSE NEWS README TODO TRANSLATORS $pkgdir/usr/share/doc/$pkgname-$pkgver || return 1
}
