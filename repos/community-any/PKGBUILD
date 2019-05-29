# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=6.1.1
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('ad662ad9ee62616f9f15efe83cfb582716208c19bcb02e2b9a819d50e80107b567c0ab7a1eb2fbf77976be81f5525b32619a49e20d307e39d310ed6cd4d3f679')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
