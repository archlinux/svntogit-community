# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=6.3.0
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('6f7f5305a4d27d5eb206b6a953cf69e5f29e904da6fcdc270e870e56bb90152d7fbde320773b8f72738cdf833a0b0c56f231ff97111ae6b0680de530bb91c74f')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
