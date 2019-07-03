# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=6.2.0
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('8dd142d55754193ff649c81b8a67fb152c7d8892d7a2a7e095217e8097ae356569884dfb3886dcd63cb047f189c85773de69e4cf6fe27742f427f72bd22cd1e4')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
