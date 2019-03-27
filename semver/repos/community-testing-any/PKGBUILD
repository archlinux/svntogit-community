# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=6.0.0
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('d147b053ef6b15aa4a16795b8ab2e2ddbca83ae86b4ac962ff3fe284d9ef336e2f805fbcb0d0622352d93c1487f7024a5306946f0facde14e80cb09792b821ad')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
