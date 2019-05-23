# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=6.1.0
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('902a8438e1e805c16cff609cba4e176ab9bf2a259148b117f4201917cc6427a64f948a1367c5797fb275eaf60b26a0db47b2abc5326947696a8c8126d90c7d71')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
