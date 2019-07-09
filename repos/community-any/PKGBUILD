# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Bruno Galeotti <bgaleotti at gmail dot com>

pkgname=typescript
pkgver=3.5.3
pkgrel=1
pkgdesc="TypeScript is a language for application scale JavaScript development"
arch=('any')
url="http://typescriptlang.org/"
license=('Apache')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('002cc1b66fcf85704321de9aeac0c97eba13da9396b7fa0e9e4e3f744946e46df764befbe8ddd8ebfe9b29924116977e6f4e45dc2b7da838cc7899915ad136fe')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz
}

# vim:set ts=2 sw=2 et:
