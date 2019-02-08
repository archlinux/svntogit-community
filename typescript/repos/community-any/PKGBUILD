# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Bruno Galeotti <bgaleotti at gmail dot com>

pkgname=typescript
pkgver=3.3.3
pkgrel=1
pkgdesc="TypeScript is a language for application scale JavaScript development"
arch=('any')
url="http://typescriptlang.org/"
license=('Apache')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('636d57a9ee784c1569f950d235bb8361d1b0d01a6847f43ac28ffedf933c3c0534be2a5a867c9db895a2af1c5dc63b00912ee1b9ee77c76ce9f20cfb174e6ed0')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz
}

# vim:set ts=2 sw=2 et:
