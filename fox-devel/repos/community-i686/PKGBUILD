# Maintainer : speps <speps at aur dot archlinux dot org>
# Contributor: Dany Martineau <dany.luc.martineau@gmail.com>

pkgname=fox-devel
pkgver=1.7.46 # version 1.7.26 up breaks theme management, maybe restored in 1.7.29
pkgrel=1
pkgdesc="Free Objects for X: GUI Toolkit for C++, development version."
arch=('i686' 'x86_64')
url="http://www.fox-toolkit.org/"
license=('LGPL' 'custom')
depends=('glu' 'libsm' 'libtiff' 'libxcursor' 'libxft' 'libxi' 'libxrandr')
makedepends=('mesa')
install="$pkgname.install"
provides=("fox=$pkgver")
source=("${url/www/ftp}pub/fox-$pkgver.tar.gz")
md5sums=('e30f45e4fcdc6f4ed655e41d5c4a4df2')

build() {
  cd fox-$pkgver
  ./configure   --prefix=/usr \
                --enable-static=no \
                --enable-release \
                --with-xft=yes \
                --with-opengl=yes \
                --with-xim \
                --with-xshm \
                --with-shape \
                --with-xcursor \
                --with-xrender \
                --with-xrandr \
                --with-xfixes \
                --with-xinput
  make
}

package() {
  cd fox-$pkgver
  make DESTDIR="$pkgdir/" install

  # license
  install -Dm644 LICENSE_ADDENDUM "$pkgdir/usr/share/licenses/$pkgname/LICENSE"

  # rename apps to prevent conflicts with fox
  for _f in `find $pkgdir/usr/bin -type f`; do
    mv $_f $_f-1.7
  done;
  for _f in `find $pkgdir/usr/share/man -type f`; do
    mv $_f `dirname $_f`/`basename $_f .1`-1.7.1
  done;
}
