# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=5.6.0
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('452f51e91df93588109fef9f90359a3a6a86a23e0493d806b3e0cfc4d5192aec04d7cdf18c9ae82afca8d48cd515e5ef52bbe600bcba1560f9c6b7494f6e6032')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
