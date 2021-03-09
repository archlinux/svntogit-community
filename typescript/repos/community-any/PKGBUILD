# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Bruno Galeotti <bgaleotti at gmail dot com>

pkgname=typescript
pkgver=4.2.3
pkgrel=2
pkgdesc="TypeScript is a language for application scale JavaScript development"
arch=('any')
url="http://typescriptlang.org/"
license=('Apache')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('a8e718c31681c92b405ab05fe31d1f89bc19bcc446fabe1c4284e36cfb5496b5a30476e6080c30d62e38f14d0627eddc34d12d79b0ed7a8fdc1ce477c49e3013')

package() {
  npm install -g --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  # Non-deterministic race in npm gives 777 permissions to random directories.
  # See https://github.com/npm/npm/issues/9359 for details.
  chmod -R u=rwX,go=rX "$pkgdir"

  # npm installs package.json owned by build user
  # https://bugs.archlinux.org/task/63396
  chown -R root:root "$pkgdir"
}

# vim:set ts=2 sw=2 et:
