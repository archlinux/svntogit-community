# Maintainer: George Rawlinson <george@rawlinson.net.nz>
# Contributor: Immae <ismael.bouya@normalesup.org>

pkgname=editline
pkgver=1.17.1
pkgrel=2
pkgdesc='A readline() replacement for UNIX without termcap (ncurses)'
arch=('x86_64')
url='http://troglobit.com/editline.html'
license=('BSD')
install="$pkgname.install"
source=("$pkgname-$pkgver.tar.gz::https://github.com/troglobit/$pkgname/archive/$pkgver.tar.gz")
sha512sums=('6fd8951a490e0a3f30bb20d775036f622e583042d6dc315d657bb9fdad76b3f4e219290f24ab497209d6143a56dd1d227152ba0c40e7912b8a443ab50f9b05dd')

build () {
  cd "$pkgname-$pkgver"
  ./autogen.sh
  ./configure --prefix=/usr
  make
}

package() {
  cd "$pkgname-$pkgver"
  make DESTDIR="$pkgdir" install
  
  # avoid libedit conflict
  mv "$pkgdir"/usr/share/man/man3/editline{,-troglobit}.3

  # license
  install -Dm0644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"

  # additional documentation
  cp -vrt "$pkgdir/usr/share/doc/$pkgname" docs
}
