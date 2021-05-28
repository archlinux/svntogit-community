
pkgname=unibilium
pkgver=2.1.1
pkgrel=1
pkgdesc='A terminfo parsing library'
arch=('x86_64')
url='https://github.com/neovim/unibilium'
depends=('glibc')
provides=('libunibilium.so')
license=('LGPL3')
source=("$pkgname-$pkgver.tar.gz::https://github.com/neovim/unibilium/archive/v$pkgver.tar.gz")
sha512sums=('ebcdcddc6c3a540d086b113bb83470c1c17cf59056b28308a484b20dc3df71de0f5d6e5bf105f9e4a8347c78500c65ae46c2b53ec87692a898c321a047664ee2')

build() {
  cd $pkgname-$pkgver
  make PREFIX=/usr
}

check() {
  cd $pkgname-$pkgver
  make test
}

package() {
  cd $pkgname-$pkgver
  DESTDIR="$pkgdir" make install PREFIX=/usr
}
