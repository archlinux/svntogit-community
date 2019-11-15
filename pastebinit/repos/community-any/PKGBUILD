# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Francois Boulogne <fboulogne at april dot org>

pkgname=pastebinit
pkgver=1.5.1
pkgrel=1
pkgdesc="Send anything you want directly to a pastebin from the command line"
arch=('any')
url="https://launchpad.net/pastebinit"
license=("GPL")
depends=("python")
makedepends=("asciidoc")
source=("$pkgname-$pkgver.tar.gz::https://github.com/felixonmars/pastebinit/archive/$pkgver.tar.gz")
sha512sums=('02b7faa54862d240eac3a8edaae2edb895cbb476cbf89dc71514a5a0a42aa2b0d26f07e5485627d1deb61f62e37018459e4d072bd4aacc886f259fced35e352c')

build() {
  cd $pkgname-$pkgver
  a2x -f manpage pastebinit.xml
  make -C po
}

package() {
  cd $pkgname-$pkgver
  install -d "$pkgdir"/usr/{bin,share/man/man1,share/locale}
  install -m 755 pastebinit "$pkgdir"/usr/bin
  install -m 644 pastebinit.1 "$pkgdir"/usr/share/man/man1
  cp -a pastebin.d "$pkgdir"/usr/share
  cp -a po/mo/* "$pkgdir"/usr/share/locale
}
